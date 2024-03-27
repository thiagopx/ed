#include <stdio.h>

int main()
{
    FILE *file = fopen(__FILE__, "r");

    if (file == NULL)
    {
        printf("Error opening file\n");
        return 1;
    }

    int line_count = 0;
    char line[100]; // sequence of non-blank characters

    while (fgets(line, 100, file) != NULL) // returns line or NULL (if reach the end of file)
    {
        line_count++;
        printf("%s\n", line);
    }

    printf("\nTotal lines in the source code: %d\n", line_count);

    fclose(file);
    return 0;
}
