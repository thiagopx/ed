#include <stdio.h>

int main()
{
    char city[4];
    city[0] = 'R';
    city[1] = 'i';
    city[2] = 'o';
    city[3] = '\0';

    printf("%s\n", city);

    char city2[] = {'R', 'i', 'o', '\0'};
    printf("%s\n", city2);

    char city3[] = "Rio";
    printf("%s\n", city3);

    return 0;
}
