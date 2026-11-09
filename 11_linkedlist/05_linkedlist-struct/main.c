#include "linkedlist.h" // Include the user-defined header file for the list data structure.
#include "student.h"
#include <stdio.h>

int main(void)
{
    LinkedList *l; // Declare a pointer to a linked list.

    // Create a list
    printf("Create a list\n");
    l = ll_create(); // Create an empty linked list and assign its pointer to 'l'.
    ll_insert(l, "João", "12345678910");
    ll_insert(l, "José", "18756423409");
    ll_append(l, "Amostradinho", "55566677788");
    ll_append(l, "Bianca", "99988877766");
    ll_print(l);

    // Search by a field of the record
    printf("Is CPF 55566677788 in the list? %d\n", ll_is_in(l, "55566677788"));
    printf("Is CPF 00000000000 in the list? %d\n", ll_is_in(l, "00000000000"));
    printf("------------\n\n");

    // The node with the first name in alphabetical order
    printf("First name in alphabetical order:\n");
    Student *s = ll_first_by_name(l);
    if (s != NULL)
        st_print(s);
    printf("------------\n\n");

    // Remove by CPF
    printf("Removing CPF 18756423409\n");
    ll_remove(l, "18756423409");
    ll_print(l);
    printf("------------\n\n");

    // Remove every student with a CPF, then clear the list
    ll_append(l, "João (2nd enrollment)", "12345678910");
    ll_remove_all(l, "12345678910"); // Removes both records with João's CPF.
    printf("After removing every 12345678910: %d students\n", ll_size(l));
    ll_print(l);
    ll_clear(l);
    printf("After clearing: empty? %d\n", ll_is_empty(l));
    printf("------------\n\n");

    ll_free(l); // Free the list, its nodes and the students they store.
    return 0; // Return 0 to indicate successful program execution.
}
