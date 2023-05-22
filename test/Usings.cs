using stdio;
//using stdio; // Should fail
using stdio.h;
//using stdio.h; // Should fail
//using "math.h"; // This Works!!! But disabled to keep C# illusion going.

int a = 0, b = 1;

int main() {
  return a + b - a - b;
}
