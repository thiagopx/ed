// An m-by-n matrix of floats, dynamically allocated.

#ifndef MATRIX_H
#define MATRIX_H

typedef struct matrix Matrix;

// Returns a new m-by-n matrix with all elements set to 0.
// Cost: O(m * n).
Matrix *matrix_create(int m, int n);

// Frees mat.
void matrix_free(Matrix *mat);

// Returns the element of mat at row i and column j.
float matrix_get(Matrix *mat, int i, int j);

// Sets the element of mat at row i and column j to v.
void matrix_set(Matrix *mat, int i, int j, float v);

// Returns the number of rows of mat.
int matrix_rows(Matrix *mat);

// Returns the number of columns of mat.
int matrix_cols(Matrix *mat);

#endif
