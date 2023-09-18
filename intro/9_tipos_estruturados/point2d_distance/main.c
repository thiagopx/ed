#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Define a 2D point struct
struct point2d
{
    float x;
    float y;
};

// Define a typedef for Point2D
typedef struct point2d Point2D;

// Function to allocate memory for a Point2D structure
Point2D *create_point()
{
    Point2D *point = (Point2D *)malloc(sizeof(Point2D));
    if (point == NULL)
    {
        fprintf(stderr, "Memory allocation failed.\n");
        exit(1);
    }
    return point;
}

// Function to read the coordinates of a point
void read_point(Point2D *point)
{
    printf("Enter the x-coordinate: ");
    scanf("%f", &(point->x));
    printf("Enter the y-coordinate: ");
    scanf("%f", &(point->y));
}

// Function to print the coordinates of a point
void print_point(const Point2D *point)
{
    printf("Point: (%.2f, %.2f)\n", point->x, point->y);
}

// Function to calculate the Euclidean distance between two points
float euclidean_distance(const Point2D *point1, const Point2D *point2)
{
    float dx = point2->x - point1->x;
    float dy = point2->y - point1->y;
    return sqrt(dx * dx + dy * dy);
}

// Function to deallocate memory for a Point2D structure
void free_point(Point2D *point)
{
    free(point);
}

int main()
{
    // Create two Point2D structures and allocate memory
    Point2D *point1 = create_point();
    Point2D *point2 = create_point();

    // Read the coordinates of the two points
    printf("Enter the coordinates of the first point:\n");
    read_point(point1);
    printf("Enter the coordinates of the second point:\n");
    read_point(point2);

    // Print the coordinates of the two points
    printf("Coordinates of the first point:\n");
    print_point(point1);
    printf("Coordinates of the second point:\n");
    print_point(point2);

    // Calculate and print the Euclidean distance between the two points
    float distance = euclidean_distance(point1, point2);
    printf("Euclidean distance between the two points: %.2f\n", distance);

    // Deallocate memory for the points
    free_point(point1);
    free_point(point2);

    return 0;
}
