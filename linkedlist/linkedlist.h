#ifndef LINKEDLIST_H
#define LINKEDLIST_H

// Define the List and ListNode data structures
typedef struct list List;          // Represents a linked list
typedef struct list_node ListNode; // Represents a node in the linked list

// Operations on the linked list

// Create an empty linked list and return a pointer to it
List *ll_create();

// Insert an element at the beginning of the linked list
void ll_insert(List *l, int v);

// Internal recursive function used by insert_sorted_into_the_list
static void _insert_sorted(List *l, int v);

// Insert an element into the linked list while keeping it sorted
void ll_insert_sorted(List *l, int v);

// Append an element to the end of the linked list
void ll_append(List *l, int v);

/**
 * Remove nodes from the list by their value
 * @param mode
 *   "all": Remove all matching nodes
 *   "first": Remove only the first matching node
 */
void ll_remove(List *l, int val, char mode[]);

// Get the size (number of elements) of the linked list
int ll_size(List *l);

// Check whether a specific element is in the linked list
int ll_is_in(List *l, int v);

// Check whether the linked list is empty
int ll_is_empty(List *l);

// Return a new linked list with the elements reversed
List *ll_reversed(List *l);

// Concatenate two linked lists, placing l2 after l1
List *ll_concatenate(List *l1, List *l2);

// Free the memory used by the linked list
void ll_free(List *l);

// Display all elements of the linked list
void ll_print(List *l);

#endif
