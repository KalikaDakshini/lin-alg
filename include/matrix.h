#ifndef MATRIX_H
#define MATRIX_H

#include <algorithm>
#include <fstream>
#include <iomanip>
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

  // Elementary Row Operations
  /**
   * @brief Swap Row i and Row j
   */
  void swap(size_t i, size_t j);

  /**
   * @brief Multiply Row i by a factor of scl
   */
  void scale(size_t i, double scale);

  /**
   * @brief Add and modify rows as Ri = Ri + scale * Rj
   */
  void add(size_t i, size_t j, double scale);

  // Iterator
  auto begin() { return this->_data.begin(); }

  auto end() { return this->_data.end(); }

  auto begin() const { return this->_data.begin(); }

  auto end() const { return this->_data.end(); }

  // Overload output operator
  friend std::ostream &operator<<(std::ostream &out, const Matrix &mat);
};

// Operator overloads for Matrix
Matrix operator+(const Matrix &mat1, const Matrix &mat2);
Matrix operator*(const Matrix &mat1, const Matrix &mat2);
Matrix operator*(const Matrix &mat, double val);

// Operator overloads for Row
Row operator+(const Row &row1, const Row &row2);
Row operator-(const Row &row1, const Row &row2);
Row operator*(const Row &row, double val);
Row operator/(const Row &row, double val);
std::ostream &operator<<(std::ostream &out, const Row &r);

#endif
