#include <stdio.h>
#include <stdlib.h>

int main()
{
    FILE *input_file_1 = fopen("vector_1.txt", "r");
    FILE *input_file_2 = fopen("vector_2.txt", "r");
    FILE *output_file = fopen("sum_vector.txt", "w"); // w means writting

    if (input_file_1 == NULL || input_file_2 == NULL || output_file == NULL)
    {
        printf("Error opening files.\n");
        return 1;
    }

    int n1, n2;
    fscanf(input_file_1, "%d", &n1); // Read the size of the vectors
    fscanf(input_file_2, "%d", &n2);

    if (n1 != n2)
    {
        printf("Error: n1 and n2 should be equal.");
        return 1;
    }

    // Dynamically allocate memory for the vectors
    int *vector_1 = (int *)malloc(n1 * sizeof(int));
    int *vector_2 = (int *)malloc(n1 * sizeof(int));
    int *sum_vector = (int *)malloc(n1 * sizeof(int));

    if (vector_1 == NULL || vector_2 == NULL || sum_vector == NULL)
    {
        printf("Memory allocation failed.\n");
        return 1;
    }

    // Read the elements of the first vector
    for (int i = 0; i < n1; i++)
    {
        fscanf(input_file_1, "%d", &vector_1[i]);
    }

    // Read the elements of the second vector
    for (int i = 0; i < n2; i++)
    {
        fscanf(input_file_2, "%d", &vector_2[i]);
    }

    // Calculate the sum of the vectors
    for (int i = 0; i < n1; i++)
    {
        sum_vector[i] = vector_1[i] + vector_2[i];
    }

    // Write the sum_vector to the output file
    fprintf(output_file, "%d\n", n1); // Write the size of the sum vector
    for (int i = 0; i < n1; i++)
    {
        fprintf(output_file, "%d ", sum_vector[i]);
    }

    // Free dynamically allocated memory
    free(vector_1);
    free(vector_2);
    free(sum_vector);

    // Close the files
    fclose(input_file_1);
    fclose(input_file_2);
    fclose(output_file);

    printf("Sum of vectors has been written to sum_vector.txt.\n");

    return 0;
}
