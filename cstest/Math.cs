using stdio;

int ambi = (int)2 + 1;

int d1 = 3, d2 = 3;

int main() {
  double dd1 = 3, dd2 = 5;
  long k = 13, j = 28;
  short f =12;
  byte bb = 10;

  int res = d1 * d2 + d2 * d2 / d2 * 3;
  //printf("%f %f %ld %ld %i %i", dd1, dd2, k, j, f, bb);
  printf("%i\n", res);
  return res; 
}
