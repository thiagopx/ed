#include "my_string.h"
#include <stdio.h>

int main(void)
{
    char str1[50] = "Hello, ";
    char str2[] = "World!";

    // my_strlen
    int length = my_strlen(str1);
    printf("Length of str1: %d\n", length);

    // my_strcpy
    my_strcpy(str1, str2);
    printf("Copied string: %s\n", str1);

    // my_strcat
    char str3[50] = "Hello, ";
    my_strcat(str3, str2);
    printf("Concatenated string: %s\n", str3);

    // my_strcmp
    int result = my_strcmp("apple", "banana");
    if (result == 0)
        printf("Strings are equal\n");
    else if (result < 0)
        printf("str1 is less than str2\n");
    else
        printf("str1 is greater than str2\n");

    return 0;
}
