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
    printf("Enter the x-coordinate: ");
    scanf("%f", &point.x);

    printf("Enter the y-coordinate: ");
    scanf("%f", &point.y);

    // Print the coordinates
    printf("The 2D point has the following coordinates:\n");
    printf("x = %.2f\n", point.x);
    printf("y = %.2f\n", point.y);

    return 0;
}
