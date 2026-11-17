#include "calc.h"
#include <stdio.h>

// Evaluates the postfix expression given as arguments, one symbol per
//   argument, and prints its value. Example: ./calc 1 2 - 4 5 + x
int main(int argc, char *argv[])
{
    Calc *calc = calc_create();
    float v;
    int i;

    for (i = 1; i < argc; i++)
    {
        char *t = argv[i]; // "12", "-5", "+", ...
        char c = t[0];
        if (t[1] == '\0' && (c == '+' || c == '-' || c == 'x' || c == '/'))
            calc_operator(calc, c); // A one-character operator.
        else if (sscanf(t, "%f", &v) == 1)
            calc_operand(calc, v); // Anything read as a number.
        else
        {
            printf("Invalid symbol: %s\n", t);
            calc_free(calc);
            return 1;
        }
    }

    printf("%.2f\n", calc_result(calc));
    calc_free(calc);
    return 0;
}
