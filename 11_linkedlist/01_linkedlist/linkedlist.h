// A singly linked list of integers, with a pointer to the first node only.

#ifndef LINKEDLIST_H
#define LINKEDLIST_H

typedef struct list LinkedList;
typedef struct list_node ListNode;

// Returns a new empty list.
LinkedList *ll_create();

// Inserts v at the beginning of l.
void ll_insert(LinkedList *l, int v);

// Inserts v into l, keeping l in ascending order.
// Requires: l is in ascending order.
// Cost: O(n).
void ll_insert_sorted(LinkedList *l, int v);

// Appends v to the end of l.
// Cost: O(n): without a pointer to the last node, the whole list is walked.
void ll_append(LinkedList *l, int v);

// Removes the first occurrence of v from l; returns 1 if v was found, 0 otherwise.
// Cost: O(n).
int ll_remove(LinkedList *l, int v);

// Removes every occurrence of v from l.
// Cost: O(n^2): each removal starts again from the first node.
void ll_remove_all(LinkedList *l, int v);

// Returns the number of elements of l.
// Cost: O(n).
int ll_size(LinkedList *l);

// Checks whether v is in l; returns 1 if it is, 0 otherwise.
// Cost: O(n).
int ll_is_in(LinkedList *l, int v);

// Checks whether l is empty; returns 1 if it is, 0 otherwise.
int ll_is_empty(LinkedList *l);

// Checks whether l is in ascending order; returns 1 if it is, 0 otherwise.
// Cost: O(n).
int ll_is_sorted(LinkedList *l);

// Returns a new list with the elements of l in reverse order.
// Cost: O(n).
LinkedList *ll_reversed(LinkedList *l);

// Returns a new list with the elements of l1 followed by those of l2.
// Cost: O(n1 + n2).
LinkedList *ll_concatenate(LinkedList *l1, LinkedList *l2);

// Returns a new list with the n values of array v, in the same order.
// Cost: O(n).
LinkedList *ll_from_array(int v[], int n);

// Removes the repeated values of l, keeping only the first occurrence of each one.
// Cost: O(n^2).
void ll_remove_duplicates(LinkedList *l);

// Frees l and all its nodes.
// Cost: O(n).
void ll_free(LinkedList *l);

// Prints the elements of l, from the first to the last.
// Cost: O(n).
void ll_print(LinkedList *l);

#endif
