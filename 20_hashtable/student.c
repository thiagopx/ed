#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "student.h"

struct student
{
   int id;
   char name[81];
   char email[43];
   char class;
};

Student *st_create(int id, const char *name, const char *email, char class)
{
   Student *student = (Student *)malloc(sizeof(Student));
   student->id = id;
   strcpy(student->name, name);
   strcpy(student->email, email);
   student->class = class;
   return student;
}

int st_get_id(Student *student)
{
   return student->id;
}
char *st_get_name(Student *student)
{
   return student->name;
}

char *st_get_email(Student *student)
{
   return student->email;
}

char st_get_class(Student *student)
{
   return student->class;
}

void st_print(Student *student)
{
   printf("%-10s %-20s (%d) - %c\n", student->name, student->email, student->id, student->class);
}

void st_free(Student *student)
{
   free(student); // No field of Student is allocated separately: one free releases it.
}
