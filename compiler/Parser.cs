using Lexer;
using Os;

int Parse(String code) {
  int lexer = Lexer.New(code);
  Lexer.TokenId id = Lexer.Peek(lexer);
  Os.Print(Lexer.TokenName(id));
  return id;
}
