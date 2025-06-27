#include "funcs.h"

Matrix gaussian_elimination(const Matrix &mat)
{
  Matrix result = Matrix(mat);
  // Repeat for every row at the first non-zero element
  for (size_t idx = 0; idx < result.rows() - 1; idx++) {
    // 1. Find the pivot row: Row with a non-zero element in the same column
    size_t pivot_row = idx;
    while (pivot_row < result.rows() && result.get(pivot_row, idx) == 0) {
      pivot_row++;
    }

    // A column of zeroes can be skipped
    if (pivot_row == result.rows()) {
      continue;
    }

    // 2. Swap the current row with pivot row
    std::swap(result.row(idx), result.row(pivot_row));

    // 3. Scale the pivot row by the first element
    const double pivot = result.get(idx, idx);
    result.row(idx) = result.row(idx) / pivot;

    // 4. Eliminate all the elements in the column underneath pivot
    for (size_t i = idx + 1; i < result.rows(); i++) {
      const double scl = result.get(i, idx);
      if (scl == 0) {
        continue;
      }
      result.row(i) = result.row(i) - result.row(idx) * scl;
    }
  }

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
