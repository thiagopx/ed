#include "linkedlist.h" // Include the user-defined header file for the list data structure.
#include <stdio.h>

int main(void)
{
   LinkedList *l; // Declare a pointer to a linked list.

   // Create a list with 10 elements
   printf("Create a list with 10 elements\n");
   l = ll_create(); // Create an empty linked list and assign its pointer to 'l'.
   for (int i = 0; i < 10; i++)
      ll_insert(l, i); // Insert elements into the list using ll_insert.
   ll_print(l);        // Show the elements of the list using ll_print.
   printf("------------\n\n");

   // Remove zero
   printf("Removing the first zero\n");
   ll_remove(l, 0);                                            // Remove the first occurrence of zero from the list using ll_remove.
   ll_print(l);                                                // Show the elements of the updated list using ll_print.
   printf("There are %d elements in the list.\n", ll_size(l)); // Print the number of elements in the list using ll_size.
   printf("------------\n\n");

   // Add and remove 1's
   printf("Adding ones and removing ones\n");
   for (int i = 0; i < 5; i++)
      ll_insert(l, 1); // Insert five occurrences of '1' into the list using ll_insert.
   ll_print(l);        // Show the elements of the updated list using ll_print.

   printf("Sum\n");
   int sum = ll_sum(l);
   printf("sum=%d\n", sum);

   // Free the memory used by the list
   ll_free(l); // Free the memory allocated for the list and its nodes using ll_free.

   return 0; // Return 0 to indicate successful program execution.
}
