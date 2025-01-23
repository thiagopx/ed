#ifndef STACK_H
#define STACK_H

/** Interface for the stack data structure
- Create an empty stack
- Insert an element at the top (push)
- Remove the element from the top (pop)
- Check if the stack is empty
- Free the stack structure
*/
typedef struct stack Stack;

// Creates a new stack.
Stack *s_create();

// Removes and returns the top element of the stack.
float s_pop(Stack *s);

// Returns the top element of the stack without removing it.
float s_top(Stack *s);

// Pushes a new element onto the stack.
void s_push(Stack *s, float v);

// Checks if the stack is empty.
int s_is_empty(Stack *s);

// Frees the memory allocated for the stack.
void s_free(Stack *s);

// Prints the elements of the stack.
void s_print(Stack *s);

#endif
