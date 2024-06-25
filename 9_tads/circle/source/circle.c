#include "circle.h"
#include <stdio.h>
#include <stdlib.h>

struct circle
{
    Point2D *center;
    double radius;
};

// Function to create a new Circle
/**
 * Creates a new Circle object with the specified center coordinates and radius.
 *
 * @param center_x The x-coordinate of the center of the circle.
 * @param center_y The y-coordinate of the center of the circle.
 * @param radius The radius of the circle.
 * @return A pointer to the newly created Circle object.
 */
Circle *create_circle(double center_x, double center_y, double radius)
{
    Circle *new_circle = (Circle *)malloc(sizeof(Circle));
    if (new_circle == NULL)
    {
        perror("Failed to allocate memory for Circle");
        exit(EXIT_FAILURE);
    }
    new_circle->center = create_point(center_x, center_y);
    new_circle->radius = radius;
    return new_circle;
}

// Function to check if a point is inside a circle
int is_point_inside_circle(Point2D *point, Circle *circle)
{
    double distance = euclidean_distance(point, circle->center);

    // If the distance is less than the radius, the point is inside the circle
    if (distance < circle->radius)
    {
        return 1; // Inside
    }
    else
    {
        return 0; // Outside
    }
}

// Function to deallocate a Circle
void free_circle(Circle *circle)
{
    free_point(circle->center);
    free(circle);
}