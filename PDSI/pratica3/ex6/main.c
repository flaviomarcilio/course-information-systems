/*============= Exercicio 6 - Funções simples sem operadores condicionais ====================
Implemente funções para realizar as operações abaixo sobre parâmetros recebidos como
números inteiros sem sinal (​unsigned int​). Suas funções ​não devem​ usar qualquer
operador condicional (exemplo: ​if​). Dica: algumas delas podem requerer operações bit-a-bit.
Abaixo um exemplo de uma função que retorna o negativo do parâmetro:

    int neg(unsigned int number) {
    return -number;
    } 

a) DDD​. Extrair código de área de números de telefone com 8 dígitos (e.g., para o telefone
3134095858 a sua função deve retornar 31). Protótipo:
    
    int ddd(unsigned int number);

b) Soma 1 se for par​. Transformar um número par no próximo número ímpar e manter um
número ímpar inalterado. Exemplo: para o número 4 a sua função deve retornar 5 e para o
número 5 a sua função deve retornar 5. Protótipo:

    int soma1SePar(unsigned int number);

c) Par ou ímpar.​ Retornar ​verdadeiro ​se o número for par ou ​falso ​caso contrário. Dica:
lembre dos conceitos de verdadeiro e falso para a linguagem C. Protótipo:

    int parOuImpar(unsigned int number);

d) Programa principal. ​Faça um programa para testar as funções ​DDD​, ​soma1SePar ​e
parOuImpar​. Para cada função, teste pelo menos três entradas diferentes que, idealmente,
dão saídas diferentes
============================================================================================*/
#include <stdio.h>
#include "functions.h"

void main() {
    unsigned int x, y;
    x = 3134964993;
    y = 2798787888;
    printf("\nddd de %u = %d", x, ddd(x));
    printf("\nddd de %u = %d", y, ddd(y));

    printf("\nnumero %u e retorno de b %u", x, soma1SePar(x));
    printf("\nnumero %u e retorno de b %u", y, soma1SePar(y));

    printf("\nnumero %u par ou impar %d", x, parOuImpar(x));
    printf("\nnumero %u par ou impar %d", y, parOuImpar(y));
    printf("\n");
}