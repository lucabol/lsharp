#ifndef AST_H
#define AST_H

#include "config.h"

extern int    NodeId[];
extern Kind   NodeKind[];
extern char*  NodeName[];
extern int    NodeLen[];
extern int    NodeFirstChild[];

extern int   NextChild;
extern int   NextId;

extern int   NodeChildren[];

inline void
die(const char *msg) {
  fprintf(stderr, "%s\n", msg);
  abort();
}

inline int
CreateNTA(Kind kind, int children[]) {
  if(NextId >= MAXSYMBOLS - 1)
    die("Error creating NT node. The program is too big. AST not big enough.");

  int id = NextId++; 
  NodeKind[id]       = kind;
  NodeName[id]       = 0;
  NodeLen[id]        = -1;
  NodeFirstChild[id] = NextChild;

  for(int i = 0; children[i] >= 0; i++) {
    if(NextChild >= MAXSYMBOLS * 10 - 1)
      die("Error creating NT child node. The program is too big. AST not big enough.");

    NodeChildren[NextChild++] = children[i];
  }
  NodeChildren[NextChild++] = -1;

  return id;
}

#define CreateNt(kind, ...) CreateNTA(kind, (int[]) {__VA_ARGS__, -1})

inline int
CreateToken(char* ptr, int len) {
  if(NextId >= MAXSYMBOLS - 1)
    die("Error creating Token node. The program is too big. AST not big enough.");

  int id = NextId++; 
  NodeKind[id]       = Token;
  NodeName[id]       = ptr;
  NodeLen[id]        = len;
  NodeFirstChild[id] = -1;

  return id;
}
#endif // Header file

#ifdef AST_IMPL

int   NodeId[MAXSYMBOLS];
Kind  NodeKind[MAXSYMBOLS];
char* NodeName[MAXSYMBOLS];
int   NodeLen[MAXSYMBOLS];
int   NodeFirstChild[MAXSYMBOLS];

int   NodeChildren[MAXSYMBOLS * 10];

int   NextChild;
int   NextId;

int   CreateNTA(Kind kind, int children[]);
int   CreateToken(char* ptr, int len);
void  die(const char *msg);
#endif
