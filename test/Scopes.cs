int a = 1;
int Sum = 0;

int main() {
  int a = Scopesa + 2;
  a += 1;
  {
    int a = 3;
    a += 1;
    {
      int a = 4;
      a += 1;
      Sum += a;
    }
    a += 1;
    Sum += a;
  }
  a += 1;
  Sum += a;
  return Sum - 15;
}
