#include <stdio.h>

// Define a 2D point struct
struct point2d
{
    float x;
    float y;
};

int main()
{
    // Declare a point2d variable
    struct point2d point;

    // Read the coordinates from the user
    printf("Enter the x and y coordinates in a single line: ");
    scanf("%f %f", &point.x, &point.y);

    // Print the coordinates
    printf("The 2D point has the following coordinates: (%.2f, %.2f)\n", point.x, point.y);

    // Declare a pointer to point2d and assign the address of point to it
    struct point2d *point_ptr = &point;

    // Manipulate the struct using the pointer
    point_ptr->x += 1.0;
    // (*point_ptr).x += 1.0; // Equivalent to the above line
    point_ptr->y += 2.0;
    // (*point_ptr).y += 2.0; // Equivalent to the above line

    // Print the coordinates after manipulation
    printf("After manipulation, the 2D point has the following coordinates: (%.2f, %.2f)\n", point_ptr->x, point_ptr->y);

    return 0;
}
