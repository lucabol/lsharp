int main() {
  bool b1 = (3 * 4 + 2 * 3) == ((3 * 4) + (2 * 3)); // * vs +
  int  i  = 0; i += 1; bool b2 = i == 1;           // +=
  bool b3 =
    ((int)3.9 * (int) 4.9 + 4 * 2) == ((((int)3.9) * ((int)4.9)) +(4 * 2)); // Cast
  bool b4 = (5 * -5) == (5 * (-5)); // unary -
  int ib1 = 0, ib2 = 0; bool b5 = (++ ib1 * 2) == ((++ib2) * 2); // preincr vs * 
  bool b6 = (2 == 2 ? 1 + 1 : 3) == ((2 == 2) ? (1 + 1): 3); // ?: vs ==

  return b1 && b2 && b3 && b4 && b5 && b6 ? 0 : 1;
}
