#include <stdio.h>
#include <stdlib.h>

void imprimeMatriz(float **matriz, int linhas, int colunas) {
    int i = 0, j = 0;

    for (i = 0; i < linhas; i++) {
        for (j = 0; j < colunas; j++) {
            printf("%3.1f ", matriz[i][j]);
        }
        printf("\n");
    }
}

float **alocaMatriz(int linhas, int colunas) {
    int i = 0, j = 0;
    float **matriz = (float **)malloc(linhas * sizeof(float));

    for (i = 0; i < linhas; i++) {
        matriz[i] = (float *)malloc(colunas * sizeof(float));
    }

    for (i = 0; i < linhas; i++) {
        for (j = 0; j < colunas; j++) {
            matriz[i][j] = 0.0;
        }
    }

    return matriz;
}

void desalocaMatriz(float **matriz, int linhas, int colunas) {
    int i = 0;

    for (i = 0; i < linhas; i++) {
        free(matriz[i]);
    }
    free(matriz);
}

void freeMatrix(int **M, int n) {
	if (n == 0) {
		free(M);
		return;
	}
	free(M[n-1]);
	freeMatrix(M, n-1);
}

int main(int argc, char const *argv[])
{
    int linhas = 0, colunas = 0, i = 0;
    float **M = NULL;

    scanf("%d %d", &linhas, &colunas);

    M = alocaMatriz(linhas, colunas);
    imprimeMatriz(M, linhas, colunas);
    desalocaMatriz(M, linhas, colunas);

    return 0;
}