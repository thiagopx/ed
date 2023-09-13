#include <stdio.h>

int main()
{
    FILE *file = fopen("main.c", "r");
    // FILE *file = fopen(__FILE__, "r");

    if (file == NULL)
    {
        printf("Error opening file\n");
        return 1;
    }

    int char_count = 0;
    char ch;

    while ((ch = fgetc(file)) != EOF) // EOF is typically -1
    {
        if (ch != ' ' && ch != '\n' && ch != '\t')
        {
            char_count++;
        }
    }

    printf("Total characters (excluding spaces, tabs, and newlines): %d\n", char_count);

    fclose(file);
    return 0;
}
