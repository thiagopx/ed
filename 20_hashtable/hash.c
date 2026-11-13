#include "hash.h"

#include <stdlib.h>
#include <string.h>

#define TABSIZE 101 // A prime size spreads the ids better over the slots.

struct hash
{
   Student *v[TABSIZE]; // NULL marks a free slot.
};

// Returns the slot where the search for id starts.
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
   for (int i = 0; i < TABSIZE; i++)
      if (tab->v[i] != NULL)
         st_free(tab->v[i]); // The table owns the students it receives.
   free(tab);
}

Student *hsh_search(Hash *tab, int id)
{
   int h = hash(id);
   while (tab->v[h] != NULL)
   {
      if (st_get_id(tab->v[h]) == id)
         return tab->v[h];
      h = (h + 1) % TABSIZE; // Linear probing: try the next slot, wrapping around.
   }

   return NULL;
}

void hsh_insert(Hash *tab, Student *student)
{
   int h = hash(st_get_id(student));

   while (tab->v[h] != NULL)
      h = (h + 1) % TABSIZE;

   tab->v[h] = student;
}
