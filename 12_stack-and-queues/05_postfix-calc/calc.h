// A postfix (RPN) calculator: operands go onto a stack, and each operator replaces the two
// operands on top by the result.

#ifndef CALC_H
#define CALC_H

typedef struct calc Calc;

// Returns a new calculator; fmt is the printf format used to show the top (e.g. "%.2f\n").
Calc *calc_create(const char *fmt);

// Pushes the operand v onto c and prints the new top.
void calc_operand(Calc *c, float v);

// Pops two operands of c, applies op (+, -, * or /), pushes the result and prints the new top;
//   a missing operand counts as zero.
void calc_operator(Calc *c, char op);

// Frees c and its stack.
void calc_free(Calc *c);

#endif
