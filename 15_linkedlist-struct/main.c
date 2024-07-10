#include "linkedlist.h" // Include the user-defined header file for the list data structure.
#include "student.h"
#include <stdio.h>

int main(void)
{
   LinkedList *l; // Declare a pointer to a linked list.

   // Student *s1 = st_create("Thiago", "12345678912");
   // Student *s2 = st_create("Israel Caldas", "12345678987");
   // st_print(s1);
   // st_print(s2);

   // Create a list
   printf("Create a list\n");
   l = ll_create(); // Create an empty linked list and assign its pointer to 'l'.
   ll_insert(l, "Thiago", "12345678910");
   ll_insert(l, "Thiago Deps", "18756423409");

   // Print list
   ll_print(l);
   return 0; // Return 0 to indicate successful program execution.
}
