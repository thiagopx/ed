#include "linkedlist.h"
#include <stdio.h>

int main(void)
{
    printf("Create a list of students\n");
    LinkedList *l = ll_create();
    ll_insert(l, "João", "12345678910");
    ll_insert(l, "José", "18756423409");
    ll_insert(l, "Bianca", "99988877766");
    ll_print(l);
    printf("------------\n\n");

    printf("Removing CPF 18756423409 (the list frees the student too)\n");
    ll_remove(l, "18756423409");
    ll_print(l);
    printf("------------\n\n");

    printf("Is the list empty? %s\n", ll_is_empty(l) ? "yes" : "no");
    ll_free(l); // Frees the list, its nodes and the students they store.
    return 0;
}
