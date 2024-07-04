#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Estrutura Pacient
typedef struct
{
    int id;
    char *name;
    struct tm *birthdate;
} Pacient;

// Estrutura Exam
typedef struct
{
    int id;
    int pacient_id;
    int rx_id;
    struct tm *time;
} Exam;

// Função para criar um novo paciente
Pacient *create_pacient(int id, const char *name, struct tm *birthdate)
{
    Pacient *new_pacient = (Pacient *)malloc(sizeof(Pacient));
    if (new_pacient == NULL)
    {
        printf("Erro ao alocar memória para o paciente.\n");
        exit(1);
    }
    new_pacient->id = id;
    new_pacient->name = strdup(name); // strdup aloca memória para a cópia do nome
    new_pacient->birthdate = birthdate;

    return new_pacient;
}

// Função para destruir um paciente
void destroy_pacient(Pacient *pacient)
{
    if (pacient != NULL)
    {
        free(pacient->name);
        free(pacient);
    }
}

// Funções "get" para acessar os campos internos de Pacient
int get_pacient_id(Pacient *pacient)
{
    return pacient->id;
}

const char *get_pacient_name(Pacient *pacient)
{
    return pacient->name;
}

struct tm *get_pacient_birthdate(Pacient *pacient)
{
    return pacient->birthdate;
}

// Função para criar um novo exame
Exam *create_exam(int id, int pacient_id, int rx_id, struct tm *time)
{
    Exam *new_exam = (Exam *)malloc(sizeof(Exam));
    if (new_exam == NULL)
    {
        printf("Erro ao alocar memória para o exame.\n");
        exit(1);
    }
    new_exam->id = id;
    new_exam->pacient_id = pacient_id;
    new_exam->rx_id = rx_id;
    new_exam->time = time;

    return new_exam;
}

// Função para destruir um exame
void destroy_exam(Exam *exam)
{
    if (exam != NULL)
    {
        free(exam);
    }
}

// Funções "get" para acessar os campos internos de Exam
int get_exam_id(Exam *exam)
{
    return exam->id;
}

int get_exam_pacient_id(Exam *exam)
{
    return exam->pacient_id;
}

int get_exam_rx_id(Exam *exam)
{
    return exam->rx_id;
}

struct tm *get_exam_time(Exam *exam)
{
    return exam->time;
}

// Função principal de teste
int main()
{
    // Definindo uma data de nascimento fictícia para o paciente
    struct tm birthdate = {0}; // Inicializar a estrutura com zeros
    birthdate.tm_year = 90;    // Ano 1990
    birthdate.tm_mon = 5;      // Junho (0-indexed)
    birthdate.tm_mday = 15;    // Dia 15

    // Criando um paciente
    Pacient *patient = create_pacient(1, "João Silva", &birthdate);

    // Imprimindo informações do paciente criado
    printf("Paciente criado:\n");
    printf("ID: %d\n", patient->id);
    printf("Nome: %s\n", patient->name);
    printf("Data de Nascimento: %s\n", asctime(patient->birthdate));

    // Definindo uma data e hora fictícias para o exame
    time_t current_time;
    struct tm exam_time;

    // Tempo do exame é o tempo atual
    current_time = time(NULL);             // Obter o tempo atual em segundos desde 01/01/1970
    exam_time = *localtime(&current_time); // Converter o tempo para a hora local

    // Criando um exame associado ao paciente criado
    Exam *exam = create_exam(101, patient->id, 1, &exam_time);

    // Imprimindo informações do exame criado
    printf("\nExame criado:\n");
    printf("ID: %d\n", get_exam_id(exam));
    printf("ID do Paciente: %d\n", get_exam_pacient_id(exam));
    printf("ID do Aparelho de Raio-X: %d\n", get_exam_rx_id(exam));
    printf("Data e Hora do Exame: %s\n", asctime(get_exam_time(exam)));

    // Liberando a memória alocada
    destroy_exam(exam);
    destroy_pacient(patient);

    return 0;
}
