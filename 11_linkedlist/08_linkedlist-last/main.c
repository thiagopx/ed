#include "linkedlist.h"
#include <stdio.h>

int main(void)
{
    printf("Appending 1 to 5 (each append is O(1))\n");
    LinkedList *l = ll_create();
    for (int i = 1; i <= 5; i++)
        ll_append(l, i);
    ll_print(l);
    printf("------------\n\n");

    printf("Inserting 0 at the beginning\n");
    ll_insert(l, 0);
    ll_print(l);
    printf("------------\n\n");

    printf("Removing 5 (the last node), then appending 6\n");
    ll_remove(l, 5);
    ll_append(l, 6); // Would be lost if 'last' still pointed to the freed node.
    ll_print(l);
    printf("------------\n\n");

    printf("Is the list empty? %s\n", ll_is_empty(l) ? "yes" : "no");
    ll_free(l);
    return 0;
}
