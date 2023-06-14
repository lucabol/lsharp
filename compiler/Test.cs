using Os;

char[] buf[1000000];

int main() {
  String t = Os.SlurpFile("Test.cs", buf);
  tassert(___len t < 0);
}
