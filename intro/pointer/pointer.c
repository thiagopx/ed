#include <stdio.h>

int main()
{
    // Declare an integer variable
    int num = 42;

    // Declare a pointer to an integer
    int *ptr;

    // Assign the address of 'num' to the pointer
    ptr = &num;

    // Display the original value of 'num', the address stored in 'ptr',
    // and the value pointed to by 'ptr'
    printf("Original num value: %d\n", num);
    printf("Address stored in ptr: %p\n", (void *)ptr); // Note the typecast
    printf("Value pointed to by ptr: %d\n", *ptr);

    // Modify the value of 'num' through the pointer
    *ptr = 100;

    // Display the updated value of 'num', the address stored in 'ptr',
    // and the value pointed to by 'ptr'
    printf("Updated num value: %d\n", num);
    printf("Address stored in ptr: %p\n", (void *)ptr); // Note the typecast
    printf("Value pointed to by ptr: %d\n", *ptr);

    return 0;
}
