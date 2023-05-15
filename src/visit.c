#include <ctype.h>
#include <stdlib.h>

#include "config.h"
#include "ast.h"
#include "visit.h"

Span GetSpan(int node) {
  char* s = NodeName[node]; 
  int len = NodeLen[node];
  return SPAN((Byte*)s, len);
}

void PrintNode(int node, Buffer* c, Buffer* h) {
  Span sp = GetSpan(node);
  BufferMCopy(ispunct(sp.ptr[0]) ? 0 : ' ', c, sp);
}

Span ttypes[] = { S("bool"),S("byte"),S("sbyte"),S("char"),S("double"),S("float"),
  S("int"),S("uint"),S("nint"),S("nuint"),S("long"),S("ulong"),S("short"),S("ushort")};
Span stypes[] = { S("bool"),S("int8_t"),S("sbyte"),S("char"),S("double"),S("float"),
  S("int32_t"),S("uint32_t"),S("int"),S("unsigned int"),S("int64_t"),S("uint64_t"),S("int16_t"),S("uint16_t")};

void PrintPrimitiveType(int node, Buffer*c, Buffer* h) {
  Span sp = GetSpan(node);
  for(size_t i = 0; i < sizeof(ttypes) / sizeof(ttypes[0]); i++) {
    if(SpanEqual(ttypes[i], sp)) {
      Span newType = stypes[i];
      BufferMCopy(' ', c, newType);
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
      PrintNode(node, ctx->c, ctx->h);
      break;
    case Generic:
      VisitChildren(node, ctx);
      break;
    case PrimitiveType:
      PrintPrimitiveType(node, ctx->c, ctx->h);
      break;
    case WithLine:
      line = NodeLine[node];
      BufferSLCopy(' ', ctx->c, "\n", "#line ", itoa(line), "\"", ctx->filename, "\"");
      VisitChildren(node, ctx);
      break;
    }
}
