#include "student.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

struct student
{
   char name[50];
   char cpf[12];
};

Student *st_create(const char *name, const char *cpf)
{
   Student *s = (Student *)malloc(sizeof(Student));
   strcpy(s->name, name);
   strcpy(s->cpf, cpf);

   return s;
}

void st_print(Student *s)
{
   // The CPF is stored as 11 digits and printed as ddd.ddd.ddd-dd.
   char cpf_block1[4];
   char cpf_block2[4];
   char cpf_block3[4];
   char cpf_block4[3];

   sscanf(s->cpf, "%3s", cpf_block1);
   sscanf(s->cpf + 3, "%3s", cpf_block2);
   sscanf(s->cpf + 6, "%3s", cpf_block3);
   sscanf(s->cpf + 9, "%2s", cpf_block4);

   printf("Name: %s \t\t CPF: %s.%s.%s-%s\n", s->name, cpf_block1, cpf_block2, cpf_block3, cpf_block4);
}

const char *st_name(Student *s)
{
   return s->name;
}

const char *st_cpf(Student *s)
{
   return s->cpf;
}

void st_free(Student *s)
{
   free(s); // No field of Student is allocated separately: one free releases it.
}
