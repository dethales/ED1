#include "Aluno.h"
#include "pilhaDupla.h"

#include <stdio.h>

int main(void)
{
    Aluno* Joao = criaAluno("Joao", 123);
    Aluno* Maria = criaAluno("Maria", 456);
    Aluno* Roberto = criaAluno("Roberto", 789);
    Aluno* Paula = criaAluno("Paula", 345);
    Aluno* Ana = criaAluno("Ana", 678);
    Aluno* Geraldo = criaAluno("Geraldo", 234);

    PilhaDupla* pd = criaPilhaDupla();

    // pilha de meninas
    push1(pd, Maria);
    push1(pd, Ana);
    push1(pd, Paula);

    imprime1(pd);
    putchar('\n');

    pop2(pd); // exemplo de erro pois a pilha esta vazia
    putchar('\n');

    // pilha de meninos
    push2(pd, Roberto);
    push2(pd, Joao);
    push2(pd, Geraldo);

    // imprime as duas pilhas
    imprime1(pd);
    imprime2(pd);
    putchar('\n');

    // retira alguns alunos das listas
    Aluno* a1 = pop1(pd);
    Aluno* a2 = pop2(pd);
    Aluno* a3 = pop2(pd);

    // imprime as duas pilhas atualizadas
    imprime1(pd);
    imprime2(pd);

    // libera toda a memoria
    destroiPilhaDupla(pd);

    destroiAluno(Joao);
    destroiAluno(Maria);
    destroiAluno(Roberto);
    destroiAluno(Paula);
    destroiAluno(Ana);
    destroiAluno(Geraldo);
    
    return 0;
}