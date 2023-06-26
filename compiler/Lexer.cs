using ctype.h;

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

Struct6(5,
    String, Code,
    int,    NextChar,
    String, Value,
    int,    TokId,
    int,    Line,
    int,    Column
    )

int New(String code) { return _New(code, 0, "", 0, 1, 0); }

int _next(String s, int lexer) {
  int idx         = NextChar[lexer];
  if(idx >= ___len s) {
    return -1;
  }

  NextChar[lexer] = idx + 1;
  char ch         = s[idx];

  // keep line and column up to date
  if(ch == '\n') {
    Line[lexer] = Line[lexer] + 1;
    Column[lexer] = 0;
  } else {
    Column[lexer] = Column[lexer] + 1;
  }
  return s[idx];
}

String _tmpS = "x";

#define RetIfEof \
  if(chi == -1) { \
    TokId[lexer] = Eof;  \
    return; \
  } \
  ch = (char) chi

#define Until(tok, ...) \
  int start = NextChar[lexer] - 1; \
  while(__VA_ARGS__) { \
    chi = _next(s, lexer); \
    RetIfEof; \
  } \
  int end         = NextChar[lexer]; \
  NextChar[lexer] = end - 1; \
  TokId[lexer] = tok; \
  Value[lexer] = s[start .. end - 1] 

void Consume(int lexer) {
  String s  = Code[lexer];
  int chi   = _next(s, lexer);
  char ch   = 0;

  RetIfEof;

  // Skip whitespace
  while(isspace(ch)) {
    chi = _next(s, lexer);
    RetIfEof;
  }

  // Is it a decimal number?
  if(isdigit(ch)) {
    Until(TokNumConst, isdigit(ch) || ch == '.');
    return;
  }

  // Is it a string constant?
  if(ch == '\"') {
    Until(TokStringConst, ! (ch == '\"'));
    return;
  }

  // Is it an identifier?
  if(isalpha(ch) || ch == '_') {
    Until(TokIdentifier, isalpha(ch) || ch == '_');
    return;
  }
  
  // Else it is some kind of punctuation
  TokId[lexer] = ch;
  _tmpS[0]     = ch;
  Value[lexer] = _tmpS;
}

TokenId PeekId(int lexer) {

  return TokId[lexer];
}

String PeekValue(int lexer) {
  return Value[lexer];
}

String TokenName(TokenId id) {
  return TokenNames[(int)id];
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
