#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Function to calculate the mean of a vector
double calculate_mean(double *vector, int size)
{
    double sum = 0.0;
    for (int i = 0; i < size; i++)
    {
        sum += vector[i];
    }
    return sum / size;
}

// Function to calculate the variance of a vector
double calculate_variance(double *vector, int size, double mean)
{
    double sum_squared_diff = 0.0;
    for (int i = 0; i < size; i++)
    {
        double diff = vector[i] - mean;
        sum_squared_diff += diff * diff;
    }
    return sum_squared_diff / size;
}

int main()
{
    int size;
    printf("Enter the size of the vector: ");
    scanf("%d", &size);

    // Dynamically allocate memory for the vector
    double *vector = (double *)malloc(size * sizeof(double));
    if (vector == NULL)
    {
        printf("Memory allocation failed.\n");
        return 1;
    }

    // Input the vector elements
    printf("Enter the vector elements:\n");
    for (int i = 0; i < size; i++)
    {
        scanf("%lf", &vector[i]);
    }

    // Calculate mean and variance
    double mean = calculate_mean(vector, size);
    double variance = calculate_variance(vector, size, mean);

    printf("Mean: %.2lf\n", mean);
    printf("Variance: %.2lf\n", variance);

    // Free the dynamically allocated memory
    free(vector);

    return 0;
}
