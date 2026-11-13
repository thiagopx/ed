// An ordered collection of teams. Which data structure stores them (dynamic vector or doubly
// linked list) is chosen in config.mk; code that uses this interface works the same with either.

#ifndef TEAMLIST_H
#define TEAMLIST_H

#include "team.h"

typedef struct teamlist TeamList;

// Returns a new empty collection.
TeamList *tl_create(void);

// Appends the team t to the end of tl.
// Ownership: tl becomes the owner of t (see tl_free).
void tl_append(TeamList *tl, Team *t);

// Returns the number of teams stored in tl.
int tl_size(TeamList *tl);

// Returns the team at position i of tl, in insertion order.
// Requires: 0 <= i < tl_size(tl).
// Ownership: the team still belongs to tl.
Team *tl_get(TeamList *tl, int i);

// Frees tl and every team stored in it.
// Cost: O(n).
void tl_free(TeamList *tl);

#endif
