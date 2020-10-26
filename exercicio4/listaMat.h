#ifndef LISTA_MAT_H
#define LISTA_MAT_H
#include "matriz.h"

typedef struct lista Lista;

Lista* criaLista(void);
void insereLista(Lista* lista, Matriz* mat);
void imprimeLista(Lista* lista);
Matriz* retiraLista(Lista* lista, int p);
void destroiLista(Lista* lista);


#endif // LISTA_MAT_H