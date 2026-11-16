#include "calc.h"
#include <stdio.h>
#include <string.h>

// Reads a postfix expression up to the end of the input and prints its value.
int main()
{
    Calc *calc = calc_create();
    char tok[32];
    float v;

    while (scanf("%31s", tok) == 1) // Reads the next symbol: everything up to a blank.
    {
        if (strlen(tok) == 1 && strchr("+-*/", tok[0]) != NULL)
            calc_operator(calc, tok[0]);
        else if (sscanf(tok, "%f", &v) == 1)
            calc_operand(calc, v);
        else
        {
            printf("Invalid symbol: %s\n", tok);
            calc_free(calc);
            return 1;
        }
    }

    printf("%.2f\n", calc_result(calc));
    calc_free(calc);
    return 0;
}
