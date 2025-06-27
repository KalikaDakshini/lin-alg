#ifndef MATRIX_H
#define MATRIX_H

#include <fstream>
#include <iostream>
#include <vector>

using Row = std::vector<double>;

class Matrix
{
  size_t _rows, _cols;
  std::vector<Row> _data;

public:
  /**
   * @brief Construct a zero matrix of dimension (rows, cols)
   */
  Matrix(size_t rows, size_t cols) :
    _rows(rows), _cols(cols), _data(_rows, Row(_cols, 0))
  {}

  /**
   * @brief Construct a matrix from elements
   */
  Matrix(const std::vector<Row> &elems) :
    _rows(elems.size()), _cols(elems[0].size()), _data(std::move(elems))
  {}

  // Accessor methods
  /**
   * @brief Return the number of rows
   */
  [[nodiscard]] size_t rows() const { return this->_rows; }

  /**
   * @brief Return the number of columns
   */
  [[nodiscard]] size_t cols() const { return this->_cols; }

  /**
   * @brief Return the [i, j] element
   */
  [[nodiscard]] double get(size_t i, size_t j) const { return _data[i][j]; }

  /**
   * @brief Return the contents of the ith row
   */
  [[nodiscard]] const Row &row(size_t i) const { return _data[i]; }

  // Mutator methods
  /**
   * @brief Return a reference to the [i, j] element
   */
  double &get(size_t i, size_t j) { return _data[i][j]; }

  /**
   * @brief Return a reference to the ith row
   */
  Row &row(size_t i) { return _data[i]; }

  // Overload output operator
  friend std::ostream &operator<<(std::ostream &out, const Matrix &mat)
  {
    // Print the size
    out << "Size: " << mat._rows << 'x' << mat._cols << '\n';

    // Print the elements
    for (size_t i = 0; i < mat._rows; i++) {
      for (size_t j = 0; j < mat._cols; ++j) {
        if (j == mat._cols - 1) {
          out << mat._data[i][j];
        }
        else {
          out << mat._data[i][j] << ", ";
        }
      }
      out << "\n";
    }
    return out;
  }
};

// Operator overloads
Matrix operator+(const Matrix &mat1, const Matrix &mat2);
Matrix operator*(const Matrix &mat1, const Matrix &mat2);
Matrix operator*(const Matrix &mat, double val);

#endif
