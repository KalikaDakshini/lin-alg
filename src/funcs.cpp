#include "funcs.h"

Matrix gaussian_elimination(const Matrix &mat)
{
  // Make a copy of matrix to edit
  Matrix result = Matrix(mat);

  size_t r = 0;
  size_t c = 0;
  // Do while there are rows and columns left
  while (r < result.rows() && c < result.cols()) {
    // 1. Find the maximum row value in the column below the pivot position
    // We are swapping with maximum value for numerical stability
    double max_val = result.get(r, c);
    size_t max_idx = r;
    for (size_t i = r; i < result.rows(); i++) {
      if (result.get(i, c) > max_val) {
        max_val = result.get(i, c);
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

    // 4. Make all values in column c, below the pivot, zero by subtraction
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

  // Return the result
  return result;
}

size_t rank(const Matrix &mat)
{
  Matrix eliminated = gaussian_elimination(mat);
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
