#include <stdio.h>

// float calculate_mean(float *ptr, int size)
// {
float calculate_mean(float ptr[], int size)
{
    float sum = 0.0f;
    for (int i = 0; i < size; ++i)
    {
        sum += ptr[i];
        // sum += *(ptr + i);
    }
    return sum / size;
}

int main()
{
    float values[] = {10.5, 20.0, 15.5, 7.2, 9.8};
    int size = sizeof(values) / sizeof(values[0]);

    // float *ptr = values; // Pointer pointing to the first element

    float mean = calculate_mean(values, size);

    printf("mean of the values: %f\n", mean);

    return 0;
}
