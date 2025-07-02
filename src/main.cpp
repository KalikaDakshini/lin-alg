// Library imports
#include <iostream>

// Third party imports
#include "funcs.h"
#include "matrix.h"

int main()
{
  const std::vector<Row> elems{
    { 2,  1, -1,  3,  4, 6},
    { 4,  2,  1,  2, -1, 2},
    {-2,  1,  2,  1,  3, 5},
    { 1,  3,  1,  4,  2, 3},
    { 3, -1,  1, -2,  5, 1},
  };
  const Matrix m1 = Matrix(elems);

  std::cout << m1 << '\n';
  std::cout << rref(m1) << '\n';
  std::cout << "Rank: " << rank(m1) << '\n';

  return 0;
}
