/*================================== Exercício 2: Fibonacci ===============================
A sequência de Fibonacci pode ser definida como:
fib(0) = 1
fib(1) = 1
fib(n) = fib(n-1) + fib(n-2), para n>2
Implemente um programa que calcule a série de Fibonacci e armazene em um vetor cada
elemento da série, de forma que a posição ​0​ armazene o termo ​0​, a posição ​1​ o termo ​1​, e
assim por diante. Seu programa deve receber do usuário um número entre ​0​ e ​1000​ e imprimir
o termo correspondente ao número recebido. O usuário deve ser capaz de entrar com vários
números interativamente em uma mesma execução. O programa termina quando o usuário
entrar com um número ​negativo ​ou maior que ​1000​. ​Dica:​ se o tipo ​int​ for insuficiente para
armazenar todos os elementos da série, use outro tipo de dados.
===========================================================================================*/
#include <stdio.h>

#define TERMOS 1001

void preencheVetor(double vetor[], int dimensao) {
    int i = 0;
    vetor[0] = 1;
    vetor[1] = 1;

    for (i = 2; i < dimensao; i++) {
        vetor[i] = vetor[i - 1] + vetor[i - 2];
    }
}

int main() {
    double fibo[TERMOS];
    int n = 0;

    preencheVetor(fibo, TERMOS);

    printf("\nQual termo de Fibonacci (entre 0 e 1000): ");
    scanf("%d", &n);

    while (n >= 0 && n < TERMOS) {
        printf("\nfib(%d) = %4.3E\n", n, fibo[n]);
        printf("\nQual termo de Fibonacci (entre 0 e 1000): ");
        scanf("%d", &n);
    }

    return 0;
}