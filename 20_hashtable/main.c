#include <stdio.h>

#include "hash.h"
#include "student.h"

int main(void)
{
   Student *student1 = st_create(123450, "Maria", "maria@email.com", 'A');
   Student *student2 = st_create(123451, "Joao", "joao@email.com", 'B');

   Hash *tab = hsh_create();

   hsh_insert(tab, student1);
   hsh_insert(tab, student2);

   int ids[] = {123450, 123451, 123452};

   Student *student;
   for (int i = 0; i < 3; i++)
   {
      student = hsh_search(tab, ids[i]);
      if (student)
         st_print(student);
      else
         printf("Record '%d' not found.\n", ids[i]);
   }

   hsh_free(tab);

   return 0;
}
