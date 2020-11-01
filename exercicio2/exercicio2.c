#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct aluno
{
    char* nome;
    int matricula;
    float p1;
    float p2;
    float p3;
};
typedef struct aluno Aluno;

Aluno* leAluno(void);
void imprimeAluno(Aluno* a);
void imprime_aprovados(int n, Aluno** turma);
float media_turma(int n, Aluno** turma);

int main(void)
{
    int numAlunos;
    char* nomeAluno = NULL;
    size_t tamNomeAluno = 0;
    int i;

    printf("Digite o numero de alunos na turma: ");
    scanf("%d", &numAlunos);
    while(getchar() != '\n');    // consume o '\n' deixado pelo scanf

    Aluno** turma = (Aluno**) malloc(numAlunos * sizeof(Aluno*));

    // carrega a turma de alunos
    for(i = 0; i < numAlunos; i++)
    {
        turma[i] = leAluno();
    }

    //imprime os alunos
    for (i = 0; i < numAlunos; i++)
    {
        imprimeAluno(turma[i]);
    }

    imprime_aprovados(numAlunos, turma);
    printf("A media da turma eh %.2f\n", media_turma(numAlunos, turma));


    return 0;
}

Aluno* leAluno(void)
{
    Aluno* a = (Aluno*) malloc(sizeof(Aluno));
    const size_t tamMaxNome = 256;
    a->nome = (char*) malloc(tamMaxNome * sizeof(char));

    printf("Digite o nome do Aluno:\n");
    fgets(a->nome, tamMaxNome, stdin);
    strtok(a->nome, "\n");  // retira o '\n' que o fgets captura no final da string

    printf("Digite a matricula de %s: ", a->nome);
    scanf("%d", &a->matricula);

    printf("Digite a nota da P1 de %s: ", a->nome);
    scanf("%f", &a->p1);
    printf("Digite a nota da P2 de %s: ", a->nome);
    scanf("%f", &a->p2);
    printf("Digite a nota da P3 de %s: ", a->nome);
    scanf("%f", &a->p3);
    while(getchar() != '\n');    // consume o '\n' deixado pelo scanf

    return a;
}

void imprimeAluno(Aluno* a)
{
    printf("%s\tMatricula: %d\tP1: %.2f\tP2: %.2f\tP3: %.2f\n", a->nome, a->matricula, a->p1, a->p2, a->p3);
}

void imprime_aprovados(int n, Aluno** turma)
{
    int i;
    float media;

    printf("Os seguintes alunos foram aprovados:\n");
    for (i = 0; i < n; i++)
    {
        media = (turma[i]->p1 + turma[i]->p2 + turma[i]->p3) / 3.0;
        if (media >= 5.0)
            printf("%s, com media %.2f\n", turma[i]->nome, media);
    }   
}

float media_turma(int n, Aluno** turma)
{
    int i;
    float mediaTurma = 0.0;
    float mediaAluno;

    for (i = 0; i < n; i++)
    {
        mediaAluno = (turma[i]->p1 + turma[i]->p2 + turma[i]->p3) / 3.0;
        mediaTurma += mediaAluno / n;
    }

    return mediaTurma;
}