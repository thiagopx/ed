#ifndef QUEUE_H
#define QUEUE_H

// Define the Queue and QueueNode data structures
typedef struct queue Queue;          // Represents a linked list
typedef struct queue_node QueueNode; // Represents a node in the linked list

// Operations on the linked list

// Creates a new empty queue and returns a pointer to it
Queue *q_create();

// Checks if the specified queue q is empty and returns 1 if true, 0 otherwise
int q_is_empty(Queue *q);

// Enqueues a float value x into the specified queue q
void q_enqueue(Queue *q, float x);

// Dequeues and returns a float value from the specified queue q
float q_dequeue(Queue *q);

// Frees the memory associated with the specified queue q
void q_free(Queue *q);

// Prints the elements of the specified queue q
void q_print(Queue *q);

#endif
