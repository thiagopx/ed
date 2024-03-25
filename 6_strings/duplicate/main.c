#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to duplicate a string
char *duplicate(char *src)
{
    int n = strlen(src) + 1; // Add one for the '\0' character
    char *dest = (char *)malloc(n * sizeof(char));

    if (dest == NULL)
    {
        perror("Memory allocation failed");
        exit(1);
    }

    strcpy(dest, src);
    return dest;
}

int main(void)
{
    char original[] = "Hello, World!";
    char *copied;

    // Duplicate the string
    copied = duplicate(original);

    // Print the original and copied strings
    printf("Original string: %s\n", original);
    printf("Copied string: %s\n", copied);

    // Remember to free the memory allocated by duplicate
    free(copied);

    return 0;
}
