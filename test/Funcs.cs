using stdio.h;
using math.h;

int Square(int x) {
  return (int)math.pow(x, 2);
}

int main() {
  stdio.printf("%i", 2);
  return Square(3) - 9;
}