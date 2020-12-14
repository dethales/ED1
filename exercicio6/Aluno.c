#include "Aluno.h"

#include <stdio.h>
#include <stdlib.h>

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

char* retornaNomeAluno(Aluno* aluno)
{
    return aluno->nome;
}

void imprimeAluno(Aluno* aluno)
{
    printf("Nome: %s\t", aluno->nome);
    printf("Matricula: %d\n", aluno->matricula);
}

void destroiAluno(Aluno* aluno)
{
    free(aluno);
}