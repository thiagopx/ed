#ifndef POINT2D
#define POINT2D

typedef struct point2d Point2D;

// Function to create a new Point2D
Point2D *create_point(double x, double y);
// Function to calculate the Euclidean distance between two points
double euclidean_distance(Point2D *point1, Point2D *point2);
// Function to read the coordinates of a Point2D
void get_point(Point2D *point, double *x, double *y);
// Function to set the coordinates of a Point2D
void set_point(Point2D *point, double x, double y);
void free_point(Point2D *point);
#endif