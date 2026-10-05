#include <stdio.h>
#include "matrix.h"

int main() {
    // Create a 3x4 matrix
    Matrix *mat = matrix_create(3, 4);

    // Fill it: element (i, j) receives the value i * 10 + j
    for (int i = 0; i < matrix_rows(mat); i++) {
        for (int j = 0; j < matrix_cols(mat); j++) {
            matrix_set(mat, i, j, i * 10 + j);
        }
    }

    // Print using only the ADT interface; this code never touches
    // the fields of struct matrix directly.
    printf("Matrix %d x %d:\n", matrix_rows(mat), matrix_cols(mat));
    for (int i = 0; i < matrix_rows(mat); i++) {
        for (int j = 0; j < matrix_cols(mat); j++) {
            printf("%5.1f ", matrix_get(mat, i, j));
        }
        printf("\n");
    }

    matrix_free(mat);

    return 0;
}
