#include <stdio.h>
#include <stdlib.h>

// Function to allocate memory for a matrix
int **allocate_matrix(int rows, int cols)
{
    int **matrix = (int **)malloc(rows * sizeof(int *));
    for (int i = 0; i < rows; i++)
    {
        matrix[i] = (int *)malloc(cols * sizeof(int));
    }
    return matrix;
}

// Function to deallocate memory for a matrix
void deallocate_matrix(int **matrix, int rows)
{
    for (int i = 0; i < rows; i++)
    {
        free(matrix[i]);
    }
    free(matrix);
}

// Function to read values for a matrix
void read_matrix_values(int rows, int cols, int **matrix)
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            printf("matrix[%d,%d]=", i, j);
            scanf("%d", &matrix[i][j]);
        }
    }
}

void matrix_sum(int rows, int cols, int **mat1, int **mat2, int **result)
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            result[i][j] = mat1[i][j] + mat2[i][j];
        }
    }
}

int main()
{
    int rows, cols;

    printf("Enter the number of rows: ");
    scanf("%d", &rows);

    printf("Enter the number of columns: ");
    scanf("%d", &cols);

    // Allocate memory for matrices
    int **matrix1 = allocate_matrix(rows, cols);
    int **matrix2 = allocate_matrix(rows, cols);
    int **result = allocate_matrix(rows, cols);

    // Input elements for matrix1
    printf("Enter elements for matrix 1:\n");
    read_matrix_values(rows, cols, matrix1);

    // Input elements for matrix2
    printf("Enter elements for matrix 2:\n");
    read_matrix_values(rows, cols, matrix2);

    // Calculate the sum of matrices
    matrix_sum(rows, cols, matrix1, matrix2, result);

    // Print the result matrix
    printf("Sum of Matrices:\n");
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            printf("%d ", result[i][j]);
        }
        printf("\n");
    }

    // Deallocate memory for matrices
    deallocate_matrix(matrix1, rows);
    deallocate_matrix(matrix2, rows);
    deallocate_matrix(result, rows);

    return 0;
}
