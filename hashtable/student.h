#ifndef STUDENT_H
#define STUDENT_H

typedef struct student Student;

Student *st_create(int id, const char *name, const char *email, char class);
int st_get_id(Student *student);
char *st_get_name(Student *student);
char *st_get_email(Student *student);
char st_get_class(Student *student);
void st_print(Student *student);

#endif