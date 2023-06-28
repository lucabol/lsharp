using Os;
using Keywords;

#include "Config.h"
#include "Struct.h"
#include "Macros.h"

#define Tokens \
  X(TokError        , Error) \
  X(TokIdentifier   , Identifier) \
  X(TokKeyword      , Identifier) \
  X(TokStringConst  , String Constant) \
  X(TokNumConst     , Numeric Constant) \
  X(Eof             , End Of File) \

#define X(n, k) n,
enum TokenId {
  Barrier = 256, // So that the Lexer can return single char punctuation marks with their ascii values
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

String _lastLine(int lexer) {
  String c = Code[lexer];
  int    i = NextChar[lexer] - 1;
  int    e = i;

  while(i > 0 && c[i] != '\n') { i -= 1;}

  i = c[i] == '\n' ? i + 1 : i;
  return c[i .. e];
}

int Error(int lexer, String msg) {
  int tokid      = PeekId(lexer);
  String tokname = TokenName(tokid);
  String value   = PeekValue(lexer);

  char[] line[10];
  char[] column[10];
  line   = Os.ItoA(Line[lexer]  , line);
  column = Os.ItoA(Column[lexer], column);

  PrintErr3("ERROR: '", msg, "'");
  PrintErr5(" at ", line, ", ", column, " - ");
  PrintErr5("found token: '", tokname, "' with value: '", value, "'\n");
  PrintErr2(_lastLine(lexer), "\n");

  // Slow but just runs when an error occurs ...
  int i;
  for(i = 0; i < Column[lexer]; i++) { PrintErr1(" ");}
  PrintErr1("^\n\n");

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
      Error(lexer,  msg); \
      return -1; \
    } \
  } \
  ch = (char) chi

#define SetEof isEof = chi == -1

#define UntilOrEof(...) \
  if(ch == '"') { chi = _next(s, lexer); } \
  int start = NextChar[lexer] - 1; \
  while(__VA_ARGS__) { \
    chi = _next(s, lexer); \
  } \
  isEof = chi == -1; \
  int end         = NextChar[lexer]; \
  NextChar[lexer] = end - (ch == '"' ? 0 : 1); \
  TokId[lexer]    = tok; \
  Value[lexer]    = s[start .. end - 2]  

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
    String v = Value[lexer];
    return Keywords.IsKeyword(v) ? TokKeyword : TokIdentifier;
  }
  
  // Else it is a punctuation
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
  return TokenNames[(int)id - 257];
}
