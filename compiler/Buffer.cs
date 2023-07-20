#include "Config.h"
#include "Struct.h"

using Os;

Struct2(MAXBUFFERS,
    String, Data,
    int,    Index)

int New(String buffer) { return _New(buffer,0); }

String ToString(int buffer) {
  String s = Data[buffer];
  return s[0 .. Index[buffer] - 1];
}

String Push(int buffer, String str) {
  String buf  = Data[buffer];
  int idx     = Index[buffer];

  String dest = buf[idx .. (___len buf - idx - 1)];
  Index[buffer] = idx + ___len str;
  return Os.StringCopy(str, dest); 
}
