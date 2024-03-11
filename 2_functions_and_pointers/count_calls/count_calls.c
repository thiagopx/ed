#include <stdio.h>

// Function with a local static variable
int count_calls()
{
    static int counter = 0; // Local static variable

    counter++; // Increment the counter
    return counter;
}

int main()
{
    printf("Function has been called %d times.\n", count_calls());
    printf("Function has been called %d times.\n", count_calls());
    printf("Function has been called %d times.\n", count_calls());
    printf("Function has been called %d times.\n", count_calls());
    printf("Function has been called %d times.\n", count_calls());

    return 0;
}
