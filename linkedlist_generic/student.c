#include "student.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

struct student
{
   char name[50];
   char cpf[12];
   Course course;
};

// Create a new Student instance and initialize its name, CPF, and course.
Student *st_create(const char *name, const char *cpf, Course course)
{
   Student *s = (Student *)malloc(sizeof(Student));
   strcpy(s->name, name);
   strcpy(s->cpf, cpf);
   s->course = course;

   return s;
}

// Print the student's name and formatted CPF.
void st_print(Student *s)
{
   // Divide the CPF into four blocks for better readability.
   char cpf_block1[4];
   char cpf_block2[4];
   char cpf_block3[4];
   char cpf_block4[3];

   // Parse the CPF into four blocks.
   sscanf(s->cpf, "%3s", cpf_block1);
   sscanf(s->cpf + 3, "%3s", cpf_block2);
   sscanf(s->cpf + 6, "%3s", cpf_block3);
   sscanf(s->cpf + 9, "%2s", cpf_block4);

   // Determine the course abbreviation.
   char course[5];
   if (s->course == COURSE_BSI)
      strcpy(course, "BSI");
   else
      strcpy(course, "ECA");

   // Print the student's name, formatted CPF, and course.
   printf("Name: %-20s CPF: %s.%s.%s-%-20s Course: %s\n", s->name, cpf_block1, cpf_block2, cpf_block3, cpf_block4, course);
}
