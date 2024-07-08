#include "linkedlist.h" // Include the user-defined header file for the linked list data structure.
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a structure for the linked list.
struct list
{
   int count;       // Number of elements in the linked list.
   ListNode *first; // A pointer to the first node in the linked list.
   ListNode *last;  // A pointer to the last node in the linked list.
};

// Define a structure for a node in the linked list.
struct list_node
{
   int info;       // An integer value stored in the node.
   ListNode *next; // A pointer to the next node in the linked list.
   ListNode *prev; // A pointer to the previous node in the linked list.
};

// Create an empty linked list and return a pointer to it.
LinkedList *ll_create()
{
   LinkedList *l = (LinkedList *)malloc(sizeof(LinkedList)); // Allocate memory for the list structure.
   l->first = NULL;                                          // Initialize the 'first' pointer to NULL, indicating an empty list.
   l->last = NULL;                                           // Initialize the 'last' pointer to NULL.
   l->count = 0;                                             // Initialize the count to zero.
   return l;                                                 // Return a pointer to the newly created list.
}

// Get the number of elements in the linked list.
int ll_size(LinkedList *l)
{
   return l->count;
}

// Check whether the linked list is empty.
int ll_is_empty(LinkedList *l)
{
   return ll_size(l) == 0;
}

// Insert an element at the beginning of the linked list.
void ll_insert(LinkedList *l, int v)
{
   ListNode *node = (ListNode *)malloc(sizeof(ListNode)); // Allocate memory for a new node.
   node->info = v;                                        // Set the 'info' field of the new node to the provided value.
   node->next = l->first;                                 // Make the new node point to the current first node.
   node->prev = NULL;

   if (!ll_is_empty(l))
      l->first->prev = node; // Set the previous of the current first node to the new node.
   else
      l->last = node; // If the list was empty, the new node is also the last node.

   l->first = node; // Update the 'first' pointer to the new node.
   l->count++;      // Increment the count.
}

// Search for a node with a specific value in the linked list.
static ListNode *_search(LinkedList *l, int v)
{
   ListNode *p = l->first;

   while ((p != NULL) && (p->info != v))
      p = p->next;

   return p; // Return the found node or NULL if not found.
}

// Function to verify if a value is in the list
int ll_is_in(LinkedList *l, int v)
{
   return _search(l, v) != NULL;
}

// Remove the first occurrence of a specific value from the linked list.
void ll_remove(LinkedList *l, int v)
{
   ListNode *p = _search(l, v);

   if (p == NULL)
      return; // If the node is not found, do nothing.

   if (p == l->first)
      l->first = p->next; // If it's the first element, update the 'first'.
   else
      p->prev->next = p->next; // Update the 'next' field of the previous element.

   if (p == l->last)
      l->last = p->prev; // If it's the last element, update the 'last'.
   else
      p->next->prev = p->prev; // Update the 'prev' field of the next element.

   free(p);    // Free the memory used by the removed node.
   l->count--; // Decrement the count.
}

// Free the memory used by the linked list and its nodes.
void ll_free(LinkedList *l)
{
   ListNode *p = l->first;
   ListNode *t;
   while (p != NULL)
   {
      t = p->next; // Store a reference to the next node.
      free(p);     // Free the memory allocated for the current node.
      p = t;       // Move to the next node.
   }
   free(l); // Free the memory allocated for the list structure itself.
}

// Display all elements of the linked list.
void ll_print(LinkedList *l)
{
   for (ListNode *p = l->first; p != NULL; p = p->next)
   {
      printf("%d ", p->info); // Print the 'info' field of each node.
   }
   printf("\n"); // Print a newline character to separate the output.
}
