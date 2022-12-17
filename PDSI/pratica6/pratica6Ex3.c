/*=========================== Exercício 3: Triângulo de Floyd =============================
Faça um programa que lê um número inteiro ​N​ e imprime as ​N​ primeiras linhas do triângulo de
Floyd:
1
2 3
4 5 6
7 8 9 10
11 12 13 14 15
Desafio:​ Faça um programa para imprimir a ​N-ésima​ linha sem calcular as anteriores.
===========================================================================================*/
#include <stdio.h>

void trianguloFloyd(int N) {
    // Imprime o Triangulo de Floyd ate a linha N
    int i = 0, j = 1, pivo = 0;

    for (i = 1; i <= N; i++) {
        pivo += j;
        printf("\n%d", pivo);
        for (j = 1; j < i; j++) {
            printf(" %d", pivo + j);
        }
    }
    printf("\n");

    // int acum = 1;
    // for (i = 1; i <= N; i++) {
    //     for (j = 1; j <= i; j++) {
    //         printf("%d ", acum);
    //         acum++;
    //     }
    //     printf("\n");
    // }

}

void linhaTrianguloFloyd(int N) {
    // Imprime a Linha N do Triangulo de Floyd
    int i = 0, j = 1, pivo = 0;

    // for (i = 1; i < N; i++) {
    //     pivo += i;
    // }
    // pivo += 1;
    pivo = ((N - 1) * N ) / 2 + 1;
    printf("\n%d", pivo);
    for (j = 1; j < N; j++) {
        printf(" %d", pivo + j);
    }
    printf("\n");
}

int main() {

    int N = 0, escolha;

    do {
        printf("\nQual linha do triangulo de Floyd: ");
        scanf("%d", &N);
        fflush(stdin);
    } while (N < 0);
    
    do {
        printf("\nEscolha opcao para imprimir (0 - Triangulo; 1 - Linha): ");
        scanf("%d", &escolha);
        if (escolha == 0) {
            trianguloFloyd(N);
        } else if (escolha == 1) {
            linhaTrianguloFloyd(N);
        }
    } while (escolha < 0 || escolha > 1);
    
    return 0;
}
