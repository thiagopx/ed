#include "linkedlist.h" // Include the user-defined header file for the linked list data structure.
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a structure for the linked list.
struct list
{
    int count;       // Number of elements in the linked list.
    ListNode *first; // A pointer to the first node in the linked list.
    ListNode *last;  // A pointer to the last node in the linked list.
};

// Define a structure for a node in the linked list.
struct list_node
{
    int info;       // An integer value stored in the node.
    ListNode *next; // A pointer to the next node in the linked list.
    ListNode *prev; // A pointer to the previous node in the linked list.
};

// Create an empty linked list and return a pointer to it.
LinkedList *ll_create()
{
    LinkedList *l = (LinkedList *)malloc(sizeof(LinkedList)); // Allocate memory for the list structure.
    l->first = NULL;                                          // Initialize the 'first' pointer to NULL, indicating an empty list.
    l->last = NULL;                                           // Initialize the 'last' pointer to NULL.
    l->count = 0;                                             // Initialize the count to zero.
    return l;                                                 // Return a pointer to the newly created list.
}

// Get the number of elements in the linked list.
int ll_size(LinkedList *l)
{
    return l->count;
}

// Check whether the linked list is empty.
int ll_is_empty(LinkedList *l)
{
    return l->count == 0;
}

// Insert an element at the beginning of the linked list.
void ll_insert(LinkedList *l, int v)
{
    ListNode *node = (ListNode *)malloc(sizeof(ListNode)); // Allocate memory for a new node.
    node->info = v;                                        // Set the 'info' field of the new node to the provided value.
    node->next = l->first;                                 // Make the new node point to the current first node.
    node->prev = NULL;

    if (!ll_is_empty(l))
        l->first->prev = node; // Set the previous of the current first node to the new node.
    else
        l->last = node; // If the list was empty, the new node is also the last node.

    l->first = node; // Update the 'first' pointer to the new node.
    l->count++;      // Increment the count.
}

// Search for a node with a specific value in the linked list.
static ListNode *_search(LinkedList *l, int v)
{
    ListNode *p = l->first;

    while ((p != NULL) && (p->info != v))
        p = p->next;

    return p; // Return the found node or NULL if not found.
}

// Function to verify if a value is in the list
int ll_is_in(LinkedList *l, int v)
{
    return _search(l, v) != NULL;
}

// Remove the first occurrence of a specific value from the linked list.
void ll_remove(LinkedList *l, int v)
{
    ListNode *p = _search(l, v);

    if (p == NULL)
        return; // If the node is not found, do nothing.

    if (p == l->first)
        l->first = p->next; // If it's the first element, update the 'first'.
    else
        p->prev->next = p->next; // Update the 'next' field of the previous element.

    if (p == l->last)
        l->last = p->prev; // If it's the last element, update the 'last'.
    else
        p->next->prev = p->prev; // Update the 'prev' field of the next element.

    free(p);    // Free the memory used by the removed node.
    l->count--; // Decrement the count.
}

// Append an element to the end of the linked list.
// With the 'last' pointer, appending costs O(1): no walk is needed.
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

// Remove every node whose value is v, in a single pass.
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

// Remove all elements, keeping the (now empty) list structure.
void ll_clear(LinkedList *l)
{
    ListNode *p = l->first;
    while (p != NULL)
    {
        ListNode *t = p->next; // Store a reference to the next node.
        free(p);
        p = t;
    }
    l->first = l->last = NULL;
    l->count = 0;
}

// Reverse the list in place: every node swaps its next and prev; first and last swap too.
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

// Keep the first k nodes and move the rest to a new list, only adjusting pointers.
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

// Free the memory used by the linked list and its nodes.
void ll_free(LinkedList *l)
{
    ListNode *p = l->first;
    ListNode *t;
    while (p != NULL)
    {
        t = p->next; // Store a reference to the next node.
        free(p);     // Free the memory allocated for the current node.
        p = t;       // Move to the next node.
    }
    free(l); // Free the memory allocated for the list structure itself.
}

// Display all elements of the linked list.
void ll_print(LinkedList *l)
{
    for (ListNode *p = l->first; p != NULL; p = p->next)
    {
        printf("%d ", p->info); // Print the 'info' field of each node.
    }
    printf("\n"); // Print a newline character to separate the output.
}

// Display all elements from the last to the first, following the 'prev' pointers.
void ll_print_reversed(LinkedList *l)
{
    for (ListNode *p = l->last; p != NULL; p = p->prev)
    {
        printf("%d ", p->info);
    }
    printf("\n");
}
