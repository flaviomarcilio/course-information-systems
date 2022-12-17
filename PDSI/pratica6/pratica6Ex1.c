/*==================== Exercício 1: Número de Euler =======================================
O valor de (número de Euler) pode ser aproximado pelo somatório:

e=1+1/1!+1/2!+1/3!+1/4!+1/5!...

Implemente um programa para aproximar o valor de e. Seu programa deve aumentar a
precisão da aproximação calculando iterativamente (isto é, num laço) os termos do somatório
acima. Seu programa deve parar a aproximação quando o i-ésimo termo ​(1/i!)​ for menor do que
10^{-6}.
Implemente esse programa fazendo uma função separada para calcular o fatorial de i. 
===========================================================================================*/
#include <stdio.h>
#include <math.h>

#define precisao pow(10, -6)

double fatorial(int N) {

    int i = 0;
    double fat = 1;

    for (i = 2; i <= N; i++) {
        fat *= i;
    }
    
    return fat;
}

int main() {

    double n_Euler = 1.0, termo = 1.0;
    int n = 1;

    do {
        termo = 1.0 / fatorial(n);
        n_Euler += termo;
        n++;
    } while (termo > precisao);

    printf("\nNumero de Euler com %d termos = %lf", n, n_Euler);
    printf("\n");
    
    return 0;
}
