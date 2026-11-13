// A queue of floats stored in a singly linked list: removal at the head, insertion at the tail.

#ifndef QUEUE_H
#define QUEUE_H

typedef struct queue Queue;
typedef struct queue_node QueueNode;

// Returns a new empty queue.
Queue *q_create();

// Checks whether q is empty; returns 1 if it is, 0 otherwise.
int q_is_empty(Queue *q);

// Inserts x at the tail of q.
void q_enqueue(Queue *q, float x);

// Removes and returns the element at the head of q.
// Requires: q is not empty.
float q_dequeue(Queue *q);

// Frees q and all its nodes.
// Cost: O(n).
void q_free(Queue *q);

// Prints the elements of q, from the head.
// Cost: O(n).
void q_print(Queue *q);

#endif
