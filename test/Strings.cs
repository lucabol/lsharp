using string.h;

int main() {
  char s[] = "Robb";
  
  uint i = 0, sum = 0;
  while(i++ < string.strlen(s)) {
    sum++;
  }
  return sum - 4;
}
