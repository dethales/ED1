#ifndef ALUNO_H
#define ALUNO_H

typedef struct aluno Aluno;

Aluno* criaAluno(char* nome, int matricula);
void imprimeAluno(Aluno* aluno);

// verifica se o aluno a eh igual ao aluno b
int comparaAluno(Aluno* a, Aluno* b);


void destroiAluno(Aluno* aluno);


#endif // ALUNO_H