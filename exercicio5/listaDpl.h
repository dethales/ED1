#ifndef LISTA_DPL_H
#define LISTA_DPL_H

typedef struct listaDpl ListaDpl;

ListaDpl* criaLista(void);
ListaDpl* insereLista(ListaDpl* lista, const char* nome);
ListaDpl* retiraLista(ListaDpl* lista, const char* chave);
void imprimeLista(ListaDpl* lista);
void destroiLista(ListaDpl* lista);


#endif // LISTA_DPL_H