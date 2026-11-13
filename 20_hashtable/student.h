// A student record (id, name, email and class); the struct stays hidden behind the functions.

#ifndef STUDENT_H
#define STUDENT_H

typedef struct student Student;

// Returns a new student with the given id, name, email and class.
// Ownership: the caller (or the table that stores it) frees it with st_free.
Student *st_create(int id, const char *name, const char *email, char class);

// Returns the id of student.
int st_get_id(Student *student);

// Returns the name of student.
char *st_get_name(Student *student);

// Returns the email of student.
char *st_get_email(Student *student);

// Returns the class of student.
char st_get_class(Student *student);

// Prints the name, email, id and class of student.
void st_print(Student *student);

// Frees student.
void st_free(Student *student);

#endif
