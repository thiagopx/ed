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

void ll_insert_sorted(LinkedList *l, int v)
{
    ListNode *prev = NULL;  // Node that will precede the new one.
    ListNode *p = l->first;

    // Find the insertion point: first node whose value is not smaller than v.
    while (p != NULL && p->info < v)
    {
        prev = p;
        p = p->next;
    }

    ListNode *node = (ListNode *)malloc(sizeof(ListNode));
    node->info = v;

    if (prev == NULL) // Empty list, or v is the smallest: insert at the beginning.
    {
        node->next = l->first;
        l->first = node;
    }
    else // Insert in the middle or at the end, right after 'prev'.
    {
        node->next = prev->next;
        prev->next = node;
    }
}

int ll_size(LinkedList *l)
{
    int cnt = 0;
    for (ListNode *p = l->first; p != NULL; p = p->next)
    {
        cnt++;
    }
    return cnt;
}

int ll_is_in(LinkedList *l, int v)
{
    ListNode *p = l->first;
    while (p != NULL)
    {
        if (p->info == v)
            return 1;
        p = p->next;
    }
    return 0;
}

int ll_remove(LinkedList *l, int v)
{
    ListNode *p = l->first;
    ListNode *prev = NULL; // The node before p: its 'next' must skip p.

    while (p != NULL)
    {
        if (p->info == v)
        {
            if (prev == NULL)
                l->first = p->next; // Removing the first node: the list starts at the next one.
            else
                prev->next = p->next;

            free(p);
            return 1;
        }
        else
        {
            prev = p;
            p = p->next;
        }
    }

    return 0;
}

void ll_remove_all(LinkedList *l, int v)
{
    while (ll_remove(l, v))
        ;
}

void ll_append(LinkedList *l, int v)
{
    ListNode *node = (ListNode *)malloc(sizeof(ListNode));
    node->info = v;
    node->next = NULL;

    if (l->first == NULL) // Empty list: the new node is also the first one.
    {
        l->first = node;
        return;
    }

    ListNode *p = l->first;
    while (p->next != NULL) // Stop at the current last node.
        p = p->next;
    p->next = node;
}

LinkedList *ll_from_array(int v[], int n)
{
    LinkedList *l = ll_create();
    ListNode *last = NULL; // Last node built so far: appending after it costs O(1).
    for (int i = 0; i < n; i++)
    {
        ListNode *node = (ListNode *)malloc(sizeof(ListNode));
        node->info = v[i];
        node->next = NULL;
        if (last == NULL)
            l->first = node; // The first value starts the list.
        else
            last->next = node;
        last = node;
    }
    return l;
}

void ll_remove_duplicates(LinkedList *l)
{
    // For each node, a second walk (q, with its own prev) removes the later copies of the same value.
    for (ListNode *p = l->first; p != NULL; p = p->next)
    {
        ListNode *prev = p;    // The node before q; starts at p itself.
        ListNode *q = p->next; // Walks the rest of the list looking for copies of p->info.
        while (q != NULL)
        {
            if (q->info == p->info)
            {
                prev->next = q->next; // Skip the copy...
                free(q);              // ...and free it.
                q = prev->next;       // prev stays where it is.
            }
            else
            {
                prev = q;
                q = q->next;
            }
        }
    }
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

void ll_print(LinkedList *l)
{
    for (ListNode *p = l->first; p != NULL; p = p->next)
    {
        printf("%d ", p->info);
    }
    printf("\n");
}
