// A singly linked list of integers that also keeps a pointer to its last node.
// Same nodes as 01_linkedlist (info + next); only the list structure changes.

#ifndef LINKEDLIST_H
#define LINKEDLIST_H

typedef struct list LinkedList;
typedef struct list_node ListNode;

// Returns a new empty list.
LinkedList *ll_create();

// Inserts v at the beginning of l.
void ll_insert(LinkedList *l, int v);

// Appends v to the end of l; thanks to the pointer to the last node, no walk is needed.
void ll_append(LinkedList *l, int v);

// Removes the first occurrence of v from l; returns 1 if v was found, 0 otherwise.
// Cost: O(n).
int ll_remove(LinkedList *l, int v);

// Checks whether l is empty; returns 1 if it is, 0 otherwise.
int ll_is_empty(LinkedList *l);

// Moves every node of l2 to the end of l1, only adjusting pointers.
// Ownership: the nodes now belong to l1; l2 ends up empty but still allocated.
void ll_join(LinkedList *l1, LinkedList *l2);

// Returns a new list with the nodes of a and b merged in ascending order, MOVING the nodes
//   (no allocation besides the new list structure).
// Requires: a and b are in ascending order.
// Ownership: the nodes now belong to the new list; a and b end up empty but still allocated.
// Cost: O(na + nb).
LinkedList *ll_merge_sorted(LinkedList *a, LinkedList *b);

// Frees l and all its nodes.
// Cost: O(n).
void ll_free(LinkedList *l);

// Prints the elements of l, from the first to the last.
// Cost: O(n).
void ll_print(LinkedList *l);

#endif
