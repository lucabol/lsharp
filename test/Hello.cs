using System;

static public class Test
{
  static int[] ai = new int[] {1,2,4};
  static int x = 1, y = 4, z = 2;

  static int Sum(int k, double r) {
    return x + k + (int)r + z + y;
  }

  static string fstringstring(string s) {
    return s;
  }
  static int Main(string[] args) {
    string s = fstringstring("bob");
    return Sum(3, 5);
  }
}

