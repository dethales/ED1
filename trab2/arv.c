#include "arv.h"

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

struct arvore
{
    char simbolo;
    Arvore* sae; // sub-arvore esquerda
    Arvore* sad; // sub-arvore direita
};

Arvore* criaArvoreVazia(void)
{
    return NULL;
}

Arvore* criaArvore(char simbolo, Arvore* esquerda, Arvore* direita)
{
    Arvore* arvore = (Arvore*) malloc(sizeof(Arvore));

    arvore->simbolo = simbolo;
    arvore->sae = esquerda;
    arvore->sad = direita;

    return arvore;
}

int ArvoreVazia(Arvore* arvore)
{
    if (arvore == NULL)
        return 1;
    return 0;
}

int pertenceArvore(Arvore* arvore, char simbolo)
{
    if (ArvoreVazia(arvore))
        return 0;

    return  (arvore->simbolo == simbolo) ||
            pertenceArvore(arvore->sae, simbolo) || 
            pertenceArvore(arvore->sad, simbolo);
}

int folhas(Arvore* arvore)
{
    if (ArvoreVazia(arvore))
        return 0;

    return 1 + folhas(arvore->sae) + folhas(arvore->sad);
}

int ocorrencias(Arvore* arvore, char simbolo)
{
    // fim da arvore
    if (ArvoreVazia(arvore))
        return 0;

    // conta um caso tenha o nome
    if (arvore->simbolo == simbolo)
        return 1 + ocorrencias(arvore->sae, simbolo) + ocorrencias(arvore->sad, simbolo);

    // conta zero caso n tenha o nome
    return ocorrencias(arvore->sae, simbolo) + ocorrencias(arvore->sad, simbolo);
}

int altura(Arvore* arvore)
{
    if (ArvoreVazia(arvore))
        return -1;
    
    if (altura(arvore->sae) > altura(arvore->sad))
        return 1 + altura(arvore->sae);
    else
        return 1 + altura(arvore->sad);
    

}

void imprimeArvore(Arvore* arvore)
{
    putchar('<');

    if (!ArvoreVazia(arvore))
    {
        putchar(arvore->simbolo);
        imprimeArvore(arvore->sae);
        imprimeArvore(arvore->sad);
    }

    printf("> ");
}

void destroiArvore(Arvore* arvore)
{
    if (!ArvoreVazia(arvore))
    {
        destroiArvore(arvore->sae);
        destroiArvore(arvore->sad);
        free(arvore);
    }
}

char* parsing(char* expressao)
{
    printf("%s\n", expressao);
    
    expressao = retiraParentesesExternos(expressao);
    printf("%s\n", expressao);

    int a = achaPosicaoOperador(expressao);
}

// funcao que retira o primeiro ou  oultimo caractere (ou ambos) somente
// se os respectivos caracteres forem parenteses
char* retiraParentesesExternos(char* expressao)
{
    if (expressao == NULL)
        return NULL;

    int tamanho = strlen(expressao);

    if (tamanho == 0)
        return expressao;

    // retira o ultimo parentese
    if(expressao[tamanho - 1] == ')')
        expressao[tamanho - 1] = '\0';

    if(expressao[0] == '(')
        // a string nao eh modificada apenas o ponteiro.
        // a referencia para o inicio da string nao eh perdida pois
        // ainda tem um ponteiro na main apontando para o inicio da string
        expressao++;

    return expressao;
}

int achaPosicaoOperador(char* expressao)
{
    // o operador atual eh operador que nao esta dentro de nehnum parentese
    // (porque a funcao retiraParentesesExternos() foi aplicada antes)
    
    int nivelParentese = 0;

    for(int i = 0; expressao[i] != '\0'; i++)
    {
        printf("%c", expressao[i]);
        if(expressao[i] == '(')
            nivelParentese++;
        else if(expressao[i] == ')')
            nivelParentese--;
        
        printf("");
    }
}