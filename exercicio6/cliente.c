#include "Aluno.h"
#include "Professor.h"
#include "listaHet.h"

#include <stdio.h>

int main(void)
{
    Aluno* Joao = criaAluno("Joao", 123);
    Aluno* Maria = criaAluno("Maria", 456);
    Aluno* Alfredo = criaAluno("Alfredo", 789);
    Aluno* Mario = criaAluno("Mario", 321);

    Professor* Marcos = criaProfessor("Marcos", 888, 5670.00);
    Professor* Elisa = criaProfessor("Elisa", 675, 7654.40);

    ListaHet* turma = criaListaHet();

    insereAluno(turma, Joao);
    insereAluno(turma, Alfredo);
    insereAluno(turma, Maria);
    insereAluno(turma, Mario);

    insereProfessor(turma, Elisa);
    insereProfessor(turma, Marcos);

    printf("Turma:\n");
    imprimeListaHet(turma);

    printf("Valor do Churrasco: R$ %.2f reais\n", valorChurrasco(turma));

    destroiLista(turma);
    
    destroiAluno(Joao);
    destroiAluno(Alfredo);
    destroiAluno(Mario);
    destroiAluno(Maria);

    destroiProfessor(Marcos);
    destroiProfessor(Elisa);

    return 0;
}