#include "point2d.h"
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

// Define a Point2D structure
struct point2d {
  double x;
  double y;
};

// Function to calculate the Euclidean distance between two points
double euclidean_distance(Point2D *point1, Point2D *point2) {
  double dx = point1->x - point2->x;
  double dy = point1->y - point2->y;
  return sqrt(dx * dx + dy * dy);
}

// Function to create a new Point2D
Point2D *create_point(double x, double y) {
  Point2D *new_point = (Point2D *)malloc(sizeof(Point2D));
  if (new_point == NULL) {
    perror("Failed to allocate memory for Point2D");
    exit(EXIT_FAILURE);
  }
  new_point->x = x;
  new_point->y = y;
  return new_point;
}

// Function to deallocate a Point2D
void free_point(Point2D *point)
{
    free(point);
}
