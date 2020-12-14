#include "Aluno.h"
#include "Fila.h"

#include <stdio.h>

// a proxima linha esta incluida no arquivo Fila.h
// #define TAM_MAX_FILA 6

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
    Aluno* alunoRetirado1 = retiraFila(f);
    imprimeFila(f);

    printf("\nRetirando mais tres aluno da fila\n");
    Aluno* alunoRetirado2 = retiraFila(f);
    Aluno* alunoRetirado3 = retiraFila(f);
    Aluno* alunoRetirado4 = retiraFila(f);
    imprimeFila(f);

    printf("\nAdicionando dois aluno retirados ao final da fila\n");
    insereFila(f, alunoRetirado2);
    insereFila(f, alunoRetirado4);
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