#ifndef DYNSTR_H
#define DYNSTR_H

// Opaque dynamic string type: always holds exactly the memory needed for
// its current value, growing or shrinking as needed via realloc.
typedef struct dynstr DynStr;

// Create a new dynamic string, initially empty.
DynStr* ds_create_empty(void);

// Create a new dynamic string initialized with a copy of s.
DynStr* ds_create_copy(const char *s);

// Reassign the value of an existing dynamic string to a copy of s.
void ds_assign(DynStr *ds, const char *s);

// Append s to the end of the current value of ds.
void ds_concat(DynStr *ds, const char *s);

// Return the string currently stored (read-only: the caller must not
// modify it directly, only through ds_assign/ds_concat).
const char* ds_get(DynStr *ds);

// Free the memory associated with the dynamic string.
void ds_free(DynStr *ds);

#endif
