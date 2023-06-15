using Os;
using Lexer;

void All() {
  FileSlurp();
  LexerT();

  Os.Print("All tests passed!");
}

void FileSlurp() {
  char[] buf[1000000];
  String t = Os.SlurpFile("Test.cs", buf);
  tassert(___len t > 0);
  tassert(t[0] == 'u' && t[1] == 's');
}

void LexerT() {
  int l1 = Lexer.New("int i 34 ,");
  int l2 = Lexer.New("double i 34 ,");

  String s = Lexer.Code[l1];
  tassert(s[0] == 'i');
  tassert(Lexer.NextChar[l1] == 0);

  s = Lexer.Code[l2];
  tassert(s[0] == 'd');
  tassert(Lexer.NextChar[l2] == 0);
}
