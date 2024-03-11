#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    int number_to_guess, user_guess;
    srand(time(NULL)); // Seed the random number generator

    // Generate a random number between 1 and 100
    number_to_guess = rand() % 100 + 1;

    printf("Welcome to the Guessing Game!\n");
    printf("I have selected a number between 1 and 100. Try to guess it!\n");

    // Loop until the user guesses the correct number
    while (1)
    {
        printf("Enter your guess: ");
        scanf("%d", &user_guess);

        if (user_guess < number_to_guess)
        {
            printf("Too low! Try again.\n");
        }
        else if (user_guess > number_to_guess)
        {
            printf("Too high! Try again.\n");
        }
        else
        {
            printf("Congratulations! You guessed the correct number: %d\n", number_to_guess);
            break; // Exit the loop when the correct number is guessed
        }
    }

    return 0;
}
