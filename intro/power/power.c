#include <stdio.h>

float calculate_power(float base, int exponent)
{
    float result = 1.0f;

    if (exponent >= 0)
        for (int i = 0; i < exponent; ++i)
            result *= base;
    else
        for (int i = 0; i < -exponent; ++i)
            result /= base;

    return result;
}

int main()
{
    float base, result;
    int exponent;

    printf("Enter the base: ");
    scanf("%f", &base);

    printf("Enter the exponent: ");
    scanf("%d", &exponent);

    result = calculate_power(base, exponent);

    printf("Result: %f\n", result);

    return 0; // Exit successfully
}
