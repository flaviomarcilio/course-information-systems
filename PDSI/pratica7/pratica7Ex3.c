/*========================== Exercício 3: Média dos elementos de um vetor ===============
Escreva uma função em C que recebe um vetor de números reais v e número de elementos n
armazenados em v e que retorna a média dos n elementos armazenados em v. O vetor deve
ser preenchido com números aleatórios através de uma outra função. Para gerar números
aleatórios, use a função ​drand48()​ no Linux, ou a função ​rand()​ no Windows, da biblioteca
stdlib.h​.
=========================================================================================*/
#include <stdio.h>
#include <stdlib.h>

#define TAM_MAX 1000

float randf() {
    return (float)rand() / RAND_MAX;
}

void preencheVetor(float vet[], int n) {
    int i = 0;

    for (i = 0; i < n; i++) {
        vet[i] = randf();
    }
}

float mediaVetor(float vet[], int n) {
    float media = 0;
    int i = 0;
    
    for (i = 0; i < n; i++) {
        media += vet[i];
    }

    return media / n;
}

int main() {
    float vetor[TAM_MAX], media = 0;
    int n = 0;

    do {
        printf("\nDigite a dimensao do vetor (0 < x < 1000): ");
        scanf("%d", &n);
        if (n <= 0 || n > TAM_MAX) {
            printf("\nValor invalido!");
        }
    } while (n <= 0 || n > TAM_MAX);
    

    preencheVetor(vetor, n);
    
    media = mediaVetor(vetor, n);
    printf("\nMedia: %.2f", media);
    printf("\n");
    return 0;
}