#include <stdbool.h>
#include <assert.h>

typedef struct {
  int a;
} S;

#define TEqual(T) static inline bool Equal##T(T a, T b) { return a == b;}
TEqual(int)
TEqual(double)

bool EqualS(S a, S b) { return a.a == b.a;}



#define Equal(X,Y) _Generic((X), \
                            int: Equalint, \
                            double: Equaldouble, \
                            S: EqualS) (X,Y)

int main() {
  bool a = Equal(1,2);
  assert(!a);

  S s1, s2; s1.a = 3; s2.a = 3;

  assert(Equal(1,1));
  assert(Equal(s1,s2));
  assert(Equal(2.0,2.0));
}
