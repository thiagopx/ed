#include "linkedlist.h"
#include "student.h"
#include "professor.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Define a structure for the linked list.
struct list
{
    int count;       // Number of elements in the linked list.
    ListNode *first; // A pointer to the first node in the linked list.
    ListNode *last;  // A pointer to the last node in the linked list.
};

// Define a structure for a node in the linked list.
struct list_node
{
    NodeType type;
    void *info;     // Data associated with the node (generic pointer).
    ListNode *prev; // A pointer to the previous node in the linked list.
    ListNode *next; // A pointer to the next node in the linked list.
};

// Create an empty linked list and return a pointer to it.
LinkedList *ll_create()
{
    LinkedList *l = (LinkedList *)malloc(sizeof(LinkedList));
    l->first = NULL;
    l->last = NULL;
    l->count = 0;
    return l;
}

// Get the number of elements in the linked list.
int ll_size(LinkedList *l)
{
    return l->count;
}

// Check whether the linked list is empty.
int ll_is_empty(LinkedList *l)
{
    return ll_size(l) == 0;
}

// Insert an element at the beginning of the linked list.
void ll_insert(LinkedList *l, void *info, NodeType type)
{
    ListNode *node = (ListNode *)malloc(sizeof(ListNode));
    node->type = type;
    node->info = info;
    node->next = l->first;
    node->prev = NULL;

    if (!ll_is_empty(l))
        l->first->prev = node;
    else
        l->last = node;

    l->first = node;
    l->count++;
}

// Display all elements of the linked list.
void ll_print(LinkedList *l)
{
    for (ListNode *p = l->first; p != NULL; p = p->next)
    {
        if (p->type == TYPE_STUDENT)
            st_print(p->info); // Print the information of each Student structure.
        else
            pr_print(p->info); // Print the information of each Professor structure.
    }
    printf("\n"); // Print a newline character to separate the output.
}

// Append an element to the end of the linked list (O(1) with 'last').
void ll_append(LinkedList *l, void *info, NodeType type)
{
    ListNode *node = (ListNode *)malloc(sizeof(ListNode));
    node->type = type;
    node->info = info;
    node->next = NULL;
    node->prev = l->last;

    if (l->last != NULL)
        l->last->next = node;
    else
        l->first = node; // Empty list: the new node is also the first.

    l->last = node;
    l->count++;
}

// The CPF of a record depends on its type: the tag decides how to read the void *.
static const char *_cpf(ListNode *p)
{
    if (p->type == TYPE_STUDENT)
        return st_cpf((Student *)p->info);
    return pr_cpf((Professor *)p->info);
}

// Search for the node whose record has this CPF (NULL if absent).
static ListNode *_search(LinkedList *l, const char *cpf)
{
    ListNode *p = l->first;
    while (p != NULL && strcmp(_cpf(p), cpf) != 0)
        p = p->next;
    return p;
}

// Check whether a record with this CPF is in the list.
int ll_is_in(LinkedList *l, const char *cpf)
{
    return _search(l, cpf) != NULL;
}

// Unlink node p; if free_record is set, also free the record it points to.
static void _unlink(LinkedList *l, ListNode *p, int free_record)
{
    if (p == l->first)
        l->first = p->next;
    else
        p->prev->next = p->next;

    if (p == l->last)
        l->last = p->prev;
    else
        p->next->prev = p->prev;

    if (free_record)
        free(p->info); // Records are flat structs: a single free releases each one.
    free(p);
    l->count--;
}

// Remove (and free) the first record with this CPF.
void ll_remove(LinkedList *l, const char *cpf)
{
    ListNode *p = _search(l, cpf);
    if (p != NULL)
        _unlink(l, p, 1);
}

// Remove (and free) every record with this CPF, in a single pass.
void ll_remove_all(LinkedList *l, const char *cpf)
{
    ListNode *p = l->first;
    while (p != NULL)
    {
        ListNode *next = p->next;
        if (strcmp(_cpf(p), cpf) == 0)
            _unlink(l, p, 1);
        p = next;
    }
}

// Remove (and free) every record, keeping the empty list structure.
void ll_clear(LinkedList *l)
{
    while (l->first != NULL)
        _unlink(l, l->first, 1);
}

// Walk to position pos (0-based). Accessing by position costs O(pos): there is no index.
static ListNode *_at(LinkedList *l, int pos)
{
    if (pos < 0 || pos >= l->count)
        return NULL;
    ListNode *p = l->first;
    for (int i = 0; i < pos; i++)
        p = p->next;
    return p;
}

// Return the type of the record at position pos (pos must be valid).
NodeType ll_type_at(LinkedList *l, int pos)
{
    return _at(l, pos)->type;
}

// New list with only the professors, pointing to the SAME records, in the same order.
// The result is never NULL: with no professor, it is an empty list.
LinkedList *ll_professors(LinkedList *l)
{
    LinkedList *r = ll_create();
    for (ListNode *p = l->first; p != NULL; p = p->next)
        if (p->type == TYPE_PROFESSOR)
            ll_append(r, p->info, p->type); // Same pointer: no record is copied.
    return r;
}

// Free the nodes and the structure, but not the records (for lists that do not own them).
void ll_free_nodes(LinkedList *l)
{
    while (l->first != NULL)
        _unlink(l, l->first, 0);
    free(l);
}

// Free nodes, structure and records (the list owns its records).
void ll_free(LinkedList *l)
{
    ll_clear(l);
    free(l);
}
