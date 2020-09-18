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

int main(void)
{
    int numAlunos;
    char* nomeAluno = NULL;
    size_t tamNomeAluno = 0;
    int i;
    char c;

    printf("Digite o numero de alunos na turma: ");
    scanf("%d", &numAlunos);
    while ((c = getchar()) != '\n' && c != EOF);    // consume o '\n' deixado pelo scanf

    Aluno** turma = (Aluno**) malloc(numAlunos * sizeof(Aluno*));

    for(i = 0; i < numAlunos; i++)
    {
        turma[i] = leAluno();
    }

    return 0;
}

Aluno* leAluno(void)
{
    Aluno* a = (Aluno*) malloc(sizeof(Aluno));
    const size_t tamMaxNome = 128;
    char c;
    a->nome = (char*) malloc(tamMaxNome * sizeof(char));

    printf("Digite o nome do Aluno:\n");
    fgets(a->nome, tamMaxNome, stdin);
    strtok(a->nome, "\n");  // retira o '\n' que o fgets captura no final da string

    printf("Digite a matricula de %s: ", a->nome); // imprime so o primeiro nome
    scanf("%d", &a->matricula);

    printf("Digite a nota da P1 de %s: ", a->nome);
    scanf("%f", &a->p1);
    printf("Digite a nota da P2 de %s: ", a->nome);
    scanf("%f", &a->p2);
    printf("Digite a nota da P3 de %s: ", a->nome);
    scanf("%f", &a->p3);
    while ((c = getchar()) != '\n' && c != EOF);    // consume o '\n' deixado pelo scanf

    return a;
}