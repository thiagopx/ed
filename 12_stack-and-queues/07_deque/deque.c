#include "deque.h"
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

struct deque
{
    DequeNode *head;
    DequeNode *tail;
};

// A doubly linked node: prev is what makes removing from the end efficient.
struct deque_node
{
    float info;
    DequeNode *prev;
    DequeNode *next;
};

Deque *dq_create()
{
    Deque *d = (Deque *)malloc(sizeof(Deque));
    d->head = d->tail = NULL;
    return d;
}

int dq_is_empty(Deque *d)
{
    return d->head == NULL;
}

void dq_push_front(Deque *d, float v)
{
    DequeNode *node = (DequeNode *)malloc(sizeof(DequeNode));
    node->info = v;
    node->prev = NULL;
    node->next = d->head;
    if (dq_is_empty(d))
        d->tail = node;
    else
        d->head->prev = node;
    d->head = node;
}

void dq_push_back(Deque *d, float v)
{
    DequeNode *node = (DequeNode *)malloc(sizeof(DequeNode));
    node->info = v;
    node->next = NULL;
    node->prev = d->tail;
    if (dq_is_empty(d))
        d->head = node;
    else
        d->tail->next = node;
    d->tail = node;
}

float dq_pop_front(Deque *d)
{
    assert(!dq_is_empty(d));
    DequeNode *t = d->head;
    float v = t->info;
    d->head = t->next;
    if (d->head == NULL) // the deque became empty
        d->tail = NULL;
    else
        d->head->prev = NULL;
    free(t);
    return v;
}

float dq_pop_back(Deque *d)
{
    assert(!dq_is_empty(d));
    DequeNode *t = d->tail;
    float v = t->info;
    d->tail = t->prev; // No walk: prev gives the new last node.
    if (d->tail == NULL) // the deque became empty
        d->head = NULL;
    else
        d->tail->next = NULL;
    free(t);
    return v;
}

void dq_free(Deque *d)
{
    DequeNode *p = d->head;
    while (p != NULL)
    {
        DequeNode *t = p->next; // Saved before free(p): p->next cannot be read afterwards.
        free(p);
        p = t;
    }
    free(d);
}

void dq_print(Deque *d)
{
    for (DequeNode *p = d->head; p != NULL; p = p->next)
        printf("%.2f ", p->info);
    printf("\n");
}
