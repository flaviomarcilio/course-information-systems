/*======================= Exercício 4: Intercalação de vetores ======================
Faça um programa que leia 2 vetores X e Y de 10 elementos cada um. Intercale os
elementos desses 2 vetores formando assim, um novo vetor Z de 20 elementos, onde, nas
posições ímpares de Z, estejam os elementos de X e, nas posições pares, os elementos de
Y.
=====================================================================================*/
#include <stdio.h>

#define TAM_VETOR 10

void leVetor(int vet[]) {
    int i = 0;

    for (i = 0; i < TAM_VETOR; i++) {
        scanf("%d", &vet[i]);
    }
}

void intercalaVetores(int A[], int B[], int C[]) {
    int i = 0, j = 0, k = 0;

    for (k = 0; k < 2 * TAM_VETOR; k++) {
        if (k % 2 == 0) {
            C[k] = A[i];
            i++;
        } else {
            C[k] = B[j];
            j++;
        }
    }
}

void imprimeVetor (int vet[], int n) {
    int k = 0;

    for (k = 0; k < n; k++) {
        printf("%d ", vet[k]);
    }
}

int main() {
    int X[TAM_VETOR], Y[TAM_VETOR], Z[2 * TAM_VETOR];
    int i = 0, j = 0, k = 0;

    printf("\nDigite os %d valores de X separados por espaco: ", TAM_VETOR);
    leVetor(X);

    printf("\nDigite os %d valores de Y separados por espaco: ", TAM_VETOR);
    leVetor(Y);

    intercalaVetores(X, Y, Z);

    printf("\nVetor Z: ");
    imprimeVetor(Z, 2*TAM_VETOR);
    printf("\n");

    return 0;
}