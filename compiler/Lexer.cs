#define MAX 1024

String[] Code [MAX];
int[]    Index[MAX];
String[] Token[MAX];

int NextLexer = 0;

int New(String s) {
  Code [NextLexer] = s;
  Index[NextLexer] = 0;

  return NextLexer++;
}


