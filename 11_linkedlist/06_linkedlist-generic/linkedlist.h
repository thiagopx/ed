// A heterogeneous doubly linked list: each node holds a void * to a record and the record's type.

#ifndef LINKEDLIST_H
#define LINKEDLIST_H

typedef enum
{
    TYPE_STUDENT,  // The record is a Student *.
    TYPE_PROFESSOR // The record is a Professor *.
} NodeType;

typedef struct list LinkedList;
typedef struct list_node ListNode;

// Returns a new empty list.
LinkedList *ll_create();

// Inserts, at the beginning of l, the record data, whose type is type.
// Ownership: l becomes the owner of data (see ll_free).
void ll_insert(LinkedList *l, void *data, NodeType type);

// Appends, to the end of l, the record data, whose type is type.
// Ownership: l becomes the owner of data (see ll_free).
void ll_append(LinkedList *l, void *data, NodeType type);

// Removes (and frees) the first record of l whose CPF is cpf.
// Cost: O(n).
void ll_remove(LinkedList *l, const char *cpf);

// Removes (and frees) every record of l whose CPF is cpf, in a single pass.
// Cost: O(n).
void ll_remove_all(LinkedList *l, const char *cpf);

// Removes (and frees) all the records of l, keeping l as an empty list.
// Cost: O(n).
void ll_clear(LinkedList *l);

// Returns the number of records of l.
int ll_size(LinkedList *l);

// Checks whether a record whose CPF is cpf is in l; returns 1 if it is, 0 otherwise.
// Cost: O(n).
int ll_is_in(LinkedList *l, const char *cpf);

// Checks whether l is empty; returns 1 if it is, 0 otherwise.
int ll_is_empty(LinkedList *l);

// Returns the record at position pos (0-based) of l, as a void *; use ll_type_at to know
//   how to convert it.
// Requires: 0 <= pos < ll_size(l).
// Ownership: the record still belongs to l.
// Cost: O(pos).
void *ll_get(LinkedList *l, int pos);

// Returns a new list pointing to the SAME records of l, in reverse order.
// Ownership: the records still belong to l; free the result with ll_free_nodes.
// Cost: O(n).
LinkedList *ll_reversed(LinkedList *l);

// Returns a new list pointing to the SAME records of l1 followed by those of l2.
// Ownership: the records still belong to l1 and l2; free the result with ll_free_nodes.
// Cost: O(n1 + n2).
LinkedList *ll_concatenate(LinkedList *l1, LinkedList *l2);

// Returns the type of the record at position pos (0-based) of l. ll_get returns void *, so
//   the caller needs this to know how to use the pointer.
// Requires: 0 <= pos < ll_size(l).
// Cost: O(pos).
NodeType ll_type_at(LinkedList *l, int pos);

// Returns a new list pointing to the SAME professor records of l, in the same order
//   (domain operation).
// Ownership: the records still belong to l; free the result with ll_free_nodes, never ll_free.
// Cost: O(n).
LinkedList *ll_professors(LinkedList *l);

// Frees only the nodes and the structure of l, not the records they point to. Use it for
//   lists that do not own their records (ll_reversed, ll_concatenate, ll_professors).
// Cost: O(n).
void ll_free_nodes(LinkedList *l);

// Frees l, its nodes AND the records (l owns the records it receives in ll_insert/ll_append).
// Cost: O(n).
void ll_free(LinkedList *l);

// Prints the records of l, from the first to the last.
// Cost: O(n).
void ll_print(LinkedList *l);

// Prints the records of l, from the last to the first.
// Cost: O(n).
void ll_print_reversed(LinkedList *l);

#endif
