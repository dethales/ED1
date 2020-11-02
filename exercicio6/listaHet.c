#include "listaHet.h"

#include <stdlib.h>
#include <stdio.h>

enum profissao
{
    PROFESSOR,
    ALUNO
};
typedef enum profissao Profissao;

typedef struct celula Celula;

struct celula
{
    Celula* prox;
    void* pessoa;
    Profissao profissao;
};

struct listaHet
{
    Celula* prim;
    Celula* ult;
};

ListaHet* criaListaHet(void)
{
    ListaHet* lista = (ListaHet*) malloc(sizeof(ListaHet));

    lista->prim = NULL;
    lista->ult = NULL;

    return lista;
}

void insereAluno(ListaHet* lista, Aluno* aluno)
{
    Celula* celula = (Celula*) malloc(sizeof(Celula));

    celula->prox = lista->prim;
    celula->pessoa = aluno;
    celula->profissao = ALUNO;

    lista->prim = celula;
    if(lista->ult == NULL) // unica celula
        lista->ult = celula;
}

void insereProfessor(ListaHet* lista, Professor* professor)
{
    Celula* celula = (Celula*) malloc(sizeof(Celula));

    celula->prox = lista->prim;
    celula->pessoa = professor;
    celula->profissao = PROFESSOR;

    lista->prim = celula;
    if(lista->ult == NULL) // unica celula
        lista->ult = celula;
}

void imprimeListaHet(ListaHet* lista)
{
    for(Celula* p = lista->prim; p != NULL; p = p->prox)
    {
        if(p->profissao == ALUNO)
        {
            printf("ALUNO -\t");
            imprimeAluno((Aluno*) p->pessoa);
        }
        else if (p->profissao == PROFESSOR)
        {
            printf("PROFESSOR -\t");
            imprimeProfessor((Professor*) p->pessoa);
        }
    }
}

float valorChurrasco(ListaHet* lista)
{
    float valor = 0.0;

    for (Celula* p = lista->prim; p != NULL; p = p->prox)
    {
        if (p->profissao == ALUNO)
            valor += 30.0;
        else if (p->profissao == PROFESSOR)
            valor += 0.02 * retornaSalario((Professor*) p->pessoa);
    }

    return valor;
}

void destroiLista(ListaHet* lista)
{
    Celula* p = lista->prim;
    Celula* q;

    while (p != NULL)
    {
        q = p->prox;
        free(p);
        p = q;
    }

    free(lista);
}