using Lexer;

#include "Config.h"
#include "Struct.h"
#include "Macros.h"

Struct6(MAXTOKENS,
    String, Value,
    String, Spaces,
    int,    TokId,
    int,    Line,
    int,    Column,
    int,    NextToRead
    )

int Peek(int lexer) {
  int next = NextToRead[lexer];

  if(next == Idx) {
    Lexer.Consume(lexer);
    int tok = _New("", "", TokError, 0, 0, 0);

    Value[tok]  = Lexer.Value[lexer];
    Spaces[tok] = Lexer.Spaces[lexer];
    TokId[tok]  = Lexer.TokId[lexer];
    Line[tok]   = Lexer.Line[lexer];
    Column[tok] = Lexer.Column[lexer];
  }
    
  return next;
}

int Consume(int lexer) {
  int next = Peek(lexer);
  NextToRead[lexer] = NextToRead[lexer] + 1;
  return next;
}

int SaveState(int lexer) { return NextToRead[lexer]; }
void RestoreState(int lexer, int state) { NextToRead[lexer] = state; }

int Current(int lexer) { return NextToRead[lexer] - 1;}
