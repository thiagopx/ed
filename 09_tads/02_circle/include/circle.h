// A circle in the plane, given by its center (a Point2D) and its radius.

#ifndef CIRCLE
#define CIRCLE

#include "point2d.h"

typedef struct circle Circle;

// Returns a new circle with center (center_x, center_y) and the given radius.
// Ownership: the caller frees it with free_circle.
Circle *create_circle(double center_x, double center_y, double radius);

// Checks whether point is inside circle; returns 1 if it is, 0 otherwise.
int is_point_inside_circle(Point2D *point, Circle *circle);

// Frees circle and its center.
void free_circle(Circle *circle);
#endif
