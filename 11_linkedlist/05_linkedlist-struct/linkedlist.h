// A doubly linked list of students, with pointers to both ends and a count.

#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include "student.h"

typedef struct list LinkedList;
typedef struct list_node ListNode;

// Returns a new empty list.
LinkedList *ll_create();

// Inserts, at the beginning of l, a new student with the given name and cpf.
// Ownership: the list creates the student and frees it when the node is removed.
void ll_insert(LinkedList *l, const char *name, const char *cpf);

// Appends, to the end of l, a new student with the given name and cpf.
// Ownership: the list creates the student and frees it when the node is removed.
void ll_append(LinkedList *l, const char *name, const char *cpf);

// Removes (and frees) the first student of l whose CPF is cpf.
// Cost: O(n).
void ll_remove(LinkedList *l, const char *cpf);

// Removes (and frees) every student of l whose CPF is cpf, in a single pass.
// Cost: O(n).
void ll_remove_all(LinkedList *l, const char *cpf);

// Removes (and frees) all the students of l, keeping l as an empty list.
// Cost: O(n).
void ll_clear(LinkedList *l);

// Returns the number of students of l.
int ll_size(LinkedList *l);

// Checks whether a student whose CPF is cpf is in l; returns 1 if it is, 0 otherwise.
// Cost: O(n).
int ll_is_in(LinkedList *l, const char *cpf);

// Checks whether l is empty; returns 1 if it is, 0 otherwise.
int ll_is_empty(LinkedList *l);

// Returns a new list with the students of l in reverse order.
// Cost: O(n).
LinkedList *ll_reversed(LinkedList *l);

// Returns a new list with the students of l1 followed by those of l2.
// Cost: O(n1 + n2).
LinkedList *ll_concatenate(LinkedList *l1, LinkedList *l2);

// Returns the student of l whose name comes first in alphabetical order (NULL if l is empty).
// Ownership: the student still belongs to l.
// Cost: O(n).
Student *ll_first_by_name(LinkedList *l);

// Frees l, its nodes and the students they hold.
// Cost: O(n).
void ll_free(LinkedList *l);

// Prints the students of l, from the first to the last.
// Cost: O(n).
void ll_print(LinkedList *l);

// Prints the students of l, from the last to the first.
// Cost: O(n).
void ll_print_reversed(LinkedList *l);

#endif
