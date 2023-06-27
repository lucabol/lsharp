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

#define TLex(lexer,id,value) { \
  int _id = Lexer.Consume(lexer); \
  tassert(_id == id); \
  tassert(Lexer.PeekId(lexer) == id); \
  tassert(Os.StringEq(Lexer.PeekValue(lexer),  value)); \
}

void LexerT() {
  int l1 = Lexer.New("int i 34 , \"bob\"");
  int l2 = Lexer.New("double i 34 ,");

  String s = Lexer.Code[l1];
  tassert(s[0] == 'i');
  tassert(Lexer.NextChar[l1] == 0);

  s = Lexer.Code[l2];
  tassert(s[0] == 'd');
  tassert(Lexer.NextChar[l2] == 0);

  tassert(Os.StringEq(Lexer.TokenName(Eof),"End Of File"));

  Os.Print("Test");
  Os.Print(Lexer.PeekValue(l1));
  TLex(l1, TokIdentifier, "int");
  TLex(l1, TokIdentifier, "i");
  TLex(l1, TokNumConst, "34");
  TLex(l1, ',', ",");
  TLex(l1, TokStringConst, "bob");
  TLex(l1, Eof, "");

}
