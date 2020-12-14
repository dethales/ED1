#include "listaDpl.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct listaDpl
{
    const char* nome;
    ListaDpl* ant;
    ListaDpl* prox;
};

ListaDpl* criaLista(void)
{
    return NULL;
}

ListaDpl* insereLista(ListaDpl* lista, const char* nome)
{
    ListaDpl* celula = (ListaDpl*) malloc(sizeof(ListaDpl));
    celula->nome = nome;
    celula->ant = NULL;
    celula->prox = lista;

    if (lista != NULL)
        lista->ant = celula;

    return celula;
}

static ListaDpl* busca(ListaDpl* l, const char* chave)
{
    ListaDpl* p;
    for (p = l; p != NULL; p = p->prox)
    {
        if (strcmp(p->nome, chave) == 0)
        {
            return p;
        }
    }
}

ListaDpl* retiraLista(ListaDpl* lista, const char* chave)
{
    ListaDpl* p = busca(lista, chave);

    // caso a lista esteja vazia ou nao encontrou
    if(p == NULL)
        return NULL;

    // caso a celula seja a primeira
    if(p->ant == NULL)
    {
        lista = p->prox;
    }
    // caso a celula nao seja a primeira
    else
    {
        p->ant->prox = p->prox;
    }

    // caso a celula nao seja a ultima da lista
    if(p->prox != NULL)
    {
        p->prox->ant = p->ant;
    }

    free(p);

    return lista;
}

void imprimeLista(ListaDpl* lista)
{
    while(lista != NULL)
    {
        puts(lista->nome);
        lista = lista->prox;
    }
}

void destroiLista(ListaDpl* lista)
{
    ListaDpl* p;
    while (lista != NULL)
    {
        p = lista->prox;
        free(lista);
        lista = p;
    }
}