#include "linkedlist.h"
#include <stdio.h>

int main(void)
{
   printf("Create a list with 5 elements, then append 100 and 200\n");
   LinkedList *l = ll_create();
   for (int i = 0; i < 5; i++)
      ll_insert(l, i);
   ll_append(l, 100); // O(1): the list keeps a pointer to the last node.
   ll_append(l, 200);
   ll_print(l);
   printf("------------\n\n");

   printf("Walking backwards, from 'last' through the 'prev' pointers\n");
   ll_print_reversed(l);
   printf("------------\n\n");

   printf("Removing 4 (the first), 2 (in the middle) and 200 (the last)\n");
   ll_remove(l, 4);
   ll_remove(l, 2);
   ll_remove(l, 200);
   ll_print(l);
   ll_print_reversed(l);
   printf("------------\n\n");

   printf("Is the list empty? %s\n", ll_is_empty(l) ? "yes" : "no");
   ll_free(l);
   return 0;
}
