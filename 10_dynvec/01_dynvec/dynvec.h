// A dynamic vector of floats: an array that doubles its capacity when it is full.

#ifndef DYNVEC_H
#define DYNVEC_H

typedef struct dynvec DynVec;

// Returns a new empty vector, with room for 4 elements.
DynVec *dv_create();

// Returns a new vector with the values read from the file filename (NULL if the file cannot
//   be opened).
// Cost: O(n).
DynVec *dv_create_from_file(const char *filename);

// Inserts x at the end of dv, doubling the capacity first if dv is full (amortized O(1)).
void dv_insert(DynVec *dv, float x);

// Checks whether x is in dv; returns 1 if it is, 0 otherwise.
// Cost: O(n).
int dv_is_in(DynVec *dv, float x);

// Returns the value at index i of dv.
// Requires: 0 <= i < dv_size(dv).
float dv_get(DynVec *dv, int i);

// Returns the number of elements of dv.
int dv_size(DynVec *dv);

// Returns the capacity of dv: how many elements fit before the next resize.
int dv_capacity(DynVec *dv);

// Frees dv.
void dv_free(DynVec *dv);

// Prints the values of dv.
// Cost: O(n).
void dv_print_values(DynVec *dv);

// Writes the values of dv to the file filename.
// Cost: O(n).
void dv_write_to_file(DynVec *dv, const char *filename);

// Returns a new vector with the values of dv1 followed by those of dv2.
// Cost: O(n1 + n2).
DynVec *dv_concatenate(DynVec *dv1, DynVec *dv2);

// Returns a new vector with the union of the values of dv1 and dv2.
// Cost: O((n1 + n2)^2).
DynVec *dv_union(DynVec *dv1, DynVec *dv2);

// Returns a new vector with the values that are both in dv1 and in dv2.
// Cost: O(n1 * n2).
DynVec *dv_intersection(DynVec *dv1, DynVec *dv2);

// Returns a new vector with a single occurrence of each value of dv.
// Cost: O(n^2).
DynVec *dv_unique(DynVec *dv);

#endif
