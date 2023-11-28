#include "stack.h"
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct stack
{
   int n_max; // Maximum capacity of the stack
   int top;   // Index of the front element
   float *v;  // Vector to store the stack elements
};

// Function to create a new dynamic stack
Stack *s_create()
{
   Stack *s = (Stack *)malloc(sizeof(Stack)); // Allocate memory for the stack structure
   s->top = -1;                               // Invalid index (means empty stack)
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

void s_push(Stack *s, float v)
{
   int n = s->top + 1; // Stack size
   if (n == s->n_max)
      reallocate(s); // Resize the vector if it is full

   s->v[++s->top] = v; // Insert the value and increment the size
}

float s_top(Stack *s)
{
   assert(!s_is_empty(s));
   return s->v[s->top];
}

float s_pop(Stack *s)
{
   assert(!s_is_empty(s));
   return s->v[s->top--];
}

// Function to check if the stack is empty
int s_is_empty(Stack *s)
{
   return (s->top == -1);
}

// Function to free the memory allocated for the stack
void s_free(Stack *s)
{
   free(s->v); // Free the data vector
   free(s);    // Free the ADT
}

void s_print(Stack *s)
{
   printf("Size: %d\n", s->top + 1);
   printf("Capacity: %d\n", s->n_max);
   printf("Top: %d\n", s->top);
   printf("Data: (top) ");
   for (int i = s->top; i >= 0; i--)
   {
      printf("%.2f ", s->v[i]);
   }
   printf("\nMemory: ");
   for (int i = 0; i <= s->n_max; i++)
   {
      printf("%.2f ", s->v[i]);
   }
   printf("\n");
}