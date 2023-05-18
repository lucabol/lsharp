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

inline char*
SymLAdd(Span s, SymType t) {
  if(NextLIndex > MAXLOCALSYMBOLS) {
    return "Too many local symbols.";
  }
  SymLcl  [NextLIndex] = s.ptr;
  SymLLen [NextLIndex] = s.len;
  SymLType[NextLIndex] = t;
  NextLIndex++;
  return NULL;
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
      SymGType[i] = t;
      SymGLength++;
      return 0;
    }

    Span e = SPAN(ptr, SymGLen[i]);

    if(SpanEqual(sym, e) && SymGType[i] == t) {
      return "Global redefinition of symbol.";
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
