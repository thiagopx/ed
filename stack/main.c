#include "stack.h"
#include <stdio.h>

int main()
{
   Stack *s = s_create();
   s_push(s, 1);
   s_push(s, 2);
   s_print(s);
   printf("\n");

   s_push(s, 3);
   s_push(s, 4);
   s_print(s);
   printf("\n");

   printf("Popping %.2f from s\n", s_pop(s));
   printf("Popping %.2f from s\n\n", s_pop(s));
   s_print(s);
   printf("\n");

   s_push(s, 5);
   s_push(s, 6);
   s_print(s);
   printf("\n");

   s_push(s, 7);
   s_print(s);
   printf("\n");
   printf("\n");

   s_free(s);

   return 0;
}