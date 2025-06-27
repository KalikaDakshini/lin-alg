// Library imports
#include <iostream>

// Third party imports
#include "funcs.h"
#include "matrix.h"

int main()
{
  const std::vector<Row> elems{
    {1,  3,  1},
    {1,  1, -1},
    {3, 11,  5},
    {9,  1, 35},
  };
  const Matrix m1 = Matrix(elems);

  const std::vector<Row> elems2{
    {0, 2, 1, -1},
    {0, 2, 3,  1},
    {0, 1, 2,  4},
  };
  const Matrix m2 = Matrix(elems2);

  std::cout << m1 << '\n';
  std::cout << gaussian_elimination(m1) << '\n';
  std::cout << "Rank: " << rank(m1) << '\n';

  std::cout << m2 << '\n';
  std::cout << gaussian_elimination(m2) << '\n';
  std::cout << "Rank: " << rank(m2) << '\n';

  return 0;
}
