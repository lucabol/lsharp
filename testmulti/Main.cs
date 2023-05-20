using Lib;
using Util;

nint Two() {
  return 2;  
}

int main() {
  nint n = Lib.ni;
  nint k = Lib.Ni();
  return Lib.Pow(n) - Util.PowDouble(Lib.Ni());
}
