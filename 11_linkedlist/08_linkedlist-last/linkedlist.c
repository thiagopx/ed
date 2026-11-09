#include "linkedlist.h"
#include <stdio.h>
#include <stdlib.h>

// The list keeps both ends: 'first' to start walking, 'last' to append without walking.
struct list
{
    ListNode *first; // A pointer to the first node (NULL if the list is empty).
    ListNode *last;  // A pointer to the last node (NULL if the list is empty).
};

// Define a structure for a node in the linked list.
struct list_node
{
    int info;       // An integer value stored in the node.
    ListNode *next; // A pointer to the next node in the linked list.
};

// Function to create an empty linked list: both ends are NULL.
LinkedList *ll_create()
{
    LinkedList *l = (LinkedList *)malloc(sizeof(LinkedList));
    l->first = NULL;
    l->last = NULL;
    return l;
}

// Function to check whether the linked list is empty.
int ll_is_empty(LinkedList *l)
{
    return l->first == NULL;
}

// Function to insert an element at the beginning of the linked list.
void ll_insert(LinkedList *l, int v)
{
    ListNode *node = (ListNode *)malloc(sizeof(ListNode));
    node->info = v;
    node->next = l->first;
    if (l->first == NULL) // Empty list: the new node is also the last one.
        l->last = node;
    l->first = node;
}

// Function to append an element to the end: no walk, thanks to 'last'.
void ll_append(LinkedList *l, int v)
{
    ListNode *node = (ListNode *)malloc(sizeof(ListNode));
    node->info = v;
    node->next = NULL;
    if (l->last == NULL) // Empty list: the new node is first AND last.
        l->first = node;
    else
        l->last->next = node; // Link after the current last node.
    l->last = node;
}

// Function to remove the first occurrence of v.
// Same walk as in 01_linkedlist, plus one extra care: removing the last node moves 'last'.
int ll_remove(LinkedList *l, int v)
{
    ListNode *prev = NULL;
    ListNode *p = l->first;
    while (p != NULL && p->info != v)
    {
        prev = p;
        p = p->next;
    }
    if (p == NULL) // Not found.
        return 0;

    if (prev == NULL)
        l->first = p->next; // Removing the first node.
    else
        prev->next = p->next;

    if (p == l->last)
        l->last = prev; // The node before it becomes the last (NULL if the list emptied).

    free(p);
    return 1;
}

// Function to move every node of l2 to the end of l1, only adjusting pointers.
void ll_join(LinkedList *l1, LinkedList *l2)
{
    if (l2->first == NULL) // Nothing to move.
        return;

    if (l1->first == NULL) // l1 empty: it simply takes l2's chain.
        l1->first = l2->first;
    else
        l1->last->next = l2->first; // Hook l2's chain after l1's last node.
    l1->last = l2->last;

    l2->first = l2->last = NULL; // l2 no longer owns those nodes.
}

// Function to merge two ascending lists into a new one, moving their nodes.
LinkedList *ll_merge_sorted(LinkedList *a, LinkedList *b)
{
    LinkedList *r = ll_create();
    while (a->first != NULL || b->first != NULL)
    {
        LinkedList *from; // The list whose first node is the smallest.
        if (b->first == NULL || (a->first != NULL && a->first->info <= b->first->info))
            from = a;
        else
            from = b;

        ListNode *node = from->first; // Unlink the first node of 'from'...
        from->first = node->next;
        if (from->first == NULL)
            from->last = NULL;

        node->next = NULL; // ...and append it to r (O(1) with 'last').
        if (r->last == NULL)
            r->first = node;
        else
            r->last->next = node;
        r->last = node;
    }
    return r;
}

// Function to free the memory used by the linked list.
void ll_free(LinkedList *l)
{
    ListNode *p = l->first;
    while (p != NULL)
    {
        ListNode *t = p->next; // Store a reference to the next node.
        free(p);
        p = t;
    }
    free(l);
}

// Function to display all elements of the linked list.
void ll_print(LinkedList *l)
{
    for (ListNode *p = l->first; p != NULL; p = p->next)
        printf("%d ", p->info);
    printf("\n");
}
