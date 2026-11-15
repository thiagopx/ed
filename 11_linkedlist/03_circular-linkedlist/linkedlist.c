#include "linkedlist.h"
#include <stdio.h>
#include <stdlib.h>

struct list
{
    ListNode *first; // Any node of the cycle; NULL when the list is empty.
};

struct list_node
{
    int info;
    ListNode *next; // The next node; the last node points back to the first.
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

    if (l->first == NULL) // The only node points to itself.
    {
        node->next = node;
    }
    else
    {
        // Find the last node (the one whose next is the first) to close the cycle.
        ListNode *last = l->first;
        while (last->next != l->first)
            last = last->next;

        node->next = l->first;
        last->next = node;
    }
    l->first = node;
}

void ll_free(LinkedList *l)
{
    if (l->first != NULL)
    {
        // Break the cycle, so the list ends in NULL like a regular one.
        ListNode *p = l->first->next;
        l->first->next = NULL;
        while (p != NULL)
        {
            ListNode *t = p->next; // Saved before free(p): p->next cannot be read afterwards.
            free(p);
            p = t;
        }
    }
    free(l);
}

void ll_print(LinkedList *l)
{
    ListNode *p = l->first;
    if (p != NULL)
        do
        {
            printf("%d ", p->info);
            p = p->next;
        } while (p != l->first);
    printf("\n");
}
