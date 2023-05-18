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
} Env;

typedef enum {
  Generic = 0,
  Token,
  PrimitiveType,
  QualIdentifier,
  WithLine,
  Using,
} Kind;

typedef enum {
  SymUsing,
  SymCUsing,
  SymQuotedUsing,
} SymType;

#include "lcs.tab.h"

#define KB(x) ((x) * 1024)
#define MB(x) (KB(x) * 1024)

// How big of a source file we can read
#define MAXFILESIZE MB(1)

// AST features
#define MAXNODES KB(64)

// Symbol table
#define MAXGLOBALEXP     10
#define MAXGLOBALSYMBOLS (1 << MAXGLOBALEXP)
#define MAXLOCALSYMBOLS  KB(1)
#define MAXSCOPES        50

// Switching C grammar features off
#define POINTERS    "you can't use pointers - use indexed slices instead."
#define REFERENCES  "you can't use references - use indexed slices instead."

#endif
