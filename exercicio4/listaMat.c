#include <stdio.h>
#include <stdlib.h>
#include "listaMat.h"
#include "matriz.h"

typedef struct celula Celula;

struct celula
{
    Matriz* mat;
    Celula* prox;
};


struct lista
{
    Celula* prim;
    Celula* ult;
};

Lista* criaLista(void)
{
    Lista* lista = (Lista*) malloc(sizeof(Lista));

    lista->prim = NULL;
    lista->ult = NULL;

    return lista;
}

void insereLista(Lista* lista, Matriz* mat)
{
    Celula* novo = (Celula*) malloc(sizeof(Celula));

    // a lista contem somente uma celula
    if(lista->ult == NULL)
    {
        lista->prim = novo;
        lista->ult = novo;
    }
    // a lista contem mais de uma celula, adiciona na ultima
    else
    {
        lista->ult->prox = novo;
        lista->ult = lista->ult->prox;
    }

    lista->ult->mat = mat;
    lista->ult->prox = NULL;
}

void imprimeLista(Lista* lista)
{
    for(Celula* aux = lista->prim; aux != NULL; aux = aux->prox)
    {
        imprimeMatriz(aux->mat);
        printf("\n");
    }
}

Matriz* retiraLista(Lista* lista, int pos)
{
    int i = 0;
    Celula* ant = NULL;
    Celula* p = lista->prim;
    Matriz* m;

    while( (p->prox != NULL) && (i < pos) )
    {
        ant = p;
        p = p->prox;
        i++;
    }

    // lista vazia
    if(p == NULL)
    {
        return NULL;
    }

    // lista com 1 elemento
    else if( (p == lista->prim) && (p == lista->ult) )
    {
        lista->prim == NULL;
        lista->ult == NULL;
    }

    // retira o ultimo da lista
    else if(p == lista->ult)
    {
        lista->ult = ant;
        ant->prox = NULL;
    }

    // retira o primeiro da lista
    else if(p == lista->prim)
    {
        lista->prim = p->prox;
    }

    // caso geral
    else
    {
        ant->prox = p->prox;
    }

    m = p->mat;
    free(p);
    return m;
}

void destroiLista(Lista* lista)
{
    Celula* p = lista->prim;
    Celula* t;

    while(p!= NULL)
    {
        t = p->prox;
        destroiMatriz(p->mat);
        free(p);
        p = t;
    }

    free(lista);
}