// A singly linked list of integers, with a pointer to the first node only.

#ifndef LINKEDLIST_H
#define LINKEDLIST_H

typedef struct list LinkedList;
typedef struct list_node ListNode;

// Returns a new empty list.
LinkedList *ll_create();

// Checks whether l is empty; returns 1 if it is, 0 otherwise.
int ll_is_empty(LinkedList *l);

// Inserts v at the beginning of l.
void ll_insert(LinkedList *l, int v);

// Removes the first occurrence of v from l; returns 1 if v was found, 0 otherwise.
// Cost: O(n).
int ll_remove(LinkedList *l, int v);

// Checks whether v is in l; returns 1 if it is, 0 otherwise.
// Cost: O(n).
int ll_is_in(LinkedList *l, int v);

// Prints the elements of l, from the first to the last.
// Cost: O(n).
void ll_print(LinkedList *l);

// Frees l and all its nodes.
// Cost: O(n).
void ll_free(LinkedList *l);

// ---- Exercises: declared here, implemented by the student ----

// Inserts v into l, keeping l in ascending order.
// Requires: l is in ascending order.
// Cost: O(n).
void ll_insert_sorted(LinkedList *l, int v);

// Appends v to the end of l.
// Cost: O(n).
void ll_append(LinkedList *l, int v);

// Returns the number of elements of l.
// Cost: O(n).
int ll_size(LinkedList *l);

// Removes every occurrence of v from l.
// Cost: O(n).
void ll_remove_all(LinkedList *l, int v);

// Checks whether l is in ascending order; returns 1 if it is, 0 otherwise.
// Cost: O(n).
int ll_is_sorted(LinkedList *l);

// Returns a new list with the elements of l in reverse order.
// Cost: O(n).
LinkedList *ll_reversed(LinkedList *l);

// Returns a new list with the elements of l1 followed by those of l2.
// Cost: O(n1 + n2).
LinkedList *ll_concatenate(LinkedList *l1, LinkedList *l2);

#endif
