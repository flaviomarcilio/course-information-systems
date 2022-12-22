#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <unistd.h>

#include "mat.h"
#include "memlog.h" 
#include "msgassert.h"

// definicoes de operacoes a serem testadas
#define OPSOMAR 1
#define OPMULTIPLICAR 2
#define OPTRANSPOR 3

// variaveis globais para opcoes
static int opescolhida;
char logfile[100], matrizA[100], matrizB[100], matrizC[100];
int optx, opty, regmem, matriz_aleatoria;

/**
 * @brief Intruções de uso do programa
 * 
 */
void uso()
{
    fprintf(stderr, "\t---------------- Parametros do Programa -----------------\n");
    fprintf(stderr, "\t-s ........... Soma duas matrizes (A + B = C )\n");
    fprintf(stderr, "\t-m ........... Multiplica duas matrizes (AB = C)\n");
    fprintf(stderr, "\t-t ........... Determina a transposta de uma matriz\n");
    fprintf(stderr, "\t-p <arq> ..... Arquivo para registro de desempenho\n");
    fprintf(stderr, "\t-l ........... Registra padrao de acesso e localidade\n");
    fprintf(stderr, "\t-x <int> ..... Numero de linhas para matriz aleatoria\n");
    fprintf(stderr, "\t-y <int> ..... Numero de colunas para matriz aleatoria\n");
    fprintf(stderr, "\t-1 <arq> ..... Arquivo para leitura da matriz 1\n");
    fprintf(stderr, "\t-2 <arq> ..... Arquivo apra leitura da matriz 2\n");
    fprintf(stderr, "\t-o <arq> ..... Arquivo para gravar a matriz resultante\n");
    fprintf(stderr, "\n");
}

/**
 * @brief Lê as opções da linha de comando e inicializa as variáveis.
 * 
 * @param argc Quantos argumentos que acompanham argv
 * @param argv Uma matriz que representa os argumentos de linha de comando inseridos pelo usuário do programa
 */
void parse_args(int argc, char **argv)
{
    int opt;

    opescolhida = -1;
    optx = -1;
    opty = -1;
    regmem = 0;
    matriz_aleatoria = 0;
    logfile[0] = 0;
    matrizA[0] = 0;
    matrizB[0] = 0;
    matrizC[0] = 0;

    while ((opt = getopt(argc, argv, "smtp:1:2:x:y:o:lh")) != EOF)
    {
        switch(opt)
        {
            case 's':
                avisoAssert(opescolhida == -1,"Mais de uma operacao escolhida");
                opescolhida = OPSOMAR;
                break;
            case 'm':
                avisoAssert(opescolhida == -1,"Mais de uma operacao escolhida");
                opescolhida = OPMULTIPLICAR;
                break;
            case 't':
                avisoAssert(opescolhida == -1,"Mais de uma operacao escolhida");
                opescolhida = OPTRANSPOR;
                break;
            case 'p':
                strcpy(logfile, optarg);
                erroAssert(strlen(logfile) > 0, "matop - nome de arquivo de registro de acesso tem que ser definido");
                break;
            case '1':
                strcpy(matrizA, optarg);
                erroAssert(strlen(matrizA) > 0, "matop - nome de arquivo da matriz A tem que ser definido");
                break;
            case '2':
                strcpy(matrizB, optarg);
                erroAssert(strlen(matrizB) > 0, "matop - nome de arquivo da matriz B tem que ser definido");
                break;
            case 'x':
                matriz_aleatoria = 1;
                optx = atoi(optarg);
                erroAssert(optx > 0, "matop - dimensao X da matriz tem que ser positiva");
                break;
            case 'y':
                matriz_aleatoria = 1;
                opty = atoi(optarg);
                erroAssert(opty > 0, "matop - dimensao Y da matriz tem que ser positiva");
                break;
            case 'o':
                strcpy(matrizC, optarg);
                erroAssert(strlen(matrizC) > 0, "matop - nome de arquivo da matriz C tem que ser definido");
                break;
            case 'l':
                regmem = 1;
                break;
            case 'h':
            default:
                uso();
                exit(1);
        }
    }

    erroAssert(opescolhida > 0, "matop - necessario escolher operacao");
    erroAssert(strlen(logfile) > 0, "matop - nome de arquivo de registro de acesso tem que ser definido");
    if (!matriz_aleatoria)
    {
        if (opescolhida == OPTRANSPOR)
        {
            erroAssert(strlen(matrizA) > 0, "matop - nome de arquivo da matriz A tem que ser definido");
            erroAssert(strlen(matrizC) > 0, "matop - nome de arquivo da matriz C tem que ser definido");
        }
        else
        {
            erroAssert(strlen(matrizA) > 0, "matop - nome de arquivo da matriz A tem que ser definido");
            erroAssert(strlen(matrizB) > 0, "matop - nome de arquivo da matriz B tem que ser definido");
            erroAssert(strlen(matrizC) > 0, "matop - nome de arquivo da matriz C tem que ser definido");
        }
    }
}

/**
 * @brief Lê uma matriz de um arquivo de texto
 * 
 * @param mat Referência para a matriz lida
 * @param file Nome do documento que será lido
 * @param id Identificação da matriz lida
 */
