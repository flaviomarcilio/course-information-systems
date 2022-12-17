#include <stdio.h>
#include <stdlib.h>

float **alocaMatriz(int n) {
    int i = 0, j = 0;

    float **matriz = (float **)malloc(n * sizeof(float *));
    for (i = 0; i < n; i++) {
        matriz[i] = (float *)malloc(n * sizeof(float));
        for (j = 0; j < n; j++) {
            matriz[i][j] = 0.0;
        }
    }
    
    return matriz;
}

void alocaMatriz2(float ***matriz, int n, int inicial) {
    int i = 0, j = 0;

    *matriz = (float **)malloc(n * sizeof(float *));
    for (i = 0; i < n; i++) {
        (*matriz)[i] = (float *)malloc(n * sizeof(float));
        for (j = 0; j < n; j++) {
            (*matriz)[i][j] = inicial;
        }
    }
}

void imprimeMatriz(float **matriz, int n) {
    int i = 0, j = 0;
    printf("\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            printf("%3.1f ", matriz[i][j]);
        }
        printf("\n");
    }
}

void desalocaMatriz(float **matriz, int n) {
    int i = 0;

    for (i = 0; i < n; i++) {
        free(matriz[i]);
    }
    free(matriz);
}

int main(int argc, char const *argv[])
{
    int n = 0, i = 0, j = 0;
    float **matriz, **matriz2;

    printf("\nDigite o tamanho n da matriz nxn: ");
    scanf("%d", &n);

    matriz = alocaMatriz(n);
    printf("\nAloca matriz retornando ponteiro");
    imprimeMatriz(matriz, n);

    alocaMatriz2(&matriz2, n, 0);
    printf("\nAloca matriz por passagem por referencia");
    imprimeMatriz(matriz2, n);

    desalocaMatriz(matriz, n);
    desalocaMatriz(matriz2, n);

    return 0;
}
