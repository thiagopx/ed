#include "calc.h"
#include "stack.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct calc
{
    char fmt[21]; // Format used to print the top of the stack
    Stack *s;     // Stack of operands (any Stack implementation works)
};

Calc *calc_create(const char *fmt)
{
    Calc *c = (Calc *)malloc(sizeof(Calc));
    strncpy(c->fmt, fmt, 20);
    c->fmt[20] = '\0';
    c->s = s_create();
    return c;
}

void calc_operand(Calc *c, float v)
{
    s_push(c->s, v);
    printf(c->fmt, v);
}

void calc_operator(Calc *c, char op)
{
    float v2 = s_is_empty(c->s) ? 0.0f : s_pop(c->s); // Second operand (top).
    float v1 = s_is_empty(c->s) ? 0.0f : s_pop(c->s);
    float v = 0.0f;

    switch (op)
    {
    case '+': v = v1 + v2; break;
    case '-': v = v1 - v2; break;
    case '*': v = v1 * v2; break;
    case '/': v = v1 / v2; break;
    }

    s_push(c->s, v);
    printf(c->fmt, v);
}

void calc_free(Calc *c)
{
    s_free(c->s);
    free(c);
}
