// Library imports
#include <iostream>

// Third party imports
#include "matrix.h"

int main()
{
  const std::vector<Row> elems{
    {1, 2, 3},
    {4, 5, 6},
    {7, 8, 9},
  };
  Matrix m1 = Matrix(elems);
  m1.row(1) = Row{1, 1, 1};

  Matrix m2 = Matrix(3, 1);
  m2.row(0) = Row{1};
  m2.row(1) = Row{2};
  m2.row(2) = Row{1};

  std::cout << m1 << '\n';
  std::cout << m2 << '\n';
  std::cout << m1 * m2 << '\n';

  return 0;
}
