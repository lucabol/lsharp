#ifndef SYMTABLE_H
#define SYMTABLE_H

#include "config.h"

#define HASH_IMPL
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

inline void PushScope() { ScopeStack[ScopeIndex++] = NextLIndex;}
inline void PopScope()  { ScopeIndex--;}

inline char*
SymGAdd(Span sym, SymType t) {
  assert(SpanValid(sym));

  if(MAXLEN < SymGLength) return "Global symbol table too small to contain all symbols in the program."; // OOM

  uint64_t h = HashString(sym.ptr, (int32_t)sym.len);
  for(int32_t i = (int32_t)h;;) {
    i = HashLookup(h, MAXGLOBALEXP, i);

    Byte* ptr = SymGbl[i];

    if(ptr == 0) {
      SymGbl[i]  = sym.ptr;
      SymGLen[i] = sym.len;
      SymGLength++;
      return 0;
    }

    Span e = SPAN(ptr, SymGLen[i]);

    if(SpanEqual(sym, e)) {
      return "Global redefinition of symbol.";
    }
  }
}

inline int
SymgGFind(Span sym) {
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

char* SymLAdd(Span s, SymType t);
int   SymLFind(Span sym);
char* SymGAdd(Span s, SymType t);
int   SymGFind(Span sym);
#endif