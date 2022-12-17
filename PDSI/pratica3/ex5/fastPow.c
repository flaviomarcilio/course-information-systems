/*============================= Exercicio 5 - Fast Pow ======================================
a)​ Neste exercício você deve usar operações de deslocamento de bits ​<<​ e/ou ​>>​. Primeiro,
faça uma função de nome ​fast_pow_2​ que recebe um inteiro ​expoente​ e retorna um
unsigned long long​ contendo a potência de dois correspondente. Por exemplo, se o
expoente ​passado como parâmetro for 7, a sua função deve retornar ​2​ elevado a ​7​. Um
número do tipo ​unsigned long long​ é um inteiro sem sinal de 64 bits. Você o trata
exatamente como um ​unsigned int​, mas o seu alcance é muito maior. Protótipo da função:

    unsigned long long fast_pow_2(int expoente);

b)​ Depois, faça um programa para responder a seguinte pergunta: qual é a maior potência de 2
que um ​unsigned long long​ é capaz de armazenar? Faça um programa que use a função
fast_pow_2​ para imprimir esse limite. Para imprimir um ​unsigned long long​ você deve
usar o especificador de formato ​%llu​.
============================================================================================*/
#include <stdio.h>

unsigned long long fast_pow_2(int expoente) {
    return (unsigned long long)1 << expoente;
}

void main() {
    printf("\nExpoente = 0, Saida = %llu", fast_pow_2(0));
    printf("\nExpoente = 1, Saida = %llu", fast_pow_2(1));
    printf("\nExpoente = 10, Saida = %llu", fast_pow_2(10));
    printf("\nExpoente = 32, Saida = %llu", fast_pow_2(32));
    // Nao e o maior numero possivel de armazenar, pois, 2^63 = 1(000...000)*63
    printf("\nExpoente = 63, Saida = %llu (maior potencia de 2 armazenada pelo unsigned long long)", fast_pow_2(63));
    printf("\nExpoente = 64, Saida = %llu (overflow - saida invalida)", fast_pow_2(64));

}