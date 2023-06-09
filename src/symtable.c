#ifndef SYMTABLE_H
#define SYMTABLE_H

#include "config.h"
#include "ulib/Hash.h"
#include "ulib/DodStruct.h"

#define LOADFACTOR 60
#define MAXLEN (1 << MAXGLOBALEXP) * LOADFACTOR / 100

extern Byte* SymGbl[];
extern Byte* SymLcl[];
extern Size  SymGLen[];
extern Size  SymLLen[];

extern Byte* SymLType[];
extern Size  SymLTLen[];
extern Byte* SymGType[];
extern Size  SymGTLen[];

extern SymKind SymGKind[];
extern SymKind SymLKind[];
extern int   NextLIndex;

extern int   ScopeStack[MAXSCOPES];
extern int   ScopeIndex;
extern int   SymGLength;

inline void
SymLAdd(Span s, SymKind t, Span typ) {
  assert(SpanValid(s));

  if(NextLIndex > MAXLOCALSYMBOLS) {
    die("Too many local symbols.");
  }
  SymLcl  [NextLIndex] = s.ptr;
  SymLLen [NextLIndex] = s.len;
  SymLKind[NextLIndex] = t;
  SymLType[NextLIndex] = typ.ptr;
  SymLTLen [NextLIndex] = typ.len;

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
SymGAdd(Span sym, SymKind t, Span typ) {
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
      SymGKind[i]= t;
      SymGType[i]= typ.ptr;
      SymGTLen[i]= typ.len;

      SymGLength++;
      return;
    }

    Span e = SPAN(ptr, SymGLen[i]);

    if(SpanEqual(sym, e) && SymGKind[i] == t) {
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

inline SymKind
SymKindFind(Span s) {
  int v;
  if((v = SymLFind(s)) != -1) {
    return SymLKind[v];
  }
  return SymGKind[SymGFind(s)];
}

inline Span
SymTypeFind(Span s) {
  int v;
  if((v = SymLFind(s)) != -1) {
    return SPAN(SymLType[v], SymLTLen[v]);
  }
  return SPAN(SymGType[v], SymGTLen[v]);
}

inline void
SymInit() {
  memset(SymGbl,   0, MAXGLOBALSYMBOLS * sizeof(SymGbl[0]));
  memset(SymGLen,  0, MAXGLOBALSYMBOLS * sizeof(SymGLen[0]));
  memset(SymGKind, 0, MAXGLOBALSYMBOLS * sizeof(SymGKind[0]));
  memset(SymGType, 0, MAXGLOBALSYMBOLS * sizeof(SymGType[0]));
  memset(SymGTLen, 0, MAXGLOBALSYMBOLS * sizeof(SymGTLen[0]));

  SymGLength = 0;
  NextLIndex = 0;
}

#endif

#ifdef SYMTABLE_IMPL

Byte*   SymGbl[MAXGLOBALSYMBOLS];
Size    SymGLen[MAXGLOBALSYMBOLS];
SymKind SymGKind[MAXGLOBALSYMBOLS];
Byte*   SymGType[MAXGLOBALSYMBOLS];
Size    SymGTLen[MAXGLOBALSYMBOLS];

int SymGLength;

Byte*   SymLcl[MAXLOCALSYMBOLS];
Size    SymLLen[MAXLOCALSYMBOLS];
SymKind SymLKind[MAXLOCALSYMBOLS];
Byte*   SymLType[MAXLOCALSYMBOLS];
Size    SymLTLen[MAXLOCALSYMBOLS];

int NextLIndex;

int   ScopeStack[MAXSCOPES];
int   ScopeIndex;

void PushScope();
void PopScope();

void  SymLAdd(Span s, SymKind t, Span typ);
int   SymLFind(Span sym);
void  SymGAdd(Span s, SymKind t, Span typ);
int   SymGFind(Span sym);

void  SymInit();

SymKind  SymKindFind(Span s);
Span SymTypeFind(Span s);

#endif
