// A student record (name and CPF); the struct stays hidden behind the functions below.

#ifndef STUDENT_H
#define STUDENT_H

typedef struct student Student;

// Returns a new student with the given name and cpf (11 digits, no punctuation).
// Ownership: the caller (or the list that stores it) frees it with st_free.
Student *st_create(const char *name, const char *cpf);

// Prints the name and the formatted CPF of s.
void st_print(Student *s);

// Returns the name of s (read-only).
const char *st_name(Student *s);

// Returns the CPF of s (read-only).
const char *st_cpf(Student *s);

// Frees the student s.
void st_free(Student *s);

#endif
