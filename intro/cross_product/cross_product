#include <stdio.h>
#include <stdlib.h>

// Function to calculate the cross product of two 3D vectors
void calculate_cross_product(double *vector1, double *vector2, double *result)
{
    result[0] = vector1[1] * vector2[2] - vector1[2] * vector2[1];
    result[1] = vector1[2] * vector2[0] - vector1[0] * vector2[2];
    result[2] = vector1[0] * vector2[1] - vector1[1] * vector2[0];
}

int main()
{
    double *vector1, *vector2, *cross_product;
    int size = 3;

    // Dynamically allocate memory for the vectors and cross product
    vector1 = (double *)malloc(size * sizeof(double));
    vector2 = (double *)malloc(size * sizeof(double));
    cross_product = (double *)malloc(size * sizeof(double));

    if (vector1 == NULL || vector2 == NULL || cross_product == NULL)
    {
        printf("Memory allocation failed.\n");
        return 1;
    }

    printf("Enter the components of vector1 (x y z): ");
    for (int i = 0; i < size; i++)
    {
        scanf("%lf", &vector1[i]);
    }

    printf("Enter the components of vector2 (x y z): ");
    for (int i = 0; i < size; i++)
    {
        scanf("%lf", &vector2[i]);
    }

    // Calculate the cross product
    calculate_cross_product(vector1, vector2, cross_product);

    printf("Cross Product: %.2lf %.2lf %.2lf\n", cross_product[0], cross_product[1], cross_product[2]);

    // Free the dynamically allocated memory
    free(vector1);
    free(vector2);
    free(cross_product);

    return 0;
}
