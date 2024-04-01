/* How to run this code:
 * gcc -lm main.c -o main
 * ./main
 *
 * In this code, -lm is used to link the math library. The math library is not linked by default, so you need to specify it
 * explicitly when using math functions like sqrt.
 */
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Define a Point2D structure
typedef struct
{
    double x;
    double y;
} Point2D;

// Define a Circle structure
typedef struct
{
    Point2D *center;
    double radius;
} Circle;

// Function to calculate the Euclidean distance between two points
double euclidean_distance(Point2D *point1, Point2D *point2)
{
    double dx = point1->x - point2->x;
    double dy = point1->y - point2->y;
    return sqrt(dx * dx + dy * dy);
}

// Function to create a new Point2D
Point2D *create_point(double x, double y)
{
    Point2D *new_point = (Point2D *)malloc(sizeof(Point2D));
    if (new_point == NULL)
    {
        perror("Failed to allocate memory for Point2D");
        exit(EXIT_FAILURE);
    }
    new_point->x = x;
    new_point->y = y;
    return new_point;
}

// Function to create a new Circle
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

// Function to deallocate a Point2D
void free_point(Point2D *point)
{
    free(point);
}

// Function to deallocate a Circle
void free_circle(Circle *circle)
{
    free_point(circle->center);
    free(circle);
}

int main()
{
    // Create a circle with center (0, 0) and radius 5
    Circle *my_circle = create_circle(0, 0, 5);

    // Create a point with coordinates (3, 4)
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
