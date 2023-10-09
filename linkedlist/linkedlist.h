#ifndef LINKEDLIST_H
#define LINKEDLIST_H

// Define the LinkedList and ListNode data structures
typedef struct list LinkedList;    // Represents a linked list
typedef struct list_node ListNode; // Represents a node in the linked list

// Operations on the linked list

// Create an empty linked list and return a pointer to it
LinkedList *ll_create();

// Insert an element at the beginning of the linked list
void ll_insert(LinkedList *l, int v);

// Insert an element into the linked list while keeping it sorted
void ll_insert_sorted(LinkedList *l, int v);

// Append an element to the end of the linked list
void ll_append(LinkedList *l, int v);

/**
 * Remove nodes from the list by their value
 * @param mode
 *   "all": Remove all matching nodes
 *   "first": Remove only the first matching node
 */
void ll_remove(LinkedList *l, int val, char mode[]);

// Get the size (number of elements) of the linked list
int ll_size(LinkedList *l);

// Check whether a specific element is in the linked list
int ll_is_in(LinkedList *l, int v);

// Check whether the linked list is empty
int ll_is_empty(LinkedList *l);

// Return a new linked list with the elements reversed
LinkedList *ll_reversed(LinkedList *l);

// Concatenate two linked lists, placing l2 after l1
LinkedList *ll_concatenate(LinkedList *l1, LinkedList *l2);

// Free the memory used by the linked list
void ll_free(LinkedList *l);

// Display all elements of the linked list
void ll_print(LinkedList *l);

#endif
