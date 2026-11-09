#ifndef STUDENT_H
#define STUDENT_H

// Define a custom data type "Student" to represent student information.
typedef struct student Student;

/**
 * Create a new Student instance and initialize its name and CPF.
 *
 * @param name - The name of the student.
 * @param cpf  - The CPF (Brazilian identification number) of the student.
 * @return     - A pointer to the newly created Student instance.
 */
Student *st_create(const char *name, const char *cpf);

/**
 * Print the student's name and formatted CPF.
 *
 * @param s - A pointer to the Student whose information should be printed.
 */
void st_print(Student *s);

// Read-only access to the fields of a Student (the struct itself stays hidden).
const char *st_name(Student *s);
const char *st_cpf(Student *s);

#endif
