using string.h;
using assert.h;

int main() {
  String stp = "John";

  char[] s = "Robb";
  s[1] = 'a';

  String[] st1[12];
  String[] st2 = { "Rob", "Bob"}; 

  st1[0] = "blah";
  st1[1] = st2[0];
  
  assert.assert(strcmp(___ptr st1[1], ___ptr st2[0]) == 0);


  uint i = 0, sum = 0;
  while(i++ < string.strlen(___ptr s)) {
    sum++;
  }
  return sum - 4;
}
