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
    ctx->toHeader    = false;
}

inline static bool
IsLocalFunc(Span sp) {
  int symbol = SymGFind(sp);
  SymType stype = SymGType[symbol];

  return (stype == SymLocalFunc) && (!SpanEqual(sp, S("main"))) && (!SpanEqual(sp, S("Main")));
}

inline static bool
IsGlobalVar(Span sp) {
  SymType t = SymTypeFind(sp);
  return t == SymGlobalVar || t == SymGlobalSliceVar;
}

void VisitToken(int node, Context* ctx) {

  Span sp = GetSpan(node);

  char spacing = ispunct(sp.ptr[0]) ? 0 : ' '; 

  Span pre = S("");


  // Local functions and global variables need to be prepended by the namespace
  if(IsLocalFunc(sp) || IsGlobalVar(sp)) {

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

void VisitQualIdentifier(int node, Context* ctx) {
  Span namespace = ChildValue(node,1);

  int nsNode = SymGFind(namespace);
  if(nsNode == -1) {
    ERR(node, "Qualified symbol without a corresponding using statement.");
    return;
  }
  switch(SymGType[nsNode]) {
    case SymUsing:
      BufferMCopy(0, ctx->c, namespace, ChildValue(node,3));
      break;
    case SymCUsing:
      visit(Child(node,3), ctx);
      break;
    default:
      die("Qualified symbol with a using statement of an unknown kind");
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
  Kind nk = NodeKind[node];

  if(nk == PrimitiveType) {
    ctx->typeName = TypeConvert(GetSpan(node));
  } else {
    ExtractType(Child(node,1), ctx);
  }
}

void EmitHeader(Span varName, Context* ctx, bool isSliceType) {
  if(ctx->globalDecl) {
    BufferMLCopy(0, ctx->h, S("extern "), ctx->typeName, S(" "),
                 ctx->name_space, varName,
                 isSliceType ? S("[]") : S(""), S(";"));
    }
}

void AddToST(Span varName, Context* ctx, bool isSliceType) {
  if(ctx->globalDecl) {
    SymGAdd(varName, isSliceType ? SymGlobalSliceVar : SymGlobalVar);
  } else {
    SymLAdd(varName, isSliceType ? SymLocalSliceVar : SymLocalVar);
  }
}

void VisitDeclSliceSimple(int node, Context* ctx) {

  ExtractType(Child(node, 1), ctx);
  Span varName = ChildValue(node, 2);

  AddToST(varName, ctx, true);
  EmitHeader(varName, ctx, true);

  VisitChildren(node, ctx);
}

void VisitSliceAssign(int node, Context* ctx) {

  Span varName = ChildValue(node, 1);

  AddToST(varName, ctx, true);
  EmitHeader(varName, ctx, true);
  
  VisitChildren(node, ctx);
}

void VisitDeclSimple(int node, Context* ctx) {

  ExtractType(Child(node, 1), ctx);
  Span varName = ChildValue(node, 2);

  AddToST(varName, ctx, false);
  EmitHeader(varName, ctx, false);

  VisitChildren(node, ctx);
}


void VisitAssign(int node, Context* ctx) {

  Span varName = ChildValue(node, 1);

  AddToST(varName, ctx, false);
  EmitHeader(varName, ctx, false);
  
  VisitChildren(node, ctx);
}

void VisitDeclAssign(int node, Context* ctx) {

  ExtractType(Child(node, 1), ctx);

  VisitChildren(node, ctx);
}

void trace(int node, Context* ctx) {
  Span s = GetSpan(node);
  char* v = s.ptr == 0 ? "" : (char*)SpanTo1KTempString(s);

  printf("%-15s %-10s ", NodeStr(NodeKind[node]), v);
  if(ctx->typeName.ptr != 0) OsPrintSpan(ctx->typeName);
  printf("%s\n", "");
}

void VisitCCode(int node, Context* ctx) {
  Span sp = ChildValue(node, 1);
  Span su = SpanSub(sp, 1, sp.len - 1);
  BufferMCopy(0, ctx->c, su);
}

void visit(int node, Context* ctx) {
  //int line = 0;
  // trace(node,ctx);

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
      ResetState(ctx);
      break;
    case DeclSimple: // Emit extern declarations in header file
      VisitDeclSimple(node, ctx);
      break;
    case DeclSliceSimple: // Emit extern declarations in header file
      VisitDeclSliceSimple(node, ctx);
      break;
    case DeclAssign: // Emit extern declarations in header file
      VisitDeclAssign(node, ctx);
      break;
    case Assign: // Assignment after declaration 
      VisitAssign(node, ctx);
      break;
    case SliceAssign: // Assignment after declaration 
      VisitSliceAssign(node, ctx);
      break;
    case QualIdentifier:
      VisitQualIdentifier(node, ctx);
      break;
    case Block:
      PushScope();
      VisitChildren(node, ctx);
      PopScope();
      break;
    case CCode:
      VisitCCode(node, ctx);
      break;
    }
}