void leMatriz(mat_tipo *mat, char file[], int id)
{
    int rows, columns;
    double elemento;

    FILE *arq;
    int retclose;

    arq = fopen(file, "r");
    erroAssert(arq != NULL, "Nao foi possivel abril o arquivo para leitura");

    fscanf(arq, "%d %d", &rows, &columns);
    erroAssert(rows > 0, "Dimensao invalida");
    erroAssert(columns > 0, "Dimensao invalida");

    criaMatriz(mat, rows, columns, id);
    inicializaMatrizNula(mat);
    
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < columns; j++)
        {
            elemento = 0;
            fscanf(arq, "%lf", &elemento);
            mat->matrix[i][j] = elemento;
            ESCREVEMEMLOG((long int)(&(mat->matrix[i][j])), sizeof(double), mat->id);
        }
    }
    retclose = fclose(arq);
    erroAssert(retclose == 0, "Falha no fechamento do arquivo de leitura");
}

/**
 * @brief Escreve uma matriz em um documento de texto
 * 
 * @param mat Matriz que será gravada
 * @param file Nome do arquivo de resultado
 */
void escreveMatriz(mat_tipo *mat, char *file)
{
    int i, j;

    FILE *arq;
    int retclose;

    arq = fopen(file, "w");
    erroAssert(arq != NULL, "Não foi possivel abrir o arquivo para escrita");

    fprintf(arq, "%d %d\n", mat->rows, mat->columns);

    for (i = 0; i < mat->rows; i++)
    {
        for (j = 0; j < mat->columns; j++)
        {
            fprintf(arq, "%lf ", mat->matrix[i][j]);
            LEMEMLOG((long int)(&(mat->matrix[i][j])), sizeof(double), mat->id);
        }
        fprintf(arq, "\n");
    }
    retclose = fclose(arq);
    erroAssert(retclose == 0, "Falha no fechamento do arquivo de escrita");
}

memlog_tipo ml;

/**
 * @brief Programa principal para a execução de operações de matrizes.
 * 
 * @param argc Quantos argumentos que acompanham argv
 * @param argv Uma matriz que representa os argumentos de linha de comando inseridos pelo usuário do programa
 * @return 0 para sucesso, 1 para erro
 */
int main(int argc, char **argv)
{
    mat_tipo a, b, c;

    parse_args(argc, argv);

    // iniciar registro de acesso
    iniciaMemLog(logfile);

    // ativar ou não registro de acesso
    if (regmem)
    {
        ativaMemLog();
    }
    else
    {
        desativaMemLog();
    }

    // execucao dependente da operacao escolhida
    switch (opescolhida)
    {
        case OPSOMAR:
            // Fase 0 - Alocação das matrizes na memória
            defineFaseMemLog(0);
            if (matriz_aleatoria)
            {
                criaMatriz(&a, optx, opty, 0);
                inicializaMatrizAleatoria(&a);
                criaMatriz(&b, optx, opty, 1);
                inicializaMatrizAleatoria(&b);
                criaMatriz(&c, optx, opty, 2);
                inicializaMatrizNula(&c);
            }
            else
            {
                leMatriz(&a, matrizA, 0);
                leMatriz(&b, matrizB, 1);
                criaMatriz(&c, a.rows, a.columns, 2);
                inicializaMatrizNula(&c);
            }

            // Fase 1 - Operação com as matrizes
            defineFaseMemLog(1);
            acessaMatriz(&a);
            acessaMatriz(&b);
            acessaMatriz(&c);
            somaMatrizes(&a, &b, &c);

            // Fase 2 - Gravação do resultado
            defineFaseMemLog(2);
            acessaMatriz(&c);

            if (regmem && matriz_aleatoria)
                imprimeMatriz(&c);
            else
                escreveMatriz(&c, matrizC);

            destroiMatriz(&a);
            destroiMatriz(&b);
            destroiMatriz(&c);
            break;
        case OPMULTIPLICAR:
            // Fase 0 - Alocação das matrizes na memória
            defineFaseMemLog(0);
            if (matriz_aleatoria)
            {
                criaMatriz(&a, optx, opty, 0);
                inicializaMatrizAleatoria(&a);
                criaMatriz(&b, optx, opty, 1);
                inicializaMatrizAleatoria(&b);
                criaMatriz(&c, optx, opty, 2);
                inicializaMatrizNula(&c);
            }
            else
            {
                leMatriz(&a, matrizA, 0);
                leMatriz(&b, matrizB, 1);
                criaMatriz(&c, a.rows, b.columns, 2);
                inicializaMatrizNula(&c);
            }

            // Fase 1 - Operação com as matrizes
            defineFaseMemLog(1);
            acessaMatriz(&a);
            acessaMatriz(&b);
            acessaMatriz(&c);
            multiplicaMatrizes(&a, &b, &c);

            // Fase 2 - Gravação do resultado
            defineFaseMemLog(2);
            acessaMatriz(&c);

            if (regmem && matriz_aleatoria)
                imprimeMatriz(&c);
            else
                escreveMatriz(&c, matrizC);

            destroiMatriz(&a);
            destroiMatriz(&b);
            destroiMatriz(&c);
            break;
        case OPTRANSPOR:
           // Fase 0 - Alocação das matrizes na memória
            defineFaseMemLog(0);
            if (matriz_aleatoria)
            {
                criaMatriz(&a, optx, opty, 0);
                inicializaMatrizAleatoria(&a);
            }
            else
            {
                leMatriz(&a, matrizA, 0);
            }

            // Fase 1 - Operação com as matrizes
            defineFaseMemLog(1);
            acessaMatriz(&a);
            transpoeMatriz(&a);

            // Fase 2 - Gravação do resultado
            defineFaseMemLog(2);
            acessaMatriz(&a);

            if (regmem && matriz_aleatoria)
                imprimeMatriz(&a);
            else
                escreveMatriz(&a, matrizC);

            destroiMatriz(&a);
            break;
        default:
            exit(1);
    }

    // conclui registro de acesso
    return finalizaMemLog();
}