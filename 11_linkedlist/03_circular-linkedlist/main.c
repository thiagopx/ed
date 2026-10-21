#include "linkedlist.h"
#include <stdio.h>

int main(void)
{
    // Create a circular list with 5 elements
    printf("Create a circular list with 5 elements\n");
    LinkedList *l = ll_create();
    for (int i = 1; i <= 5; i++)
        ll_insert(l, i);
    ll_print(l);
    printf("There are %d elements in the list.\n", ll_size(l));
    printf("------------\n\n");

    // There is no real first or last: any node can be the start
    printf("Rotating the start of the list\n");
    for (int i = 0; i < 5; i++)
    {
        ll_rotate(l);
        ll_print(l);
    }
    printf("------------\n\n");

    // A single node points to itself
    printf("A list with one element\n");
    LinkedList *one = ll_create();
    ll_insert(one, 42);
    ll_print(one);
    ll_rotate(one);
    ll_print(one);

    ll_free(l);
    ll_free(one);

    return 0;
}
