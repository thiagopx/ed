#include "stack.h"
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

struct stack
{
    StackNode *top; // NULL when the stack is empty.
};

struct stacknode
{
    float info;
    StackNode *next;
};

Stack *s_create()
{
    Stack *s = (Stack *)malloc(sizeof(Stack));
    s->top = NULL;
    return s;
}

int s_is_empty(Stack *s)
{
    return s->top == NULL;
}

void s_push(Stack *s, float v)
{
    StackNode *node = (StackNode *)malloc(sizeof(StackNode));
    node->info = v;
    node->next = s->top;
    s->top = node;
}

float s_top(Stack *s)
{
    assert(!s_is_empty(s));
    return s->top->info;
}

float s_pop(Stack *s)
{
    assert(!s_is_empty(s));

    float v = s->top->info;
    StackNode *p = s->top; // Saved to be freed after top moves on.
    s->top = s->top->next;
    free(p);
    return v;
}

void s_free(Stack *s)
{
    StackNode *p = s->top;
    while (p != NULL)
    {
        StackNode *t = p->next; // Saved before free(p): p->next cannot be read afterwards.
        free(p);
        p = t;
    }
    free(s);
}

void s_print(Stack *s)
{
    for (StackNode *p = s->top; p != NULL; p = p->next)
        printf("%.2f ", p->info);

    printf("\n");
}
