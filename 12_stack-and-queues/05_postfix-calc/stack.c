#include "stack.h"
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct stack
{
    int n_max; // Capacity of v.
    int n;     // Number of elements; the top is v[n-1].
    float *v;
};

Stack *s_create()
{
    Stack *s = (Stack *)malloc(sizeof(Stack));
    s->n = 0;
    s->n_max = 4;
    s->v = (float *)malloc(s->n_max * sizeof(float));
    return s;
}

// Doubles the capacity of s.
// Cost: O(n): realloc may copy the elements to a new block.
static void reallocate(Stack *s)
{
    s->n_max *= 2;
    s->v = (float *)realloc(s->v, s->n_max * sizeof(float));
}

void s_push(Stack *s, float v)
{
    if (s->n == s->n_max)
        reallocate(s);

    s->v[s->n++] = v;
}

float s_top(Stack *s)
{
    assert(!s_is_empty(s));
    return s->v[s->n - 1];
}

float s_pop(Stack *s)
{
    assert(!s_is_empty(s));
    return s->v[--s->n];
}

int s_is_empty(Stack *s)
{
    return (s->n == 0);
}

void s_free(Stack *s)
{
    free(s->v);
    free(s);
}

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
