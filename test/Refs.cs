using string.h;

int k[*];

int main() {
  char t[*] = "Test";
  int a[*]  = {1,2,3};
  //int d[*]  = a;
  
  int i, sum = 0;
  for(i = 0; i < 3; i++) {
    sum += a[i];
  }
  return sum - 6;
}
