#include "Arvore.h"
#include "Aluno.h"

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

struct arvore
{
    Aluno* aluno;
    Arvore* sae; // sub-arvore esquerda
    Arvore* sad; // sub-arvore direita
};

Arvore* criaArvoreVazia(void)
{
    return NULL;
}

Arvore* criaArvore(Aluno* aluno, Arvore* esquerda, Arvore* direita)
{
    Arvore* arvore = (Arvore*) malloc(sizeof(Arvore));

    arvore->aluno = aluno;
    arvore->sae = esquerda;
    arvore->sad = direita;

    return arvore;
}

int ArvoreVazia(Arvore* arvore)
{
    if (arvore == NULL)
        return 1;
    return 0;
}

int pertenceArvore(Arvore* arvore, Aluno* aluno)
{
    if (ArvoreVazia(arvore))
        return 0;

    return  comparaAluno(arvore->aluno, aluno) || // funcao dentro de aluno.c
            pertenceArvore(arvore->sae, aluno) || 
            pertenceArvore(arvore->sad, aluno);
}

int folhas(Arvore* arvore)
{
    if (ArvoreVazia(arvore))
        return 0;

    return 1 + folhas(arvore->sae) + folhas(arvore->sad);
}

int ocorrencias(Arvore* arvore, Aluno* aluno)
{
    // fim da arvore
    if (ArvoreVazia(arvore))
        return 0;

    // conta um caso tenha o nome
    if (comparaAluno(arvore->aluno, aluno))
        return 1 + ocorrencias(arvore->sae, aluno) + ocorrencias(arvore->sad, aluno);

    // conta zero caso n tenha o nome
    return ocorrencias(arvore->sae, aluno) + ocorrencias(arvore->sad, aluno);
}

int altura(Arvore* arvore)
{
    if (ArvoreVazia(arvore))
        return -1;
    
    if (altura(arvore->sae) > altura(arvore->sad))
        return 1 + altura(arvore->sae);
    else
        return 1 + altura(arvore->sad);
    

}

void imprimeArvore(Arvore* arvore)
{
    putchar('<');

    if (!ArvoreVazia(arvore))
    {
        imprimeAluno(arvore->aluno);
        imprimeArvore(arvore->sae);
        putchar('\n'); // razoes esteticas
        imprimeArvore(arvore->sad);
    }

    printf("> ");
}

void destroiArvore(Arvore* arvore)
{
    if (!ArvoreVazia(arvore))
    {
        destroiArvore(arvore->sae);
        destroiArvore(arvore->sad);
        free(arvore);
    }
}