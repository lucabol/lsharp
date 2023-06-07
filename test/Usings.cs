//using stdio; // Should fail
using stdio.h;

int a = 0, b = 1;

#define TEST int x = 1; \
                      int y = 2

TEST;

int main() {
  stdio.printf("%d",a);
  return a + b - a - b;
}
