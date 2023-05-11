#ifndef AST_H
#define AST_H

#include "ulib/Span.h"
#include "config.h"

extern int   SymbolId[];
extern Byte* SymbolName[];
extern Size  SymbolLen[];
extern int   SymbolFirstChild[];

extern int   NextChild;
extern int   NextId;

extern int   SymbolChildren[];

inline void
die(const char *msg) {
  fprintf(stderr, "%s\n", msg);
  abort();
}

inline int
CreateSymbolA(Span name, int children[]) {
  if(NextId >= MAXSYMBOLS - 1)
    die("The program is too big. AST not big enough.");

  int id = NextId++; 
  SymbolName[id]       = name.ptr;
  SymbolLen[id]        = name.len;
  SymbolFirstChild[id] = NextChild;

  for(int i = 0; children[i] >= 0; i++) {
    if(NextChild >= MAXSYMBOLS * 10 - 1)
      die("The program is too big. AST not big enough.");

    SymbolChildren[NextChild++] = children[i];
  }
  SymbolChildren[NextChild++] = -1;

  return id;
}


#endif // Header file

#ifdef AST_IMPL

int   SymbolId[MAXSYMBOLS];
Byte* SymbolName[MAXSYMBOLS];
Size  SymbolLen[MAXSYMBOLS];
int   SymbolFirstChild[MAXSYMBOLS];

int   SymbolChildren[MAXSYMBOLS * 10];

int   NextChild;
int   NextId;

int CreateSymbolA(Span name, int children[]);
void die(const char *msg);
#endif
