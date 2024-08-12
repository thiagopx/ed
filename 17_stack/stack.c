#include "stack.h"
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

// Define the structure for the queue.
struct stack
{
    StackNode *top; // Pointer to top of the stack.
};

// Define a structure for a node in the stack.
struct stacknode
{
    float info;      // A float value stored in the node.
    StackNode *next; // A pointer to the next node in the stack.
};

// Function to create a new empty stack.
Stack *s_create()
{
    Stack *s = (Stack *)malloc(sizeof(Stack));
    s->top = NULL;
    return s;
}

// Function to check whether the stack is empty.
int s_is_empty(Stack *s)
{
    return s->top == NULL;
}

// Function to push a float value into the queue.
void s_push(Stack *s, float v)
{
    StackNode *node = (StackNode *)malloc(sizeof(StackNode)); // Allocate memory for a new node.
    node->info = v;
    node->next = s->top;
    s->top = node;
}

float s_top(Stack *s)
{
    assert(!s_is_empty(s));
    return s->top->info;
}

float s_pop(Stack *s)
{
    assert(!s_is_empty(s));

    float v = s->top->info;
    StackNode *p = s->top; // Store for removal
    s->top = s->top->next;
    free(p);
    return v;
}

// Function to free the memory used by the stack.
void s_free(Stack *s)
{
    StackNode *p = s->top;
    while (p != NULL)
    {
        StackNode *t = p->next; // Store a reference to the next node.
        free(p);                // Free the memory allocated for the current node.
        p = t;                  // Move to the next node.
    }
    free(s); // Free the memory allocated for the queue structure itself.
}

// Function to display all elements of the queue.
void s_print(Stack *s)
{
    for (StackNode *p = s->top; p != NULL; p = p->next)
        printf("%.2f ", p->info);

    printf("\n");
}
