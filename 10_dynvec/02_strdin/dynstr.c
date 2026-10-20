#include "dynstr.h"
#include <stdlib.h>
#include <string.h>

// Implementation of the type: the dynamic string only ever keeps a buffer
// exactly as large as it needs to hold the current value plus '\0'.
struct dynstr {
    char *v;
};

// Resizes the internal buffer to hold n characters plus the terminator.
static void reallocate(DynStr *ds, int n) {
    ds->v = (char *)realloc(ds->v, n + 1);
}

// Create a new dynamic string initialized with a copy of s.
DynStr* ds_create_copy(const char *s) {
    DynStr *ds = (DynStr *)malloc(sizeof(DynStr));

    ds->v = NULL;
    ds_assign(ds, s);

    return ds;
}

// Create a new dynamic string, initially empty.
DynStr* ds_create_empty(void) {
    return ds_create_copy("");
}

// Reassign the value of an existing dynamic string to a copy of s.
void ds_assign(DynStr *ds, const char *s) {
    reallocate(ds, strlen(s));
    strcpy(ds->v, s);
}

// Append s to the end of the current value of ds.
void ds_concat(DynStr *ds, const char *s) {
    reallocate(ds, strlen(ds->v) + strlen(s));
    strcat(ds->v, s);
}

// Return the string currently stored.
const char* ds_get(DynStr *ds) {
    return ds->v;
}

// Free the memory associated with the dynamic string.
void ds_free(DynStr *ds) {
    free(ds->v);
    free(ds);
}
