#include "dynvec.h"
#include <stdio.h>

int main()
{
  DynVec *dv = dv_create();
  dv_insert(dv, 10);
  printf("size=%d capacity=%d\n", dv_size(dv), dv_capacity(dv));
  dv_print_values(dv);
  dv_free(dv);
  dv = dv_create_from_file("data.txt");
  dv_print_values(dv);
  printf("size=%d capacity=%d\n", dv_size(dv), dv_capacity(dv));
  dv_free(dv);

  DynVec *dv1 = dv_create();
  DynVec *dv2 = dv_create();
  dv_insert(dv1, 1);
  dv_insert(dv1, 3);
  dv_insert(dv1, 6);
  dv_insert(dv2, 10);
  dv_insert(dv2, 20);

  dv = dv_concatenate(dv1, dv2);
  dv_print_values(dv);
  return 0;
}