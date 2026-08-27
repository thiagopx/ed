#include <stdio.h>
#include <stdlib.h>

float *transpose(int rows, int cols, float *mat)
{
    // Allocate memory for the transposed matrix
    float *trp = (float *)malloc(cols * rows * sizeof(float));

    // Fill the transposed matrix
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            trp[j * rows + i] = mat[i * cols + j];
        }
    }

    return trp;
}

int main()
{
    int rows, cols;

    printf("Enter the number of rows: ");
    scanf("%d", &rows);

    printf("Enter the number of columns: ");
    scanf("%d", &cols);

    // Dynamically allocate memory for the original matrix
    float *matrix = (float *)malloc(rows * cols * sizeof(float));

    if (matrix == NULL)
    {
        printf("Memory allocation failed.\n");
        return 1;
    }

    // Input the elements of the original matrix
    printf("Enter the elements of the matrix (%d x %d):\n", rows, cols);
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            printf("matrix[%d,%d]=", i, j);
            scanf("%f", &matrix[i * cols + j]);
        }
    }

    // Calculate the transposed matrix
    float *transposed_matrix = transpose(rows, cols, matrix);

    // Print the transposed matrix
    printf("Transposed Matrix:\n");
    for (int i = 0; i < cols; i++)
    {
        for (int j = 0; j < rows; j++)
        {
            printf("%.2f ", transposed_matrix[i * rows + j]);
        }
        printf("\n");
    }

    // Free the dynamically allocated memory
    free(matrix);
    free(transposed_matrix);

    return 0;
}
