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

  // dv_insert(dv, 10);
  // printf("size=%d capacity=%d\n", dv_size(dv), dv_capacity(dv));
  // dv_print_values(dv);
  // dv_free(dv);
  // dv = dv_create_from_file("data.txt");
  // dv_print_values(dv);
  // printf("size=%d capacity=%d\n", dv_size(dv), dv_capacity(dv));
  // dv_free(dv);

  // DynVec *dv1 = dv_create();
  // DynVec *dv2 = dv_create();
  // dv_insert(dv1, 1);
  // dv_insert(dv1, 3);
  // dv_insert(dv1, 6);
  // dv_insert(dv2, 10);
  // dv_insert(dv2, 20);

  // dv = dv_concatenate(dv1, dv2);
  // dv_print_values(dv);
  return 0;
}