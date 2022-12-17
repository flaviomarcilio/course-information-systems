/*=============================== Exercicio 1 - Conversão de tipo ===========================
a)​ Escreva uma função que recebe um número ponto flutuante como parâmetro e retorna um
ponto flutuante equivalente à sua parte inteira. Exemplo: se a sua função receber -3.141592
como parâmetro, ela deve retornar -3.0. Protótipo da função:

    float parteInteira(float x);

b)​ Escreva uma função que recebe um número ponto flutuante como parâmetro e retorna um
ponto flutuante equivalente à sua parte fracionária. Exemplo: se a sua função receber
-3.141592 como parâmetro, ela deve retornar -0.141592. Protótipo da função:

    float parteFracionaria(float x);

c)​ Escreva uma função que recebe dois inteiros ​x​ e ​y​ como parâmetros e retorna um ponto
flutuante correspondente à divisão do primeiro pelo segundo (​x​ dividido por ​y​). Protótipo da
função:

    float divInts(int x, int y);

d)​ Faça um programa para testar as funções das letras ​a​, ​b​ e ​c​. Para cada função, teste pelo
menos três entradas diferentes que, idealmente, dão saídas diferentes.
==============================================================================================*/
#include <stdio.h>

float parteInteira(float x) {
    return (int)x;
}

float parteFracionaria(float x) {
    return x - (int)x;
}

float divInts(int x, int y) {
    return (float)x / y;
}

void main() {

    float x1 = -3.141592, x2 = 3.141592, x3 = 0.1152, x4 = -0.0;
    int a = 10, b = 3, c = 2, d = 5;

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