#include <stdio.h>
#include <math.h>

#define MAX_SIZE 100

int main()
{
    int values[MAX_SIZE];
    int n;
    printf("Enter the number of values: ");
    scanf("%d", &n);

    if (n <= 0)
    {
        printf("Number of values must be positive.\n");
        return 1;
    }

    if (n > MAX_SIZE)
    {
        printf("Number of values must be fewer than %d.\n", MAX_SIZE);
        return 1;
    }

    float sum = 0.0f;

    // Input values and calculate sum
    printf("Enter %d values:\n", n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &values[i]);
        sum += values[i];
    }

    float mean = sum / n;

    int farthest = values[0];
    float max_distance = fabs(values[0] - mean);

    // Find the value farthest from the mean
    for (int i = 1; i < n; i++)
    {
        float distance = fabs(values[i] - mean);
        if (distance > max_distance)
        {
            max_distance = distance;
            farthest = values[i];
        }
    }

    printf("Mean: %.2f\n", mean);
    printf("Value Farthest from Mean: %d\n", farthest);

    return 0;
}
