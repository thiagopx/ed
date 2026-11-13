#include "linkedlist.h"
#include "student.h"
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct list
{
    int count;
    ListNode *first;
    ListNode *last;
};

struct list_node
{
    Student *info;
    ListNode *next;
    ListNode *prev;
};

LinkedList *ll_create()
{
    LinkedList *l = (LinkedList *)malloc(sizeof(LinkedList));
    l->first = NULL;
    l->last = NULL;
    l->count = 0;
    return l;
}

int ll_size(LinkedList *l)
{
    return l->count;
}

int ll_is_empty(LinkedList *l)
{
    return ll_size(l) == 0;
}

void ll_insert(LinkedList *l, const char *name, const char *cpf)
{
    ListNode *node = (ListNode *)malloc(sizeof(ListNode));
    node->info = st_create(name, cpf); // The list creates, and therefore owns, the student.
    node->next = l->first;
    node->prev = NULL;

    if (!ll_is_empty(l))
        l->first->prev = node;
    else
        l->last = node; // If the list was empty, the new node is also the last node.

    l->first = node;
    l->count++;
}

void ll_append(LinkedList *l, const char *name, const char *cpf)
{
    if (ll_is_empty(l))
        ll_insert(l, name, cpf);
    else
    {
        ListNode *node = (ListNode *)malloc(sizeof(ListNode));
        node->info = st_create(name, cpf); // The list creates, and therefore owns, the student.
        node->next = NULL;
        node->prev = l->last;

        l->last->next = node;
        l->last = node;
        l->count++;
    }
}

// Returns the node of the student whose CPF is cpf (NULL if there is none).
static ListNode *_search(LinkedList *l, const char *cpf)
{
    ListNode *p = l->first;
    while (p != NULL && strcmp(st_cpf(p->info), cpf) != 0) // Compare strings, not pointers.
        p = p->next;
    return p;
}

int ll_is_in(LinkedList *l, const char *cpf)
{
    return _search(l, cpf) != NULL;
}

// Unlinks node p from l and frees it together with the student it owns.
static void _unlink_and_free(LinkedList *l, ListNode *p)
{
    if (p == l->first)
        l->first = p->next;
    else
        p->prev->next = p->next;

    if (p == l->last)
        l->last = p->prev;
    else
        p->next->prev = p->prev;

    st_free(p->info); // The list owns the student: it was created by ll_insert/ll_append.
    free(p);
    l->count--;
}

void ll_remove(LinkedList *l, const char *cpf)
{
    ListNode *p = _search(l, cpf);
    if (p != NULL)
        _unlink_and_free(l, p);
}

void ll_remove_all(LinkedList *l, const char *cpf)
{
    ListNode *p = l->first;
    while (p != NULL)
    {
        ListNode *next = p->next; // Save it: p may be freed.
        if (strcmp(st_cpf(p->info), cpf) == 0)
            _unlink_and_free(l, p);
        p = next;
    }
}

void ll_clear(LinkedList *l)
{
    while (l->first != NULL)
        _unlink_and_free(l, l->first);
}

// Returns the NODE of the student whose name comes first alphabetically (NULL if l is empty).
// Returning the node (not the student) lets the caller keep walking or unlink from there.
static ListNode *_first_by_name(LinkedList *l)
{
    if (l->first == NULL)
        return NULL;
    ListNode *best = l->first; // Best candidate so far.
    for (ListNode *p = l->first->next; p != NULL; p = p->next)
        if (strcmp(st_name(p->info), st_name(best->info)) < 0)
            best = p;
    return best;
}

Student *ll_first_by_name(LinkedList *l)
{
    ListNode *node = _first_by_name(l);
    return node == NULL ? NULL : node->info;
}

void ll_free(LinkedList *l)
{
    ListNode *p = l->first;
    ListNode *t;
    while (p != NULL)
    {
        t = p->next;   // Saved before free(p): p->next cannot be read afterwards.
        st_free(p->info);
        free(p);
        p = t;
    }
    free(l);
}

void ll_print(LinkedList *l)
{
    for (ListNode *p = l->first; p != NULL; p = p->next)
    {
        st_print(p->info);
    }
    printf("\n");
}
