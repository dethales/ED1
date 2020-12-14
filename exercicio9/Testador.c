#include "Arvore.h"
#include "Aluno.h"

#include <stdio.h>

int main(void)
{
    Aluno* Joao = criaAluno("Joao", 123);
    Aluno* Maria = criaAluno("Maria", 456);
    Aluno* Roberto = criaAluno("Roberto", 789);
    Aluno* Paula = criaAluno("Paula", 345);
    Aluno* Ana = criaAluno("Ana", 678);
    Aluno* Geraldo = criaAluno("Geraldo", 234);

    // aluno que nao entrara na arvore
    Aluno* Fajuto = criaAluno("Fajuto", 999);

/*
    diagrama da arvore criada
    (o = celula vazia)

                        Joao
                        * *
                      *     *
                    *         *
                  *             * 
                Maria          Paula
                *  *            *  *
              *     *          *    o
            *        *        *
          *           *      *
       Roberto      Ana    Geraldo
         *  *       *  *      *  *
       o      o    *    *    o     *
                  *      *           *
                 *        *            *
               Joao       Paula        Ana
                * *        *  *        *  *
               o   o      o    o      o    o
                  
*/

    Arvore* a = criaArvore(
        Joao,
        criaArvore(
            Maria,
            criaArvore(
                Roberto,
                criaArvoreVazia(),
                criaArvoreVazia()
                ),
            criaArvore(
                Ana,
                criaArvore(
                    Joao,
                    criaArvoreVazia(),
                    criaArvoreVazia()
                ),
                criaArvore(
                    Paula,
                    criaArvoreVazia(),
                    criaArvoreVazia()
                )
            )
        ),
        criaArvore(
            Paula,
            criaArvore(
                Geraldo,
                criaArvoreVazia(),
                criaArvore(
                    Ana,
                    criaArvoreVazia(),
                    criaArvoreVazia()
                )
            ),
            criaArvoreVazia()
        )
    );

    // imprime a arvore
    imprimeArvore(a);

    // verifica o numero de folhas da arvore (9 folhas)
    printf("\nNumero de folhas: %d\n", folhas(a));

    // verifica se Maria esta na arvore
    printf("A aluna Maria ");
    if (!pertenceArvore(a, Maria))
        printf("nao ");
    printf("esta na arvore\n");

    // verifica se Fajuto esta na arvore
    printf("O aluno Fajuto ");
    if (!pertenceArvore(a, Fajuto))
        printf("nao ");
    printf("esta na arvore\n");

 
    printf("Numero de ocorrencias de Joao: %d\n", ocorrencias(a, Joao)); // 2
    printf("Numero de ocorrencias de Fajuto: %d\n", ocorrencias(a, Fajuto)); // 2
    printf("Numero de ocorrencias de Maria: %d\n", ocorrencias(a, Maria)); // 2

    printf("Altura da arvore: %d\n", altura(a)); // altura: 3  

    return 0;
}