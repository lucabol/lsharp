int main() {
  bool b1 = (3 * 4 + 2 * 3) == ((3 * 4) + (2 * 3)); // * vs +
  int  i  = 0; i += 1; bool b2 = i == 1;           // +=
  bool b3 =
    ((int)3.9 * (int) 4.9 + 4 * 2) == ((((int)3.9) * ((int)4.9)) +(4 * 2)); // Cast
  
  return b1 && b2 && b3 ? 0 : 1;
}
