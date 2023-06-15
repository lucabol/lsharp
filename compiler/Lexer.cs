#include "Config.h"
#include "Struct.h"

#define Tokens \
  X(TokError) \
  X(TokIdentifier) \
  X(TokValueType) \
  X(TokStringConst) \
  X(TokNumConst) \

#define X(n) n,
enum TokenId {
  Tokens
}
#undef X

#define X(n) #n,
String[] TokenNames = { Tokens };
#undef X

Struct4(5, String,Code, int,NextChar, String,Value, int,TokId)

int New(String code) { return _New(code, 0, "", 0); }

void Consume(int lexer) {}
TokenId  Peek(int lexer) {

  TokenId e = TokError;
  return e;
}

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
