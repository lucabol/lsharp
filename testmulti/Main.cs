using Lib;
using Util;

nint Two() {
  return 2;  
}

int main() {
  nint n = Lib.ni;
  nint k = Lib.Ni();

  int i, sum = 0;
  for(i = 0; i < 2; i++) {
    sum += Lib.Ar[i];
  }
  return Lib.Pow(n) - Util.PowDouble(Lib.Ni()) + k - 217 + sum;
}
