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
