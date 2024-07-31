#ifndef PROFESSOR_H
#define PROFESSOR_H

// Define an enumeration for different department types.
typedef enum
{
   DEPT_INF, // Department of Informatics
   DEPT_ENG, // Department of Engineering
} Department;

// Define a custom data type "Professor" to represent professor information.
typedef struct professor Professor;

/**
 * Create a new Professor instance and initialize its name, CPF, and department.
 *
 * @param name - The name of the professor.
 * @param cpf  - The CPF (Brazilian identification number) of the professor.
 * @param dept - The department to which the professor belongs (e.g., DEPT_INF or DEPT_ENG).
 * @return     - A pointer to the newly created Professor instance.
 */
Professor *pr_create(const char *name, const char *cpf, Department dept);

/**
 * Print the professor's name and formatted CPF.
 *
 * @param p - A pointer to the Professor whose information should be printed.
 */
void pr_print(Professor *p);

#endif
