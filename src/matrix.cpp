#include "matrix.h"

// ========== Matrix Functions ========== //

// Elementary Row Operations
void Matrix::swap(size_t i, size_t j)
{
  std::swap(this->_data[i], this->_data[j]);
}

void Matrix::scale(size_t i, double scale)
{
  this->_data[i] = this->_data[i] * scale;
}

void Matrix::add(size_t i, size_t j, double scale)
{
  this->_data[i] = this->_data[i] + this->_data[j] * scale;
}

// Overload output stream
std::ostream &operator<<(std::ostream &out, const Matrix &mat)
{
  // Print the size
  out << "Size: " << mat._rows << 'x' << mat._cols << '\n';

  // Print the elements
  for (const auto &row : mat) {
    out << row << '\n';
  }
  return out;
}

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

// Overload multiplication
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

// Overload scalar multiplication
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

// ========== Row Functions ========== //
// Overload Row addition
Row operator+(const Row &row1, const Row &row2)
{
  if (row1.size() != row2.size()) {
    throw std::invalid_argument("ERROR::ROWADD::Sizes don't match");
  }

  Row result = Row(row1.size());
  for (size_t i = 0; i < row1.size(); i++) {
    result[i] = row1[i] + row2[i];
  }

  return result;
}

// Overload Row subtraction
Row operator-(const Row &row1, const Row &row2)
{
  if (row1.size() != row2.size()) {
    throw std::invalid_argument("ERROR::ROWADD::Sizes don't match");
  }

  Row result = Row(row1.size());
  for (size_t i = 0; i < row1.size(); i++) {
    result[i] = row1[i] - row2[i];
  }

  return result;
}

// Overload Row scalar multiplication
Row operator*(const Row &row, double val)
{
  Row result = Row(row.size());
  for (size_t i = 0; i < row.size(); i++) {
    result[i] = row[i] * val;
  }

  return result;
}

// Overload Row scalar division
Row operator/(const Row &row, double val)
{
  Row result = Row(row.size());
  for (size_t i = 0; i < row.size(); i++) {
    result[i] = row[i] / val;
  }

  return result;
}

// Overload output stream
std::ostream &operator<<(std::ostream &out, const Row &row)
{
  // Set precision to 2
  out << std::fixed;
  out << std::setprecision(2);
  out << "[";
  for (size_t i = 0; i < row.size(); i++) {
    if (i == row.size() - 1) {
      out << std::setw(6) << row[i];
    }
    else {
      out << std::setw(6) << row[i] << ", ";
    }
  }

  out << "]";

  return out;
}
