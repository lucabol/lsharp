
int main() {
  long rounds = 1000000000;

  double pi = 1;
  double x  = 1;
  long i     = 0;

  for (i = 2; i < rounds + 2; i++) {
      x  *= -1;
      pi += (x / (2 * (double)i - 1));
  }

  pi *= 4;
  return (int)pi;
}

#if NET
return main();
#endif
