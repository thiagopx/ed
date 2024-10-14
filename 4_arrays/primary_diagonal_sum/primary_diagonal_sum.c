#include <stdio.h>

int primary_diagonal_sum(int matrix[][4], int size)
{
    int sum = 0;
    for (int i = 0; i < size; i++)
    {
        sum += matrix[i][i]; // Add the diagonal element at (i, i)
    }
    return sum;
}

int main()
{
    int matrix[][4] = {
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 10, 11, 12},
        {13, 14, 15, 16}};

    int size = sizeof(matrix) / sizeof(matrix[0]);

    int sum = primary_diagonal_sum(matrix, size);

    printf("Sum of the primary diagonal: %d\n", sum);

    return 0;
}
