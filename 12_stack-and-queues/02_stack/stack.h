// A stack of floats stored in a singly linked list: the top is the first node.

#ifndef STACK_H
#define STACK_H

typedef struct stack Stack;
typedef struct stacknode StackNode;

// Returns a new empty stack.
Stack *s_create();

// Removes and returns the top element of s.
// Requires: s is not empty.
float s_pop(Stack *s);

// Returns the top element of s without removing it.
// Requires: s is not empty.
float s_top(Stack *s);

// Pushes v onto s.
void s_push(Stack *s, float v);

// Checks whether s is empty; returns 1 if it is, 0 otherwise.
int s_is_empty(Stack *s);

// Frees s and all its nodes.
// Cost: O(n).
void s_free(Stack *s);

// Prints the elements of s, from the top.
// Cost: O(n).
void s_print(Stack *s);

#endif
