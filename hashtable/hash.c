#include "hash.h"

#include <stdlib.h>
#include <string.h>

// Hash table size (prime number)
#define TABSIZE 101

// Hash table
struct hash
{
   Student *v[TABSIZE];
};

// hash function
static int hash(int id)
{
   return id % TABSIZE;
}

Hash *hsh_create()
{
   Hash *tab = (Hash *)malloc(sizeof(Hash));

   for (int i = 0; i < TABSIZE; i++)
      tab->v[i] = NULL;

   return tab;
}

void hsh_free(Hash *tab)
{
   // free entries
   for (int i = 0; i < TABSIZE; i++)
      free(tab->v[i]);

   // free the structure
   free(tab);
}

Student *hsh_search(Hash *tab, int id)
{
   // search by id
   int h = hash(id);
   while (tab->v[h] != NULL)
   {
      if (st_get_id(tab->v[h]) == id)
         return tab->v[h];
      h = (h + 1) % TABSIZE;
   }

   return NULL;
}

void hsh_insert(Hash *tab, Student *student)
{
   // hashing
   int h = hash(st_get_id(student));

   // search for the next free position
   while (tab->v[h] != NULL)
      h = (h + 1) % TABSIZE;

   // new record
   // Student *student = (Student *)malloc(sizeof(Student));
   // student->id = id;
   // strcpy(student->name, name);
   // strcpy(student->email, email);
   // student->class = class;

   // insert the new record
   tab->v[h] = student;
}
