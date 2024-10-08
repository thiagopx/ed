#include "linkedlist.h" // Include the user-defined header file for the linked list data structure.
#include "student.h"    // Include the user-defined header file for the Student structure.
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
    Student *info;  // Data associated with the node (in this case, a Student structure).
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
    return ll_size(l) == 0;
}

// Insert an element at the beginning of the linked list.
void ll_insert(LinkedList *l, const char *name, const char *cpf)
{
    ListNode *node = (ListNode *)malloc(sizeof(ListNode)); // Allocate memory for a new node.
    node->info = st_create(name, cpf);                     // Create a Student instance and assign it to the 'info' field of the new node.
    node->next = l->first;                                 // Make the new node point to the current first node.
    node->prev = NULL;

    if (!ll_is_empty(l))
        l->first->prev = node; // Set the previous of the current first node to the new node.
    else
        l->last = node; // If the list was empty, the new node is also the last node.

    l->first = node; // Update the 'first' pointer to the new node.
    l->count++;      // Increment the count.
}

// Append an element to the end of the linked list.
void ll_append(LinkedList *l, const char *name, const char *cpf)
{
    if (ll_is_empty(l))
        ll_insert(l, name, cpf);
    else
    {
        ListNode *node = (ListNode *)malloc(sizeof(ListNode)); // Allocate memory for a new node.
        node->info = st_create(name, cpf);                     // Create a Student instance and assign it to the 'info' field of the new node.
        node->next = NULL;                                     // Make the new node point to NULL, indicating the end of the list.
        node->prev = l->last;                                  // Make the new node point to the current last node.

        l->last->next = node; // Make the current last node point to the new node.
        l->last = node;       // Update the 'last' pointer to the new node.
        l->count++;           // Increment the count.
    }
}

// Free the memory used by the linked list and its nodes.
void ll_free(LinkedList *l)
{
    ListNode *p = l->first;
    ListNode *t;
    while (p != NULL)
    {
        t = p->next;   // Store a reference to the next node.
        free(p->info); // Free the memory allocated for the Student structure.
        free(p);       // Free the memory allocated for the current node.
        p = t;         // Move to the next node.
    }
    free(l); // Free the memory allocated for the list structure itself.
}

// Display all elements of the linked list.
void ll_print(LinkedList *l)
{
    for (ListNode *p = l->first; p != NULL; p = p->next)
    {
        st_print(p->info); // Print the 'name' field of each Student structure.
    }
    printf("\n"); // Print a newline character to separate the output.
}
