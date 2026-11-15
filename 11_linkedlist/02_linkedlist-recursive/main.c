#include "linkedlist.h"
#include <stdio.h>

int main(void)
{
   printf("Create a list with 10 elements\n");
   LinkedList *l = ll_create();
   for (int i = 0; i < 10; i++)
      ll_insert(l, i);
   ll_print(l);
   printf("------------\n\n");

   printf("Printing in reverse order (the recursion prints on the way back)\n");
   ll_print_reversed(l);
   printf("------------\n\n");

   printf("Removing 9 (the first node), 0 (the last) and 42 (absent)\n");
   ll_remove(l, 9);
   ll_remove(l, 0);
   ll_remove(l, 42);
   ll_print(l);
   printf("------------\n\n");

   printf("Is the list empty? %s\n", ll_is_empty(l) ? "yes" : "no");
   ll_free(l);
   return 0;
}
