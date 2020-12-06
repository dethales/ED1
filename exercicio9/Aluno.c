#include "Aluno.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct aluno
{
    int matricula;
    char* nome;
};

Aluno* criaAluno(char* nome, int matricula)
{
    Aluno* aluno = (Aluno*) malloc(sizeof(Aluno));

    aluno->nome = nome;
    aluno->matricula = matricula;

    return aluno;
}

void imprimeAluno(Aluno* aluno)
{
    printf("Nome: %s\t", aluno->nome);
    printf("Matricula: %d\n", aluno->matricula);
}

// verifica se o aluno a eh igual ao aluno b
int comparaAluno(Aluno* a, Aluno* b)
{
    return ( (a->matricula == b->matricula) && !strcmp(a->nome, b->nome) );
}

void destroiAluno(Aluno* aluno)
{
    free(aluno);
}