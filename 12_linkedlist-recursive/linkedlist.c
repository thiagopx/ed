#include "linkedlist.h" // Include the user-defined header file for the linked list data structure.
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a structure for the linked list.
struct list
{
   ListNode *first; // A pointer to the first node in the linked list.
};

// Define a structure for a node in the linked list.
struct list_node
{
   int info;       // An integer value stored in the node.
   ListNode *next; // A pointer to the next node in the linked list.
};

// Function to create an empty linked list and return a pointer to it.
LinkedList *ll_create()
{
   LinkedList *l = (LinkedList *)malloc(sizeof(LinkedList)); // Allocate memory for the list structure.
   l->first = NULL;                                          // Initialize the 'first' pointer to NULL, indicating an empty list.
   return l;                                                 // Return a pointer to the newly created list.
}

// Function to check whether the linked list is empty.
int ll_is_empty(LinkedList *l)
{
   return l->first == NULL; // Check if the 'first' pointer is NULL, indicating an empty list.
}

// Function to insert an element at the beginning of the linked list.
void ll_insert(LinkedList *l, int v)
{
   ListNode *node = (ListNode *)malloc(sizeof(ListNode)); // Allocate memory for a new node.
   node->info = v;                                        // Set the 'info' field of the new node to the provided value.
   node->next = l->first;                                 // Make the new node point to the current first node.
   l->first = node;                                       // Update the 'first' pointer to point to the new node.
}

static int _ll_size(ListNode *p)
{
   if (p != NULL)
      return 1 + _ll_size(p->next);

   return 0;
}

// Function to get the size (number of elements) of the linked list.
int ll_size(LinkedList *l)
{
   return _ll_size(l->first);
}

static int _ll_sum(ListNode *p)
{
   if (p != NULL)
      return _ll_sum(p->next) + p->info;

   return 0;
}

int ll_sum(LinkedList *l)
{
   return _ll_sum(l->first);
}

static int _ll_is_in(ListNode *p, int val)
{
   if (p == NULL)
      return 0;

   // if (p->info != val)
   //    return _ll_is_in(p->next, val);

   // return 1;

   if (p->info == val)
      return 1;

   return _ll_is_in(p->next, val);
}

// Function to verify if a value is in the list
int ll_is_in(LinkedList *l, int val)
{
   return _ll_is_in(l->first, val);
}

//    ListNode *p = l->first;
//    while (p != NULL)
//    {
//       if (p->info == val)
//          return 1;
//       p = p->next;
//    }
//    return 0;
// }

static ListNode *_ll_remove(ListNode *p, int val)
{
   ListNode *aux;
   if (p != NULL)
   {
      // found!
      if (p->info == val)
      {
         aux = p;
         p = p->next;
         free(aux);
      }
      // continue to search
      else
         p->next = _ll_remove(p->next, val);
   }
   return p;
}

// Function to remove nodes from the list by their value.
void ll_remove(LinkedList *l, int val)
{
   l->first = _ll_remove(l->first, val);
}

static void _ll_free(ListNode *p)
{
   if (p != NULL)
   {
      _ll_free(p->next);
      free(p);
   }
}

// Function to free the memory used by the linked list.
void ll_free(LinkedList *l)
{
   _ll_free(l->first);
   free(l); // free the list structure
}

static void _ll_print(ListNode *p)
{
   if (p != NULL)
   {
      printf("%d ", p->info);
      _ll_print(p->next);
   }
}

// Function to display all elements of the linked list.
void ll_print(LinkedList *l)
{
   _ll_print(l->first);
   printf("\n");
}
