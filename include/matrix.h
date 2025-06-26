#ifndef MATRIX_H
#define MATRIX_H

#include <iostream>
#include <vector>

class Matrix
{
private:
  size_t _rows;
  size_t _cols;
  std::vector<double> _elems;

public:
  // Constructors
  Matrix(size_t rows, size_t cols) :
    _rows(rows), _cols(cols), _elems(_rows * _cols, 0.0)
  {}

  Matrix(const std::vector<std::vector<double>> &elems);

  // Accessor methods
  /**
   * @brief Access the element at [i, j]
   */
  const double &get(size_t i, size_t j) const
  {
    return this->_elems[i * this->_cols + j];
  }

  /**
   * @brief Get the number of rows of matrix
   */
  size_t rows() const { return this->_rows; }

  /**
   * @brief Get the number of columns of matrix.
   */
  size_t cols() const { return this->_cols; }

  // Mutator methods
  /**
   * @brief Modify the element at [i, j]
   */
  double &get(size_t i, size_t j) { return this->_elems[i * this->_cols + j]; }

  /**
   * @brief Overload ostream to print matriix
   */
  friend std::ostream &operator<<(std::ostream &out, const Matrix &mat);
};

#endif
