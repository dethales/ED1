#include "Professor.h"

#include <stdlib.h>
#include <stdio.h>

struct professor
{
    char* nome;
    int siape;
    float salario;
};

Professor* criaProfessor(char* nome, int siape, float salario)
{
    Professor* professor = (Professor*) malloc(sizeof(Professor));

    professor->nome = nome;
    professor->siape = siape;
    professor->salario = salario;

    return professor;
}

void imprimeProfessor(Professor* professor)
{
    printf("Nome: %s\t", professor->nome);
    printf("Siape: %d\t", professor->siape);
    printf("Salario: %.2f\n", professor->salario);
}

char* retornaNomeProfessor(Professor* professor)
{
    return professor->nome;
}

float retornaSalario(Professor* professor)
{
    return professor->salario;
}

void destroiProfessor(Professor* professor)
{
    free(professor);
}