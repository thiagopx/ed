#include <stdio.h>

int main()
{

    /* First C program */

    /* Declarations: All variables used need to be declared */
    int age;

    /* Start of the program */
    printf("How old are you?: ");
    scanf("%d", &age);

    printf("%d? Wow, you look like you're only %d years old!\n", age, age * 2);

    /* End of the program */

    return 0;
}
