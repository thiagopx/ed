#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LENGTH 100
#define NUM_STUDENTS 5

// Function to duplicate a string
char *duplicate_string(const char *s)
{
    char *d = (char *)malloc(strlen(s) + 1);

    if (d == NULL)
    {
        perror("memory_allocation_failed");
        exit(EXIT_FAILURE);
    }

    strcpy(d, s);
    return d;
}

int main()
{
    char *student_names[NUM_STUDENTS];

    printf("Enter names of %d students:\n", NUM_STUDENTS);

    for (int i = 0; i < NUM_STUDENTS; i++)
    {
        char input[MAX_NAME_LENGTH];
        printf("Student %d: ", i + 1);

        if (scanf(" %99[^\n]", input) != 1)
        {
            printf("error_reading_input\n");
            return 1;
        }

        // // Read student name
        // scanf(" %99[^\n]", input);

        // Duplicate and store the name
        student_names[i] = duplicate_string(input);
    }

    printf("\nEntered names of students:\n");
    for (int i = 0; i < NUM_STUDENTS; i++)
    {
        printf("Student_%d: %s\n", i + 1, student_names[i]);
        free(student_names[i]); // Free memory for each name
    }

    return 0;
}
