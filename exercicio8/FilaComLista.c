#include "Fila.h"

#include <stdlib.h>
#include <stdio.h>

typedef struct celula Celula;
struct celula
{
    Celula* prox;
    Aluno* aluno;
};

struct fila
{
    Celula* primeiro;
    Celula* ultimo;
    int tamanho;
};



Fila* criaFila(void)
{
    Fila* f = (Fila*) malloc(sizeof(Fila));

    f->primeiro = NULL;
    f->ultimo = NULL;
    f->tamanho = 0;

    return f;
}

void insereFila(Fila* fila, Aluno* aluno)
{
    // fila cheia ou invalida
    if (fila->tamanho >= TAM_MAX_FILA || fila == NULL)
    {
        fprintf(stderr, "ERRO: Fila cheia ou invalida\n");
        return;
    }

    // cria e preenche a celula
    Celula* celula = (Celula*) malloc(sizeof(Celula));
    celula->aluno = aluno;
    celula->prox = NULL;

    
    // fila vazia
    if (fila->ultimo == NULL)
        // a fila fica com uma unica celula
        fila->primeiro = celula;
    else
    {
        // precisa encadear a ultima celula da fila com a nova celula
        fila->ultimo->prox = celula;
    }

    fila->ultimo = celula;
    fila->tamanho++;
}

Aluno* retiraFila(Fila* fila)
{
    // fila vazia ou invalida
    if ( (fila->tamanho == 0) || (fila == NULL) )
    {
        fprintf(stderr, "ERRO: fila vazia ou invalida\n");
        return NULL;
    }

    // guarda a referencia da celula a ser retirada
    Celula* celulaRetirada = fila->primeiro;

    // guarda a referencia do aludo a ser retornado
    Aluno* alunoRetirado = fila->primeiro->aluno;

    // encadeia o inicio da fila
    fila->primeiro = fila->primeiro->prox;

    // fila com uma unica celula fica vazia
    if(fila->primeiro == NULL)
        fila->ultimo == NULL;

    // retira a celula
    free(celulaRetirada);
    fila->tamanho--;

    return alunoRetirado;
}

void imprimeFila(Fila* fila)
{
    for (Celula* p = fila->primeiro; p != NULL; p = p->prox)
        imprimeAluno(p->aluno);
}

void destroiFila(Fila* fila)
{
    Celula* atual = fila->primeiro;
    Celula* proxima = NULL;

    while(atual != NULL)
    {
        proxima = atual->prox;
        free(atual);
        atual = proxima;
    }

    free(fila);
}