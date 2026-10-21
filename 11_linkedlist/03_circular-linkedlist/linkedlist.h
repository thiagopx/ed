#ifndef LINKEDLIST_H
#define LINKEDLIST_H

// Define the LinkedList and ListNode data structures
typedef struct list LinkedList;    // Represents a circular linked list
typedef struct list_node ListNode; // Represents a node in the list

// Operations on the circular linked list

// Create an empty circular list and return a pointer to it
LinkedList *ll_create();

// Check whether the list is empty
int ll_is_empty(LinkedList *l);

// Insert an element at the beginning of the list (it becomes the new first)
void ll_insert(LinkedList *l, int v);

// Get the number of elements in the list
int ll_size(LinkedList *l);

// Move the start of the list one node forward
void ll_rotate(LinkedList *l);

// Free the memory used by the list
void ll_free(LinkedList *l);

// Display all elements, starting from the first
void ll_print(LinkedList *l);

#endif
