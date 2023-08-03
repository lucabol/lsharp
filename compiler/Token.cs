using Lexer;

#include "Config.h"
#include "Struct.h"
#include "Macros.h"

Struct5(MAXTOKENS,
    String, Value,
    String, Spaces,
    int,    TokId,
    int,    Line,
    int,    Column
    )

int Next(int lexer) {
  Lexer.Consume(lexer);
  int tok = _New("", "", TokError, 0, 0);

  Value[tok]  = Lexer.Value[lexer];
  Spaces[tok] = Lexer.Spaces[lexer];
  TokId[tok]  = Lexer.TokId[lexer];
  Line[tok]   = Lexer.Line[lexer];
  Column[tok] = Lexer.Column[lexer];

  return tok;
}
