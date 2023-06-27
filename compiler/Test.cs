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

  tassert(Os.StringEq(Lexer.TokenName(Eof),"End Of File"));

  TLex(l1, TokIdentifier, "int"); TLex(l1, TokIdentifier, "i"); TLex(l1, TokNumConst, "34");
  TLex(l1, ',', ","); TLex(l1, TokStringConst, "bob"); TLex(l1, Eof, ""); TLex(l1, Eof, "");

  int l2 = Lexer.New("");
  TLex(l2, Eof, "");

  Os.Print("THE ERROR BELOW IS EXPECTED - Check line,column and format\n\n");
  int l3 = Lexer.New("\n\n   \"wrong");
  int wr = Lexer.Consume(l3);
  tassert(wr == -1);
}
