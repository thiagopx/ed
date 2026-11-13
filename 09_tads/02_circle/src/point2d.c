#include "point2d.h"
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

struct point2d {
  double x;
  double y;
};

double euclidean_distance(Point2D *point1, Point2D *point2) {
  double dx = point1->x - point2->x;
  double dy = point1->y - point2->y;
  return sqrt(dx * dx + dy * dy);
}

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

void get_point(Point2D *point, double *x, double *y) {
  *x = point->x;
  *y = point->y;
}

void set_point(Point2D *point, double x, double y) {
  point->x = x;
  point->y = y;
}

void free_point(Point2D *point)
{
    free(point);
}
