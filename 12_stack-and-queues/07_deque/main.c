#include "deque.h"
#include <stdio.h>

int main()
{
    Deque *d = dq_create();
    dq_push_back(d, 1);
    dq_push_back(d, 2);
    dq_print(d);
    printf("\n");

    dq_push_front(d, 3);
    dq_push_front(d, 4);
    dq_push_back(d, 5);
    dq_print(d);
    printf("\n");

    printf("Popping %.2f from the front\n", dq_pop_front(d));
    printf("Popping %.2f from the back\n\n", dq_pop_back(d));
    dq_print(d);
    printf("\n");

    printf("Popping %.2f from the back\n", dq_pop_back(d));
    printf("Popping %.2f from the back\n", dq_pop_back(d));
    printf("Popping %.2f from the back\n\n", dq_pop_back(d));
    printf("Empty: %d\n", dq_is_empty(d));

    dq_free(d);
    return 0;
}
