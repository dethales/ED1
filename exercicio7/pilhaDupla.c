#include "pilhaDupla.h"

#include <stdlib.h>
#include <stdio.h>

struct pilhaDupla
{
    Aluno* item[MaxTam];
    int topo1;
    int topo2;
};

PilhaDupla* criaPilhaDupla(void)
{
    PilhaDupla* p = (PilhaDupla*) malloc(sizeof(PilhaDupla));

    p->topo1 = 0;
    p->topo2 = MaxTam - 1;

    return p;
}

void push1(PilhaDupla* pilhaDupla, Aluno* aluno)
{
    if(!pilhaDupla)
        return;

    if(pilhaDupla->topo1 > pilhaDupla->topo2)
        fprintf(stderr, "ERRO: Pilha dupla esta cheia\n");
    else
    {
        pilhaDupla->item[pilhaDupla->topo1] = aluno;
        pilhaDupla->topo1++;
    }
}

void push2(PilhaDupla* pilhaDupla, Aluno* aluno)
{
    if(!pilhaDupla)
    return;

    if(pilhaDupla->topo2 < pilhaDupla->topo1)
        fprintf(stderr, "ERRO: Pilha dupla esta cheia\n");
    else
    {
        pilhaDupla->item[pilhaDupla->topo2] = aluno;
        pilhaDupla->topo2--;
    }
}

Aluno* pop1(PilhaDupla* pilhaDupla)
{
    if(!pilhaDupla)
        return NULL;

    if(pilhaDupla->topo1 == 0)
        fprintf(stderr, "ERRO: Pilha esta vazia\n");
    else
    {
        pilhaDupla->topo1--;
        return pilhaDupla->item[pilhaDupla->topo1];
    }
}

Aluno* pop2(PilhaDupla* pilhaDupla)
{
    if(!pilhaDupla)
        return NULL;
  
    if(pilhaDupla->topo2 == MaxTam - 1)
        fprintf(stderr, "ERRO: Pilha esta vazia\n");
    else
    {
        pilhaDupla->topo2++;
        return pilhaDupla->item[pilhaDupla->topo2];
    }
}

void imprime1(PilhaDupla* pilhaDupla)
{
    if(!pilhaDupla)
        return;

    for(int i = 0; i < pilhaDupla->topo1; i++)
        imprimeAluno(pilhaDupla->item[i]);
}

void imprime2(PilhaDupla* pilhaDupla)
{
    if(!pilhaDupla)
        return;

    for(int i = MaxTam - 1; i > pilhaDupla->topo2; i--)
        imprimeAluno(pilhaDupla->item[i]);
}

void destroiPilhaDupla(PilhaDupla* pilhaDupla)
{
    if(!pilhaDupla)
        return;

    free(pilhaDupla);
}