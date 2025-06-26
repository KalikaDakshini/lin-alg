#include <iostream>
#include <vector>

#include "matrix.h"

int main()
{
  const std::vector<std::vector<double>> elems1{
    {1, 2},
    {1, 1},
    {2, 3},
  };

  const std::vector<double> elems2{1, 2, 2, 1};

  const Matrix m1 = Matrix(elems1);
  const Matrix m2 = Matrix(2, 2, elems2);
  std::cout << m2 + m2 << '\n';
  std::cout << m1 * m2 << '\n';
  std::cout << m2 * 2 << '\n';

  return EXIT_SUCCESS;
}
