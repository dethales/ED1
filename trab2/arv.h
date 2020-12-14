#ifndef ARVORE_H
#define ARVORE_H


typedef struct arvore Arvore;

Arvore* criaArvoreVazia(void);
Arvore* criaArvore(char simbolo, Arvore* esquerda, Arvore* direita);
int ArvoreVazia(Arvore* arvore);
int pertenceArvore(Arvore* arvore, char simbolo);
int folhas(Arvore* arvore);
int ocorrencias(Arvore* arvore, char simbolo);
int altura(Arvore* arvore);
void imprimeArvore(Arvore* arvore);
void destroiArvore(Arvore* arvore);

// faz o parsing da expressao e monta a arvore de opreacoes
char* parsing(char* expressao);


char* retiraParentesesExternos(char* expressao);
int achaPosicaoOperador(char* expressao);

#endif // ARVORE_H