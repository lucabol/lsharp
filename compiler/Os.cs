using stdio.h;
using stdlib.h;
using ctype.h;
using string.h;

void Die(String s) {
  PrintErr(s);
  stdlib.exit(stdlib.EXIT_FAILURE);
}

void Print(String s) {
  stdio.fwrite(___ptr s, 1, ___len s, stdio.stdout);
  stdio.fflush(stdio.stdout);
}
void PrintLn(String s) {
  stdio.fwrite(___ptr s, 1, ___len s, stdio.stdout);
  stdio.fwrite(___ptr "\n", 1, 1, stdio.stdout);
  stdio.fflush(stdio.stdout);
}
void PrintErr(String s) {
  stdio.fwrite(___ptr s, 1, ___len s, stdio.stderr);
  stdio.fflush(stdio.stderr);
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

bool StringEq(String a, String b) {
  return !`memcmp(a.ptr, b.ptr, a.len)`;
}

// Copy __len src chars to the start of dest, doesn't modify __len dest
// Returns a String(__ptr dest, __len src)
String StringCopy(String src, String dest) {
  int len = ___len src;
  if(len > ___len dest) {
    Die("RUNTIME ERROR: Trying to copy a string to a smaller one.");
  }

  `memcpy(dest.ptr, src.ptr, len);`
  return dest[0 .. (len == 0 ? 0 : len - 1)];
}
