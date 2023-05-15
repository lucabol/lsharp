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
  WithLine,
} Kind;

#include "lcs.tab.h"

// How big of a source file we can read
#define MAXFILESIZE 1024 * 1024

// AST features
#define MAXSYMBOLS 1024


// Switching C grammar features off
#define POINTERS  "you can't use pointers - use indexed slices instead."
#define REFERENCES  "you can't use references - use indexed slices instead."

#endif
