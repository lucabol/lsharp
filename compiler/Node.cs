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

int _AddChildren(int[] children) {
  int firstChild = ChildIdx;
  int i;
  for(i = 0; i < ___len children; i++) {
    Children[ChildIdx] = children[i];
    ChildIdx += 1;
  }
  Children[ChildIdx] = 0;
  return firstChild;
}

int CreateNode(NodeIdType type, int[] children) {

  int firstChild = _AddChildren(children);
  int node = _New(type, firstChild);
  return node;
}
