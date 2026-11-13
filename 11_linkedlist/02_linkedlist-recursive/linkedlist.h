// A singly linked list of integers whose operations are written recursively, node by node.

#ifndef LINKEDLIST_H
#define LINKEDLIST_H

typedef struct list LinkedList;
typedef struct list_node ListNode;

// Returns a new empty list.
LinkedList *ll_create();

// Inserts v at the beginning of l.
void ll_insert(LinkedList *l, int v);

// Inserts v into l, keeping l in ascending order (recursive).
// Requires: l is in ascending order.
// Cost: O(n).
void ll_insert_sorted(LinkedList *l, int v);

// Appends v to the end of l (recursive).
// Cost: O(n).
void ll_append(LinkedList *l, int v);

// Removes the first occurrence of val from l (recursive).
// Cost: O(n).
void ll_remove(LinkedList *l, int val);

// Removes every occurrence of val from l (recursive).
// Cost: O(n).
void ll_remove_all(LinkedList *l, int val);

// Returns the number of elements of l (recursive).
// Cost: O(n).
int ll_size(LinkedList *l);

// Checks whether v is in l (recursive); returns 1 if it is, 0 otherwise.
// Cost: O(n).
int ll_is_in(LinkedList *l, int v);

// Checks whether l is empty; returns 1 if it is, 0 otherwise.
int ll_is_empty(LinkedList *l);

// Returns the sum of the elements of l (recursive).
// Cost: O(n).
int ll_sum(LinkedList *l);

// Returns how many elements of l are even and stores their sum in *sum, in a single pass
//   (recursive).
// Cost: O(n).
int ll_count_even(LinkedList *l, int *sum);

// Returns a new list with the elements of l in reverse order (recursive).
// Cost: O(n).
LinkedList *ll_reversed(LinkedList *l);

// Returns a new list with the elements of l1 followed by those of l2 (recursive).
// Cost: O(n1 + n2).
LinkedList *ll_concatenate(LinkedList *l1, LinkedList *l2);

// Frees l and all its nodes.
// Cost: O(n).
void ll_free(LinkedList *l);

// Prints the elements of l, from the first to the last.
// Cost: O(n).
void ll_print(LinkedList *l);

// Prints the elements of l, from the last to the first.
// Cost: O(n).
void ll_print_reversed(LinkedList *l);

// Checks whether l1 and l2 have the same elements in the same order; returns 1 if they do.
// Cost: O(n).
int ll_equals(LinkedList *l1, LinkedList *l2);

#endif
