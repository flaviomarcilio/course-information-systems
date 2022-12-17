#include <stdio.h>
#include "funcoes.h"

void main() {

    float x1 = -3.141592, x2 = 3.141592, x3 = 0.1152, x4 = -0.0;
    int a = 10, b = 3, c = 2, d = -5;

    printf("\n******** Teste Parte Inteira ************");
    printf("\nEntrada = %f, Saida = %.1f", x1, parteInteira(x1));
    printf("\nEntrada = %f, Saida = %.1f", x2, parteInteira(x2));
    printf("\nEntrada = %f, Saida = %.1f", x3, parteInteira(x3));
    printf("\nEntrada = %f, Saida = %.1f", x4, parteInteira(x4));
    printf("\n");
    printf("\n******** Teste Parte Fracionaria ************");
    printf("\nEntrada = %f, Saida = %f", x1, parteFracionaria(x1));
    printf("\nEntrada = %f, Saida = %f", x2, parteFracionaria(x2));
    printf("\nEntrada = %f, Saida = %f", x3, parteFracionaria(x3));
    printf("\nEntrada = %f, Saida = %f", x4, parteFracionaria(x4));
    printf("\n");
    printf("\n******** Teste Divisao Inteira ************");
    printf("\na = %d, b = %d, a / b = %f", a, b, divInts(a, b));
    printf("\na = %d, c = %d, a / c = %f", a, c, divInts(a, c));
    printf("\nd = %d, b = %d, d / b = %f", d, b, divInts(d, b));
    printf("\nd = %d, c = %d, d / c = %f", d, c, divInts(d, c));
    printf("\n");

}