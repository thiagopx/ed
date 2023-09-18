#include <stdio.h>
#include <stdlib.h>

// Define a 2D point struct
struct point2d
{
    float x;
    float y;
};

// Function to read the coordinates of a point
void read_point(struct point2d *point)
{
    printf("Enter the x-coordinate: ");
    scanf("%f", &(point->x));

    printf("Enter the y-coordinate: ");
    scanf("%f", &(point->y));
}

// Function to print the coordinates of a point using a const pointer
void print_point(const struct point2d *point)
{
    printf("The 2D point has the following coordinates:\n");
    printf("x = %.2f\n", point->x);
    printf("y = %.2f\n", point->y);
}

int main()
{
    // Declare a pointer to a point2d
    struct point2d *point;

    // Dynamically allocate memory for the point
    point = (struct point2d *)malloc(sizeof(struct point2d));

    if (point == NULL)
    {
        fprintf(stderr, "Memory allocation failed.\n");
        return 1;
    }

    // Read the coordinates of the dynamically allocated point
    read_point(point);

    // Print the coordinates of the dynamically allocated point
    print_point(point);

    // Free the dynamically allocated memory
    free(point);

    return 0;
}
