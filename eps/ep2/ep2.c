#include <stdio.h>
#include <stdlib.h>

// Function to write an image represented as a 2D matrix of unsigned char to a PPM format P2 file
void write_image_to_ppm(const char *filename, unsigned char **image_data, int width, int height)
{
    // Open the file for writing
    FILE *file = fopen(filename, "w");
    if (!file)
    {
        fprintf(stderr, "Error opening file for writing: %s\n", filename);
        return;
    }

    // Write the PPM header
    fprintf(file, "P2\n");
    fprintf(file, "%d %d\n", width, height);
    fprintf(file, "255\n"); // Maximum pixel value

    // Write the image data
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            fprintf(file, "%d", image_data[i][j]);
            if (j < width - 1)
            {
                fprintf(file, " ");
            }
            else
            {
                fprintf(file, "\n");
            }
        }
    }

    // Close the file
    fclose(file);
}

int main()
{
    // TODO

    return 0;
}