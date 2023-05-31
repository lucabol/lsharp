#ifndef AST_H
#define AST_H

#include "config.h"

#ifdef AST_IMPL
#define EXTERN

int   CreateNTA(Kind kind, int children[]);
int   CreateToken(Kind kind, char* ptr, int len, int line, int column);
Span  ChildValue(int node, int num);
int   Child(int node, int num);
void AstInit();

#else
#define EXTERN extern
#endif

EXTERN int    NodeId[MAXNODES];
EXTERN Kind   NodeKind[MAXNODES];
EXTERN char*  NodeName[MAXNODES];
EXTERN int    NodeLen[MAXNODES];
EXTERN int    NodeFirstChild[MAXNODES];
EXTERN int    NodeLine[MAXNODES];
EXTERN int    NodeColumn[MAXNODES];

EXTERN int   NextChild;
EXTERN int   NextId;

EXTERN int   NodeChildren[MAXNODES];

inline void
AstInit() {
  NextChild = 0;
  NextId    = 0;
}

inline int
CreateNTA(Kind kind, int children[]) {
  if(NextId >= MAXNODES - 1)
    die("Error creating NT node. The program is too big. AST not big enough.");

  int id = NextId++; 
  NodeKind[id]       = kind;
  NodeName[id]       = 0;
  NodeLen[id]        = -1;
  NodeFirstChild[id] = NextChild;
  NodeLine[id]       = NodeLine[children[0]];
  NodeColumn[id]     = NodeColumn[children[0]];

  for(int i = 0; children[i] >= 0; i++) {
    if(NextChild >= MAXNODES * 10 - 1)
      die("Error creating NT child node. The program is too big. AST not big enough.");

    NodeChildren[NextChild++] = children[i];
  }
  NodeChildren[NextChild++] = -1;

  return id;
}

#define CreateNt(kind, ...) CreateNTA(kind, (int[]) {__VA_ARGS__, -1})

inline int
CreateToken(Kind kind, char* ptr, int len, int line, int column) {
  if(NextId >= MAXNODES - 1)
    die("Error creating Token node. The program is too big. AST not big enough.");

  int id = NextId++; 
  NodeKind[id]       = kind;
  NodeName[id]       = ptr;
  NodeLen[id]        = len;
  NodeFirstChild[id] = -1;
  NodeLine[id]       = line;
  NodeColumn[id]     = column;

  return id;
}

inline int
Child(int node, int num) {
  int firstChild = NodeFirstChild[node];
  return NodeChildren[firstChild + num - 1];
}
// Children nodes start from 1 for consistency with Bison rules
inline Span
ChildValue(int node, int num) {
  int child = Child(node,num);
  return SPAN((Byte*)NodeName[child], NodeLen[child]);
}

#endif // Header file
