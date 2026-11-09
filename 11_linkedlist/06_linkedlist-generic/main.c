#include "linkedlist.h" // Include the user-defined header file for the list data structure.
#include "student.h"
#include "professor.h"
#include <stdio.h>

int main(void)
{
    LinkedList *l; // Declare a pointer to a linked list.

    Student *s1 = st_create("Rodrigo", "12345678912", COURSE_BSI);
    Student *s2 = st_create("Rafael", "09876554321", COURSE_ECA);
    Professor *p1 = pr_create("Thiago", "01812356768", DEPT_INF);
    Professor *p2 = pr_create("Ronnald", "64938467201", DEPT_ENG);

    // Create a list: from now on, the list owns these four records
    printf("Create a list\n");
    l = ll_create(); // Create an empty linked list and assign its pointer to 'l'.
    ll_insert(l, s1, TYPE_STUDENT);
    ll_insert(l, p2, TYPE_PROFESSOR);
    ll_insert(l, p1, TYPE_PROFESSOR);
    ll_insert(l, s2, TYPE_STUDENT);
    ll_print(l);
    printf("------------\n\n");

    // The type of each position: the list knows it, the compiler does not
    printf("Element at position 1 is a %s\n", ll_type_at(l, 1) == TYPE_PROFESSOR ? "professor" : "student");
    printf("------------\n\n");

    // A list that only points to the professors (shallow copy)
    printf("Only the professors (same records, new nodes)\n");
    LinkedList *profs = ll_professors(l);
    ll_print(profs);
    ll_free_nodes(profs); // Frees the nodes only: the records still belong to l.
    printf("------------\n\n");

    // Search and removal by CPF (the removed record is freed by the list)
    printf("Is CPF 64938467201 in the list? %d\n", ll_is_in(l, "64938467201"));
    printf("Removing CPF 64938467201\n");
    ll_remove(l, "64938467201");
    ll_print(l);
    printf("------------\n\n");

    // Remove every record with a CPF, then clear the list
    ll_append(l, st_create("Rodrigo (2nd enrollment)", "12345678912", COURSE_ECA), TYPE_STUDENT);
    ll_remove_all(l, "12345678912"); // Removes and frees both records with this CPF.
    printf("After removing every 12345678912: %d records\n", ll_size(l));
    ll_clear(l);
    printf("After clearing: empty? %d\n", ll_is_empty(l));

    ll_free(l); // Frees nodes, structure and the records the list owns.
    return 0;   // Return 0 to indicate successful program execution.
}
