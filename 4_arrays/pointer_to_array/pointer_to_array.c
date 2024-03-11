#include <stdio.h>

// Try this code with the line below uncommented.
#define PRINT_ADDRESS

// Compiling this code: gcc -o your_program_name your_source_file.c -DPRINT_ADDRESS

int main()
{
    int numbers[] = {10, 20, 30, 40, 50};
    int *ptr = numbers; // Pointer pointing to the first element

    int size =
        sizeof(numbers) / sizeof(numbers[0]); // Calculate the size of the array

    printf("Array elements using pointer (version 1):\n");
    for (int i = 0; i < size; ++i)
    {
        // printf("%d ", ptr[i]); // Print the value pointed to by the pointer
        printf("%d ", *(ptr + i)); // Print the value pointed to by the pointer
#ifdef PRINT_ADDRESS
        printf("(address stored in ptr: %p)\n", (void *)ptr);
#endif
    }

    printf("\n");
    printf("Array elements using pointer (version 2):\n");
    for (int i = 0; i < size; ++i)
    {
        printf("%d ", *ptr); // Print the value pointed to by the pointer
        ptr++;               // Move the pointer to the next element
#ifdef PRINT_ADDRESS
        printf("(address stored in ptr: %p)\n", (void *)ptr);
#endif
    }

    return 0;
}
