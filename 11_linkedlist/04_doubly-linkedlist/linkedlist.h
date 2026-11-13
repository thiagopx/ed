// A doubly linked list of integers, with pointers to the first and last nodes and a count.

#ifndef LINKEDLIST_H
#define LINKEDLIST_H

typedef struct list LinkedList;
typedef struct list_node ListNode;

// Returns a new empty list.
LinkedList *ll_create();

// Inserts v at the beginning of l.
void ll_insert(LinkedList *l, int v);

// Appends v to the end of l; with the pointer to the last node, no walk is needed.
void ll_append(LinkedList *l, int v);

// Removes the first occurrence of val from l.
// Cost: O(n): the search walks the list; unlinking the node found costs O(1).
void ll_remove(LinkedList *l, int val);

// Removes every occurrence of val from l, in a single pass.
// Cost: O(n).
void ll_remove_all(LinkedList *l, int val);

// Removes all the elements of l, keeping l as an empty list.
// Cost: O(n).
void ll_clear(LinkedList *l);

// Returns the number of elements of l.
int ll_size(LinkedList *l);

// Checks whether v is in l; returns 1 if it is, 0 otherwise.
// Cost: O(n).
int ll_is_in(LinkedList *l, int v);

// Checks whether l is empty; returns 1 if it is, 0 otherwise.
int ll_is_empty(LinkedList *l);

// Returns a new list with the elements of l in reverse order.
// Cost: O(n).
LinkedList *ll_reversed(LinkedList *l);

// Returns a new list with the elements of l1 followed by those of l2.
// Cost: O(n1 + n2).
LinkedList *ll_concatenate(LinkedList *l1, LinkedList *l2);

// Reverses l in place, only swapping pointers (no node is allocated).
// Cost: O(n).
void ll_reverse_in_place(LinkedList *l);

// Keeps the first k nodes in l and moves the remaining ones, in order, to a new list, only
//   adjusting pointers; returns the new list (empty if l has k nodes or fewer).
// Cost: O(k).
LinkedList *ll_split_at(LinkedList *l, int k);

// Frees l and all its nodes.
// Cost: O(n).
void ll_free(LinkedList *l);

// Prints the elements of l, from the first to the last.
// Cost: O(n).
void ll_print(LinkedList *l);

// Prints the elements of l, from the last to the first, following the prev pointers.
// Cost: O(n).
void ll_print_reversed(LinkedList *l);

#endif
