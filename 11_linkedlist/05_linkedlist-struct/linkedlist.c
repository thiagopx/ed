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

int ll_is_empty(LinkedList *l)
{
    return l->count == 0;
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

// Returns the node of the student whose CPF is cpf (NULL if there is none).
static ListNode *_search(LinkedList *l, const char *cpf)
{
    ListNode *p = l->first;
    while (p != NULL && strcmp(st_cpf(p->info), cpf) != 0) // Compare strings, not pointers.
        p = p->next;
    return p;
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
