#include <stdio.h>

// Define the maximum value for which factorial can be computed using int data type
#define MAX_FACTORIAL_VALUE 12

int main() {
    int n;

    // Read input from user
    printf("Enter an integer: ");
    scanf("%d", &n);

    if (n < 0) {
        printf("Factorial is not defined for negative numbers.\n");
    } else if (n > MAX_FACTORIAL_VALUE) {
        printf("Factorial for values greater than %d cannot be computed with int data type.\n", MAX_FACTORIAL_VALUE);
    } else {
        int factorial = 1;

        // Calculate factorial using a loop
        for (int i = 1; i <= n; ++i) {
            factorial *= i;
        }

        // Display the factorial
        printf("Factorial of %d is %d\n", n, factorial);
    }

    return 0;
}
