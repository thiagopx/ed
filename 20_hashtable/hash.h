// A hash table of students indexed by id, with open addressing (linear probing).

#ifndef HASH_H
#define HASH_H

#include "student.h"

// Hash table size (prime number)
#define N 101

typedef struct hash Hash;

// Returns a new empty table.
// Cost: O(N): every slot starts free.
Hash *hsh_create();

// Frees tab and every student stored in it.
// Cost: O(N).
void hsh_free(Hash *tab);

// Returns the student of tab whose id is id (NULL if there is none).
// Ownership: the student still belongs to tab.
// Cost: O(1) on average; O(N) in the worst case.
Student *hsh_search(Hash *tab, int id);

// Inserts student into tab.
// Requires: tab has a free slot.
// Ownership: tab becomes the owner of student (see hsh_free).
// Cost: O(1) on average; O(N) in the worst case.
void hsh_insert(Hash *tab, Student *student);

#endif
