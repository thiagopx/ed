// A professor record (name, CPF and department); the struct stays hidden behind the functions.

#ifndef PROFESSOR_H
#define PROFESSOR_H

typedef enum
{
   DEPT_INF, // Department of Informatics
   DEPT_ENG, // Department of Engineering
} Department;

typedef struct professor Professor;

// Returns a new professor with the given name, cpf (11 digits, no punctuation) and dept.
// Ownership: the caller (or the list that stores it) frees it with pr_free.
Professor *pr_create(const char *name, const char *cpf, Department dept);

// Prints the name, the formatted CPF and the department of p.
void pr_print(Professor *p);

// Returns the CPF of x (read-only).
const char *pr_cpf(Professor *x);

// Frees the professor x.
void pr_free(Professor *x);

#endif
