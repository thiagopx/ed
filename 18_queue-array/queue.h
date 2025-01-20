#ifndef QUEUE_H
#define QUEUE_H

/**
 - Create an empty queue
 - Insert an element at the end
 - Remove the element from the beginning
 - Check if the queue is empty
 - Free the queue
*/

typedef struct queue Queue;

// Function prototypes.

// Creates a new empty queue and returns a pointer to it
Queue *q_create();

// Enqueues a float value v into the specified queue q
void q_enqueue(Queue *q, float v);

// Dequeues and returns a float value from the specified queue q
float q_dequeue(Queue *q);

// Checks if the specified queue q is empty and returns 1 if true, 0 otherwise
int q_is_empty(Queue *q);

// Frees the memory associated with the specified queue q
void q_free(Queue *q);

// Prints the elements of the specified queue q
void q_print(Queue *q);

#endif
