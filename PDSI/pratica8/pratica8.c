/*===================================== Exercício 2 - Rede Social ========================================
Problema
Uma rede social de amizades pode ser representada por um grafo em que é o conjunto de nós e o conjunto 
de arestas do mesmo. Cada um dos nós representa uma pessoa e, caso duas pessoas e sejam amigas, existe 
uma aresta. Umas das maneiras usuais para se representar um grafo é através de uma matriz de adjacência 
de colunas e linhas. Cada linha (ou coluna) contém as relações da pessoa.

Nesta prática, considere que você vai implementar um simulador de redes sociais de amizade usando uma 
matriz de adjacência. O número de pessoas da rede social é definido na constante NUM_PESSOAS​ do arquivo 
​redesocial.h​. A matriz de adjacência é a variável global M[NUM_PESSOAS][NUM_PESSOAS]​, declarada no 
arquivo ​redesocial.c​. Uma variável global tem um escopo global, ou seja, pode ser usada em qualquer 
parte do arquivo em que ela foi declarada sem a necessidade de passá-la como parâmetro. Neste exercício,
considere que as pessoas da rede social podem ser identificadas pelos inteiros 0,1,2,...,NUM_PESSOAS-1​.

2.1​ Implementar um procedimento para inicializar a matriz de adjacência que gerencia a rede
social. Inicialmente, ninguém é amigo de ninguém, ou seja, todas as posições da matriz são
zeradas.
==========================================================================================================*/

#include <stdio.h>

#include "redesocial.h"

void main() {
    popularRedeSocialAleatoriamente(0.6);
    imprimirRedeSocial();
    int n = numAmigosEmComum(2,4);
    printf("\nNumero de amigos em comum entre 2 e 4: %d", n);
    printf("\n");
    //gabarito: 2
    //se voce eh forte, remova o comentario da linha abaixo
    printf("\nCoef. de aglomeracao da pessoa 2 eh: %.2f",coeficienteAglomeracao(2));
    printf("\n");
    //gabarito: 0.67
}