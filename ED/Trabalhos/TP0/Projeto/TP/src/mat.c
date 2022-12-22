#include "mat.h"
#include "memlog.h"
#include "msgassert.h"

// limite superior da inicializacao aleatoria
#define INITRANDOMRANGE 10

/**
 * @brief Cria uma matriz com dimensões rows X columns.
 * 
 * @param mat Ponteiro para matriz
 * @param rows Número de linhas da matriz
 * @param columns Número de colunas da matriz
 * @param id Identificador da matriz para rastreamento
 */
void criaMatriz(mat_tipo *mat, int rows, int columns, int id)
{
    erroAssert(rows > 0, "Dimensao invalida");
    erroAssert(columns > 0, "Dimensao invalida");

    mat->rows = rows;
    mat->columns = columns;
    mat->id = id;

    int i;
    mat->matrix = (double **)malloc(rows * sizeof(double));
    erroAssert(mat->matrix != NULL, "Linhas nao alocadas");
    
    for (i = 0; i < rows; i++)
    {
        mat->matrix[i] = (double *)malloc(columns * sizeof(double));
        erroAssert(mat->matrix[i] != NULL, "Colunas nao alocadas");
    }
}

/**
 * @brief Inicializa a matriz com valores nulos.
 * 
 * @param mat Ponteiro para matriz
 */
void inicializaMatrizNula(mat_tipo *mat)
{
    erroAssert(mat->rows > 0, "Dimensao invalida");
    erroAssert(mat->columns > 0, "Dimensao invalida");

    int i, j;

    for (i = 0; i < mat->rows; i++)
    {
        for(j = 0; j < mat->columns; j++){
            mat->matrix[i][j] = 0;
            ESCREVEMEMLOG((long int)(&(mat->matrix[i][j])), sizeof(double), mat->id);
        }
    }
}

/**
 * @brief Inicializa a matriz com valores aleatórios
 * 
 * @param mat Ponteiro para matriz
 */
void inicializaMatrizAleatoria(mat_tipo *mat)
{
    erroAssert(mat->rows > 0, "Dimensao invalida");
    erroAssert(mat->columns > 0, "Dimensao invalida");

    int i, j;

    for (i = 0; i < mat->rows; i++)
    {
        for(j = 0; j < mat->columns; j++)
        {
            mat->matrix[i][j] = drand48()*INITRANDOMRANGE;
            ESCREVEMEMLOG((long int)(&(mat->matrix[i][j])), sizeof(double), mat->id);
        }
    }
}

/**
 * @brief Acessa a matriz para fins de registro de acesso
 * 
 * @param mat Ponteiro para matriz
 * @return double 
 */
double acessaMatriz(mat_tipo *mat)
{
    erroAssert(mat->rows > 0, "Dimensao invalida");
    erroAssert(mat->columns > 0, "Dimensao invalida");

    int i, j;
    double aux, s = 0.0;

    for (i = 0; i < mat->rows; i++)
    {
        for (j = 0; j < mat->columns; j++)
        {
            aux = mat->matrix[i][j];
            s += aux;
            LEMEMLOG((long int)(&(mat->matrix[i][j])), sizeof(double), mat->id);
        }
    }
    return s;
}

/**
 * @brief Imprime a matriz com a identificação de linhas e colunas.
 * 
 * @param mat Ponteiro para matriz
 */
void imprimeMatriz(mat_tipo *mat)
{
    erroAssert(mat->rows > 0, "Dimensao invalida");
    erroAssert(mat->columns > 0, "Dimensao invalida");

    int i, j;

    printf("%9s", " ");
    for(j = 0; j < mat->columns; j++)
        printf("%8d ", j);
    printf("\n");

    for (i = 0; i < mat->rows; i++)
    {
        printf("%8d ",i);
        for(j = 0; j < mat->columns; j++)
        {
            printf("%8.2f ", mat->matrix[i][j]);
            LEMEMLOG((long int)(&(mat->matrix[i][j])), sizeof(double), mat->id);
        }
        printf("\n");
    }
}

/**
 * @brief Insere o valor v na posição (x, y) da matriz mat.
 * 
 * @param mat Ponteiro para matriz
 * @param x Índice da linha onde o valor será inserido na matriz
 * @param y Índice da coluna onde o valor será inserido na matriz
 * @param v Valor que será inserido na matriz
 */
void escreveElemento(mat_tipo *mat, int x, int y, double v)
{
    erroAssert((x >= 0) && (x < mat->rows), "Indice invalido");
    erroAssert((y >= 0) && (y < mat->columns), "Indice invalido");

    mat->matrix[x][y] = v;
    ESCREVEMEMLOG((long int)(&(mat->matrix[x][y])), sizeof(double), mat->id);
}

/**
 * @brief Lê o elemento (x, y) da matriz mat.
 * 
 * @param mat Ponteiro para matriz
 * @param x Índice da linha do elemento que será lido
 * @param y Índice da coluna do elemento que será lido
 * @return double 
 */
