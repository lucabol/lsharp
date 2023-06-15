#include "Config.h"
#include "Struct.h"

Struct4(5, String,Code, int,NextChar, String,Value, int,TokId)

int New(String code) { return _New(code, 0, "", 0); }

/*
String[] Code [MAXLEXERS];
int[]    Index[MAXLEXERS];
String[] Token[MAXLEXERS];
int Idx = 0;

int New(String s, Index i, String tok) {
  if(Idx >= MAXLEXERS) { Die("You are using too many lexers."); }

  Code [Idx] = s;
  Index[Idx] = i;
  Token[Idx] = tok;

  return Idx++;
}

*/
