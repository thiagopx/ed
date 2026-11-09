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
   printf("Adding ones\n");
   for (int i = 0; i < 5; i++)
      ll_insert(l, 1); // Insert five occurrences of '1' into the list using ll_insert.
   ll_print(l);        // Show the elements of the updated list using ll_print.
   printf("------------\n\n");

   // Walk the list backwards, from 'last' through the 'prev' pointers
   printf("Removing 5 and printing in both directions\n");
   ll_remove(l, 5);
   ll_print(l);
   ll_print_reversed(l);
   ll_remove_all(l, 1); // Remove all occurrences of '1' in a single pass.
   ll_print(l);
   printf("------------\n\n");

   // Checking membership
   printf("Checking whether some values are in the list\n");
   int values[5] = {-1, 0, 4, 5, 10}; // Array of values to check in the list.
   for (int i = 0; i < 5; i++)
      if (ll_is_in(l, values[i]))
         printf("%d is in the list.\n", values[i]);
      else
         printf("%d is NOT in the list.\n", values[i]);
   printf("------------\n\n");

   // Append to the end
   printf("Appending 100 and 200 (O(1) with 'last')\n");
   ll_append(l, 100);
   ll_append(l, 200);
   ll_print(l);
   printf("------------\n\n");

   // Reverse in place and split at a position
   printf("Reversing in place\n");
   ll_reverse_in_place(l);
   ll_print(l);
   ll_print_reversed(l);
   printf("Keeping the first 4 nodes and moving the rest to a new list\n");
   LinkedList *tail = ll_split_at(l, 4);
   ll_print(l);
   ll_print(tail);
   ll_print_reversed(tail);
   printf("sizes: %d and %d\n", ll_size(l), ll_size(tail));
   printf("------------\n\n");

   // Clear keeps the structure; free releases it
   printf("Clearing the tail\n");
   ll_clear(tail);
   printf("empty? %d\n", ll_is_empty(tail));
   ll_append(tail, 7); // The cleared list can still be used.
   ll_print(tail);

   // Free the memory used by the list
   ll_free(l); // Free the memory allocated for the list and its nodes using ll_free.
   ll_free(tail);

   return 0; // Return 0 to indicate successful program execution.
}
