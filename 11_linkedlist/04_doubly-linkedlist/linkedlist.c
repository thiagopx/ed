#include "linkedlist.h"
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct list
{
    int count;
    ListNode *first;
    ListNode *last;
};

struct list_node
{
    int info;
    ListNode *next;
    ListNode *prev;
};

LinkedList *ll_create()
{
    LinkedList *l = (LinkedList *)malloc(sizeof(LinkedList));
    l->first = NULL;
    l->last = NULL;
    l->count = 0;
    return l;
}

int ll_is_empty(LinkedList *l)
{
    return l->count == 0;
}

void ll_insert(LinkedList *l, int v)
{
    ListNode *node = (ListNode *)malloc(sizeof(ListNode));
    node->info = v;
    node->next = l->first;
    node->prev = NULL;

    if (!ll_is_empty(l))
        l->first->prev = node;
    else
        l->last = node; // If the list was empty, the new node is also the last node.

    l->first = node;
    l->count++;
}

// Returns the first node whose value is v (NULL if there is none).
static ListNode *_search(LinkedList *l, int v)
{
    ListNode *p = l->first;

    while ((p != NULL) && (p->info != v))
        p = p->next;

    return p;
}

void ll_remove(LinkedList *l, int v)
{
    ListNode *p = _search(l, v);

    if (p == NULL)
        return;

    if (p == l->first)
        l->first = p->next;
    else
        p->prev->next = p->next;

    if (p == l->last)
        l->last = p->prev;
    else
        p->next->prev = p->prev;

    free(p);
    l->count--;
}

void ll_append(LinkedList *l, int v)
{
    ListNode *node = (ListNode *)malloc(sizeof(ListNode));
    node->info = v;
    node->next = NULL;    // The new node is the last one...
    node->prev = l->last; // ...and comes after the current last (NULL if the list is empty).

    if (l->last != NULL)
        l->last->next = node; // Link the old last node to the new one.
    else
        l->first = node; // Empty list: the new node is also the first one.

    l->last = node;
    l->count++;
}

void ll_free(LinkedList *l)
{
    ListNode *p = l->first;
    ListNode *t;
    while (p != NULL)
    {
        t = p->next; // Saved before free(p): p->next cannot be read afterwards.
        free(p);
        p = t;
    }
    free(l);
}

void ll_print(LinkedList *l)
{
    for (ListNode *p = l->first; p != NULL; p = p->next)
    {
        printf("%d ", p->info);
    }
    printf("\n");
}

void ll_print_reversed(LinkedList *l)
{
    for (ListNode *p = l->last; p != NULL; p = p->prev)
    {
        printf("%d ", p->info);
    }
    printf("\n");
}
