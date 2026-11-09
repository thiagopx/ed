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

   if (p->info == val)
      return 1;

   return _ll_is_in(p->next, val);
}

// Function to verify if a value is in the list
int ll_is_in(LinkedList *l, int val)
{
   return _ll_is_in(l->first, val);
}


// Recursive helper: returns the (possibly new) first node of the chain starting at p.
static ListNode *_ll_insert_sorted(ListNode *p, int v)
{
   if (p == NULL || p->info >= v) // Base case: the new node goes right here.
   {
      ListNode *node = (ListNode *)malloc(sizeof(ListNode));
      node->info = v;
      node->next = p; // The rest of the chain (possibly empty) comes after it.
      return node;
   }
   p->next = _ll_insert_sorted(p->next, v); // Insert into the subchain and relink.
   return p;
}

// Function to insert an element while keeping the list in ascending order.
void ll_insert_sorted(LinkedList *l, int v)
{
   l->first = _ll_insert_sorted(l->first, v);
}

// Recursive helper: appending to a chain is appending to its subchain.
static ListNode *_ll_append(ListNode *p, int v)
{
   if (p == NULL) // Base case: empty chain; the new node is the whole chain.
   {
      ListNode *node = (ListNode *)malloc(sizeof(ListNode));
      node->info = v;
      node->next = NULL;
      return node;
   }
   p->next = _ll_append(p->next, v);
   return p;
}

// Function to append an element to the end of the linked list.
void ll_append(LinkedList *l, int v)
{
   l->first = _ll_append(l->first, v);
}

// Recursive helper: counts the even values of the chain and accumulates their sum in *sum.
static int _ll_count_even(ListNode *p, int *sum)
{
   if (p == NULL) // Base case: an empty chain has no even values.
      return 0;
   int count = _ll_count_even(p->next, sum); // Solve the subchain first...
   if (p->info % 2 == 0)                     // ...then add this node, if it is even.
   {
      *sum += p->info;
      count++;
   }
   return count;
}

// Function to count the even elements and compute their sum in a single pass.
int ll_count_even(LinkedList *l, int *sum)
{
   *sum = 0;
   return _ll_count_even(l->first, sum);
}

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

// Recursive helper: removes every node whose value is val.
static ListNode *_ll_remove_all(ListNode *p, int val)
{
   if (p == NULL) // Base case: nothing to remove in an empty chain.
      return NULL;
   p->next = _ll_remove_all(p->next, val); // Clean the subchain first.
   if (p->info == val)                     // Then decide about this node.
   {
      ListNode *rest = p->next;
      free(p);
      return rest;
   }
   return p;
}

// Function to remove every occurrence of val.
void ll_remove_all(LinkedList *l, int val)
{
   l->first = _ll_remove_all(l->first, val);
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

static void _ll_print_reversed(ListNode *p)
{
   if (p != NULL)
   {
      _ll_print_reversed(p->next); // First print the rest of the list...
      printf("%d ", p->info);      // ...and only then this node.
   }
}

// Function to display the elements from the last to the first.
void ll_print_reversed(LinkedList *l)
{
   _ll_print_reversed(l->first);
   printf("\n");
}

static int _ll_equals(ListNode *p1, ListNode *p2)
{
   if (p1 == NULL && p2 == NULL) // Both ended together: equal.
      return 1;
   if (p1 == NULL || p2 == NULL) // Only one ended: different sizes.
      return 0;
   return p1->info == p2->info && _ll_equals(p1->next, p2->next);
}

// Function to check whether two lists have the same elements in the same order.
int ll_equals(LinkedList *l1, LinkedList *l2)
{
   return _ll_equals(l1->first, l2->first);
}
