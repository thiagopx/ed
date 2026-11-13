// A double-ended queue (deque) of floats stored in a circular dynamic vector.

#ifndef DEQUE_H
#define DEQUE_H

typedef struct deque Deque;

// Returns a new empty deque.
Deque *dq_create();

// Inserts v at the beginning of d, doubling the capacity first if d is full (amortized O(1)).
void dq_push_front(Deque *d, float v);

// Inserts v at the end of d, doubling the capacity first if d is full (amortized O(1)).
void dq_push_back(Deque *d, float v);

// Removes and returns the first element of d.
// Requires: d is not empty.
float dq_pop_front(Deque *d);

// Removes and returns the last element of d.
// Requires: d is not empty.
float dq_pop_back(Deque *d);

// Checks whether d is empty; returns 1 if it is, 0 otherwise.
int dq_is_empty(Deque *d);

// Frees d.
void dq_free(Deque *d);

// Prints the elements of d, in order, and the whole vector.
// Cost: O(n_max).
void dq_print(Deque *d);

#endif
