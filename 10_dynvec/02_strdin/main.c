#include "dynstr.h"
#include <stdio.h>

// Reads an entire text file into a dynamic string, growing it one buffer
// at a time via ds_concat -- the caller never needs to know the file size
// in advance.
DynStr* read_text(const char *filename) {
    FILE *f = fopen(filename, "rt");
    if (f == NULL)
        return NULL;

    DynStr *s = ds_create_empty();
    char buffer[64];
    while (fgets(buffer, sizeof(buffer), f) != NULL)
        ds_concat(s, buffer);

    fclose(f);
    return s;
}

int main() {
    // A dynamic string can be reassigned like a value, growing or
    // shrinking its internal buffer as needed.
    DynStr *city = ds_create_copy("Rio de Janeiro");
    printf("city = %s\n", ds_get(city));

    ds_assign(city, "Recife");
    printf("city = %s\n", ds_get(city));
    ds_free(city);

    // Reading a whole file without knowing its size ahead of time.
    DynStr *text = read_text("poem.txt");
    printf("poem =\n%s", ds_get(text));
    ds_free(text);

    return 0;
}
