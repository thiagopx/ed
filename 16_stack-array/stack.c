#include "stack.h"
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct stack
{
    int n_max; // Maximum capacity of the stack
    int n;     // Stack size (the top is n-1)
    float *v;  // Vector to store the stack elements
};

// Function to create a new stack
Stack *s_create()
{
    Stack *s = (Stack *)malloc(sizeof(Stack)); // Allocate memory for the stack structure
    s->n = 0;                                  // Invalid index (means empty stack)
    s->n_max = 4;
    s->v = (float *)malloc(s->n_max * sizeof(float)); // Allocate memory for the vector data
    return s;
}

// Helper function to reallocate memory for the dynamic vector
static void reallocate(Stack *s)
{
    s->n_max *= 2;                                           // Double the capacity
    s->v = (float *)realloc(s->v, s->n_max * sizeof(float)); // Reallocate memory for the vector data
}

// Function to insert an element at the top of the stack.
void s_push(Stack *s, float v)
{
    if (s->n == s->n_max)
        reallocate(s); // Resize the vector if it is full

    s->v[s->n++] = v; // Insert the value and increment the size
}

// Function to return the top element of the stack without removing it.
float s_top(Stack *s)
{
    assert(!s_is_empty(s));
    return s->v[s->n - 1];
}

// Function to remove and return the top element of the stack.
float s_pop(Stack *s)
{
    assert(!s_is_empty(s));
    return s->v[--s->n];
}

// Function to check if the stack is empty
int s_is_empty(Stack *s)
{
    return (s->n == 0);
}

// Function to free the memory allocated for the stack
void s_free(Stack *s)
{
    free(s->v); // Free the data vector
    free(s);    // Free the ADT
}

// Function to print the stack.
void s_print(Stack *s)
{
    printf("Size: %d\n", s->n);
    printf("Capacity: %d\n", s->n_max);
    printf("Top: %d\n", s->n - 1);
    printf("Data: (top) ");
    for (int i = s->n - 1; i >= 0; i--)
    {
        printf("%.2f ", s->v[i]);
    }
    printf("\nMemory: ");
    for (int i = 0; i < s->n_max; i++)
    {
        printf("%.2f ", s->v[i]);
    }
    printf("\n");
}