#include "linkedlist.h"
#include <stdio.h>

int main(void)
{
    // Appending without walking the list
    printf("Appending 1 to 5 (each append is O(1))\n");
    LinkedList *l = ll_create();
    for (int i = 1; i <= 5; i++)
        ll_append(l, i);
    ll_print(l);
    printf("------------\n\n");

    // Removing the last node must move 'last'
    printf("Removing 5 (the last node), then appending 6\n");
    ll_remove(l, 5);
    ll_append(l, 6); // Would be lost if 'last' still pointed to the freed node.
    ll_print(l);
    printf("------------\n\n");

    // Joining two lists in O(1)
    printf("Joining [10 20] at the end of the list\n");
    LinkedList *other = ll_create();
    ll_append(other, 10);
    ll_append(other, 20);
    ll_join(l, other);
    ll_print(l);
    printf("other is empty? %d\n", ll_is_empty(other));
    ll_join(other, l); // Joining into an empty list: it takes the whole chain.
    printf("after joining l into the empty list: ");
    ll_print(other);
    printf("l is empty? %d\n", ll_is_empty(l));
    printf("------------\n\n");

    // Merging two sorted lists by moving nodes
    printf("Merging [1 4 9] and [2 3 10 12]\n");
    LinkedList *a = ll_create();
    LinkedList *b = ll_create();
    int va[3] = {1, 4, 9}, vb[4] = {2, 3, 10, 12};
    for (int i = 0; i < 3; i++)
        ll_append(a, va[i]);
    for (int i = 0; i < 4; i++)
        ll_append(b, vb[i]);
    LinkedList *m = ll_merge_sorted(a, b);
    ll_print(m);
    printf("a empty? %d, b empty? %d\n", ll_is_empty(a), ll_is_empty(b));

    ll_free(l);
    ll_free(other);
    ll_free(a);
    ll_free(b);
    ll_free(m);
    return 0;
}
