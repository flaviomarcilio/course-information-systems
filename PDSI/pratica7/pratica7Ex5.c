/*======================== Exercício 5: Inverso de um vetor =============================
Faça um programa para ler um vetor X de n elementos e gerar um outro vetor com esses
n elementos em ordem inversa. Exemplo: Se X= {3, 5, 2, 8, 4}, deverá ser gerado um vetor
Y= {4, 8, 2, 5, 3}. O valor de n é lido pelo teclado.
=========================================================================================*/
#include <stdio.h>

#define TAM_MAX 100

void leVetor(int vet[], int n) {
    int i = 0;

    for (i = 0; i < n; i++) {
        scanf("%d", &vet[i]);
    }
}

void inverteVetor(int A[], int B[], int n) {
    int i = 0, j = n - 1;

    for (i = 0; i < n; i++) {
        B[i] = A[j];
        j--;
    }
}

void imprimeVetor (int vet[], int n) {
    int k = 0;

    for (k = 0; k < n; k++) {
        printf("%d ", vet[k]);
    }
}

int main() {

    int X[TAM_MAX], Y[TAM_MAX];
    int i = 0, j = 0, n = 0;

    do {
        printf("\nDigite a dimensao do vetor (0 < n < %d): ", TAM_MAX);
        scanf("%d", &n);
        if (n >= TAM_MAX || n <= 0) {
            printf("\nValor invalido!");
        }
    } while (n >= TAM_MAX || n <= 0);

    printf("\nDigite os %d valores dos vetor separados por espaco: ", n);
    leVetor(X, n);

    inverteVetor(X, Y, n);

    printf("\nVetor Digitado: ");
    imprimeVetor(X, n);

    printf("\nVetor Invertido: ");
    imprimeVetor(Y, n);
    printf("\n");
    return 0;
}