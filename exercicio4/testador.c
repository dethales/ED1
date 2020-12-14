#include "listaMat.h"
#include "matriz.h"
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int i, j;

    Matriz* m1;
    m1 = inicializaMatriz(4, 4);
    for (i=0;i<4;i++)
        for (j=0;j<4; j++)
            modificaElemento(m1, i, j, i+j);

    Matriz* m2;
    m2 = inicializaMatriz(3, 4);
    for (i=0;i<3;i++)
        for (j=0;j<4; j++)
            modificaElemento(m2, i, j, i*i+j*j);

    Matriz* m3;
    m3 = inicializaMatriz(5, 7);
    for (i=0;i<5;i++)
        for (j=0;j<7; j++)
            modificaElemento(m3, i, j, i/(j+1));

    Matriz* m4;
    m4 = inicializaMatriz(6, 4);
    for (i=0;i<6;i++)
        for (j=0;j<4; j++)
            modificaElemento(m4, i, j, i);
            

    Lista* l1 = criaLista();
    insereLista(l1, m1);
    insereLista(l1, m2);
    insereLista(l1, m3);
    insereLista(l1, m4);


    Lista* l2 = criaLista();
    insereLista(l2, transposta(m1));
    insereLista(l2, transposta(m4));
    insereLista(l2, transposta(m3));
    insereLista(l2, transposta(m2));


    printf("Lista 1:\n");
    imprimeLista(l1);

    printf("\nLista 2:\n");
    imprimeLista(l2);

    Matriz* m5 = retiraLista(l1, 0); // retira primeiro: [m1 m2 m3 m4] -> [m2 m3 m4]
    Matriz* m6 = retiraLista(l1, 1); // retira no meio  [m2 m3 m4] -> [m2 m4]
    MAtriz* m7 = retiraLista(l1, 1); // retira no fim [m2 m4] -> [m2]
    printf("Lista 1 com elementos retirados:\n");
    imprimeLista(l1);
    
    insereLista(l1, m1); // [m2] -> [m2 m1]
    insereLista(l1, m4); // [m2 m1] -> [m2 m1 m4]
    printf("Lista 1 com matrizes reinseridas:\n");
    imprimeLista(l1);

    destroiLista(l1);
    destroiLista(l2);

    // destroi a unica matriz "solta", que nao pertence a nenhuma lista
    destroiMatriz(m6);
    

    return 0;
}