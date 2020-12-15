#include "arv.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// armazena o conetudo do arquivo no vetor de strings 'linhas'
// e retorna o numero de linhas do arquivo
int leArquivo(char*** linhas, char* nomeArquivoEntrada);
void escreveArquivo(char* nomeArquivoSaida, int* saida, int numeroLinhas);


int main(void)
{
    char** expressoes;

    int numeroLinhas = leArquivo(&expressoes, "entrada.txt");
    int saida[numeroLinhas];
    Arvore* arvore[numeroLinhas];

    // cria cada arvore e calcula o valor das expressoes
    for(int i = 0; i < numeroLinhas; i++)
    {
        arvore[i] = parsing(expressoes[i]);
        saida[i] = calculaExpressao(arvore[i]);
    }

    escreveArquivo("saida.txt", saida, numeroLinhas);

    // libera memoria
    for (int i = 0; i < numeroLinhas; i++)
    {
        destroiArvore(arvore[i]);
        free(expressoes[i]);
    }
    free(expressoes);

    return EXIT_SUCCESS;
}

/* 
    le o arquivo "nomeArquivoEntrada" ja existente
    e armazena cada linha em uma posicao de um vetor,
    retorna o numero de linhas lidas
*/
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

    if (expressoes == NULL)
    {
        perror("Erro de alocacao");
        exit(EXIT_FAILURE);
    }

    // abre o aquivo "entrada.txt"
    FILE* arquivoEntrada = fopen(nomeArquivoEntrada, "r");

    // testa se a abertura do arquivo foi bem sucedida
    if (arquivoEntrada == NULL)
    {
        perror(nomeArquivoEntrada);
        exit(EXIT_FAILURE);
    }

    // a funcao getline() le a linha, armazena no buffer e retorna o numero
    // de caracteres na linha, retorna -1 quando terminar o arquivo
    while (tamanhoLinha = getline(&bufferLinha, &tamanhoBufferLinha, arquivoEntrada) != -1)
    {
        // o numero de linhas lidas ultrapassou o numero de linhas alocadas
        // para o vetor de strings "expressoes". realocando uma quantidade
        // maior de linhas...
        if (contagemLinhas >= tamanhoVetorExpressoes)
        {
            tamanhoVetorExpressoes += tamanhoVetorExpressoes;
    
            // realoca em uma variavel temporaria para testar se o realloc deu certo
            char** temp = realloc(expressoes, tamanhoVetorExpressoes * sizeof(char*));
            if (temp == NULL)
            {
                perror("Erro de alocacao");
                exit(EXIT_FAILURE);
            }

            expressoes = temp;
        }

        // remove o '\n' do buffer
        bufferLinha[strcspn(bufferLinha, "\n")] = 0;

        // copia o buffer para o vetor de linhas
        expressoes[contagemLinhas] = strdup(bufferLinha);
        if(expressoes[contagemLinhas] == NULL)
        {
            perror("Erro de alocacao");
            exit(EXIT_FAILURE);
        }
    

        contagemLinhas++;
    }

    // libera o buffer de leitura do arquivo
    free(bufferLinha);

    // fecha o arquivo e checa por erros
    if (fclose(arquivoEntrada))
    {
        perror(nomeArquivoEntrada);
        exit(EXIT_FAILURE);
    }

    // retorna o ponteiro
    *linhas = expressoes;

    // retorna o numero de linhas
    return contagemLinhas;
}

/*
*/
void escreveArquivo(char* nomeArquivoSaida, int* saida, int numeroLinhas)
{
    int flagErroEscrita = EXIT_SUCCESS;
    FILE* arquivoSaida = fopen(nomeArquivoSaida, "w");

    // testa se a abertura do arquivo foi bem sucedida
    if (arquivoSaida == NULL)
    {
        perror(nomeArquivoSaida);
        exit(EXIT_FAILURE);
    }

    for(int i = 0; i < numeroLinhas; i++)
    {
        fprintf(arquivoSaida, "%d", saida[i]);
        // checa por erros na escrita
        if (ferror(arquivoSaida))
        {
            flagErroEscrita = EXIT_FAILURE;
            break;
        }
        // checa se nao eh a ultima linha
        if(i < numeroLinhas - 1)
        {
            // coloca '\n', exceto na ultima linha
            fputc('\n', arquivoSaida);
            // checa por erros na escrita
            if (ferror(arquivoSaida))
            {
                flagErroEscrita = EXIT_FAILURE;
                break;
            }
        }
    }

    // fecha o arquivo e checa por erros
    if (fclose(arquivoSaida) || flagErroEscrita == EXIT_FAILURE)
    {
        perror(nomeArquivoSaida);
        exit(EXIT_FAILURE);
    }
}