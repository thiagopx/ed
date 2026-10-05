#include "matrix.h"
#include <stdio.h>
#include <stdlib.h>

// Implementation with a flat array: all elements live in one contiguous
// block, and element (i, j) is stored at data[i * cols + j].
// This is an internal detail of the module; clients never need to know it.
struct matrix {
    int rows;
    int cols;
    float *data;
};

Matrix *matrix_create(int m, int n) {
    Matrix *mat = (Matrix *)malloc(sizeof(Matrix));
    if (mat == NULL) {
        perror("Failed to allocate memory for Matrix");
        exit(EXIT_FAILURE);
    }

    mat->rows = m;
    mat->cols = n;
    mat->data = (float *)calloc(m * n, sizeof(float));
    if (mat->data == NULL) {
        perror("Failed to allocate memory for Matrix elements");
        exit(EXIT_FAILURE);
    }

    return mat;
}

void matrix_free(Matrix *mat) {
    free(mat->data);
    free(mat);
}

float matrix_get(Matrix *mat, int i, int j) {
    return mat->data[i * mat->cols + j];
}

void matrix_set(Matrix *mat, int i, int j, float v) {
    mat->data[i * mat->cols + j] = v;
}

int matrix_rows(Matrix *mat) {
    return mat->rows;
}

int matrix_cols(Matrix *mat) {
    return mat->cols;
}
