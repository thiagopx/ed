#include "queue.h"
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

// Define the structure for the queue.
struct queue
{
   QueueNode *front; // Pointer to the front of the queue.
   QueueNode *rear;  // Pointer to the rear of the queue.
};

// Define a structure for a node in the linked list.
struct queue_node
{
   float info;      // A float value stored in the node.
   QueueNode *next; // A pointer to the next node in the linked list.
};

// Function to create a new empty queue.
Queue *q_create()
{
   Queue *q = (Queue *)malloc(sizeof(Queue)); // Allocate memory for the queue structure.
   q->front = q->rear = NULL;                 // Initialize the front and rear pointers to NULL, indicating an empty queue.
   return q;
}

// Function to check whether the queue is empty.
int q_is_empty(Queue *q)
{
   return q->front == NULL;
}

// Function to enqueue a float value into the queue.
void q_enqueue(Queue *q, float v)
{
   QueueNode *node = (QueueNode *)malloc(sizeof(QueueNode)); // Allocate memory for a new node.
   node->info = v;
   node->next = NULL;

   if (q_is_empty(q))
      q->front = node;
   else
      q->rear->next = node;

   q->rear = node;
}

// Function to dequeue and return a float value from the queue.
float q_dequeue(Queue *q)
{
   assert(!q_is_empty(q));

   float v = q->front->info;
   QueueNode *p = q->front; // Store for removal

   if (q->front != q->rear)
      q->front = q->front->next;
   else
      q->front = q->rear = NULL;

   free(p);
   return v;
}

// Function to free the memory used by the queue.
void q_free(Queue *q)
{
   QueueNode *p = q->front;
   while (p != NULL)
   {
      QueueNode *t = p->next; // Store a reference to the next node.
      free(p);                // Free the memory allocated for the current node.
      p = t;                  // Move to the next node.
   }
   free(q); // Free the memory allocated for the queue structure itself.
}

// Function to display all elements of the queue.
void q_print(Queue *q)
{
   for (QueueNode *p = q->front; p != NULL; p = p->next)
      printf("%.2f ", p->info);

   printf("\n");
}
