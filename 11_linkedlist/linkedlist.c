#include "linkedlist.h" // Include the user-defined header file for the linked list data structure.
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a structure for the linked list.
struct list
{
    ListNode *first; // A pointer to the first node in the linked list.
};

// Define a structure for a node in the linked list.
struct list_node
{
    int info;       // An integer value stored in the node.
    ListNode *next; // A pointer to the next node in the linked list.
};

// Function to create an empty linked list and return a pointer to it.
LinkedList *ll_create()
{
    LinkedList *l = (LinkedList *)malloc(sizeof(LinkedList)); // Allocate memory for the list structure.
    l->first = NULL;                                          // Initialize the 'first' pointer to NULL, indicating an empty list.
    return l;                                                 // Return a pointer to the newly created list.
}

// Function to check whether the linked list is empty.
int ll_is_empty(LinkedList *l)
{
    return l->first == NULL; // Check if the 'first' pointer is NULL, indicating an empty list.
}

// Function to insert an element at the beginning of the linked list.
void ll_insert(LinkedList *l, int v)
{
    ListNode *node = (ListNode *)malloc(sizeof(ListNode)); // Allocate memory for a new node.
    node->info = v;                                        // Set the 'info' field of the new node to the provided value.
    node->next = l->first;                                 // Make the new node point to the current first node.
    l->first = node;                                       // Update the 'first' pointer to point to the new node.
}

// Function to get the size (number of elements) of the linked list.
int ll_size(LinkedList *l)
{
    int cnt = 0; // Initialize a counter to zero.
    for (ListNode *p = l->first; p != NULL; p = p->next)
    {
        cnt++; // Increment the counter for each node in the list.
    }
    return cnt; // Return the total number of elements in the linked list.
}

// Function to verify if a value is in the list
int ll_is_in(LinkedList *l, int val)
{
    ListNode *p = l->first;
    while (p != NULL)
    {
        if (p->info == val)
            return 1;
        p = p->next;
    }
    return 0;
}

// Function to remove the first occurrence of a specific element from the linked list
int ll_remove(LinkedList *l, int v)
{
    ListNode *p = l->first; // Pointer to the current node being examined
    ListNode *prev = NULL;  // Pointer to the previous node

    // Traverse the list
    while (p != NULL)
    {
        // Check if the current node contains the element to be removed
        if (p->info == v)
        {
            // If the element to be removed is at the beginning of the list
            if (prev == NULL)
                l->first = p->next; // Update the 'first' pointer to skip the first node
            // If the element to be removed is in the middle or end of the list
            else
                prev->next = p->next; // Update the 'next' pointer of the previous node

            free(p);  // Deallocate memory occupied by the removed node
            return 1; // Indicate success (element found and removed)
        }
        else
        {
            prev = p;    // Update the 'prev' pointer
            p = p->next; // Move to the next node
        }
    }

    return 0; // Indicate that the element was not found
}

// Remove all elements that match a specific value from the linked list
void ll_remove_all(LinkedList *l, int v)
{
    while (ll_remove(l, v))
        ;
}

// Function to free the memory used by the linked list.
void ll_free(LinkedList *l)
{
    ListNode *p = l->first;
    while (p != NULL)
    {
        ListNode *t = p->next; // Store a reference to the next node.
        free(p);               // Free the memory allocated for the current node.
        p = t;                 // Move to the next node.
    }
    free(l); // Free the memory allocated for the list structure itself.
}

// Function to display all elements of the linked list.
void ll_print(LinkedList *l)
{
    for (ListNode *p = l->first; p != NULL; p = p->next)
    {
        printf("%d ", p->info); // Print the 'info' field of each node.
    }
    printf("\n"); // Print a newline character to separate the output.
}
