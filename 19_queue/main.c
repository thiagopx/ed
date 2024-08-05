#include "queue.h"
#include <stdio.h>

int main()
{
   Queue *q = q_create();
   q_enqueue(q, 1);
   q_enqueue(q, 2);
   q_print(q);
   printf("\n");

   q_enqueue(q, 3);
   q_enqueue(q, 4);
   q_print(q);
   printf("\n");

   printf("Dequeuing %.2f from q\n", q_dequeue(q));
   printf("Dequeuing %.2f from q\n\n", q_dequeue(q));
   q_print(q);
   printf("\n");

   q_enqueue(q, 5);
   q_enqueue(q, 6);
   q_print(q);
   printf("\n");

   q_enqueue(q, 7);
   q_print(q);
   printf("\n");

   q_free(q);

   return 0;
}