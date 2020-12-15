#include "arv.h"

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

// variavel que representa o dado que fica armazenado em cada no
union simboloMatematico
{
    int numero;
    char operador;
};

typedef union simboloMatematico simbolo;

struct arvore
{
    simbolo elemento;
    Arvore* esquerda; // sub-arvore esquerda
    Arvore* direita; // sub-arvore direita
};

// funcoes auxiliares
static int achaPosicaoOperador(char* expressao);
static char* retiraParentesesExternos(char* expressao);

Arvore* criaArvoreVazia(void)
{
    return NULL;
}

Arvore* criaNoFolha(int numero)
{
    Arvore* arvore = (Arvore*) malloc(sizeof(Arvore));

    arvore->elemento.numero = numero;
    arvore->esquerda = NULL;
    arvore->direita = NULL;

    return arvore;
}

Arvore* criaArvoreComFilhos(char operador, Arvore* esquerda, Arvore* direita)
{
    Arvore* arvore = (Arvore*) malloc(sizeof(Arvore));

    arvore->elemento.operador = operador;
    arvore->direita = direita;
    arvore->esquerda = esquerda;

    return arvore;
}

int ArvoreVazia(Arvore* arvore)
{
    if (arvore == NULL)
        return 1;
    return 0;
}

int ArvoreEhNo(Arvore* arvore)
{
    if(arvore->esquerda == NULL && arvore->direita == NULL)
        return 1;
    return 0;
}

void imprimeArvore(Arvore* arvore)
{
    putchar('(');

    if (!ArvoreVazia(arvore))
    {
        if(ArvoreEhNo(arvore))
            printf("%d", arvore->elemento.numero);
        else
        {
            imprimeArvore(arvore->esquerda);
            putchar(arvore->elemento.operador);
            imprimeArvore(arvore->direita);
        }
    }

    putchar(')');
}

int calculaExpressao(Arvore* arvore)
{
    // no folha, retorna o numero
    if(ArvoreEhNo(arvore))
        return arvore->elemento.numero;

    // no com filhos retorna a operacao a ser feita nos dois filhos
    switch (arvore->elemento.operador)
    {
        case '+':
            return  calculaExpressao(arvore->esquerda) +
                    calculaExpressao(arvore->direita);
            break;
        case '-':
            return  calculaExpressao(arvore->esquerda) -
                    calculaExpressao(arvore->direita);
            break;
        case '*':
            return  calculaExpressao(arvore->esquerda) *
                    calculaExpressao(arvore->direita);
            break;
        case '/':
            return  calculaExpressao(arvore->esquerda) /
                    calculaExpressao(arvore->direita);
            break;
        default:
            break;
    }
}

void destroiArvore(Arvore* arvore)
{
    if (!ArvoreVazia(arvore))
    {
        destroiArvore(arvore->esquerda);
        destroiArvore(arvore->direita);
        free(arvore);
    }
}

// cria a arvore atraves de texto
Arvore* parsing(char* expressao)
{
    expressao = retiraParentesesExternos(expressao);
    int posicaoOperador = achaPosicaoOperador(expressao);

    // nao achou operador, no folha contendo numero
    if (posicaoOperador == -1)
    {
        expressao = retiraParentesesExternos(expressao);
        int numero = atoi(expressao);
        return criaNoFolha(numero);
    }
    // achou operador, o no contem 2 filhos (somente operacoes binarias)
    else
    {
        char* expressaoArvoreEsquerda;
        char* expressaoArvoreDireita;
        char operador;

        // copia o char que representa a operacao
        operador = expressao[posicaoOperador];

        // restante da string depois do operador matematico
        expressaoArvoreDireita = &expressao[posicaoOperador + 1];

        // substitui o caractere do operador por um \0
        expressao[posicaoOperador] = '\0';
        expressaoArvoreEsquerda = expressao;

        /*  exemplo do que foi feito:
            "(((47)-(7))*(2))-(3)\0"
             ^               ^
        expressao     posicaoOperador
            
            "(((47)-(7))*(2))\0(3)\0"
             ^                 ^
        arvEsquerda        arvDireita

            a string foi separada em duas usando o \0 como separador
        */

       // chama recursivamente a funcao parsing()
        return criaArvoreComFilhos( operador,
                                    parsing(expressaoArvoreEsquerda),
                                    parsing(expressaoArvoreDireita));
    }
}

// funcao que retira o primeiro ou  ou ultimo caractere (ou ambos) somente
// se os respectivos caracteres forem parenteses
static char* retiraParentesesExternos(char* expressao)
{
    if (expressao == NULL)
        return NULL;

    int tamanho = strlen(expressao);

    if (tamanho == 0)
        return expressao;

    // retira o ultimo parentese
    if(expressao[tamanho - 1] == ')')
    {
        expressao[tamanho - 1] = '\0';
    }

    if(expressao[0] == '(')
        // a string nao eh modificada apenas o ponteiro.
        // a referencia para o inicio da string nao eh perdida pois
        // ainda tem um ponteiro na main apontando para o inicio da string
        expressao++;

    return expressao;
}

// funcao que acha a posicao do operador (+, -, *, /) na string
static int achaPosicaoOperador(char* expressao)
{
    // o operador atual eh operador que nao esta dentro de nehnum parentese
    // (porque a funcao retiraParentesesExternos() foi aplicada antes)
    // ou seja, quando nivelParentese = 0
    
    int nivelParentese = 0;
    int posicaoOperador = -1; // valor retornado quando n acha operador

    for(int i = 0; expressao[i] != '\0'; i++)
    {
        //printf("%c", expressao[i]);
        if(expressao[i] == '(')
            nivelParentese++;
        else if (expressao[i] == ')')
            nivelParentese--;
        else if (nivelParentese <= 0)
        {
            if (expressao[i] == '+' || expressao[i] == '-' ||
                expressao[i] == '*' || expressao[i] == '/')
            {
                posicaoOperador = i;
            }
        }
    }

    return posicaoOperador;
}