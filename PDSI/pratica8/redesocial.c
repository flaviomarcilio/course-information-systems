/*===================================== Exercício 2 - Rede Social ========================================

2.1​ Implementar um procedimento para inicializar a matriz de adjacência que gerencia a rede
social. Inicialmente, ninguém é amigo de ninguém, ou seja, todas as posições da matriz são
zeradas.
    Protótipo: void inicializar_rede();

2.2​ Implementar um procedimento para marcar duas pessoas como amigas na matriz de
adjacência. 
    Protótipo: void adicionar_amizade(int i, int j);
Observação:​ Lembre que a relação de amizade é simétrica!

2.3​ Implementar uma função que retorna um número aleatório de tipo ponto flutuante entre 0 e
1. ​Dica:​ o maior número aleatório gerado pela função ​rand()​ é definido pela constante
RAND_MAX​ da biblioteca ​stdlib.h​. 
    Protótipo: float random_float();

2.4​ Implementar um procedimento para criar uma rede social aleatória a partir de um único
parâmetro P [0, 1]. ​Para cada par de pessoas (i, j)​, este procedimento deve gerar um número 
aleatório de tipo ponto flutuante r entre 0 e 1 (ex: 0.2345). Caso r seja menor que P, então 
deve-se criar uma amizade entre as pessoas ni e nj. Exemplo: se P = 0.8, para o par de pessoas 
n0 e n1, se o número r gerado for 0.5412, então você deve criar uma amizade entre essas pessoas. 
Você deve repetir esse processo para todos os pares de pessoas.
    Protótipo: void popularRedeSocialAleatoriamente(float P);
Observações:​ Lembre que a relação de amizade é simétrica, ou seja, se você testou o par (i, j)
então você não deve testar o par (j, i). Lembre também que uma pessoa não pode ser amiga dela mesma.

2.5​ Implementar um procedimento para imprimir a matriz de adjacência de uma rede social.
    Protótipo: void imprimirRedeSocial();

2.6​ Implementar uma função para retornar o número de amigos em comum que duas pessoas
têm. Essa função deve também imprimir os identificadores dos amigos em comum. 
Protótipo: int numAmigosEmComum(int v, int u);

2.7​ ​DESAFIO PARA OS FORTES:​ Implementar uma função para calcular o coeficiente de aglomeração 
de uma pessoa. 
    Protótipo: float coeficienteAglomeracao(int v);

O coeficiente de aglomeração de um nó ​i​ em um grafo é a probabilidade de dois amigos de ​i
serem também amigos entre si. Ele é calculado da seguinte maneira:
    a. Conte o número ​n ​de amigos de ​i​.
    b. Crie um contador ​cont​ e o inicialize com ​0​.
    c. Para cada amigo ​u​ de ​i​, conte quantos amigos ​v​ de ​i​ também é amigo de ​u​, lembrando
    que ​u ≠ v​. Adicione essa contagem ao contador ​cont​. ​Dica:​ se adicionar as amizades
    (u,v)​ e ​(v,u)​ ao ​cont​, então divida ​cont​ por ​2​ no final do processo.
    d. O coeficiente de aglomeração é o quociente da divisão entre ​cont​ e o número máximo
    possível de amizades entre os ​n ​amigos de ​i​, dado por ​n * (n-1) / 2​.
Observação: ​o coeficiente de aglomeração deve ser um número entre ​0​ e ​1​
==========================================================================================================*/

#include <stdio.h>
#include <stdlib.h>

#include "redesocial.h"

int M[NUM_PESSOAS][NUM_PESSOAS];

void inicializar_rede() {
    int i = 0, j = 0;

    for (i = 0; i < NUM_PESSOAS; i++) {
        for (j = 0; j < NUM_PESSOAS; j++) {
            M[i][j] = 0;
        }
    }
}

void adicionar_amizade(int i, int j) {
    M[i][j] = 1;
    M[j][i] = 1;
}

float random_float() {
    return (float)rand() / RAND_MAX;
}

void popularRedeSocialAleatoriamente(float P) {
    int i = 0, j = 0;
    float r = 0;

    inicializar_rede();
    for (i = 0; i < NUM_PESSOAS; i++) {
        for (j = i + 1; j < NUM_PESSOAS; j++) {
            r = random_float();
            if (r < P) {
                adicionar_amizade(i, j);
            }
        }
    }
}

void imprimirRedeSocial() {
    int i = 0, j = 0;

    printf("\nMatriz de Adjacencia:\n");
    for (i = 0; i < NUM_PESSOAS; i++) {
        for (j = 0; j < NUM_PESSOAS; j++) {
            printf("%d ", M[i][j]);
        }
        printf("\n");
    }
}

int numAmigosEmComum(int v, int u) {
    int j = 0, amigosEmComum = 0;

    printf("\nAmigos em comum entre %d e %d: ", v, u);
    for (j = 0; j < NUM_PESSOAS; j++) {
        if (M[v][j] == M[u][j] && M[v][j] != 0) {
            amigosEmComum++;
            printf("%d ", j);
        }
    }
    printf("\n");
    return amigosEmComum;
}

float coeficienteAglomeracao(int v) {
    int i = 0, j = 0, n = 0, cont = 0;
    float coef = 0;

    for (i = 0; i < NUM_PESSOAS; i++) {
        if (M[v][i] == 1) {
            n++;
            cont += numAmigosEmComum(v,i);
        }
    }
    if (n >= 2) {
        coef = (float)cont / (n * (n - 1));
    } else {
        coef = 0;
    }
    
    return coef;
}