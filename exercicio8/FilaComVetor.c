#include "Fila.h"
#include "Aluno.h"

#include <stdlib.h>
#include <stdio.h>

struct fila
{
    Aluno* item[TAM_MAX_FILA];
    int tamanho;
    int inicio;
};


Fila* criaFila(void)
{
    Fila* f = (Fila*) malloc(sizeof(Fila));

    f->inicio = 0;
    f->tamanho = 0;

    return f;
}

void insereFila(Fila* fila, Aluno* aluno)
{
    // fila cheia ou invalida
    if ( (fila->tamanho >= TAM_MAX_FILA) || (fila == NULL) )
    {
        fprintf(stderr, "ERRO: Fila cheia ou invalida\n");
        return;
    }

    // acha a posicao final da fila circular
    int final = (fila->inicio + fila->tamanho) % TAM_MAX_FILA;

    // insere o aluno no final da fila e atualiza o tamanho
    fila->item[final] = aluno;
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

    Aluno* alunoRetirado = fila->item[fila->inicio];

    // incrementa a posicao inicial da fila circular
    fila->inicio = (fila-> inicio + 1) % TAM_MAX_FILA;

    // atualiza o tamanho da fila
    fila->tamanho--;

    return alunoRetirado;
}

void imprimeFila(Fila* fila)
{
    int posicao;

    for (int i = 0; i < fila->tamanho; i++)
    {
        /*  acha a posicao absoluta na fila circular (variavel posicao)
            atraves da posicao relativa (variavel i) */
        posicao = (fila->inicio + i) % TAM_MAX_FILA;

        // imprime o item da fila
        imprimeAluno(fila->item[posicao]);
    }    
}

void destroiFila(Fila* fila)
{
    // fila invalida
    if(fila == NULL)
        return;

    free(fila);
}
