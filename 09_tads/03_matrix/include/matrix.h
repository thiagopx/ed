#ifndef MATRIX_H
#define MATRIX_H

// ADT: m-by-n matrix, dynamically allocated

typedef struct matrix Matrix;

// Creates and returns an m-by-n matrix with all elements set to 0
Matrix *matrix_create(int m, int n);

// Frees the memory allocated for the matrix
void matrix_free(Matrix *mat);

// Returns the element at row i and column j
float matrix_get(Matrix *mat, int i, int j);

// Sets the element at row i and column j to v
void matrix_set(Matrix *mat, int i, int j, float v);

// Returns the number of rows
int matrix_rows(Matrix *mat);

// Returns the number of columns
int matrix_cols(Matrix *mat);

#endif
