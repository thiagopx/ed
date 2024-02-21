#include <stdio.h>

int main()
{
    float fahrenheit, celsius;

    // Input temperature in Fahrenheit
    printf("Enter temperature in Fahrenheit: ");
    scanf("%f", &fahrenheit);

    // Convert Fahrenheit to Celsius
    celsius = (fahrenheit - 32) * 5 / 9;

    // Output temperature in Celsius
    printf("Temperature in Celsius: %.2f\n", celsius);

    // Check if temperature is below freezing
    if (celsius < 0)
    {
        printf("It's freezing outside!\n");
    }
    else
    {
        printf("It's not freezing outside.\n");
    }

    return 0;
}
