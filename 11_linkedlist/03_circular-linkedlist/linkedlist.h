// A circular singly linked list of integers: the last node points back to the first.

#ifndef LINKEDLIST_H
#define LINKEDLIST_H

typedef struct list LinkedList;
typedef struct list_node ListNode;

// Returns a new empty list.
LinkedList *ll_create();

// Checks whether l is empty; returns 1 if it is, 0 otherwise.
int ll_is_empty(LinkedList *l);

// Inserts v at the beginning of l; v becomes the new first.
// Cost: O(n): the last node must be found to close the cycle.
void ll_insert(LinkedList *l, int v);

// Returns the number of elements of l.
// Cost: O(n).
int ll_size(LinkedList *l);

// Moves the start of l one node forward.
void ll_rotate(LinkedList *l);

// Solves the Josephus problem on l: starting at the first node, removes every k-th node
//   (printing each removed value) until a single node remains, and returns its value.
// Requires: l is not empty and k >= 1.
// Cost: O(n * k).
int ll_josephus(LinkedList *l, int k);

// Frees l and all its nodes.
// Cost: O(n).
void ll_free(LinkedList *l);

// Prints the elements of l, starting from the first.
// Cost: O(n).
void ll_print(LinkedList *l);

#endif
