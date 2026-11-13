// A student record (name, CPF and course); the struct stays hidden behind the functions below.

#ifndef STUDENT_H
#define STUDENT_H

typedef enum
{
    COURSE_BSI,
    COURSE_ECA,
} Course;

typedef struct student Student;

// Returns a new student with the given name, cpf (11 digits, no punctuation) and course.
// Ownership: the caller (or the list that stores it) frees it with st_free.
Student *st_create(const char *name, const char *cpf, Course course);

// Prints the name, the formatted CPF and the course of s.
void st_print(Student *s);

// Returns the CPF of x (read-only).
const char *st_cpf(Student *x);

// Frees the student x.
void st_free(Student *x);

#endif
