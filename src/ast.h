#ifndef AST_H
#define AST_H

#include "config.h"

extern int    NodeId[];
extern Kind   NodeKind[];
extern char*  NodeName[];
extern int    NodeLen[];
extern int    NodeFirstChild[];
extern int    NodeLine[];
extern int    NodeColumn[];

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

#ifdef AST_IMPL

int   NodeId[MAXNODES];
Kind  NodeKind[MAXNODES];
char* NodeName[MAXNODES];
int   NodeLen[MAXNODES];
int   NodeFirstChild[MAXNODES];
int   NodeLine[MAXNODES];
int   NodeColumn[MAXNODES];

int   NodeChildren[MAXNODES * 10];

int   NextChild;
int   NextId;

int   CreateNTA(Kind kind, int children[]);
int   CreateToken(Kind kind, char* ptr, int len, int line, int column);
Span  ChildValue(int node, int num);
int   Child(int node, int num);
void  die(const char *msg);
#endif
