#include <stdio.h>

int main()
{
    double num1, num2, result;
    char operator;

    printf("Enter first number: ");
    scanf("%lf", &num1);

    printf("Enter operator (+, -, *, /): ");
    scanf(" %c", &operator); // Notice the space before %c to consume the newline character.

    printf("Enter second number: ");
    scanf("%lf", &num2);

    switch (operator)
    {
    case '+':
        result = num1 + num2;
        break;
    case '-':
        result = num1 - num2;
        break;
    case '*':
        result = num1 * num2;
        break;
    case '/':
        if (num2 != 0)
            result = num1 / num2;
        else
        {
            printf("Error: Division by zero\n");
            return 1; // Exit with an error code
        }
        break;
    default:
        printf("Error: Invalid operator\n");
        return 1; // Exit with an error code
    }

    printf("Result: %lf\n", result);

    return 0; // Exit successfully
}
