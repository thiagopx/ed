#include <stdio.h>
#include <stdlib.h>

// Function to calculate the cross product of two 3D vectors
void calculate_elementwise_sum(double *vector1, double *vector2, double *result, int size)
{
    int sum = 0;

    for (int i = 0; i < size; i++)
        result[i] += vector1[i] + vector2[i];
}

int main()
{
    double *vector1, *vector2, *sum;
    int size = 5;

    // Dynamically allocate memory for the vectors and cross product
    vector1 = (double *)malloc(size * sizeof(double));
    vector2 = (double *)malloc(size * sizeof(double));
    sum = (double *)malloc(size * sizeof(double));

    if (vector1 == NULL || vector2 == NULL || sum == NULL)
    {
        printf("Memory allocation failed.\n");
        return 1;
    }

    printf("Enter the elements of vector1: ");
    for (int i = 0; i < size; i++)
    {
        scanf("%lf", &vector1[i]);
    }

    printf("Enter the elements of vector2: ");
    for (int i = 0; i < size; i++)
    {
        scanf("%lf", &vector2[i]);
    }

    // Calculate the cross product
    calculate_elementwise_sum(vector1, vector2, sum, size);

    for (int i = 0; i < size; i++)
        printf("sum[%d] = %lf\n", i, sum[i]);

    // Free the dynamically allocated memory
    free(vector1);
    free(vector2);
    free(sum);

    return 0;
}
