#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    char name[50];
    int id;
    int age;
} Student;

// Function to read student data from a file and return an array of students
Student *read_students_from_file(const char *filename, int *num_students)
{
    FILE *file = fopen(filename, "r");
    if (file == NULL)
    {
        perror("Error opening the file");
        return NULL;
    }

    if (fscanf(file, "%d", num_students) != 1)
    {
        perror("Error reading the number of records");
        fclose(file);
        return NULL;
    }

    Student *students = (Student *)malloc((*num_students) * sizeof(Student));
    if (students == NULL)
    {
        perror("Memory allocation failed");
        fclose(file);
        return NULL;
    }

    for (int i = 0; i < *num_students; i++)
    {
        int num_scanned_items = fscanf(file, " %[^\n]", students[i].name);
        num_scanned_items += fscanf(file, "%d", &students[i].id);
        num_scanned_items += fscanf(file, "%d", &students[i].age);
        if (num_scanned_items != 3)
        {
            perror("Error reading student data");
            fclose(file);
            free(students);
            return NULL;
        }
    }

    fclose(file);
    return students;
}

// Function to print an array of students
void print_students(Student *students, int num_students)
{
    printf("Student Report:\n");
    printf("------------------------------------------------\n");
    printf("Name\t\tID\t\tAge\n");
    printf("------------------------------------------------\n");

    for (int i = 0; i < num_students; i++)
    {
        printf("%s\t\t%d\t\t%d\n", students[i].name, students[i].id, students[i].age);
    }
}

int main()
{
    int num_students;
    Student *students = read_students_from_file("students.txt", &num_students);

    if (students != NULL)
    {
        print_students(students, num_students);
        free(students);
    }

    return 0;
}
