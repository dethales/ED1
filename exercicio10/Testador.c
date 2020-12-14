#include "Aluno.h"
#include "ABB.h"

#include <stdio.h>

int main(void)
{
    Aluno* Joao = criaAluno("Joao", 123);
    Aluno* Maria = criaAluno("Maria", 456);
    Aluno* Roberto = criaAluno("Roberto", 789);
    Aluno* Paula = criaAluno("Paula", 345);
    Aluno* Ana = criaAluno("Ana", 678);
    Aluno* Geraldo = criaAluno("Geraldo", 234);

    Arvore* abb = criaABB();


    printf("Preenchendo a arvore com os alunos...\n");
    abb = insereABB(abb, Joao);
    abb = insereABB(abb, Maria);
    abb = insereABB(abb, Roberto);
    abb = insereABB(abb, Paula);
    abb = insereABB(abb, Ana);
    abb = insereABB(abb, Geraldo);

    imprimeABB(abb);

    printf("\nBuscando o aluno de matricula 456:\n");
    Arvore* alunoBuscado1 = buscaABB(abb, 456);
    imprimeNo(alunoBuscado1);


    printf("\nRetirando agora a Maria:\n");
    retiraABB(abb, 456);
    imprimeABB(abb);

    printf("\nLiberando a lista...\n");
    liberaABB(abb);

    destroiAluno(Joao);
    destroiAluno(Maria);
    destroiAluno(Roberto);
    destroiAluno(Paula);
    destroiAluno(Ana);
    destroiAluno(Geraldo);

    return 0;
}