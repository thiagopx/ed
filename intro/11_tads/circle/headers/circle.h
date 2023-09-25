#ifndef CIRCLE
#define CIRCLE

#include "point2d.h"

typedef struct circle Circle;

// Function to create a new Circle
Circle *create_circle(double center_x, double center_y, double radius);
// Function to check if a point is inside a circle
int is_point_inside_circle(Point2D *point, Circle *circle);
// Function to deallocate a Circle
void free_circle(Circle *circle);
#endif
