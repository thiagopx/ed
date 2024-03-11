#include <stdio.h>

// Function to calculate the length of a string (analogous to strlen)
int my_strlen(const char *str)
{
    int length = 0;

    while (str[length] != '\0')
        length++;

    return length;
}

// Function to copy one string to another (analogous to strcpy)
void my_strcpy(char *dest, const char *src)
{
    int i = 0;

    while (src[i] != '\0')
    {
        dest[i] = src[i];
        i++;
    }

    dest[i] = '\0'; // Null-terminate the destination string
}

// Function to concatenate two strings (analogous to strcat)
void my_strcat(char *dest, const char *src)
{
    int dest_len = my_strlen(dest);
    int i = 0;

    while (src[i] != '\0')
    {
        dest[dest_len + i] = src[i];
        i++;
    }

    dest[dest_len + i] = '\0'; // Null-terminate the concatenated string
}

// Function to compare two strings (analogous to strcmp)
int my_strcmp(const char *str1, const char *str2)
{
    int i;

    for (i = 0; str1[i] != '\0' && str2[i] != '\0'; ++i)
    {
        int d = str1[i] - str2[i];

        if (d != 0)
            return d;
    }

    return (str1[i] - str2[i]);
}

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
