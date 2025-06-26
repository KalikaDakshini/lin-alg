#include "matrix.h"

Matrix::Matrix(const std::vector<std::vector<double>> &elems) :
  _rows(elems.size()), _cols(elems[0].size()), _elems([&] {
    std::vector<double> flat;
    // Reserver elements to avoid copies
    flat.reserve(_rows * _cols);
    // Copy all elements from vectors into local attribute
    for (const auto &row : elems) {
      for (const auto &elem : row) {
        flat.push_back(elem);
      }
    }
    return flat;
  }())
{}

std::ostream &operator<<(std::ostream &out, const Matrix &mat)
{
  for (size_t i = 0; i < mat.rows(); i++) {
    out << "[";
    for (size_t j = 0; j < mat.cols(); j++) {
      out << mat.get(i, j) << ", ";
    }
    out << "]\n";
  }

  return out;
}
