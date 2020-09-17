#include <stdio.h>
#include <stdlib.h>

struct aluno
{
    char* nome;
    int matricula;
    float p1;
    float p2;
    float p3;
};
typedef struct aluno Aluno;

int main(void)
{
    int numAlunos;
    char* nomeAluno = NULL;
    size_t tamNomeAluno = 0;
    int i;

    printf("Digite o numero de alunos na turma: ");
    scanf("%d", &numAlunos);

    Aluno** turma = (Aluno**) malloc(numAlunos * sizeof(Aluno*));

    for(i = 0; i < numAlunos; i++)
        turma[i] = (Aluno*) malloc(sizeof(Aluno));

    turma[0]->nome = "Joao";
    printf("%s", turma[0]->nome);

    return 0;
}