using Lib;
using Main;

double d = 2.0;

int PowDouble(int i) {
  return Lib.Pow(i) * (int)d - Main.Two();
}
