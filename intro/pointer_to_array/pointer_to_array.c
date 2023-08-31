#include <stdio.h>

int main()
{
    int numbers[] = {10, 20, 30, 40, 50};
    int *ptr = numbers; // Pointer pointing to the first element

    int size =
        sizeof(numbers) / sizeof(numbers[0]); // Calculate the size of the array

    // printf("Array elements using pointer:\n");
    // for (int i = 0; i < size; ++i) {
    //   printf("%d ", *ptr); // Print the value pointed to by the pointer
    //   ptr++;               // Move the pointer to the next element
    // }

    printf("Array elements using pointer:\n");
    for (int i = 0; i < size; ++i)
    {
        // printf("%d ", ptr[i]); // Print the value pointed to by the pointer
        printf("%d ", *(ptr + i)); // Print the value pointed to by the pointer
    }

    printf("\n");

    return 0;
}
