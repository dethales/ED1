#include "ABB.h"
#include "Aluno.h"

#include <stdio.h>
#include <stdlib.h>

struct arvore
{
    Aluno* aluno;
    Arvore* esquerda;
    Arvore* direita;
};


Arvore* criaABB(void)
{
    return NULL;
}

Arvore* insereABB(Arvore* abb, Aluno* aluno)
{
    // chega no final da arvore
    if (abb == NULL)
    {
        // cria um novo no
        abb = (Arvore*) malloc(sizeof(Arvore));
        abb->aluno = aluno;
        abb->esquerda = NULL;
        abb->direita = NULL;
    }
    else if (retornaMatricula(aluno) < retornaMatricula(abb->aluno))
        abb->esquerda = insereABB(abb->esquerda, aluno);
    else
        abb->direita = insereABB(abb->direita, aluno);
    
    return abb;
}

void imprimeNo(Arvore* abb)
{
    // arvore vazia
    if (abb == NULL)
        return;

    imprimeAluno(abb->aluno);
}

void imprimeABB(Arvore* abb)
{
    // final da arvore
    if (abb == NULL)
        return;
    

    imprimeABB(abb->esquerda);
    imprimeAluno(abb->aluno);
    imprimeABB(abb->direita);

}

Arvore* buscaABB(Arvore* abb, int matriculaChave)
{
    // final da arvore
    if (abb == NULL)
        return NULL;

    // a matricula esta a esquerda (menor) do no atual
    if (matriculaChave < retornaMatricula(abb->aluno))
        return buscaABB(abb->esquerda, matriculaChave);

    // a matricula esta a direita (maior) do no atual
    if (matriculaChave > retornaMatricula(abb->aluno))
        return buscaABB(abb->direita, matriculaChave);

    // achou o aluno
    return abb;
}

Arvore* retiraABB(Arvore* abb, int matriculaChave)
{
    // buscando na arvore:
    abb = buscaABB(abb, matriculaChave);


    // final da arvore ou nao encontrou
    if (abb == NULL)
        return NULL;

    // no folha
    if (abb->direita == NULL && abb->esquerda == NULL)
    {
        free(abb);
        abb = NULL;
    }

    // um filho a direita
    else if (abb->esquerda == NULL)
    {
        Arvore* aux = abb;
        abb = abb->direita;
        free(aux);
    }

    // um filho a esquerda
    else if (abb->direita == NULL)
    {
        Arvore* aux = abb;
        abb = abb->esquerda;
        free(aux);
    }

    // dois filhos
    else
    {
        // acha o antecessor
        Arvore* noAntecessor = abb->esquerda;
        while(noAntecessor->direita != NULL)
            noAntecessor = noAntecessor->direita;

        // troca os alunos do no abb pelo do antecessor
        Aluno* aux = abb->aluno;
        abb->aluno = noAntecessor->aluno;
        noAntecessor->aluno = aux;

        // retira o no que agora caiu na subarvore da esquerda
        abb->esquerda = retiraABB(abb->esquerda, matriculaChave);
    }

    return abb;
}

Arvore* liberaABB(Arvore* abb)
{
    if (abb != NULL)
    {
        abb->esquerda = liberaABB(abb->esquerda);
        abb->direita = liberaABB(abb->direita);
        free(abb);
    }

    return NULL;
}