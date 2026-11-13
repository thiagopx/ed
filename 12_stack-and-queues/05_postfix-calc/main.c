#include "calc.h"
#include <stdio.h>
#include <stdlib.h>

// Reads a postfix expression from the keyboard; type q to quit.
int main()
{
    Calc *calc = calc_create("%.2f\n");
    char c;

    while (scanf(" %c", &c) == 1) // reads the next non-blank character
    {
        if (c == '+' || c == '-' || c == '*' || c == '/')
            calc_operator(calc, c);
        else if (c == 'q')
            break;
        else
        {
            float v;
            ungetc(c, stdin); // gives the character back and tries to read a number
            if (scanf("%f", &v) == 1)
                calc_operand(calc, v);
            else
            {
                printf("Reading error\n");
                calc_free(calc);
                return 1;
            }
        }
    }

    calc_free(calc);
    return 0;
}
