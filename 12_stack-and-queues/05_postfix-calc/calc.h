// A postfix (RPN) calculator: operands go onto a stack, and each operator replaces the two
// operands on top by the result.

#ifndef CALC_H
#define CALC_H

typedef struct calc Calc;

// Returns a new calculator, with an empty stack of operands.
Calc *calc_create();

// Pushes the operand v onto c.
void calc_operand(Calc *c, float v);

// Pops two operands of c, applies op (+, -, x or /) and pushes the result; a missing operand
//   counts as zero.
void calc_operator(Calc *c, char op);

// Returns the value on the top of c, the result of what was read so far (0 if c has no operand).
float calc_result(Calc *c);

// Frees c and its stack.
void calc_free(Calc *c);

#endif
