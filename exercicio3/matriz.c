#include <stdlib.h>
#include <stdio.h>
#include "matriz.h"

struct matriz
{
    int nlinhas;
    int ncolunas;
    int** mat;
};

Matriz* inicializaMatriz(int nlinhas, int ncolunas)
{
    // verifica valores de entrada negativos
    if(nlinhas < 0)
        nlinhas = -nlinhas;
    if(ncolunas < 0)
        ncolunas = -ncolunas;

    Matriz* m = (Matriz*) malloc(sizeof(Matriz));

    m->nlinhas = nlinhas;
    m->ncolunas = ncolunas;

    m->mat = (int**) calloc(nlinhas, sizeof(int*));
    for(int i = 0; i < nlinhas; i++)
    {
        m->mat[i] = (int*) calloc(ncolunas, sizeof(int));
    }

    return m;
}

void modificaElemento(Matriz* mat, int linha, int coluna, int elem)
{
    mat->mat[linha][coluna] = elem;
}

int recuperaElemento(Matriz* mat, int linha, int coluna)
{
    return mat->mat[linha][coluna];
}

int recuperaNColunas(Matriz* mat)
{
    return mat->ncolunas;
}

int recuperaNLinhas(Matriz* mat)
{
    return mat->nlinhas;
}

Matriz* transposta(Matriz* mat)
{
    Matriz* matTransposta = inicializaMatriz(mat->ncolunas, mat->nlinhas);

    for(int i = 0; i < matTransposta->nlinhas; i++)
        for(int j = 0; j < matTransposta->ncolunas; j++)
            matTransposta->mat[i][j] = mat->mat[j][i];

    return matTransposta;
}

Matriz* multiplicacao(Matriz* mat1, Matriz* mat2)
{
    Matriz* produto = inicializaMatriz(mat1->nlinhas, mat2->ncolunas);

    for(int i = 0; i < produto->nlinhas; i++)
        for(int j = 0; j < produto->ncolunas; j++)
            for(int k = 0; k < mat1->ncolunas; k++)
                produto->mat[i][j] += mat1->mat[i][k] * mat2->mat[k][j];

    return produto;
}

void imprimeMatriz(Matriz* mat)
{
    for(int i = 0; i < mat->nlinhas; i++)
    {
        for(int j = 0; j < mat->ncolunas; j++)
            printf("%d ", mat->mat[i][j]);

        printf("\n");
    }
}

void destroiMatriz(Matriz* mat)
{
    for(int i = 0; i < mat->nlinhas; i++)
        free(mat->mat[i]);

    free(mat->mat);
    free(mat);
}