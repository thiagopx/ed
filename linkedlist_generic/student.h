#ifndef STUDENT_H
#define STUDENT_H

// Define an enumeration for different course types.
typedef enum
{
   COURSE_BSI,
   COURSE_ECA,
} Course;

// Define a custom data type "Student" to represent student information.
typedef struct student Student;

/**
 * Create a new Student instance and initialize its name, CPF, and course.
 *
 * @param name  - The name of the student.
 * @param cpf   - The CPF (Brazilian identification number) of the student.
 * @param course - The course in which the student is enrolled (e.g., COURSE_BSI or COURSE_ECA).
 * @return      - A pointer to the newly created Student instance.
 */
Student *st_create(const char *name, const char *cpf, Course course);

/**
 * Print the student's name and formatted CPF.
 *
 * @param s - A pointer to the Student whose information should be printed.
 */
void st_print(Student *s);

#endif
