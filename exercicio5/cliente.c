#include "listaDpl.h"
#include<stdio.h>

int main(void)
{
    const char* nomes[] =
    {   "Joao",
        "Maria",
        "Pedro",
        "Roberta",
        "Joana",
        "Marcos",
        "Cassio",
        "Gabriel",
        "Ana"
    };
    const int TAM_NOMES = 9;


    ListaDpl* l = criaLista();

    for(int i = 0; i < TAM_NOMES; i++)
    {
        l = insereLista(l, nomes[i]);
    }

    imprimeLista(l);

    // ultimo da lista
    l = retiraLista(l, "Ana");
    putchar('\n');
    imprimeLista(l);

    // primeiro da lista
    l = retiraLista(l, "Joao");
    putchar('\n');
    imprimeLista(l);

    // caso geral
    l = retiraLista(l, "Marcos");
    putchar('\n');
    imprimeLista(l);

    destroiLista(l);

    return 0;
}