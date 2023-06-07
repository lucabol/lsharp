using string.h;

int[] b = {1,2,3},
      d = {1,2,3};

char[] GetName() {
  char[] name = "Beppe";
  return name;
}

int main() {
  char[]
    s1 = "Test",
    s2 = "Bob",
    s3[10];

  int[] a = {1,2,3},
        k = a;

  int[] c  = a[0 .. 2];
  
  int[] r[3]; r[0] = 1; r[1] = 2; r[2] = 3;

  int i, sum = 0;
  for(i = 0; i < 3; i++) {
    sum += a[i] + b[i] + k[i] + d[i] + c[i] + r[i];
  }
  
  char[] name = GetName();

  return sum - 6 * 6;
}
