#ifndef STACK_H
#define STACK_H

typedef struct stack Stack;

Stack *s_create();

float s_pop(Stack *q);

float s_top(Stack *q);

void s_push(Stack *s, float v);

int s_is_empty(Stack *s);

void s_free(Stack *s);

void s_print(Stack *s);

#endif
