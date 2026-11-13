// A stack of floats stored in a dynamic vector that doubles its capacity when full.

#ifndef STACK_H
#define STACK_H

typedef struct stack Stack;

// Returns a new empty stack.
Stack *s_create();

// Removes and returns the top element of s.
// Requires: s is not empty.
float s_pop(Stack *s);

// Returns the top element of s without removing it.
// Requires: s is not empty.
float s_top(Stack *s);

// Pushes v onto s, doubling the capacity first if s is full (amortized O(1)).
void s_push(Stack *s, float v);

// Checks whether s is empty; returns 1 if it is, 0 otherwise.
int s_is_empty(Stack *s);

// Frees s.
void s_free(Stack *s);

// Prints the size, the capacity, the elements of s (from the top) and the whole vector.
// Cost: O(n_max).
void s_print(Stack *s);

#endif
