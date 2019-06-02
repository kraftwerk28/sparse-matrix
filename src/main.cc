#include <iostream>
#include "matrix.h"

int main() {
  SparseMatrix s;

  s.push(3, 3, 10);
  s.push(0, 0, -10);
  s.push(3, 4, 15);
  s.push(0, 0, -10);

  RegularMatrix sc = s.convert();
  sc.print();

  return 0;
}
