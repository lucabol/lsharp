
int main() {
  long n = 1000000000;

  double sum = 0.0;
  double flip = -1.0;
  long i;
  for (i = 1; i <= n; i++) {    
      flip *= -1.0;        
      sum += flip / (double)(2*i - 1);               
  }  
  return (int)sum;
}

#if NET
return main();
#endif
