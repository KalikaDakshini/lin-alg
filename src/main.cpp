// Library imports
#include <iostream>

// Third party imports
#include "funcs.h"
#include "matrix.h"

int main()
{
  const std::vector<Row> elems{
    {1,  2,  2, 2},
    {2,  4, 6, 8},
    {3, 6, 8, 10},
  };
  const Matrix m1 = Matrix(elems);

  std::cout << m1 << '\n';
  std::cout << gaussian_elimination(m1) << '\n';
  std::cout << "Rank: " << rank(m1) << '\n';

  return 0;
}
