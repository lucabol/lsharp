/*
 * Thechnically, we are:
 * 1. Simplifiying C by removing pointers, references, structs, unions, ...
 * 2. Make integer types of fixed size (i.e., int -> int32_t, long -> int64_t,...)
 * 3. Introduce a simple namespace/module system
 * 4. Interoperate seamenslessly with C (i.e., using stdio.h ... stdio.printf(...))
 * 5. Make array manipulation safe (array store len, foreach, ...)
*/
#include <ctype.h>
#include <stdlib.h>

#include "config.h"
#include "ast.h"
#include "visit.h"
#include "symtable.h"

Span GetSpan(int node) {
  char* s = NodeName[node]; 
  int len = NodeLen[node];
  return SPAN((Byte*)s, len);
}

void PrintNode(int node, Context* ctx) {
  Span sp = GetSpan(node);
  char spacing = ispunct(sp.ptr[0]) ? 0 : ' '; 

  int symbol = SymGFind(sp);
  Span pre = S("");

  // Local functions need to be prepended by the namespace
  if(symbol != -1 && SymGType[symbol] == SymLocalFunc && !SpanEqual(sp, S("main"))) {
    pre = ctx->name_space;
    spacing = 0;
  };

  BufferMCopy(spacing, ctx->c, pre, sp);
  if(ctx->toHeader) {
    BufferMCopy(spacing, ctx->h, pre, sp);
  }
}

Span ttypes[] = { S("bool"),S("byte"),S("sbyte"),S("char"),S("double"),S("float"),
  S("int"),S("uint"),S("nint"),S("nuint"),S("long"),S("ulong"),S("short"),S("ushort")};
Span stypes[] = { S("bool"),S("int8_t"),S("sbyte"),S("char"),S("double"),S("float"),
  S("int32_t"),S("uint32_t"),S("int"),S("unsigned int"),S("int64_t"),S("uint64_t"),S("int16_t"),S("uint16_t")};

void PrintPrimitiveType(int node, Context* ctx) {
  Span sp = GetSpan(node);
  for(size_t i = 0; i < sizeof(ttypes) / sizeof(ttypes[0]); i++) {
    if(SpanEqual(ttypes[i], sp)) {
      Span newType = stypes[i];
      BufferMCopy(' ', ctx->c, newType);
      if(ctx->toHeader) {
        BufferMCopy(' ', ctx->h, newType);
      }
      break;
    }
  }
}

void VisitChildren(int node, Context* ctx) {
  int child = NodeFirstChild[node];
  while(true) {
    int n = NodeChildren[child++];
    if(n >= 0) {
      visit(n, ctx);
    } else {
      break;
    }
  }
}

void VisitUsing(int node, Context* ctx) {
  int afterUsing = Child(node, 1);
  Kind kind      = NodeKind[afterUsing];

  if(kind == Token) {
    Span value = ChildValue(node, 1);
    int symbol = SymGFind(value);
    if(symbol == -1) die("Using symbol not found");
    SymType t = SymGType[symbol];
    if(t == SymQuotedUsing) {
      BufferMLCopy(0, ctx->h, S("#include "), value);
    } else {
      BufferMLCopy(0, ctx->h, S("#include \""), value, S(".h\""));
    }
  } else if(kind == QualIdentifier){
    Span beforeDot = ChildValue(afterUsing, 1);
    Span afterDot  = ChildValue(afterUsing, 3);
    BufferMLCopy(0, ctx->h, S("#include \""), beforeDot, S("."), afterDot, S(".h\""));
  } else {
    die("Unknown term after using");
  }
}

void VisitQualFunc(int node, Context* ctx) {
  Span namespace = ChildValue(node,1);

  int nsNode = SymGFind(namespace);
  if(nsNode == -1) {
    die("Function call without a corresponding using statement.");
  }
  switch(SymGType[nsNode]) {
    case SymUsing:
      BufferMCopy(0, ctx->c, namespace, ChildValue(node,3));
      visit(Child(node,4), ctx);
      visit(Child(node,5), ctx);
      visit(Child(node,6), ctx);
      break;
    case SymCUsing:
      visit(Child(node,3), ctx);
      visit(Child(node,4), ctx);
      visit(Child(node,5), ctx);
      visit(Child(node,6), ctx);
      break;
    default:
      die("Qualified function call without a corresponding 'using' statement.");
  }
}
char *itoa(long n)
{
    static char buf[15];

    snprintf(buf, sizeof(buf), "%ld", n);
    return   buf;
}

void visit(int node, Context* ctx) {
  int line = 0;

  switch(NodeKind[node]) {
    case Token:
      PrintNode(node, ctx);
      break;
    case Generic:
      VisitChildren(node, ctx);
      break;
    case PrimitiveType: // Standarize size of ints
      PrintPrimitiveType(node, ctx);
      break;
    case WithLine: // Insert file and line numbers
      line = NodeLine[node];
      BufferSLCopy(0, ctx->c, "\n", "#line ", itoa(line), " \"", ctx->filename, "\"");
      VisitChildren(node, ctx);
      break;
    case Using: // Change Using to import
      VisitUsing(node, ctx);
      break;
    case FuncDef:
      ctx->toHeader = true;
      VisitChildren(node, ctx);
      BufferSLCopy(0,ctx->h, ";");
      break;
    case FuncCall:
      VisitChildren(node, ctx);
      break;
    case QualFuncCall:
      VisitQualFunc(node, ctx);
      break;
    case Block:
      ctx->toHeader = false;
      VisitChildren(node, ctx);
      break;
    case QualIdentifier:
      die("Qualified identifiers shouldn't be in this position.");
    }
}
