using Os;
using Lexer;
using Token;

#include "Config.h"
#include "Struct.h"
#include "Macros.h"

int Parse(String code) {
  int lexer = Lexer.New(code);
  int tok   = Token.Next(lexer);

  Os.Print(Lexer.TokenName(Token.TokId[tok]));
  return 0;
}
