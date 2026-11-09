#ifndef LINKEDLIST_H
#define LINKEDLIST_H

// A singly linked list that also keeps a pointer to its last node.
// Same nodes as 01_linkedlist (info + next); only the list structure changes.
typedef struct list LinkedList;    // Represents a linked list
typedef struct list_node ListNode; // Represents a node in the linked list

// Create an empty linked list and return a pointer to it
LinkedList *ll_create();

// Insert an element at the beginning of the linked list (O(1))
void ll_insert(LinkedList *l, int v);

// Append an element to the end of the linked list (O(1), thanks to 'last')
void ll_append(LinkedList *l, int v);

// Remove the first occurrence of v; return 1 if it was found, 0 otherwise
int ll_remove(LinkedList *l, int v);

// Check whether the linked list is empty
int ll_is_empty(LinkedList *l);

// Move every node of l2 to the end of l1, in O(1), only adjusting pointers;
// l2 ends up empty (but still allocated)
void ll_join(LinkedList *l1, LinkedList *l2);

// Merge two lists in ascending order into a new list, MOVING their nodes (no allocation
// besides the new list structure); a and b end up empty (but still allocated)
LinkedList *ll_merge_sorted(LinkedList *a, LinkedList *b);

// Free the memory used by the linked list
void ll_free(LinkedList *l);

// Display all elements of the linked list
void ll_print(LinkedList *l);

#endif
