#ifndef FILA_H
#define FILA_H

#include "Aluno.h"
#define TAM_MAX_FILA 6

typedef struct fila Fila;


Fila* criaFila(void);
void insereFila(Fila* fila, Aluno* aluno);
Aluno* retiraFila(Fila* fila);
void imprimeFila(Fila* fila);
void destroiFila(Fila* fila);

#endif // FILA_H