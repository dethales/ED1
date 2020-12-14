#ifndef PILHA_DUPLHA_H
#define PILHA_DUPLA_H

#include "Aluno.h"
#define MaxTam 1000

typedef struct pilhaDupla PilhaDupla;

PilhaDupla* criaPilhaDupla(void);
void push1(PilhaDupla* pilhaDupla, Aluno* aluno);
void push2(PilhaDupla* pilhaDupla, Aluno* aluno);
Aluno* pop1(PilhaDupla* pilhaDupla);
Aluno* pop2(PilhaDupla* pilhaDupla);
void imprime1(PilhaDupla* pilhaDupla);
void imprime2(PilhaDupla* pilhaDupla);
void destroiPilhaDupla(PilhaDupla* pilhaDupla);


#endif // PILHA_DUPLA_H