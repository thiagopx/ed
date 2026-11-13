// A dynamic string: always holds exactly the memory needed for its current value, growing or
// shrinking as needed via realloc.

#ifndef DYNSTR_H
#define DYNSTR_H

typedef struct dynstr DynStr;

// Returns a new empty dynamic string.
DynStr* ds_create_empty(void);

// Returns a new dynamic string with a copy of s.
// Cost: O(len(s)).
DynStr* ds_create_copy(const char *s);

// Replaces the value of ds by a copy of s.
// Cost: O(len(s)).
void ds_assign(DynStr *ds, const char *s);

// Appends s to the end of the value of ds.
// Cost: O(len(ds) + len(s)): realloc may copy the current value to a new block.
void ds_concat(DynStr *ds, const char *s);

// Returns the string stored in ds (read-only: change it only through ds_assign/ds_concat).
const char* ds_get(DynStr *ds);

// Frees ds.
void ds_free(DynStr *ds);

#endif
