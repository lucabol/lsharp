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
    s2 = "Bob";

  int[] a = {1,2,3},
        k = {1,2,3};

  //int[] c  = a[1 .. 2];
  
  int i, sum = 0;
  for(i = 0; i < 3; i++) {
    sum += a[i] + b[i] + k[i] + d[i];
  }
  
  char[] name = GetName();

  return sum - 24;
}
