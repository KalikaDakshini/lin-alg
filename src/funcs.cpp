#include "funcs.h"

Matrix rref(const Matrix &mat)
{
  // Make a copy of matrix to turn matrix into REF
  Matrix result = Matrix(mat);

  size_t r = 0;
  size_t c = 0;
  // Do while there are rows and columns left
  while (r < result.rows() && c < result.cols()) {
    // 1. Find the maximum row value in the column below the pivot position
    // We are swapping with maximum value for numerical stability
    size_t max_idx = r;
    double max_val = result.get(max_idx, c);
    for (size_t i = r; i < result.rows(); i++) {
      const double val = result.get(i, c);
      if (val > max_val) {
        max_val = val;
        max_idx = i;
      }
    }

    // 2. If the max_val is zero, try next column
    if (std::abs(max_val) < 1e-9) {
      c = c + 1;
      continue;
    }

    // 3. Swap the row with the row containing max_val
    result.swap(r, max_idx);

    // 4. Set pivot to 1 and make all values in column c, below the pivot, zero
    // by subtraction
    result.scale(r, 1 / result.get(r, c));
    for (size_t i = r + 1; i < result.rows(); i++) {
      const double scl = result.get(i, c);
      if (std::abs(scl) < 1e-9) {
        continue;
      }

      result.add(i, r, -scl);
    }

    // 5. Go to next row
    r += 1;
    c += 1;
  }

  // Use the REF matrix to generate a unique RREF matrix
  for (size_t i = result.rows() - 1; i > 0; --i) {
    // Find the column with the pivot
    r = i;
    c = 0;
    while (c < result.cols() && std::abs(result.get(r, c)) < 1e-9) {
      c += 1;
    }
    // If there is no pivot, move to next row
    if (c == result.cols()) {
      continue;
    }

    // Make all the elements in the column above the pivot zero
    for (size_t j = r; j > 0; j--) {
      const size_t row_idx = j - 1;
      result.add(row_idx, r, -result.get(row_idx, c));
    }
  }

  // Return the result
  return result;
}

size_t rank(const Matrix &mat)
{
  const Matrix eliminated = rref(mat);
  size_t rank = eliminated.rows();

  for (const auto &row : eliminated) {
    if (std::all_of(row.begin(), row.end(), [](double val) {
          return val == 0.0;
        })) {
      rank -= 1;
    }
  }

  return rank;
}
