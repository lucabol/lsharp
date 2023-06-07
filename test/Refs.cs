using string.h;

int[] b = {1,2,3},
      d = {1,2,3};

char[] GetName() {
  char[] name = "Rob"; // 3 chars
  return name;
}

int main() {
  char[]
    s1 = "Test", // 4 chars
    s2 = "Bob", // 3 chars
    s3[10]; // 10 chars

  int[] a = {1,2,3},
        k = a;

  int[] c  = a[0 .. 2];
  
  int[] r[3]; r[0] = 1; r[1] = 2; r[2] = 3;

  int i, sum = 0;
  for(i = 0; i < ___len a; i++) {
    sum += a[i] + b[i] + k[i] + d[i] + c[i] + r[i];
  }
  
  char[] name = GetName();

  return sum + ___len s1 + ___len s2 + ___len s3 + ___len name - 6 * 6 -
              ( 4 + 3 + 10 + 3);
}
