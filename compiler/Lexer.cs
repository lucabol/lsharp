#include "Config.h"
#include "Struct.h"

#define Tokens \
  X(TokError        , Error) \
  X(TokIdentifier   , Identifier) \
  X(TokPrimitiveType, Primitive Type) \
  X(TokStringConst  , String Constant) \
  X(TokNumConst     , Numeric Constant) \
  X(Eof             , End Of File) \

#define X(n, k) n,
enum TokenId {
  Tokens
}
#undef X

#define X(n, k) #k,
String[] TokenNames = { Tokens };
#undef X

Struct4(5, String,Code, int,NextChar, String,Value, int,TokId)

int New(String code) { return _New(code, 0, "", 0); }

void Consume(int lexer) {}

TokenId  Peek(int lexer) {

  return TokId[lexer];
}

String TokenName(TokenId id) { return TokenNames[(int)id]; }

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
