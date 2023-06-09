using stdio.h;
using stdlib.h;
using ctype.h;

void Die(String s) {
  PrintErr(s);
  stdlib.exit(stdlib.EXIT_FAILURE);
}

void Print(String s) {
  fwrite(___ptr s, 1, ___len s, stdio.stdout);
}
void PrintErr(String s) {
  fwrite(___ptr s, 1, ___len s, stdio.stderr);
}

String SlurpFile(String path, String buffer) {

    int len = 0;

    // Not zero terminated!!
    `FILE*` f = stdio.fopen(___ptr path, ___ptr "r");
    if (!f) {
      Die("Can't open file");
    }

    len = (int)fread(___ptr buffer, 1, ___len buffer, f);

    if(ferror(f)) {
      Die("Error reading from file");
    }
    if(!feof(f)) {
      Die("File partially read. You may need a bigger buffer");
    }

    fclose(f);

    return buffer[0 .. len];
}

bool StringEq(String a, String b) {
  return !`memcmp(a.ptr, b.ptr, a.len)`;
}

bool IsSpace(char c) { return ctype.isspace(c);}
bool IsDigit(char c) { return ctype.isdigit(c);}
bool IsAlpha(char c) { return ctype.isalpha(c);}

String ItoA(long n, String buf) {
  int len = stdio.snprintf(___ptr buf, ___len buf, `"%ld"`, n);
  if(len > ___len buf) {
    Die("Buffer passed to ItoA too small.");
  }
  `buf.len` = len;
  return buf;
}
