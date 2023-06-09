/*
 * We are:
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
  SymKind stype = SymGKind[symbol];

  return (stype == SymLocalFunc) && (!SpanEqual(sp, S("main"))) && (!SpanEqual(sp, S("Main")));
}

inline static bool
IsGlobalVar(Span sp) {
  SymKind t = SymKindFind(sp);
  return t == SymGlobalVar || t == SymGlobalSliceVar || t == SymGlobalRefVar;
}

void VisitToken(int node, Context* ctx) {

  Span sp = GetSpan(node);

  char fch = sp.ptr[0];
  char spacing = ispunct(fch) ? 0 : ' '; 

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
Span stypes[] = { S("bool"),S("int8_t"),S("sint8_t"),S("char"),S("double"),S("float"),
  S("int32_t"),S("uint32_t"),S("int_least16_t"),S("uint_least16_t"),S("int64_t"),S("uint64_t"),S("int16_t"),S("uint16_t")};

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

    SymKind t = SymGKind[symbol];
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
  switch(SymGKind[nsNode]) {
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
  } else if(nk == Token) { // Got to be the string type
    ctx->typeName = S("String");
  } else {
    ExtractType(Child(node,1), ctx);
  }
}

// TODO: remove this enum by adding an IsGlobal field to symbol table to make it hortogonal.
typedef enum {IsVar, IsSlice, IsRef} VarKind;

void EmitHeader(Span varName, Context* ctx, VarKind vkind) {
  if(ctx->globalDecl) {
    if(vkind != IsRef) {
      BufferMLCopy(0, ctx->h, S("extern "), ctx->typeName, S(" "),
                   ctx->name_space, varName,
                   vkind == IsSlice ? S("[]") : S(""), S(";"));
    } else {
      BufferMLCopy(0, ctx->h, S("extern "), ctx->typeName, S("Span "),
                   ctx->name_space, varName, S(";"));
    }
  }
}

void AddToST(Span varName, Context* ctx, VarKind vkind) {
  if(ctx->globalDecl) {
    SymGAdd(varName, vkind == IsSlice ? SymGlobalSliceVar :
                     vkind == IsRef   ? SymGlobalRefVar : SymGlobalVar,
            ctx->typeName);
  } else {
    SymLAdd(varName, vkind == IsSlice ? SymLocalSliceVar :
                     vkind == IsRef   ? SymLocalRefVar : SymLocalVar,
            ctx->typeName);
  }
}

void VisitSliceAssign(int node, Context* ctx) {

  Span varName = ChildValue(node, 1);

  AddToST(varName, ctx, IsSlice);
  EmitHeader(varName, ctx, IsSlice);
  
  VisitChildren(node, ctx);
}

void VisitRefDeclAssign(int node, Context* ctx) {
  ExtractType(Child(node, 1), ctx);

  // Reset temporary buffers, should we have a BufferReset function?
  BufferDealloc(ctx->arrays, ctx->arrays->index);
  BufferDealloc(ctx->spans,  ctx->spans->index);

  visit(Child(node, 2), ctx);
  visit(Child(node, 3), ctx);

  if(ctx->arrays->index > 0) {
    BufferMCopy(' ',ctx->c,ctx->typeName);
    Span refDecls = BufferToSpan(ctx->arrays);
    BufferMCopy(0,ctx->c, refDecls, S(";"));
  }
  if(ctx->spans->index > 0) {
    BufferMCopy(0,ctx->c,ctx->typeName, S("Span "));
    Span refDecls = BufferToSpan(ctx->spans);
    BufferMCopy(0,ctx->c, refDecls, S(";"));
  }
}

void VisitRefType(int node, Context* ctx) {
  ExtractType(Child(node, 1), ctx);

  BufferMCopy(0,ctx->c, ctx->typeName, S("Span "));

  if(ctx->toHeader) {
    BufferMCopy(0,ctx->h, ctx->typeName, S("Span "));
  }
}
void VisitRefAssignList(int node, Context* ctx) {

  Span varName = ChildValue(node, 1);

  AddToST(varName, ctx, IsRef);
  EmitHeader(varName, ctx, IsRef);
  
  Span pre = S(" __Buf");

  Buffer* tmp = ctx->c;
  ctx->c = ctx->arrays;
  BufferMCopy(0, ctx->c, pre, varName, S("[] "));
  visit(Child(node, 2), ctx);
  visit(Child(node, 3), ctx);
  visit(Child(node, 4), ctx);
  visit(Child(node, 5), ctx);
  ctx->c = tmp;

  BufferMCopy(0, ctx->spans, ctx->globalDecl ? ctx->name_space : S(""),
              varName, S("="), S("{"), pre, varName, S(",ARSIZE("),pre,varName, S(")}"));
}

void VisitRefAssignConst(int node, Context* ctx) {

  Span varName = ChildValue(node, 1);

  AddToST(varName, ctx, IsRef);
  EmitHeader(varName, ctx, IsRef);
  
  Span pre = S(" __Buf");

  Buffer* tmp = ctx->c;
  ctx->c = ctx->arrays;
  BufferMCopy(0, ctx->c, pre, varName, S("[ "));
  visit(Child(node, 3), ctx);
  BufferSCopy(0, ctx->c," ]");
  ctx->c = tmp;

  BufferMCopy(0, ctx->spans, ctx->globalDecl ? ctx->name_space : S(""),
              varName, S("="), S("{"), pre, varName, S(",ARSIZE("),pre,varName, S(")}"));
}

void VisitRefAssignStr(int node, Context* ctx) {

  Span varName = ChildValue(node, 1);

  AddToST(varName, ctx, IsRef);
  EmitHeader(varName, ctx, IsRef);
  
  Span pre = S(" __Buf");

  Buffer* tmp = ctx->c;
  ctx->c = ctx->arrays;
  BufferMCopy(0, ctx->c, pre, varName, S("[] "));
  visit(Child(node, 2), ctx);
  visit(Child(node, 3), ctx);
  ctx->c = tmp;

  BufferMCopy(0, ctx->spans, ctx->globalDecl ? ctx->name_space : S(""),
              varName, S("="), S("{"), pre, varName, S(",ARSIZE("),pre,varName, S(") - 1}"));
}

void VisitRefOp(int node, Context* ctx) {
  BufferSCopy(0, ctx->c, "(");
  visit(Child(node,2), ctx);
  BufferSCopy(0, ctx->c, ")");
  Span op = ChildValue(node,1);
  if(SpanEqual(op, S("___len"))) {
    BufferSCopy(0, ctx->c, ".len");
  } else if(SpanEqual(op, S("___ptr"))) {
    BufferSCopy(0, ctx->c, ".ptr");
  } else {
    ERR(Child(node,1), "Unknown slice operator.");
  }
}
void VisitString(int node, Context* ctx) {
  if(SpanEqual(ctx->typeName, S("String"))) {
    BufferSCopy(0, ctx->c, "CharSpanFromLit(");
    visit(Child(node,1), ctx);
    BufferSCopy(0, ctx->c, ")");
  } else {
    visit(Child(node,1), ctx);
  }
}

void VisitRefAssignFunc(int node, Context* ctx) {

  Span varName = ChildValue(node, 1);

  AddToST(varName, ctx, IsRef);
  EmitHeader(varName, ctx, IsRef);
  
  Buffer* tmp = ctx->c;
  ctx->c = ctx->spans;
  visit(Child(node, 1), ctx);
  visit(Child(node, 2), ctx);
  visit(Child(node, 3), ctx);
  ctx->c = tmp;
}

void VisitRefAssignId(int node, Context* ctx) {

  Span target = ChildValue(node, 1);

  AddToST(target, ctx, IsRef);
  EmitHeader(target, ctx, IsRef);
  
  Span source  = ChildValue(node, 3);
  SymKind kind = SymKindFind(source);

  Buffer* tmp = ctx->c;
  ctx->c = ctx->spans;
  if(kind == SymGlobalSliceVar || kind == SymLocalSliceVar) {
    BufferMCopy(0, ctx->c, target, S(" = "), ctx->typeName, S("SpanArr("), source, S(", "));
    visit(Child(node, 5), ctx);
    BufferMCopy(0, ctx->c, S(", "));
    visit(Child(node, 7), ctx);
    BufferMCopy(0, ctx->c, S(" )"));
  } else if(kind == SymGlobalRefVar || kind == SymLocalRefVar) {
    BufferMCopy(0, ctx->c, target, S(" = "), ctx->typeName, S("SpanSlice("), source, S(", "));
    visit(Child(node, 5), ctx);
    BufferMCopy(0, ctx->c, S(", "));
    visit(Child(node, 7), ctx);
    BufferMCopy(0, ctx->c, S(" )"));
  } else {
    ERR(node, "Trying to slice a non-sliceable type.");
  }
  ctx->c = tmp;
}

void VisitIndexer(int node, Context* ctx) {

  // The indexing operator when using an imported symbol doesn't know the type (array or slice). It assumes slice.
  // This is clearly awkward. Either I need a global symbol table across all parsed files or remove support for arrays.
  int id = Child(node,1);
  SymKind kind = SymGlobalRefVar;

  if(NodeKind[id] != QualIdentifier) { 
    Span varName = ChildValue(node, 1);
    kind = SymKindFind(varName);
  }

  if(kind == SymGlobalRefVar || kind == SymLocalRefVar) {
    BufferMCopy(0, ctx->c, ctx->typeName, S("SpanGet("));
    visit(Child(node, 1), ctx);
    BufferSCopy(0, ctx->c, ", ");
    visit(Child(node, 3), ctx);
    BufferSCopy(0, ctx->c, ")");

  } else {
    VisitChildren(node, ctx);
  }
}

void VisitIndexerS(int node, Context* ctx) {

  // The indexing operator when using an imported symbol doesn't know the type (array or slice). It assumes slice.
  // This is clearly awkward. Either I need a global symbol table across all parsed files or remove support for arrays.
  int id = Child(node,1);
  SymKind kind = SymGlobalRefVar;

  if(NodeKind[id] != QualIdentifier) { 
    Span varName = ChildValue(node, 1);
    kind = SymKindFind(varName);
  }

  if(kind == SymGlobalRefVar || kind == SymLocalRefVar) {
    BufferMCopy(0, ctx->c, ctx->typeName, S("SpanSet("));
    visit(Child(node, 1), ctx);
    BufferSCopy(0, ctx->c, ", ");
    visit(Child(node, 3), ctx);
    BufferSCopy(0, ctx->c, ", ");
    visit(Child(node, 6), ctx);
    BufferSCopy(0, ctx->c, ")");
  } else {
    VisitChildren(node, ctx);
  }
}
void VisitAssign(int node, Context* ctx) {

  Span varName = ChildValue(node, 1);

  AddToST(varName, ctx, IsVar);
  EmitHeader(varName, ctx, IsVar);
  
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
      // line = NodeLine[node];
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
    case DeclAssign: // Emit extern declarations in header file
      VisitDeclAssign(node, ctx);
      break;
    case Assign: // Assignment after declaration 
      VisitAssign(node, ctx);
      break;
    case SliceAssign: // Assignment after declaration 
      VisitSliceAssign(node, ctx);
      break;
    case RefDeclAssign: // Assignment after declaration 
      VisitRefDeclAssign(node, ctx);
      break;
    case RefAssignList: // Assignment after declaration 
      VisitRefAssignList(node, ctx);
      break;
    case RefAssignConst: // Assignment after declaration 
      VisitRefAssignConst(node, ctx);
      break;
    case RefAssignId: // Assignment after declaration 
      VisitRefAssignId(node, ctx);
      break;
    case RefAssignStr: // Assignment after declaration 
      VisitRefAssignStr(node, ctx);
      break;
    case RefAssignFunc: // Assignment after declaration 
      VisitRefAssignFunc(node, ctx);
      break;
    case RefAssignCommas: // Assignment after declaration 
      visit(Child(node, 1), ctx);
      int afterComma = Child(node,3);
      Kind k = NodeKind[afterComma]; 
      if(k != RefAssignFunc) {
        BufferSCopy(' ', ctx->arrays, ",");
      }
      BufferSCopy(' ', ctx->spans, ",");
      visit(afterComma, ctx);
      break;
    case Indexer: // Maybe array, maybe ref
      VisitIndexer(node, ctx);
      break;
    case IndexerS: // Maybe array, maybe ref
      VisitIndexerS(node, ctx);
      break;
    case RefType: // Maybe array, maybe ref
      VisitRefType(node, ctx);
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
    case RefOp:
      VisitRefOp(node, ctx);
      break;
    case String:
      VisitString(node, ctx);
      break;
    }
}
