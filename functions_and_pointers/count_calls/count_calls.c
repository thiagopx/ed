#include <stdio.h>

// Function with a local static variable
int count_calls() {
    static int counter = 0;  // Local static variable

    counter++;  // Increment the counter
    return counter;
}

int main() {
    for (int i = 0; i < 5; i++) {
        int result = count_calls();
        printf("Function has been called %d times.\n", result);
    }

    return 0;
}
