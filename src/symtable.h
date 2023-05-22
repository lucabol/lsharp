#ifndef SYMTABLE_H
#define SYMTABLE_H

#include "config.h"
#include "ulib/Hash.h"

#define LOADFACTOR 60
#define MAXLEN (1 << MAXGLOBALEXP) * LOADFACTOR / 100

extern Byte* SymGbl[];
extern Byte* SymLcl[];
extern Size  SymGLen[];
extern Size  SymLLen[];

extern SymType SymGType[];
extern SymType SymLType[];
extern int   NextLIndex;

extern int   ScopeStack[MAXSCOPES];
extern int   ScopeIndex;
extern int   SymGLength;

inline void
SymLAdd(Span s, SymType t) {
  if(NextLIndex > MAXLOCALSYMBOLS) {
    die("Too many local symbols.");
  }
  SymLcl  [NextLIndex] = s.ptr;
  SymLLen [NextLIndex] = s.len;
  SymLType[NextLIndex] = t;
  NextLIndex++;
}

inline int
SymLFind(Span sym) {
  for(int i = NextLIndex - 1; i >= 0; i--) {
    Span s = SPAN(SymLcl[i], SymLLen[i]);
    if(SpanEqual(sym, s)) return i;
  }
  return -1;
}

inline void PushScope() {
  ScopeStack[ScopeIndex++] = NextLIndex;
}
inline void PopScope()  {
  NextLIndex = ScopeStack[--ScopeIndex];
}

inline void
SymGAdd(Span sym, SymType t) {
  assert(SpanValid(sym));

  if(MAXLEN < SymGLength)
    die("Global symbol table too small to contain all symbols in the program."); // OOM

  uint64_t h = HashString(sym.ptr, (int32_t)sym.len);
  for(int32_t i = (int32_t)h;;) {
    i = HashLookup(h, MAXGLOBALEXP, i);

    Byte* ptr = SymGbl[i];

    if(ptr == 0) {
      SymGbl[i]  = sym.ptr;
      SymGLen[i] = sym.len;
      SymGType[i] = t;
      SymGLength++;
      return;
    }

    Span e = SPAN(ptr, SymGLen[i]);

    if(SpanEqual(sym, e) && SymGType[i] == t) {
      die("Global redefinition of symbol.");
    }
  }
}

inline int
SymGFind(Span sym) {
  assert(SpanValid(sym));

  uint64_t h = HashString(sym.ptr, (int32_t)sym.len);
  for(int32_t i = (int32_t)h;;) {
    i = HashLookup(h, MAXGLOBALEXP, i);

    Byte* ptr = SymGbl[i];
    if(ptr == 0) return -1;

    Span e = SPAN(ptr, SymGLen[i]);

    if(SpanEqual(sym, e)) {
      return i;
    }
  }
}

inline SymType
SymTypeFind(Span s) {
  int v;
  if((v = SymLFind(s)) != -1) {
    return SymLType[v];
  }
  return SymGType[SymGFind(s)];
}

inline void
SymInit() {
  memset(SymGbl,   0, MAXGLOBALSYMBOLS * sizeof(SymGbl[0]));
  memset(SymGLen,  0, MAXGLOBALSYMBOLS * sizeof(SymGLen[0]));
  memset(SymGType, 0, MAXGLOBALSYMBOLS * sizeof(SymGType[0]));
  SymGLength = 0;

  NextLIndex = 0;
}

#endif

#ifdef SYMTABLE_IMPL

Byte* SymGbl[MAXGLOBALSYMBOLS];
Size  SymGLen[MAXGLOBALSYMBOLS];
SymType SymGType[MAXGLOBALSYMBOLS];
int SymGLength;

Byte* SymLcl[MAXLOCALSYMBOLS];
Size  SymLLen[MAXLOCALSYMBOLS];
SymType SymLType[MAXLOCALSYMBOLS];
int   NextLIndex;

int   ScopeStack[MAXSCOPES];
int   ScopeIndex;

void PushScope();
void PopScope();

void  SymLAdd(Span s, SymType t);
int   SymLFind(Span sym);
void  SymGAdd(Span s, SymType t);
int   SymGFind(Span sym);

void  SymInit();

SymType  SymTypeFind(Span s);

#endif
