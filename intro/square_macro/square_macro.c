#include <stdio.h>

// Define a macro to calculate the square of a number
#define SQUARE(x) ((x) * (x))

int main() {
    int num = 5;
    int squared = SQUARE(num);

    printf("The square of %d is %d\n", num, squared);

    return 0;
}
