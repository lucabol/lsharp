using Os;
using Lexer;
using Token;

#include "Config.h"
#include "Struct.h"
#include "Macros.h"

enum NodeIdType {
  Generic
}

Struct2(MAXNODES,
    int, NodeType,
    int, FirstChild
)

int[] Children[MAXCHILDREN];
int   ChildIdx = 0;

int AddChild(int child) {
  if(ChildIdx >= MAXCHILDREN) {
    Die("Too many nodes. Increase MAXCHILDREN.");
  }
  int v = ChildIdx;
  ChildIdx += 1;
  return v;
}

int CreateNode(NodeIdType type, int childId) {

  int child = AddChild(childId);
  int node = _New(type, child);
  return node;
}
