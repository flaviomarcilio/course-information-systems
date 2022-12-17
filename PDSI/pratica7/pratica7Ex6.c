/*============================ Exercício 6: União de vetores =========================
Faça um programa para preencher dois vetores X e Y de 60 posições com valores aleatórios
entre 0 e 365. Imprima a conjunto união desses dois vetores. 
Curiosidade: leia sobre o paradoxo do aniversário.
======================================================================================*/
#include <stdio.h>
#include <stdlib.h>

#define TAM_VETOR 60

int random(int n) {
    return rand() % n;
}

void preencheVetor(int vet[], int n) {
    int i = 0;

    for (i = 0; i < n; i++) {
        vet[i] = random(366);
    }
}

void imprimeVetor(int vet[], int n) {
    int i = 0;

    for (i = 0; i < n; i++) {
        printf("%d ", vet[i]);
    }
}

int existe(int valor, int vetor[], int indice) {
	int i = 0;
	for (i = 0; i < indice; i++) {
		if (valor == vetor[i]) {
			return 1;
		}
	}
	return 0;
}

int vetorUniao(int A[], int B[], int UAB[]) {
    int i = 0, j = 0, k = 0;

    while (i < TAM_VETOR) {
        if (!existe(A[i], UAB, j)) {
            UAB[j] = A[i];
            j++;
            k++;
        }
        if (!existe(B[i], UAB, k)) {
            UAB[k] = B[i];
            j++;
            k++;
        }
        i++;
    }
    return k;
}

int main() {
    int X[TAM_VETOR], Y[TAM_VETOR], U[2*TAM_VETOR];
    int tamanho_U = 0;

    preencheVetor(X, TAM_VETOR);

    preencheVetor(Y, TAM_VETOR);

    tamanho_U = vetorUniao(X, Y, U);

    printf("\nVetor Uniao: ");
    imprimeVetor(U, tamanho_U);
    printf("\n");
    return 0;
}