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

int ll_size(LinkedList *l)
{
    return l->count;
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

int ll_is_in(LinkedList *l, int v)
{
    return _search(l, v) != NULL;
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

void ll_remove_all(LinkedList *l, int v)
{
    ListNode *p = l->first;
    while (p != NULL)
    {
        ListNode *next = p->next; // Save it: p may be freed below.
        if (p->info == v)
        {
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
        p = next;
    }
}

void ll_clear(LinkedList *l)
{
    ListNode *p = l->first;
    while (p != NULL)
    {
        ListNode *t = p->next; // Saved before free(p): p->next cannot be read afterwards.
        free(p);
        p = t;
    }
    l->first = l->last = NULL;
    l->count = 0;
}

void ll_reverse_in_place(LinkedList *l)
{
    ListNode *p = l->first;
    while (p != NULL)
    {
        ListNode *t = p->next; // Save the old next before overwriting it.
        p->next = p->prev;
        p->prev = t;
        p = t; // Continue along the old direction.
    }
    ListNode *t = l->first; // The old first becomes the last, and vice versa.
    l->first = l->last;
    l->last = t;
}

LinkedList *ll_split_at(LinkedList *l, int k)
{
    LinkedList *r = ll_create();
    if (k >= l->count) // Nothing to move.
        return r;

    if (k <= 0) // Everything moves: r takes all nodes and l becomes empty.
    {
        r->first = l->first;
        r->last = l->last;
        r->count = l->count;
        l->first = l->last = NULL;
        l->count = 0;
        return r;
    }

    ListNode *p = l->first; // Walk to the k-th node: the new last node of l.
    for (int i = 1; i < k; i++)
        p = p->next;

    r->first = p->next; // The new list starts right after p...
    r->last = l->last;  // ...and ends where l used to end.
    r->count = l->count - k;

    r->first->prev = NULL; // Cut the link in both directions at the border.
    p->next = NULL;
    l->last = p;
    l->count = k;
    return r;
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
