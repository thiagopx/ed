// A dynamic vector of teams: a growable array of Team pointers.

#ifndef TEAMVEC_H
#define TEAMVEC_H

#include "team.h"

typedef struct teamvec TeamVec;

// Returns a new empty vector, with a small initial capacity (e.g., 4 teams).
TeamVec *tv_create(void);

// Inserts the team t at the end of tv, doubling the capacity (realloc) first if tv is full.
// Ownership: tv becomes the owner of t (see tv_free).
void tv_insert(TeamVec *tv, Team *t);

// Returns the number of teams stored in tv.
int tv_size(TeamVec *tv);

// Returns the team at position i of tv.
// Requires: 0 <= i < tv_size(tv).
// Ownership: the team still belongs to tv.
Team *tv_get(TeamVec *tv, int i);

// Frees each team stored in tv, the internal array and then tv itself.
// Cost: O(n).
void tv_free(TeamVec *tv);

#endif
