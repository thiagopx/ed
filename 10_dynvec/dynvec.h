#ifndef DYNVEC_H
#define DYNVEC_H

// Define a forward declaration for a structure called 'dynvec.'
typedef struct dynvec DynVec;

// Function prototypes.

// Create a new dynamic vector and return a pointer to it.
DynVec *dv_create();

// Create a new dynamic vector from a file and return a pointer to it.
DynVec *dv_create_from_file(const char *filename);

// Insert a float value into the dynamic vector.
void dv_insert(DynVec *dv, float x);

// Verify if a value is in the dynamic vector.
int dv_is_in(DynVec *dv, float x);

// Get the value at a specific index 'i' in the dynamic vector.
float dv_get(DynVec *dv, int i);

// Get the current size (number of elements) of the dynamic vector.
int dv_size(DynVec *dv);

// Get the current capacity (maximum number of elements without resizing) of the dynamic vector.
int dv_capacity(DynVec *dv);

// Free the memory associated with the dynamic vector.
void dv_free(DynVec *dv);

// Print the values of the dynamic vector.
void dv_print_values(DynVec *dv);

// Write the contents of the dynamic vector to a file.
void dv_write_to_file(DynVec *dv, const char *filename);

// Concatenate two dynamic vectors and return a new dynamic vector.
DynVec *dv_concatenate(DynVec *dv1, DynVec *dv2);

// Find the union of two dynamic vectors and return a new dynamic vector.
DynVec *dv_union(DynVec *dv1, DynVec *dv2);

// Find the intersection of two dynamic vectors and return a new dynamic vector.
DynVec *dv_intersection(DynVec *dv1, DynVec *dv2);

// Return a new dynamic vector with a unique ocurrence or each element
DynVec *dv_unique(DynVec *dv);

// End of the conditional compilation directives.
#endif
