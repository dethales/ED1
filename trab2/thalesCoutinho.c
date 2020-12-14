#include "arv.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// armazena o conetudo do arquivo no vetor de strings 'linhas'
// e retorna o numero de linhas do arquivo
int leArquivo(char*** linhas, char* nomeArquivoEntrada);


int main(void)
{
    char** expressoes;
    int numeroLinhas = leArquivo(&expressoes, "entrada.txt");

/* impressao das strings
    for(int i = 0;  i < numeroLinhas; i++)
    {
        printf("%s\n", expressoes[i]);
    }
*/

    parsing(expressoes[0]);

    for (int i = 0; i < numeroLinhas; i++)
    {
        free(expressoes[i]);
    }
    free(expressoes);
}

int leArquivo(char*** linhas, char* nomeArquivoEntrada)
{
    // tamanho inicial do vetor de strings que armazena as linhas do arquivo
    size_t tamanhoVetorExpressoes = 1;

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
        // para o vetor de strings expressoes. realocando uma quantidade
        // maior de linhas
        if (contagemLinhas >= tamanhoVetorExpressoes)
        {
            tamanhoVetorExpressoes += tamanhoVetorExpressoes;
    
            // realoca para uma variavel temporaria para testar se deu certo
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

