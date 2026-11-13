// A point in the plane, with coordinates x and y.

#ifndef POINT2D
#define POINT2D

typedef struct point2d Point2D;

// Returns a new point with coordinates x and y.
// Ownership: the caller frees it with free_point.
Point2D *create_point(double x, double y);

// Returns the Euclidean distance between point1 and point2.
double euclidean_distance(Point2D *point1, Point2D *point2);

// Stores the coordinates of point in *x and *y.
void get_point(Point2D *point, double *x, double *y);

// Sets the coordinates of point to x and y.
void set_point(Point2D *point, double x, double y);

// Frees point.
void free_point(Point2D *point);
#endif
