#include <stdio.h>

int main()
{
    FILE *file = fopen(__FILE__, "r");

    if (file == NULL)
    {
        printf("Error opening file\n");
        return 1;
    }

    int word_count = 0;
    char word[100]; // sequence of non-blank characters

    while (fscanf(file, "%s", word) != EOF)
    {
        word_count++;
        printf("%s\n", word);
    }

    printf("\nTotal words in the source code: %d\n", word_count);

    fclose(file);
    return 0;
}
