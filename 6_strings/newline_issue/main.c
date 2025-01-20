#include <stdio.h>

int main()
{
    char user_char;
    printf("Please enter a character: ");
    scanf(" %c", &user_char);
    printf("You entered: %c\n", user_char);

    char user_string[100];
    printf("Please enter a string: ");
    scanf(" %99[^\n]", user_string);
    printf("You entered: %s\n", user_string);

    return 0;
}