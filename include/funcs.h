#ifndef FUNCS_H
#define FUNCS_H

#include "matrix.h"
#include <algorithm>

/**
 * @brief Return an upper traingular matrix reduced using gaussian elimination
 */
Matrix gaussian_elimination(const Matrix &mat);

/**
 * @brief Return the rank of the matrix using Gaussian elimination
 */
size_t rank(const Matrix &mat);

#endif
