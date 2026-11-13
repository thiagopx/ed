#include "linkedlist.h"
#include "student.h"
#include "professor.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct list
{
    int count;
    ListNode *first;
    ListNode *last;
};

struct list_node
{
    NodeType type; // Says how to read info.
    void *info;    // The record: a Student * or a Professor *.
    ListNode *prev;
    ListNode *next;
};

// Only these three helpers know the types stored in the list.

// Prints the record of p according to its type.
static void _print(ListNode *p)
{
    if (p->type == TYPE_STUDENT)
        st_print((Student *)p->info);
    else
        pr_print((Professor *)p->info);
}

// Returns the CPF of the record of p: the type decides how to read the void *.
static const char *_cpf(ListNode *p)
{
    if (p->type == TYPE_STUDENT)
        return st_cpf((Student *)p->info);
    return pr_cpf((Professor *)p->info);
}

// Frees the record of p with the function of its own TAD.
static void _free_record(ListNode *p)
{
    if (p->type == TYPE_STUDENT)
        st_free((Student *)p->info);
    else
        pr_free((Professor *)p->info);
}

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

void ll_print(LinkedList *l)
{
    for (ListNode *p = l->first; p != NULL; p = p->next)
        _print(p);
    printf("\n");
}

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

// Returns the node whose record has this cpf (NULL if there is none).
static ListNode *_search(LinkedList *l, const char *cpf)
{
    ListNode *p = l->first;
    while (p != NULL && strcmp(_cpf(p), cpf) != 0)
        p = p->next;
    return p;
}

int ll_is_in(LinkedList *l, const char *cpf)
{
    return _search(l, cpf) != NULL;
}

// Unlinks node p from l; if free_record is set, also frees the record it points to.
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
        _free_record(p);
    free(p);
    l->count--;
}

void ll_remove(LinkedList *l, const char *cpf)
{
    ListNode *p = _search(l, cpf);
    if (p != NULL)
        _unlink(l, p, 1);
}

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

void ll_clear(LinkedList *l)
{
    while (l->first != NULL)
        _unlink(l, l->first, 1);
}

// Returns the node at position pos (0-based), or NULL if pos is out of range.
// Cost: O(pos): there is no index.
static ListNode *_at(LinkedList *l, int pos)
{
    if (pos < 0 || pos >= l->count)
        return NULL;
    ListNode *p = l->first;
    for (int i = 0; i < pos; i++)
        p = p->next;
    return p;
}

NodeType ll_type_at(LinkedList *l, int pos)
{
    return _at(l, pos)->type;
}

LinkedList *ll_professors(LinkedList *l)
{
    LinkedList *r = ll_create();
    for (ListNode *p = l->first; p != NULL; p = p->next)
        if (p->type == TYPE_PROFESSOR)
            ll_append(r, p->info, p->type); // Same pointer: no record is copied.
    return r;
}

void ll_free_nodes(LinkedList *l)
{
    while (l->first != NULL)
        _unlink(l, l->first, 0);
    free(l);
}

void ll_free(LinkedList *l)
{
    ll_clear(l);
    free(l);
}
