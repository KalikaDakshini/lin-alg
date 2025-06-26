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

Matrix operator+(const Matrix &mat1, const Matrix &mat2)
{
  if (mat1.rows() != mat2.rows() || mat1.cols() != mat2.cols()) {
    throw std::invalid_argument("ERROR::ADDITION::Matrix dimensions mismatch");
  }

  Matrix result = Matrix(mat1.rows(), mat1.cols());
  // Add all elements of matrices
  for (size_t i = 0; i < mat1.rows(); i++) {
    for (size_t j = 0; j < mat1.cols(); j++) {
      result.get(i, j) = mat1.get(i, j) + mat2.get(i, j);
    }
  }

  return result;
}

Matrix operator*(const Matrix &mat, double val)
{
  Matrix result = Matrix(mat.rows(), mat.cols());
  // Add all elements of matrices
  for (size_t i = 0; i < mat.rows(); i++) {
    for (size_t j = 0; j < mat.cols(); j++) {
      result.get(i, j) = mat.get(i, j) * val;
    }
  }

  return result;
}

Matrix operator*(const Matrix &mat1, const Matrix &mat2)
{
  // Check dimensions
  if (mat1.cols() != mat2.rows()) {
    throw std::invalid_argument(
      "ERROR::MULTIPLICATION::Matrix dimensions mismatch"
    );
  }

  Matrix result = Matrix(mat1.rows(), mat2.cols());
  // Perform textbook matrix multiplication
  for (size_t i = 0; i < mat1.rows(); i++) {
    for (size_t j = 0; j < mat2.cols(); j++) {
      double dot_prod = 0.0;
      for (size_t k = 0; k < mat1.cols(); k++) {
        dot_prod += mat1.get(i, k) * mat2.get(k, j);
      }
      result.get(i, j) = dot_prod;
    }
  }

  return result;
}
