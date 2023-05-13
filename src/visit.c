#include "config.h"
#include "ast.h"

void visit(int node, Buffer* c, Buffer* h) {
  if(NodeKind[node] == Token) {
      char* s = NodeName[node]; 
      int len = NodeLen[node];
      Span sp = SPAN((Byte*)s, len);
      BufferMCopy(' ', c, sp);
  } else {
    int child = NodeFirstChild[node];
    while(true) {
      int n = NodeChildren[child++];
      if(n >= 0) {
        visit(n, c, h);
      } else {
        break;
      }
    }
  }
}
