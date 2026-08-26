#include <stdio.h>
#include <math.h>

// Function to calculate volume of a cylinder
double cylinder_volume(double radius, double height)
{
    return M_PI * pow(radius, 2) * height;
    // return M_PI * radius * radius * height;
}

int main()
{
    double radius, height;

    printf("Enter the radius of the cylinder: ");
    scanf("%lf", &radius);

    printf("Enter the height of the cylinder: ");
    scanf("%lf", &height);

    double volume = cylinder_volume(radius, height);

    printf("\nCylinder Parameters:\n");
    printf("Radius: %.2lf\n", radius);
    printf("Height: %.2lf\n", height);
    printf("Volume: %.2lf\n", volume);

    return 0;
}