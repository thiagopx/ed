#include "linkedlist.h"
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct list
{
   ListNode *first; // NULL when the list is empty.
};

struct list_node
{
   int info;
   ListNode *next; // NULL in the last node.
};

LinkedList *ll_create()
{
   LinkedList *l = (LinkedList *)malloc(sizeof(LinkedList));
   l->first = NULL;
   return l;
}

int ll_is_empty(LinkedList *l)
{
   return l->first == NULL;
}

void ll_insert(LinkedList *l, int v)
{
   ListNode *node = (ListNode *)malloc(sizeof(ListNode));
   node->info = v;
   node->next = l->first;
   l->first = node;
}

// Returns the number of nodes of the chain starting at p.
static int _ll_size(ListNode *p)
{
   if (p != NULL)
      return 1 + _ll_size(p->next);

   return 0;
}

int ll_size(LinkedList *l)
{
   return _ll_size(l->first);
}

// Returns the sum of the values of the chain starting at p.
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

// Checks whether val is in the chain starting at p.
static int _ll_is_in(ListNode *p, int val)
{
   if (p == NULL)
      return 0;

   if (p->info == val)
      return 1;

   return _ll_is_in(p->next, val);
}

int ll_is_in(LinkedList *l, int val)
{
   return _ll_is_in(l->first, val);
}

// Returns the chain starting at p with v inserted in order (its first node may change).
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

void ll_insert_sorted(LinkedList *l, int v)
{
   l->first = _ll_insert_sorted(l->first, v);
}

// Returns the chain starting at p with v appended: appending to a chain is appending to its
//   subchain.
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

void ll_append(LinkedList *l, int v)
{
   l->first = _ll_append(l->first, v);
}

// Returns how many values of the chain starting at p are even, adding them to *sum.
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

int ll_count_even(LinkedList *l, int *sum)
{
   *sum = 0;
   return _ll_count_even(l->first, sum);
}

// Returns the chain starting at p without the first node whose value is val.
static ListNode *_ll_remove(ListNode *p, int val)
{
   ListNode *aux;
   if (p != NULL)
   {
      if (p->info == val) // Found: the chain now starts at the next node.
      {
         aux = p;
         p = p->next;
         free(aux);
      }
      else // Not here: remove from the subchain and relink.
         p->next = _ll_remove(p->next, val);
   }
   return p;
}

void ll_remove(LinkedList *l, int val)
{
   l->first = _ll_remove(l->first, val);
}

// Returns the chain starting at p without the nodes whose value is val.
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

void ll_remove_all(LinkedList *l, int val)
{
   l->first = _ll_remove_all(l->first, val);
}

// Frees the chain starting at p, from the last node back to p.
static void _ll_free(ListNode *p)
{
   if (p != NULL)
   {
      _ll_free(p->next);
      free(p);
   }
}

void ll_free(LinkedList *l)
{
   _ll_free(l->first);
   free(l);
}

// Prints the chain starting at p, in order.
static void _ll_print(ListNode *p)
{
   if (p != NULL)
   {
      printf("%d ", p->info);
      _ll_print(p->next);
   }
}

void ll_print(LinkedList *l)
{
   _ll_print(l->first);
   printf("\n");
}

// Prints the chain starting at p, from the last node to p.
static void _ll_print_reversed(ListNode *p)
{
   if (p != NULL)
   {
      _ll_print_reversed(p->next); // First print the rest of the list...
      printf("%d ", p->info);      // ...and only then this node.
   }
}

void ll_print_reversed(LinkedList *l)
{
   _ll_print_reversed(l->first);
   printf("\n");
}

// Checks whether the chains starting at p1 and p2 have the same values in the same order.
static int _ll_equals(ListNode *p1, ListNode *p2)
{
   if (p1 == NULL && p2 == NULL) // Both ended together: equal.
      return 1;
   if (p1 == NULL || p2 == NULL) // Only one ended: different sizes.
      return 0;
   return p1->info == p2->info && _ll_equals(p1->next, p2->next);
}

int ll_equals(LinkedList *l1, LinkedList *l2)
{
   return _ll_equals(l1->first, l2->first);
}
