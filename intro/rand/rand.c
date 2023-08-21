#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    /** Set a seed based on the current time
     * In Linux, the time() function returns the elapsed time in seconds from
     * January 1, 1970, 00:00:00 (UTC) to the present moment.
     */
    // srand(time(NULL));

    // Generate and display 5 random numbers
    printf("Random numbers generated:\n");
    for (int i = 0; i < 5; i++)
    {
        int random_number = rand();
        printf("%d\n", random_number);
    }

    return 0;
}