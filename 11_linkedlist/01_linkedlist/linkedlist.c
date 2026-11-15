#include "linkedlist.h"
#include <stdio.h>
#include <stdlib.h>

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

// Returns the first node of l whose value is v, or NULL if there is none.
// Cost: O(n).
static ListNode *_search(LinkedList *l, int v)
{
    ListNode *p = l->first;
    while (p != NULL && p->info != v)
        p = p->next;
    return p;
}

int ll_is_in(LinkedList *l, int v)
{
    return _search(l, v) != NULL;
}

int ll_remove(LinkedList *l, int v)
{
    // 1. Search: walk until p holds v, keeping in prev the node before it.
    ListNode *prev = NULL;
    ListNode *p = l->first;
    while (p != NULL && p->info != v)
    {
        prev = p;
        p = p->next;
    }

    if (p == NULL) // v is not in the list.
        return 0;

    // 2. Unlink p and free it.
    if (prev == NULL)
        l->first = p->next; // p is the first node: the list now starts at the next one.
    else
        prev->next = p->next;
    free(p);
    return 1;
}

void ll_print(LinkedList *l)
{
    for (ListNode *p = l->first; p != NULL; p = p->next)
        printf("%d ", p->info);
    printf("\n");
}

void ll_free(LinkedList *l)
{
    ListNode *p = l->first;
    while (p != NULL)
    {
        ListNode *t = p->next; // Saved before free(p): p->next cannot be read afterwards.
        free(p);
        p = t;
    }
    free(l);
}
