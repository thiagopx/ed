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

// Search for the node of the student with a given CPF (NULL if absent).
static ListNode *_search(LinkedList *l, const char *cpf)
{
    ListNode *p = l->first;
    while (p != NULL && strcmp(st_cpf(p->info), cpf) != 0) // Compare strings, not pointers.
        p = p->next;
    return p;
}

// Check whether a student with this CPF is in the list.
int ll_is_in(LinkedList *l, const char *cpf)
{
    return _search(l, cpf) != NULL;
}

// Unlink node p from the list and free it together with the student it owns.
static void _unlink_and_free(LinkedList *l, ListNode *p)
{
    if (p == l->first)
        l->first = p->next;
    else
        p->prev->next = p->next;

    if (p == l->last)
        l->last = p->prev;
    else
        p->next->prev = p->prev;

    free(p->info); // The list owns the student: it was created by ll_insert/ll_append.
    free(p);
    l->count--;
}

// Remove the first student with this CPF.
void ll_remove(LinkedList *l, const char *cpf)
{
    ListNode *p = _search(l, cpf);
    if (p != NULL)
        _unlink_and_free(l, p);
}

// Remove every student with this CPF, in a single pass.
void ll_remove_all(LinkedList *l, const char *cpf)
{
    ListNode *p = l->first;
    while (p != NULL)
    {
        ListNode *next = p->next; // Save it: p may be freed.
        if (strcmp(st_cpf(p->info), cpf) == 0)
            _unlink_and_free(l, p);
        p = next;
    }
}

// Remove all students, keeping the (now empty) list structure.
void ll_clear(LinkedList *l)
{
    while (l->first != NULL)
        _unlink_and_free(l, l->first);
}

// Return the NODE of the student whose name comes first alphabetically (NULL if empty).
// Returning the node (not the student) lets the caller keep walking or unlink from there.
static ListNode *_first_by_name(LinkedList *l)
{
    if (l->first == NULL)
        return NULL;
    ListNode *best = l->first; // Best candidate so far.
    for (ListNode *p = l->first->next; p != NULL; p = p->next)
        if (strcmp(st_name(p->info), st_name(best->info)) < 0)
            best = p;
    return best;
}

// Return the student whose name comes first alphabetically (NULL if the list is empty).
Student *ll_first_by_name(LinkedList *l)
{
    ListNode *node = _first_by_name(l);
    return node == NULL ? NULL : node->info;
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
