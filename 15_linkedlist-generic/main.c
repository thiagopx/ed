#include "linkedlist.h" // Include the user-defined header file for the list data structure.
#include "student.h"
#include "professor.h"
#include <stdio.h>

int main(void)
{
    LinkedList *l; // Declare a pointer to a linked list.

    Student *s1 = st_create("Rodrigo", "12345678912", COURSE_BSI);
    Student *s2 = st_create("Rafael", "09876554321", COURSE_ECA);
    // st_print(s1);
    // st_print(s2);

    Professor *p1 = pr_create("Thiago", "018123567687", DEPT_INF);
    Professor *p2 = pr_create("Ronnald", "64938467201", DEPT_ENG);
    // pr_print(p1);
    // pr_print(p2);

    // Create a list
    printf("Create a list\n");
    l = ll_create(); // Create an empty linked list and assign its pointer to 'l'.
    ll_insert(l, s1, TYPE_STUDENT);
    ll_insert(l, p2, TYPE_PROFESSOR);
    ll_insert(l, p1, TYPE_PROFESSOR);
    ll_insert(l, s2, TYPE_STUDENT);

    // Print list
    ll_print(l);
    return 0; // Return 0 to indicate successful program execution.
}
