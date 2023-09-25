#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "point2d.h"
#include "circle.h"

int main()
{
    // Create a circle with center (0, 0) and radius 5
    Circle *my_circle = create_circle(0, 0, 5);

    // Create a point with coordinates (2, 1)
    Point2D *my_point = create_point(2, 1);

    // Check if the point is inside the circle
    if (is_point_inside_circle(my_point, my_circle))
    {
        printf("The point is inside the circle.\n");
    }
    else
    {
        printf("The point is outside the circle.\n");
    }

    // Deallocate memory
    free_circle(my_circle);
    free_point(my_point);

    return 0;
}