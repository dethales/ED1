#ifndef PROFESSOR_H
#define PROFESSOR_H

typedef struct professor Professor;

Professor* criaProfessor(char* nome, int siape, float salario);
void imprimeProfessor(Professor* professor);
char* retornaNomeProfessor(Professor* professor);
float retornaSalario(Professor* professor);
void destroiProfessor(Professor* professor);


#endif // PROFESSOR_H