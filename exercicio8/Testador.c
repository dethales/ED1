#include "Aluno.h"
#include "Fila.h"

#include <stdio.h>

int main(void)
{
    Aluno* Joao = criaAluno("Joao", 123);
    Aluno* Maria = criaAluno("Maria", 456);
    Aluno* Roberto = criaAluno("Roberto", 789);
    Aluno* Paula = criaAluno("Paula", 345);
    Aluno* Ana = criaAluno("Ana", 678);
    Aluno* Geraldo = criaAluno("Geraldo", 234);

    // aluno que vai tentar ser inserido na fila cheia
    Aluno* Penetra = criaAluno("Penetra", -1);

    Fila* f = criaFila();

    printf("Tendando retirar de uma fila vazia\n");
    retiraFila(f);

    printf("\nAdicionando os primeiros dois alunos na fila\n");
    insereFila(f, Maria);
    insereFila(f, Paula);
    imprimeFila(f);
    
    printf("\nAdicionando mais um aluno\n");
    insereFila(f, Ana);
    imprimeFila(f);

    printf("\nAdicionando o restante dos alunos\n");
    insereFila(f, Geraldo);
    insereFila(f, Joao);
    insereFila(f, Roberto);
    imprimeFila(f);

    printf("\nTentando adicionar um aluno na fila cheia\n");
    insereFila(f, Penetra);

    printf("\nRetirando um aluno da fila\n");
    retiraFila(f);
    imprimeFila(f);

    printf("\nRetirando mais tres aluno da fila\n");
    retiraFila(f);
    retiraFila(f);
    retiraFila(f);
    imprimeFila(f);

    printf("\nAdicionando um aluno retirado ao final da fila\n");
    insereFila(f, Paula);
    imprimeFila(f);

    // libera memoria
    destroiFila(f);

    destroiAluno(Joao);
    destroiAluno(Maria);
    destroiAluno(Roberto);
    destroiAluno(Paula);
    destroiAluno(Ana);
    destroiAluno(Geraldo);
    destroiAluno(Penetra);

    return 0;
}