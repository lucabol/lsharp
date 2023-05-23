#ifndef CONFIG_H
#define CONFIG_H

#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <stdbool.h>

#include "ulib/Span.h"
#include "ulib/Buffer.h"
#include "ulib/OsStdc.h"
#include "ulib/OptGet.h"


typedef struct {
  char* filename;
  int startNode;
  Buffer* e;
} Env;

#define NODETYPES \
  X(Generic) \
  X(Token) \
  X(PrimitiveType) \
  X(QualIdentifier) \
  X(WithLine) \
  X(Using) \
  X(FuncDef) \
  X(Block) \
  X(GlobalDecl) \
  X(Assign) \
  X(DeclSimple) \
  X(DeclAssign) \
  X(SliceAssign) \
  X(CCode) \
  X(DeclSliceSimple) \

#define X(n) n,
typedef enum {
  NODETYPES
} Kind;
#undef X

#define X(n) if(node == n) return #n;
inline static const char* NodeStr(Kind node) {
  NODETYPES
  return "UNknown node type";
}
#undef X

typedef enum {
  SymNotFound = -1,
  SymUsing,
  SymCUsing,
  SymQuotedUsing,
  SymLocalFunc,
  SymLocalVar,
  SymGlobalVar,
  SymLocalSliceVar,
  SymGlobalSliceVar,
} SymType;

typedef struct {
  Buffer* c;
  Buffer* h;
  Buffer* e;

  char* filename;
  Span name_space;

  bool toHeader;
  bool globalDecl;
  Span typeName;
} Context;

#include "lcs.tab.h"

#define KB(x) ((x) * 1024)
#define MB(x) (KB(x) * 1024)

// How big of a source file we can read
#define MAXFILESIZE MB(1)
// How big the buffer for errors
#define MAXERRORBUF KB(1)

// AST features
#define MAXNODES KB(64)

// Max length of command line to invoke the C compiler
#define MAXCMDLINE KB(1)

// Symbol table
#define MAXGLOBALEXP     10
#define MAXGLOBALSYMBOLS (1 << MAXGLOBALEXP)
#define MAXLOCALSYMBOLS  KB(1)
#define MAXSCOPES        50

// Switching C grammar features off
#define POINTERS    "you can't use pointers - use indexed slices instead."
#define REFERENCES  "you can't use references - use indexed slices instead."

// C compiler options (in gcc terms)
#define COMP   "gcc"
#define OPT_g  "-g3" 
#define OPT_O  "-Ofast -fwhole-program" 
#define OPT_o  "-o" 
#define OPT_c  "-c" 

#define CFLAGS "-Wall -Wextra -Wconversion -Wdouble-promotion" \
     " -Wno-unused-parameter -Wno-unused-function -Wno-sign-conversion" \
     " -fsanitize=undefined -fsanitize-undefined-trap-on-error -Wno-missing-braces -lm"

static inline char*
itoa(long n)
{
    static char buf[15];

    snprintf(buf, sizeof(buf), "%ld", n);
    return   buf;
}

static inline void
PushError(Buffer* e, char* filename, int firstline, int firstcolumn, char* msg) {
  BufferSLCopy(0, e, filename, " error: ", itoa(firstline), ":", itoa(firstline), " ", msg);
}

void die(const char *msg);
#endif
