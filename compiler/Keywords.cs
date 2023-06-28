// gperf -G7c keywords.gperf to regenerate the perfect hash and tables
using Os;

#define TOTAL_KEYWORDS 39
#define MIN_WORD_LENGTH 2
#define MAX_WORD_LENGTH 9
#define MIN_HASH_VALUE 2
#define MAX_HASH_VALUE 72

char[] asso_values =
  {
    73, 73, 73, 73, 73, 73, 73, 73, 73, 73,
    73, 73, 73, 73, 73, 73, 73, 73, 73, 73,
    73, 73, 73, 73, 73, 73, 73, 73, 73, 73,
    73, 73, 73, 41, 73, 73, 73, 36, 25, 73,
    73, 73, 31, 26, 73, 21, 35, 60, 73, 73,
    73, 73, 73, 73, 73, 73, 73, 73, 73, 73,
    10,  5,  0, 73, 73, 73, 73, 73, 73, 73,
    73, 73, 73, 73, 73, 73, 73, 73, 73, 73,
    73, 73, 73, 25, 73, 73, 73, 73, 73, 73,
    73, 73, 73, 73, 55, 10, 73, 73,  5, 15,
    30,  0,  5,  5, 10, 50, 73,  5, 73, 20,
     0,  5, 73, 73,  5, 15, 10,  0, 73,  0,
    73, 73, 73, 73, 20, 73, 73, 73
  };

int
hash (String str)
{
  int len = ___len str;
  return len + asso_values[(int)str[len - 1]] + asso_values[(int)str[0]];
}

String[] wordlist =
  {
    "", "",
    ">>",
    "new",
    "else",
    "while",
    "",
    ">=",
    ">>=",
    "namespace",
    "using",
    "return",
    "==",
    "for",
    "goto",
    "break",
    "___len",
    "<=",
    "<<=",
    "case",
    "",
    "___ptr",
    "<<",
    "continue",
    "enum",
    "",
    "sizeof",
    "|=",
    "-=",
    "", "",
    "switch",
    "&=",
    "+=",
    "", "",
    "String",
    "do",
    "*=",
    "", "", "",
    "||",
    "%=",
    "", "", "",
    "default",
    "!=",
    "", "", "",
    "&&",
    "", "", "", "",
    "if",
    "", "", "", "",
    "^=",
    "", "", "", "",
    "/=",
    "", "", "", "",
    ".."
  };

bool IsKeyword(String str)
{
  int len = ___len str;
  if (len <= MAX_WORD_LENGTH && len >= MIN_WORD_LENGTH)
    {
      int key = hash(str);

      if (key <= MAX_HASH_VALUE)
        {
          String s = wordlist[key];
          int    l = ___len s;

          if (l <= MAX_WORD_LENGTH && l >= MIN_WORD_LENGTH && str[0] == s[0] && Os.StringEq(str, s)) {
            return true;
          }
        }
    }
  return false;
}

