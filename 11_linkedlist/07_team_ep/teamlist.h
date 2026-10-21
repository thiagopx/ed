#ifndef TEAMLIST_H
#define TEAMLIST_H

#include "team.h"

// Opaque type: an ordered collection of teams. Which data structure stores
// them (dynamic vector or doubly linked list) is chosen in config.mk --
// code that uses this interface must work the same with either one.
typedef struct teamlist TeamList;

// Create an empty collection
TeamList *tl_create(void);

// Insert a team at the end of the collection
void tl_append(TeamList *tl, Team *t);

// Number of teams currently stored
int tl_size(TeamList *tl);

// Team at position i (0 <= i < tl_size), in insertion order
Team *tl_get(TeamList *tl, int i);

// Free the collection and every team stored in it
void tl_free(TeamList *tl);

#endif
