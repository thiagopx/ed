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

int ll_is_empty(LinkedList *l)
{
    return l->count == 0;
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

// Returns the node whose record has this cpf (NULL if there is none).
static ListNode *_search(LinkedList *l, const char *cpf)
{
    ListNode *p = l->first;
    while (p != NULL && strcmp(_cpf(p), cpf) != 0)
        p = p->next;
    return p;
}

// Unlinks node p from l and frees it together with the record it points to.
static void _unlink(LinkedList *l, ListNode *p)
{
    if (p == l->first)
        l->first = p->next;
    else
        p->prev->next = p->next;

    if (p == l->last)
        l->last = p->prev;
    else
        p->next->prev = p->prev;

    _free_record(p);
    free(p);
    l->count--;
}

void ll_remove(LinkedList *l, const char *cpf)
{
    ListNode *p = _search(l, cpf);
    if (p != NULL)
        _unlink(l, p);
}

void ll_free(LinkedList *l)
{
    while (l->first != NULL)
        _unlink(l, l->first);
    free(l);
}
