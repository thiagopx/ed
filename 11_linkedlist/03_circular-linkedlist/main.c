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

    printf("------------\n\n");

    // Josephus: remove every 3rd node until one is left
    printf("Josephus with 7 people, removing every 3rd\n");
    LinkedList *circle = ll_create();
    for (int i = 7; i >= 1; i--)
        ll_insert(circle, i); // Inserting at the start in reverse gives 1 2 3 4 5 6 7.
    ll_print(circle);
    printf("Removed in this order: ");
    int survivor = ll_josephus(circle, 3);
    printf("Survivor: %d\n", survivor);
    ll_print(circle);

    ll_free(l);
    ll_free(one);
    ll_free(circle);

    return 0;
}
