#ifndef VISIT_H
#define VISIT_H

#include "ulib/Buffer.h"

typedef struct {
  Buffer* c;
  Buffer* h;
  char* filename;
} Context;

void visit(int node, Context* ctx);

#endif
