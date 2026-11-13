#include "professor.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

struct professor
{
   char name[50];
   char cpf[15];
   Department dept;
};

Professor *pr_create(const char *name, const char *cpf, Department dept)
{
   Professor *p = (Professor *)malloc(sizeof(Professor));
   strcpy(p->name, name);
   strcpy(p->cpf, cpf);
   p->dept = dept;

   return p;
}

void pr_print(Professor *p)
{
   // The CPF is stored as 11 digits and printed as ddd.ddd.ddd-dd.
   char cpf_block1[4];
   char cpf_block2[4];
   char cpf_block3[4];
   char cpf_block4[3];

   sscanf(p->cpf, "%3s", cpf_block1);
   sscanf(p->cpf + 3, "%3s", cpf_block2);
   sscanf(p->cpf + 6, "%3s", cpf_block3);
   sscanf(p->cpf + 9, "%2s", cpf_block4);

   char dept[10];
   if (p->dept == DEPT_INF)
      strcpy(dept, "INF");
   else
      strcpy(dept, "ENG");

   printf("Name: %-20s CPF: %s.%s.%s-%-20s Dept: %s\n", p->name, cpf_block1, cpf_block2, cpf_block3, cpf_block4, dept);
}

const char *pr_cpf(Professor *x)
{
   return x->cpf;
}

void pr_free(Professor *x)
{
   free(x); // No field of Professor is allocated separately: one free releases it.
}
