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

#define ERR(node, msg) PushError(ctx->e, ctx->filename, NodeLine[node], NodeColumn[node], msg)

Span GetSpan(int node) {
  char* s = NodeName[node]; 
  int len = NodeLen[node];
  return SPAN((Byte*)s, len);
}

void ResetState(Context* ctx) {
    ctx->typeName    = SPAN0;
    ctx->globalDecl  = false;
    ctx->isSliceType = false;
    ctx->toHeader    = false;
}

void VisitToken(int node, Context* ctx) {

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

Span TypeConvert(Span sp) {
  for(size_t i = 0; i < sizeof(ttypes) / sizeof(ttypes[0]); i++) {
    Span nt = ttypes[i];
    if(SpanEqual(nt, sp)) {
      return stypes[i];
    }
  }
  return sp;
}

void PrintPrimitiveType(int node, Context* ctx) {
  Span sp = GetSpan(node);
  Span nt = TypeConvert(sp);

  BufferMCopy(' ', ctx->c, nt);
  if(ctx->toHeader) {
    BufferMCopy(' ', ctx->h, nt);
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
    if(symbol == -1) die("Using symbol not found in the symbol table??");

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
    die("Found a using idenfitier with an unknown type in the symbol table??");
  }
}

void VisitQualFunc(int node, Context* ctx) {
  Span namespace = ChildValue(node,1);

  int nsNode = SymGFind(namespace);
  if(nsNode == -1) {
    ERR(node, "Qualified function call without a corresponding using statement.");
    return;
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
      die("Qualified function call with a using statement of an unknown kind");
  }
}

void VisitFuncDef(int node, Context* ctx) {
  ctx->toHeader = true;
  visit(Child(node,1), ctx);
  visit(Child(node,2), ctx);
  visit(Child(node,3), ctx);
  visit(Child(node,4), ctx);
  visit(Child(node,5), ctx);
  BufferSLCopy(0,ctx->h, ";");
  ctx->toHeader = false;
  visit(Child(node,6), ctx);
}

void ExtractType(int node, Context* ctx) {
  int maybeValueType = node;
  Kind nk = NodeKind[maybeValueType];

  if(nk == Token || nk == PrimitiveType) {
    ctx->typeName = TypeConvert(GetSpan(maybeValueType));
  } else {
    int sliceType = Child(maybeValueType, 1);
    if(NodeKind[sliceType] != Token) {
      die("The first node of a slice type is not a token??");
    }
    ctx->typeName    = TypeConvert(GetSpan(sliceType));
    ctx->isSliceType = true;
  }
}

void EmitExternDecl(Span varName, Context* ctx) {
  BufferMLCopy(' ', ctx->h, S("extern"), ctx->typeName, varName, ctx->isSliceType ? S("[]") : S(""), S(";"));
}

void VisitDecl(int node, Context* ctx) {

  if(ctx->globalDecl) {
    ExtractType(Child(node, 1), ctx);
    int maybeToken = Child(node, 2);
    if(NodeKind[maybeToken] == Token) {
      EmitExternDecl(GetSpan(maybeToken), ctx);
    } else {
      int sliceToken = Child(maybeToken, 1);
      if(NodeKind[sliceToken] != Token) {
        die("The first node of a slice assignment node is not a token??");
      }
      EmitExternDecl(GetSpan(sliceToken), ctx);
    }
  }

  VisitChildren(node, ctx);
}


void trace(int node, Context* ctx) {
  Span s = GetSpan(node);
  char* v = s.ptr == 0 ? "" : (char*)SpanTo1KTempString(s);

  printf("%-15s %-10s ", NodeStr(NodeKind[node]), v);
  if(ctx->typeName.ptr != 0) OsPrintSpan(ctx->typeName);
  printf("%s\n", "");
}
void visit(int node, Context* ctx) {
  //int line = 0;
  //trace(node,ctx);

  switch(NodeKind[node]) {
    case Token:
      VisitToken(node, ctx);
      break;
    case Generic:
      VisitChildren(node, ctx);
      break;
    case PrimitiveType: // Standarize size of ints
      PrintPrimitiveType(node, ctx);
      break;
    case WithLine: // Insert file and line numbers (or just newlines)
      // line = NodeLine[node] - 1;
      // BufferSLCopy(0, ctx->c, "\n", "#line ", itoa(line), " \"", ctx->filename, "\"");
      BufferSLCopy(0, ctx->c, "");
      VisitChildren(node, ctx);
      break;
    case Using: // Change Using to import
      VisitUsing(node, ctx);
      break;
    case FuncDef: // Generate an external function declaration in the header
      VisitFuncDef(node, ctx);
      break;
    case GlobalDecl: // Set a flag to remember the last type name while walking the ast
      ctx->globalDecl = true;
      VisitChildren(node, ctx);
      ctx->globalDecl = false;
      break;
    case QualFuncCall: // Prepend the correct qualifier to a function call
      VisitQualFunc(node, ctx);
      break;
    case Decl: // Emit extern declarations in header file
      VisitDecl(node, ctx);
      //VisitChildren(node, ctx);
      break;
    case QualIdentifier:
      die("Qualified identifiers shouldn't be in this position.");
    }
}
