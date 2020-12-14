#include "Aluno.h"
#include "Professor.h"

typedef struct listaHet ListaHet;

ListaHet* criaListaHet(void);
void insereAluno(ListaHet* lista, Aluno* aluno);
void insereProfessor(ListaHet* lista, Professor* professor);
void imprimeListaHet(ListaHet* lista);
float valorChurrasco(ListaHet* lista);
void destroiLista(ListaHet* lista);