/*=========================== Exercício 1: Produto Escalar ================================
Escreva um programa em C que recebe dois arranjos de números reais u e v e a dimensão n
dos dois arranjos e que retorna o produto escalar de u e v. O produto escalar de dois arranjos
é dado pela seguinte expressão:
    u*v = u_0*v_0 + v_1*v_1 + ... + u_n*v_n
Assuma que n é menor que o número máximo de elementos do arranjo (por exemplo, 100).
Para testar, preencha cada vetor com um único valor.
===========================================================================================*/
#include <stdio.h>

#define TAM_MAX 100

float produtoEscalar(float u[], float v[], int n) {

    int i = 0;
    float prodEsc = 0;

    for (i = 0; i < n; i++) {
        prodEsc += u[i] * v[i];
    }

    return prodEsc;
}

void preencheVetor(float vetor[], int dimensao) {
    int i = 0;
    printf("\nDigite os valores para o vetor separados por espacos: ");
    for (i = 0; i < dimensao; i++) {
        scanf("%f", &vetor[i]);
    }

}

void imprimeVetor(float vetor[], int dimensao) {
    int i = 0;

    for (i = 0; i < dimensao; i++) {
        printf("%.2f ", vetor[i]);
    }
}

int main() {

    float u[TAM_MAX], v[TAM_MAX], prod = 0;
    int n = 0;

    do {
        printf("\nDigite a dimensao dos vetores (1 - 100): ");
        scanf("%d", &n);
        if (n > TAM_MAX || n <= 0) {
            printf("\nDimensao invalida!");
        }
    } while (n > TAM_MAX || n <= 0);
    
    preencheVetor(u, n);
    preencheVetor(v, n);

    prod = produtoEscalar(u, v, n);

    printf("\nVetor u: ");
    imprimeVetor(u, n);
    printf("\nVetor v: ");
    imprimeVetor(v, n);

    printf("\nProduto escalar entre u e v: %.2f", prod);
    printf("\n");

}