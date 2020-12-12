#include <stdio.h>
#include <stdlib.h>
#include "string.h"

// armazena o conetudo do arquivo no vetor de strings 'linhas'
// e retorna o numero de linhas do arquivo
int leArquivo(char*** linhas, char* nomeArquivoEntrada);

int main(void)
{
    char** expressoes;
    int numeroLinhas = leArquivo(&expressoes, "entrada.txt");


    for(int i = 0; i < numero)
    free(expressoes);
}

int leArquivo(char*** linhas, char* nomeArquivoEntrada)
{
    // tamanho inicial do vetor de strings que armazena as linhas do arquivo
    size_t tamanhoVetorExpressoes = 10;

    // buffer que armazena cada linha lida
    char* bufferLinha = NULL;

    // tamanho do buffer, gerenciado pelo getline()
    size_t tamanhoBufferLinha = 0;

    // conta o numero de linhas ja lidas do arquivo
    int contagemLinhas = 0;

    // numero de char na linha, eh ssize porque getline() pode retornar -1
    ssize_t tamanhoLinha;

    // aloca o vetor de strings que armazena as linhas lidas
    char** expressoes = (char**) malloc(tamanhoVetorExpressoes * sizeof(char*));

    if(expressoes == NULL)
    {
        perror("Erro de alocacao");
        exit(EXIT_FAILURE);
    }

    // abre o aquivo "entrada.txt"
    FILE* arquivoEntrada = fopen(nomeArquivoEntrada, "r");

    // testa se a abertura do arquivo foi bem sucedida
    if(arquivoEntrada == NULL)
    {
        perror(nomeArquivoEntrada);
        exit(EXIT_FAILURE);
    }

    do
    {
        // le uma linha usando getline(), a propria funcao determina
        // o tamanho do buffer, retorna -1 quando detecta EOF
        tamanhoLinha = getline(&bufferLinha, &tamanhoBufferLinha, arquivoEntrada);

        // o numero de linhas lidas ultrapassou o numero de linhas alocadas
        // para o vetor de strings expressoes. realocando uma quantidade
        // maior de linhas
        if(contagemLinhas >= tamanhoVetorExpressoes)
        {
            tamanhoVetorExpressoes += tamanhoVetorExpressoes;
    
            // realoca para uma variavel temporaria para testar se deu certo
            char** temp = realloc(expressoes, tamanhoVetorExpressoes * sizeof(char*));
            if(temp == NULL)
            {
                perror("Erro de alocacao");
                exit(EXIT_FAILURE);
            }

            // novo vetor de expressoes
            expressoes = temp;
        }

        // copia do arquivo para o vetor de strings
        expressoes[contagemLinhas] = strdup(bufferLinha);

        contagemLinhas++;

    } while (tamanhoLinha >= 0); // geline() retorna -1 quando terminar o arquivo

    // corrige o valor pois a ultima linha lida eh vazia
    contagemLinhas--;

    free(bufferLinha);

    if (fclose(arquivoEntrada);

    // retorna o ponteiro
    *linhas = expressoes;

    return contagemLinhas;
}