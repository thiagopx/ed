#include "linkedlist.h"
#include <stdio.h>
#include <stdlib.h>

// Define a structure for the circular list.
struct list
{
    ListNode *first; // Any node of the cycle; NULL when the list is empty.
};

// Define a structure for a node in the list.
struct list_node
{
    int info;       // An integer value stored in the node.
    ListNode *next; // The next node; the last node points back to the first.
};

// Function to create an empty circular list and return a pointer to it.
LinkedList *ll_create()
{
    LinkedList *l = (LinkedList *)malloc(sizeof(LinkedList));
    l->first = NULL;
    return l;
}

// Function to check whether the list is empty.
int ll_is_empty(LinkedList *l)
{
    return l->first == NULL;
}

// Function to insert an element at the beginning of the list.
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

// Function to get the number of elements in the list.
int ll_size(LinkedList *l)
{
    int cnt = 0;
    ListNode *p = l->first;
    if (p != NULL)
        do
        {
            cnt++;
            p = p->next;
        } while (p != l->first); // Stop when we are back at the start.
    return cnt;
}

// Function to move the start of the list one node forward.
void ll_rotate(LinkedList *l)
{
    if (l->first != NULL)
        l->first = l->first->next;
}

// Function to solve the Josephus problem on the list.
// Combines two operations of the circular list: moving forward around the cycle and
// removing a node knowing the one before it. Counting never "falls off" the end.
int ll_josephus(LinkedList *l, int k)
{
    // prev starts at the last node (the one before first), so that prev->next is the first.
    ListNode *prev = l->first;
    while (prev->next != l->first)
        prev = prev->next;

    while (prev->next != prev) // More than one node left.
    {
        for (int i = 1; i < k; i++) // Move k-1 nodes: prev->next becomes the k-th node.
            prev = prev->next;

        ListNode *victim = prev->next;
        prev->next = victim->next; // Unlink the victim; the cycle stays closed.
        if (victim == l->first)    // Never leave first pointing to freed memory.
            l->first = victim->next;
        printf("%d ", victim->info);
        free(victim);
        // Counting restarts at the node after the victim: prev stays where it is.
    }
    printf("\n");

    l->first = prev; // The survivor is the only node; it points to itself.
    return prev->info;
}

// Function to free the memory used by the list.
void ll_free(LinkedList *l)
{
    if (l->first != NULL)
    {
        // Break the cycle, so the list ends in NULL like a regular one.
        ListNode *p = l->first->next;
        l->first->next = NULL;
        while (p != NULL)
        {
            ListNode *t = p->next; // Store a reference to the next node.
            free(p);
            p = t;
        }
    }
    free(l);
}

// Function to display all elements, starting from the first.
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
