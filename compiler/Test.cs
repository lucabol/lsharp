using Os;

void All() {
  FileSlurp();

  Os.Print("All tests passed!");
}

void FileSlurp() {
  char[] buf[1000000];
  String t = Os.SlurpFile("Test.cs", buf);
  tassert(___len t < 0);
}
