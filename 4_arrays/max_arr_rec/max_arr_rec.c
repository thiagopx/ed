#include <stdio.h>

int max(int *arr, int size)
{
    if (size == 1)
    {
        return arr[0]; // Base case: array with only one element
        // return *arr; // Base case: array with only one element
    }
    else
    {
        int max_of_rest = max(&arr[1], size - 1); // Recursive call
        // int max_of_rest = max(arr + 1, size - 1); // Recursive call
        return (arr[0] > max_of_rest) ? arr[0] : max_of_rest;
        // return (*arr > max_of_rest) ? *arr : max_of_rest;
    }
}

int main()
{
    int numbers[] = {10, 24, 7, 42, 15, 30, 18};
    int size = sizeof(numbers) / sizeof(numbers[0]);

    int max_value = max(numbers, size);

    printf("Maximum value in the array: %d\n", max_value);

    return 0;
}
