#ifndef ALUNO_H
#define ALUNO_H

typedef struct aluno Aluno;

Aluno* criaAluno(char* nome, int matricula);
void imprimeAluno(Aluno* aluno);
void destroiAluno(Aluno* aluno);


#endif // ALUNO_H