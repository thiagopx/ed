#include "linkedlist.h"
#include <stdio.h>

int main(void)
{
    printf("Create a circular list with 5 elements\n");
    LinkedList *l = ll_create();
    for (int i = 1; i <= 5; i++)
        ll_insert(l, i); // Each new node becomes the first; the last one points back to it.
    ll_print(l);
    printf("------------\n\n");

    printf("A list with one element: the node points to itself\n");
    LinkedList *one = ll_create();
    ll_insert(one, 42);
    ll_print(one);
    printf("------------\n\n");

    printf("Is the list empty? %s\n", ll_is_empty(l) ? "yes" : "no");
    ll_free(l);
    ll_free(one);
    return 0;
}
