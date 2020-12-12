#ifndef ARVORE_H
#define ARVORE_H

#include "Aluno.h"

typedef struct arvore Arvore;

Arvore* criaArvoreVazia(void);
Arvore* criaArvore(Aluno* aluno, Arvore* esquerda, Arvore* direita);
int ArvoreVazia(Arvore* arvore);
int pertenceArvore(Arvore* arvore, Aluno* aluno);
int folhas(Arvore* arvore);
int ocorrencias(Arvore* arvore, Aluno* aluno);
int altura(Arvore* arvore);
void imprimeArvore(Arvore* arvore);
void destroiArvore(Arvore* arvore);

#endif // ARVORE_H