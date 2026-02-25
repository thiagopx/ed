#ifndef POINT2D
#define POINT2D

typedef struct point2d Point2D;

// Function to create a new Point2D
Point2D *create_point(double x, double y);
// Function to calculate the Euclidean distance between two points
double euclidean_distance(Point2D *point1, Point2D *point2);
void free_point(Point2D *point);
#endif