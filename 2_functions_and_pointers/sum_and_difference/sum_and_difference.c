#include <stdio.h>

// Function to calculate sum and difference of two double values
void calculate_sum_and_difference(
    double a, double b, double *sum, double *difference)
{
    *sum = a + b;
    *difference = a - b;
}

int main()
{
    double num1, num2, sum, difference;

    printf("Enter the first number: ");
    scanf("%lf", &num1);

    printf("Enter the second number: ");
    scanf("%lf", &num2);

    calculate_sum_and_difference(num1, num2, &sum, &difference);

    printf("Sum: %.2lf\n", sum);
    printf("Difference: %.2lf\n", difference);

    return 0;
}
