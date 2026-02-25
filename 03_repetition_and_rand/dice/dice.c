#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void roll_dice()
{
    int result = rand() % 6 + 1; // Generate a random number between 1 and 6 (like a dice roll)
    printf("You rolled a %d!\n", result);
}

int main()
{
    // Initialize the random number generator with the current time
    srand(time(NULL));

    printf("Welcome to the Virtual Dice Roll!\n");
    printf("Press Enter to roll the dice...");
    getchar();
    // Wait for Enter key press
    roll_dice();

    return 0;
}
