#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <limits.h>

int main()
{
    /** Set a seed based on the current time
     * In Linux, the time() function returns the elapsed time in seconds from
     * January 1, 1970, 00:00:00 (UTC) to the present moment.
     */
    // srand(time(NULL));
    srand(10);

    // Generate and display 5 random numbers
    printf("Random numbers generated:\n");
    for (int i = 0; i < 50; i++)
    {
        double random_number = (((double)rand()) / INT_MAX) * 10;
        printf("%lf\n", random_number);
    }

    return 0;
}