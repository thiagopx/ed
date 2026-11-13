#include "queue.h"
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

struct queue
{
   QueueNode *head;
   QueueNode *tail;
};

struct queue_node
{
   float info;
   QueueNode *next;
};

Queue *q_create()
{
   Queue *q = (Queue *)malloc(sizeof(Queue));
   q->head = q->tail = NULL;
   return q;
}

int q_is_empty(Queue *q)
{
   return q->head == NULL;
}

void q_enqueue(Queue *q, float v)
{
   QueueNode *node = (QueueNode *)malloc(sizeof(QueueNode));
   node->info = v;
   node->next = NULL;

   if (q_is_empty(q))
      q->head = node;
   else
      q->tail->next = node;

   q->tail = node;
}

float q_dequeue(Queue *q)
{
   assert(!q_is_empty(q));

   float v = q->head->info;
   QueueNode *p = q->head; // Saved to be freed after head moves on.

   if (q->head != q->tail)
      q->head = q->head->next;
   else
      q->head = q->tail = NULL;

   free(p);
   return v;
}

void q_free(Queue *q)
{
   QueueNode *p = q->head;
   while (p != NULL)
   {
      QueueNode *t = p->next; // Saved before free(p): p->next cannot be read afterwards.
      free(p);
      p = t;
   }
   free(q);
}

void q_print(Queue *q)
{
   for (QueueNode *p = q->head; p != NULL; p = p->next)
      printf("%.2f ", p->info);

   printf("\n");
}
