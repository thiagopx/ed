#include "student.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

struct student
{
   char name[50];
   char cpf[12];
};

// Create a new Student instance and initialize its name and CPF.
Student *st_create(const char *name, const char *cpf)
{
   Student *s = (Student *)malloc(sizeof(Student));
   strcpy(s->name, name);
   strcpy(s->cpf, cpf);

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

   // Print the student's name and formatted CPF.
   printf("Name: %s \t\t CPF: %s.%s.%s-%s\n", s->name, cpf_block1, cpf_block2, cpf_block3, cpf_block4);
}
