#include "dynvec.h"
#include <stdio.h>

int main() {
  DynVec *dv = dv_create();
  dv_insert(dv, 10);
  printf("size=%d capacity=%d\n", dv_size(dv), dv_capacity(dv));
  dv_print_values(dv);
  dv_free(dv);
  dv = dv_create_from_file("data.txt");
  dv_print_values(dv);
  printf("size=%d capacity=%d\n", dv_size(dv), dv_capacity(dv));
  dv_free(dv);
  return 0;
}