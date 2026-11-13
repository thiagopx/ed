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

DynStr* ds_create_copy(const char *s) {
    DynStr *ds = (DynStr *)malloc(sizeof(DynStr));

    ds->v = NULL;
    ds_assign(ds, s);

    return ds;
}

DynStr* ds_create_empty(void) {
    return ds_create_copy("");
}

void ds_assign(DynStr *ds, const char *s) {
    reallocate(ds, strlen(s));
    strcpy(ds->v, s);
}

void ds_concat(DynStr *ds, const char *s) {
    reallocate(ds, strlen(ds->v) + strlen(s));
    strcat(ds->v, s);
}

const char* ds_get(DynStr *ds) {
    return ds->v;
}

void ds_free(DynStr *ds) {
    free(ds->v);
    free(ds);
}
