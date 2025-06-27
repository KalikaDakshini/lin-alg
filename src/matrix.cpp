#include "matrix.h"

// Overload addition
Matrix operator+(const Matrix &mat1, const Matrix &mat2)
{
  if (mat1.rows() != mat2.rows() || mat1.cols() != mat2.cols()) {
    throw std::invalid_argument("ERROR::ADDITION::Dimensions don't match");
  }

  Matrix result = Matrix(mat1.rows(), mat1.cols());

  for (size_t i = 0; i < mat1.rows(); i++) {
    for (size_t j = 0; j < mat1.cols(); j++) {
      result.get(i, j) = mat1.get(i, j) + mat2.get(i, j);
    }
  }

  return result;
}

// Overload addition
Matrix operator*(const Matrix &mat1, const Matrix &mat2)
{
  if (mat1.cols() != mat2.rows()) {
    throw std::invalid_argument("ERROR::MULT::Dimensions don't match");
  }

  Matrix result = Matrix(mat1.rows(), mat2.cols());

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

// Overload addition
Matrix operator*(const Matrix &mat, double val)
{
  Matrix result = Matrix(mat.rows(), mat.cols());

  for (size_t i = 0; i < mat.rows(); i++) {
    for (size_t j = 0; j < mat.cols(); j++) {
      result.get(i, j) = mat.get(i, j) * val;
    }
  }

  return result;
}
