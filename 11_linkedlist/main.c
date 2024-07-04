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
      ll_insert(l, 1);  // Insert five occurrences of '1' into the list using ll_insert.
   ll_print(l);         // Show the elements of the updated list using ll_print.
   ll_remove_all(l, 1); // Remove all occurrences of '1' from the list using ll_remove.
   ll_print(l);         // Show the elements of the updated list using ll_print.
   printf("------------\n\n");

   // Checking whether 4 and 10 are in the list
   printf("Checking whether 4 and 10 are in the list\n");
   int values[5] = {-1, 0, 4, 5, 10}; // Array of values to check in the list.
   for (int i = 0; i < 5; i++)
      if (ll_is_in(l, values[i]))                   // Check if each value is in the list using ll_is_in.
         printf("%d is in the list.\n", values[i]); // Print if the value is in the list.
      else
         printf("%d is NOT in the list.\n", values[i]); // Print if the value is not in the list.

   // Free the memory used by the list
   ll_free(l); // Free the memory allocated for the list and its nodes using ll_free.

   return 0; // Return 0 to indicate successful program execution.
}
