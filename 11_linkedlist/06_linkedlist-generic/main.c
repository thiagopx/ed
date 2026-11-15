#include "linkedlist.h"
#include "student.h"
#include "professor.h"
#include <stdio.h>

int main(void)
{
    Student *s1 = st_create("Rodrigo", "12345678912", COURSE_BSI);
    Student *s2 = st_create("Rafael", "09876554321", COURSE_ECA);
    Professor *p1 = pr_create("Thiago", "01812356768", DEPT_INF);
    Professor *p2 = pr_create("Ronnald", "64938467201", DEPT_ENG);

    printf("Create a list: from now on, the list owns these four records\n");
    LinkedList *l = ll_create();
    ll_insert(l, s1, TYPE_STUDENT);
    ll_insert(l, p2, TYPE_PROFESSOR);
    ll_insert(l, p1, TYPE_PROFESSOR);
    ll_insert(l, s2, TYPE_STUDENT);
    ll_print(l);
    printf("------------\n\n");

    printf("Removing CPF 64938467201 (the list frees the record with pr_free)\n");
    ll_remove(l, "64938467201");
    ll_print(l);
    printf("------------\n\n");

    printf("Is the list empty? %s\n", ll_is_empty(l) ? "yes" : "no");
    ll_free(l); // Frees nodes, structure and the records the list owns.
    return 0;
}
