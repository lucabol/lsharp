using Lexer;

int Parse(String code) {
  int lexer = Lexer.New(code);
  Lexer.TokenId id = Lexer.Peek(lexer);
  return id;
}
