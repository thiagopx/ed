#ifndef HASH_H
#define HASH_H

#include "student.h"

// Hash table size (prime number)
#define N 101

typedef struct hash Hash;

Hash *hsh_create();
void hsh_free(Hash *tab);
Student *hsh_search(Hash *tab, int id);
void hsh_insert(Hash *tab, Student *student);

#endif