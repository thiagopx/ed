#include "deque.h"
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct deque
{
    int n;
    int n_max; // Capacity of v.
    int head;  // Index of the first element (the tail is (head + n) % n_max)
    float *v;
};

Deque *dq_create()
{
    Deque *d = (Deque *)malloc(sizeof(Deque));
    d->n = 0;
    d->n_max = 4;
    d->v = (float *)malloc(d->n_max * sizeof(float));
    d->head = 0;
    return d;
}

// Doubles the capacity of d, keeping the circular order (same as the queue).
// Cost: O(n).
static void reallocate(Deque *d)
{
    d->n_max *= 2;
    d->v = (float *)realloc(d->v, d->n_max * sizeof(float));
    if (d->head != 0)
    {
        int k = d->n - d->head; // elements between head and the end of the old vector
        memmove(&d->v[d->n_max - k], &d->v[d->head], k * sizeof(float));
        d->head = d->n_max - k;
    }
}

void dq_push_front(Deque *d, float v)
{
    if (d->n == d->n_max)
        reallocate(d);
    d->head = (d->head - 1 + d->n_max) % d->n_max; // + n_max: from 0, wraps to n_max - 1.
    d->v[d->head] = v;
    d->n++;
}

void dq_push_back(Deque *d, float v)
{
    if (d->n == d->n_max)
        reallocate(d);
    int tail = (d->head + d->n) % d->n_max;
    d->v[tail] = v;
    d->n++;
}

float dq_pop_front(Deque *d)
{
    assert(!dq_is_empty(d));
    float v = d->v[d->head];
    d->head = (d->head + 1) % d->n_max;
    d->n--;
    return v;
}

float dq_pop_back(Deque *d)
{
    assert(!dq_is_empty(d));
    int last = (d->head + d->n - 1) % d->n_max; // head does not move.
    d->n--;
    return d->v[last];
}

int dq_is_empty(Deque *d)
{
    return d->n == 0;
}

void dq_free(Deque *d)
{
    free(d->v);
    free(d);
}

void dq_print(Deque *d)
{
    printf("Size: %d\n", d->n);
    printf("Capacity: %d\n", d->n_max);
    printf("Head: %d \t Tail: %d\n", d->head, (d->head + d->n) % d->n_max);
    printf("Data: ");
    for (int i = 0; i < d->n; i++)
        printf("%.2f ", d->v[(d->head + i) % d->n_max]);
    printf("\nMemory: ");
    for (int i = 0; i < d->n_max; i++)
        printf("%.2f ", d->v[i]);
    printf("\n");
}
