// A queue of floats stored in a circular dynamic vector that doubles its capacity when full.

#ifndef QUEUE_H
#define QUEUE_H

typedef struct queue Queue;

// Returns a new empty queue.
Queue *q_create();

// Inserts v at the tail of q, doubling the capacity first if q is full (amortized O(1)).
void q_enqueue(Queue *q, float v);

// Removes and returns the element at the head of q.
// Requires: q is not empty.
float q_dequeue(Queue *q);

// Checks whether q is empty; returns 1 if it is, 0 otherwise.
int q_is_empty(Queue *q);

// Frees q.
void q_free(Queue *q);

// Prints the size, the capacity, the elements of q (from the head) and the whole vector.
// Cost: O(n_max).
void q_print(Queue *q);

#endif
