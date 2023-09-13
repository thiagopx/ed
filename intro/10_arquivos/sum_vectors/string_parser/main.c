#include <stdio.h>

int main() {
    // Parsing values from a string using sscanf
    char input_string[] = "John 25 75.5";
    char name[50];
    int age;
    float height;

    sscanf(input_string, "%s %d %f", name, &age, &height);

    printf("Name: %s\n", name);
    printf("Age: %d\n", age);
    printf("Height: %.2f\n", height);

    // Formatting values into a string using sprintf
    char output_string[100];
    int score = 95;

    sprintf(output_string, "Student: %s, Score: %d", name, score);

    printf("Formatted String: %s\n", output_string);

    return 0;
}
