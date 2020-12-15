#ifndef ARVORE_H
#define ARVORE_H


typedef struct arvore Arvore;

Arvore* criaArvoreVazia(void);
Arvore* criaNoFolha(int numero);
Arvore* criaArvoreComFilhos(char operador, Arvore* esquerda, Arvore* direita);
int ArvoreVazia(Arvore* arvore);
void imprimeArvore(Arvore* arvore);
void destroiArvore(Arvore* arvore);
Arvore* parsing(char* expressao);
Arvore* criaNoFolha(int numero);
int calculaExpressao(Arvore* arvore);

#endif // ARVORE_H