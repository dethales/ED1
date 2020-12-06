#ifndef ABB_H
#define ABB_H

#include "Aluno.h"

typedef struct arvore Arvore;

Arvore* criaABB(void);
Arvore* insereABB(Arvore* abb, Aluno* aluno);
void imprimeNo(Arvore* abb);
void imprimeABB(Arvore* abb);
Arvore* buscaABB(Arvore* abb, int matriculaChave);
Arvore* retiraABB(Arvore* abb, int matriculaChave);
Arvore* liberaABB(Arvore* abb);

#endif // ABB_H