#include <stdio.h>

int main()
{
    char user_char;

    printf("Please enter a character: ");
    scanf("%c", &user_char);
    printf("You entered: %c\n", user_char);

    printf("Please enter a character: ");
    scanf(" %c", &user_char);
    printf("You entered: %c\n", user_char);

    return 0;
}