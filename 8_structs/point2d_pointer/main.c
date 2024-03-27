#include <stdio.h>

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
    // Declare a point2d variable
    struct point2d point;

    // Read the coordinates of the point
    read_point(&point);

    // Print the coordinates of the point
    print_point(&point);

    return 0;
}
