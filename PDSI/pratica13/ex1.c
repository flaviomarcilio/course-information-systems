/*========================== Exercício 1 - Alocação dinâmica de matrizes ===============================
Escreva um programa para ler um número inteiro ​n​ do teclado e criar dinamicamente uma
matriz ​n x n​ de pontos flutuantes, atribuindo ​0.0​ a todas as suas posições. Uma matriz de
pontos flutuantes de dimensões ​n x n​ é, na verdade, um vetor de ​n​ ponteiros para pontos
flutuantes em que cada ponteiro deste vetor aponta para um vetor de ​n​ pontos flutuantes.
Assim, para resolver esse exercício, primeiro aloque dinamicamente um vetor de ​n​ posições de
ponteiros para pontos flutuantes. Depois, para cada posição ​i​ deste vetor, aloque um vetor de
tamanho ​n​ de pontos flutuantes e atribua ​0.0​ a cada uma das suas posições. Por fim, imprima
a matriz.
DESAFIO:​ faça a alocação da matriz em uma função.
========================================================================================================*/

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[])
{
    int n = 0, i = 0, j = 0;
    float **matriz;
    printf("\nDigite o tamanho n da matriz nxn: ");
    scanf("%d", &n);

    // Alocação dinâmica de matrizes
    matriz = (float **)malloc(n * sizeof(float *)); // Alocação do total de linhas - cada linha é um vetor
    for (i = 0; i < n; i++) {
        matriz[i] = (float *)malloc(n * sizeof(float)); // Alocação de cada vetor
    }

    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            matriz[i][j] = 0;
            printf("%.1f ", matriz[i][j]);
        }
        printf("\n");
    }

    // Desalocando a memória
    for (i = 0; i < n; i++) {
        free(matriz[i]);
    }
    free(matriz);

    return 0;
}
