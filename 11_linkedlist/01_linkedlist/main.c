#include "linkedlist.h"
#include <stdio.h>

int main(void)
{
    printf("Create a list with 10 elements\n");
    LinkedList *l = ll_create();
    for (int i = 0; i < 10; i++)
        ll_insert(l, i); // Each value goes to the beginning: the list ends up reversed.
    ll_print(l);
    printf("------------\n\n");

    printf("Removing 0 (the last node), 9 (the first) and 42 (absent)\n");
    printf("ll_remove(l, 0) = %d\n", ll_remove(l, 0));
    printf("ll_remove(l, 9) = %d\n", ll_remove(l, 9));
    printf("ll_remove(l, 42) = %d\n", ll_remove(l, 42));
    ll_print(l);
    printf("------------\n\n");

    printf("Checking which values are in the list\n");
    int values[5] = {-1, 0, 4, 5, 10};
    for (int i = 0; i < 5; i++)
        if (ll_is_in(l, values[i]))
            printf("%d is in the list.\n", values[i]);
        else
            printf("%d is NOT in the list.\n", values[i]);
    printf("------------\n\n");

    printf("Is the list empty? %s\n", ll_is_empty(l) ? "yes" : "no");
    ll_free(l);
    return 0;
}
