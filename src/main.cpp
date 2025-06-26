#include <iostream>
#include <vector>

#include "matrix.h"

int main()
{
  const std::vector<std::vector<double>> elems{
    {1, 0, 0},
    {0, 1, 0},
    {0, 0, 1},
  };
  const Matrix m = Matrix(elems);
  std::cout << m << "\n";
}
