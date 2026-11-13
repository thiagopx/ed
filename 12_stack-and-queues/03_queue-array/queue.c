#include "queue.h"
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct queue
{
    int n;
    int n_max; // Capacity of v.
    int head;  // Index of the first element (the tail is (head + n) % n_max)
    float *v;
};

Queue *q_create()
{
    Queue *q = (Queue *)malloc(sizeof(Queue));

    q->n = 0;
    q->n_max = 4;
    q->v = (float *)malloc(q->n_max * sizeof(float));
    q->head = 0;

    return q;
}

// Doubles the capacity of q.
// Cost: O(n): realloc may copy the elements to a new block.
static void reallocate(Queue *q)
{
    q->n_max *= 2;
    q->v = (float *)realloc(q->v, q->n_max * sizeof(float));
}

void q_enqueue(Queue *q, float v)
{
    if (q->n == q->n_max)
    {
        reallocate(q);

        // If the queue wraps around the end of the old vector, the block from head to
        // the old end must move to the end of the new vector. memmove (string.h) copies
        // a block of bytes, like a loop copying element by element.
        if (q->head != 0)
        {
            memmove(
                &q->v[q->n_max - q->n + q->head], // destination
                &q->v[q->head],                   // source
                (q->n - q->head) * sizeof(float)  // bytes to shift
            );
            q->head = q->n_max - q->n + q->head;
        }
    }
    int tail = (q->head + q->n) % q->n_max;
    q->v[tail] = v;
    q->n++;
}

float q_dequeue(Queue *q)
{
    assert(!q_is_empty(q));
    float v = q->v[q->head];
    q->head = (q->head + 1) % q->n_max;
    q->n--;
    return v;
}

int q_is_empty(Queue *q)
{
    return (q->n == 0);
}

void q_free(Queue *q)
{
    free(q->v);
    free(q);
}

void q_print(Queue *q)
{
    printf("Size: %d\n", q->n);
    printf("Capacity: %d\n", q->n_max);
    printf("Head: %d \t Tail: %d\n", q->head, (q->head + q->n) % q->n_max);
    printf("Data: ");
    for (int i = 0; i < q->n; i++)
    {
        printf("%.2f ", q->v[(q->head + i) % q->n_max]);
    }
    printf("\n");
    printf("Memory: ");
    for (int i = 0; i < q->n_max; i++)
    {
        printf("%.2f ", q->v[i]);
    }
    printf("\n");
}