double leElemento(mat_tipo *mat, int x, int y)
{
    erroAssert((x >= 0) && (x < mat->rows), "Indice invalido");
    erroAssert((y >= 0) && (y < mat->columns), "Indice invalido");

    LEMEMLOG((long int)(&(mat->matrix[x][y])), sizeof(double), mat->id);
    return mat->matrix[x][y];
}

/**
 * @brief Faz uma cópia da matriz src em dst.
 * 
 * @param src Ponteiro da matriz original que será copiada
 * @param dst Ponteiro da matriz copiada
 * @param dst_id Identificador para a matriz compiada
 */
void copiaMatriz(mat_tipo *src, mat_tipo *dst, int dst_id)
{
    erroAssert(src->rows > 0, "Dimensao invalida");
    erroAssert(src->columns > 0, "Dimensao invalida");

    int i, j;

    criaMatriz(dst, src->rows, src->columns, dst_id);
    inicializaMatrizNula(dst);

    for (i = 0; i < src->rows; i++)
    {
        for(j = 0; j < src->columns; j++)
        {
            dst->matrix[i][j] = src->matrix[i][j];
            LEMEMLOG((long int)(&(src->matrix[i][j])), sizeof(double), src->id);
            ESCREVEMEMLOG((long int)(&(dst->matrix[i][j])), sizeof(double), dst->id);
        }
    }
}

/**
 * @brief Soma as matrizes a e b e armazena o resultado em c.
 * 
 * @param a Ponteiro para a primeira matriz
 * @param b Ponteiro para a segunda matriz
 * @param c Ponteiro para a matriz de resultado
 */
void somaMatrizes(mat_tipo *a, mat_tipo *b, mat_tipo *c)
{
    erroAssert(a->rows == b->rows, "Dimensoes incompativeis");
    erroAssert(a->columns == b->columns, "Dimensoes incompativeis");
    erroAssert(c->rows == b->rows, "Dimensoes incompativeis");
    erroAssert(c->columns == b->columns, "Dimensoes incompativeis");

    int i, j;

    for (i = 0; i < a->rows; i++)
    {
        for(j = 0; j < a->columns; j++)
        {
            c->matrix[i][j] = a->matrix[i][j] + b->matrix[i][j];
            LEMEMLOG((long int)(&(a->matrix[i][j])), sizeof(double), a->id);
            LEMEMLOG((long int)(&(b->matrix[i][j])), sizeof(double), b->id);
            ESCREVEMEMLOG((long int)(&(c->matrix[i][j])), sizeof(double), c->id);
        }
    }
}

/**
 * @brief Multiplica as matrizes a e b e armazena o resultado em c.
 * 
 * @param a Ponteiro para a matriz à direita
 * @param b Ponteiro para a matriz à esquerda
 * @param c Ponteiro para a matriz de resultado
 */
void multiplicaMatrizes(mat_tipo *a, mat_tipo *b, mat_tipo *c)
{
    erroAssert(a->columns == b->rows, "Dimensoes incompativeis");
    erroAssert(c->rows == a->rows, "Dimensoes incompativeis");
    erroAssert(c->columns == b->columns, "Dimensoes incompativeis");

    int i, j, k;

    for (i = 0; i < c->rows; i++)
    {
        for (j = 0; j < c->columns; j++)
        {
            for (k = 0; k < a->columns; k++)
            {
                c->matrix[i][j] += a->matrix[i][k] * b->matrix[k][j];
                LEMEMLOG((long int)(&(a->matrix[i][k])), sizeof(double), a->id);
                LEMEMLOG((long int)(&(b->matrix[k][j])), sizeof(double), b->id);
                ESCREVEMEMLOG((long int)(&(c->matrix[i][j])), sizeof(double), c->id);
            }
        }
    }
}

/**
 * @brief Determina a matriz transposta de a
 * 
 * @param a Ponteiro para a matriz
 */
void transpoeMatriz(mat_tipo *a)
{
    erroAssert(a->rows > 0, "Dimensao invalida");
    erroAssert(a->columns > 0, "Dimensao invalida");

    mat_tipo b;

    criaMatriz(&b, a->columns, a->rows, a->id + 1);
    inicializaMatrizNula(&b);

    for (int i = 0; i < a->rows; i++)
    {
        for (int j = 0; j < a->columns; j++)
        {
            b.matrix[j][i] = a->matrix[i][j];
            LEMEMLOG((long int)(&(a->matrix[i][j])), sizeof(double), a->id);
            ESCREVEMEMLOG((long int)(&(b.matrix[j][i])), sizeof(double), b.id);
        }
    }

    destroiMatriz(a);
    *a = b;
}

/**
 * @brief Faz a desalocação de memória da matriz a.
 * 
 * @param a Ponteiro para a matriz a ser desalocada
 */
void destroiMatriz(mat_tipo *a)
{
    avisoAssert(((a->rows > 0) && (a->columns > 0)), "Matriz já foi destruida");

    int i;

    for (i = 0; i < a->rows; i++)
    {
        free(a->matrix[i]);
    }

    free(a->matrix);

    a->rows = a->columns = -1;
}