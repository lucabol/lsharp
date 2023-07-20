using Os;
using Lexer;
using Keywords;
using Buffer;

void All() {
  KeywordsT();
  FileSlurp();
  LexerT();
  Strings();
  Buffers();

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
  int l1 = Lexer.New("int i 34 , \"bob\" while");

  tassert(Os.StringEq(Lexer.TokenName(Eof),"End Of File"));

  TLex(l1, TokIdentifier, "int"); TLex(l1, TokIdentifier, "i"); TLex(l1, TokNumConst, "34");
  TLex(l1, ',', ","); TLex(l1, TokStringConst, "bob");
  TLex(l1, TokKeyword, "while"); TLex(l1, Eof, ""); TLex(l1, Eof, "");

  int l2 = Lexer.New("");
  TLex(l2, Eof, "");

  Os.Print("THE ERROR BELOW IS EXPECTED - Check line,column and format\n\n");
  int l3 = Lexer.New("\n\n   \"wrong");
  int wr = Lexer.Consume(l3);
  tassert(wr == -1);
  
  int l4 = Lexer.New("\"\" \"bo\nb\" \"\"");
  TLex(l4,TokStringConst,"");TLex(l4,TokStringConst,"bo\nb");TLex(l4,TokStringConst,"");

  String s = "int i  34 ,  \"bob\" while";
  int ll = Lexer.New(s);

  char[] buf[100];
  int b = Buffer.New(buf);

  while(Lexer.Consume(ll) != Eof) {
    String ts  = Lexer.PeekSpaces(ll);
    String str = Lexer.PeekId(ll) == TokStringConst ? "\"" : ""; 

    Buffer.Push(b, ts);
    ts = Lexer.PeekValue(ll);

    Buffer.Push(b, str);
    Buffer.Push(b, ts);
    Buffer.Push(b, str);
  }
  String ts  = Lexer.PeekSpaces(ll);
  Buffer.Push(b, ts);

  String ss = Buffer.ToString(b);
  tassert(Os.StringEq(ss,s));
}

void KeywordsT() {
  tassert(Keywords.IsKeyword("if"));
  tassert(Keywords.IsKeyword(">>"));
  tassert(Keywords.IsKeyword("while"));

  tassert(!Keywords.IsKeyword("xx"));
}

void Strings() {
  String s = "abc";
  char[] d[10]; Os.StringCopy("kadef", d);
  String c = Os.StringCopy(s, d);

  tassert(Os.StringEq(s,c));
  tassert(Os.StringEq(d[3 .. 4],"ef"));
}

void Buffers() {
  char[] backS[100];
  int b = Buffer.New(backS);

  String s = Buffer.Push(b, "Hello");
  tassert(Os.StringEq(s, "Hello"));

  s = Buffer.Push(b, " world");
  tassert(Os.StringEq(s, " world"));
  tassert(Os.StringEq(Buffer.ToString(b), "Hello world"));


  s = Buffer.Push(b, "");
  tassert(Os.StringEq(s, ""));
  tassert(Os.StringEq(Buffer.ToString(b), "Hello world"));
}
