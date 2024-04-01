#include "dynvec.h" // Include the header file for the DynVec data structure
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

// Define the structure for the dynamic vector
struct dynvec
{
   int n;     // number of elements
   int n_max; // vector capacity
   float *v;  // vector data
};

// Function to create a new dynamic vector
DynVec *dv_create()
{
   DynVec *dv = (DynVec *)malloc(sizeof(DynVec)); // Allocate memory for the DynVec structure

   dv->n = 0;                                          // Initialize the number of elements to 0
   dv->n_max = 4;                                      // Allocate initially space for 4 elements
   dv->v = (float *)malloc(dv->n_max * sizeof(float)); // Allocate memory for the vector data

   return dv; // Return a pointer to the created dynamic vector
}

// Function to create a new dynamic vector from a file
DynVec *dv_create_from_file(const char *filename)
{
   FILE *f = fopen(filename, "rt"); // Open the file for reading
   if (f == NULL)
      return NULL; // Return NULL if the file cannot be opened

   // Create a new dynamic vector
   DynVec *dv = dv_create();
   float x;
   while (fscanf(f, "%f", &x) == 1) // Read and insert values from the file into the dynamic vector
      dv_insert(dv, x);

   fclose(f); // Close the file
   return dv; // Return a pointer to the created dynamic vector
}

// Helper function to reallocate memory for the dynamic vector
static void reallocate(DynVec *dv)
{
   dv->n_max *= 2;                                             // Double the capacity
   dv->v = (float *)realloc(dv->v, dv->n_max * sizeof(float)); // Reallocate memory for the vector data
}

// Function to insert a float value into the dynamic vector
void dv_insert(DynVec *dv, float x)
{
   // Check if the capacity is enough, and if not, reallocate memory
   if (dv->n == dv->n_max)
      reallocate(dv);

   dv->v[dv->n++] = x; // Insert the value and increment the size
}

// Function to get the current size (number of elements) of the dynamic vector
int dv_size(DynVec *dv)
{
   return dv->n;
}

// Function to get the current capacity (maximum number of elements without resizing) of the dynamic vector
int dv_capacity(DynVec *dv)
{
   return dv->n_max;
}

// Function to get the value at a specific index 'i' in the dynamic vector
float dv_get(DynVec *dv, int i)
{
   assert(i >= 0 && i < dv->n); // Runtime assertion to ensure 'i' is within valid bounds

   return dv->v[i];
}

// Function to free the memory associated with the dynamic vector
void dv_free(DynVec *dv)
{
   free(dv->v); // Free the data vector
   free(dv);    // Free the ADT
}

// Function to print the values of the dynamic vector
void dv_print_values(DynVec *dv)
{
   for (int i = 0; i < dv_size(dv); i++) // Iterate through the elements of the dynamic vector
      printf("%f ", dv_get(dv, i));
   printf("\n");
}

DynVec *dv_concatenate(DynVec *dv1, DynVec *dv2)
{
   DynVec *dv = dv_create();

   for (int i = 0; i < dv_size(dv1); i++)
   {
      float v = dv_get(dv1, i);
      dv_insert(dv, v);
   }

   for (int i = 0; i < dv_size(dv2); i++)
   {
      float v = dv_get(dv2, i);
      dv_insert(dv, v);
   }

   return dv;
}
