using Os;

#include "Config.h"
#include "Struct.h"
#include "Macros.h"

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

char[] _tmpS[1];

int _error(int lexer, String msg) {
  int tokid      = PeekId(lexer);
  String tokname = TokenName(tokid);
  String value   = PeekValue(lexer);

  char[] line[10];
  char[] column[10];
  line   = Os.ItoA(Line[lexer]  , line);
  column = Os.ItoA(Column[lexer], column);

  PrintErr3("ERROR: ", msg, "\n");
  PrintErr5("at: ", line, ", ", column, "\n");
  PrintErr4("Token: ", tokname, " with value", value);

  return -1;
}

// Compiler, please optimize away the if test as msg is a compile time string.
#define RetIfEof(msg) \
  if(chi == -1) { \
    TokId[lexer] = Eof;  \
    if(Os.StringEq(msg,"")) { \
      Value[lexer] = ""; \
      return Eof; \
    } else { \
      _error(lexer,  msg); \
      return -1; \
    } \
  } \
  ch = (char) chi

// One loop to rule them all with annoying special cases ...
#define Until(tok, msg, ...) \
  if(ch == '"') { chi = _next(s, lexer); RetIfEof(msg); } \
  int start = NextChar[lexer] - 1; \
  while(__VA_ARGS__) { \
    chi = _next(s, lexer); \
    RetIfEof(msg); \
  } \
  int end         = NextChar[lexer]; \
  NextChar[lexer] = end - (ch == '"' ? 0 : 1); \
  TokId[lexer]    = tok; \
  Value[lexer]    = s[start .. end - 2]  

int Consume(int lexer) {
  String s  = Code[lexer];
  int chi   = _next(s, lexer);
  char ch   = 0;

  RetIfEof("");

  // Skip whitespace
  while(Os.IsSpace(ch)) {
    chi = _next(s, lexer);
    RetIfEof("");
  }

  // Is it a decimal number?
  if(Os.IsDigit(ch)) {
    Until(TokNumConst,"", Os.IsDigit(ch) || ch == '.');
    return TokNumConst;
  }

  // Is it a string constant?
  if(ch == '\"') {
    Until(TokStringConst, "String not properly closed", ! (ch == '\"'));
    return TokStringConst;
  }

  // Is it an identifier?
  if(Os.IsAlpha(ch) || ch == '_') {
    Until(TokIdentifier, "", Os.IsAlpha(ch) || ch == '_');
    return TokIdentifier;
  }
  
  // Else it is some kind of punctuation
  TokId[lexer] = ch;
  _tmpS[0]     = ch;
  Value[lexer] = _tmpS;
  return ch;
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
