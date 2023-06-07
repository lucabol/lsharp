//using stdio; // Should fail
using stdio.h;

int a = 0, b = 1;

int main() {
  stdio.printf("%d",a);
  return a + b - a - b;
}
