/*====== Exercicio 4 - Introdução à passagem de parâmetro por referência ===============
a)​ Escreva uma função de nome ​troca​ que recebe como parâmetros duas variáveis capazes
de armazenar endereços de memória de pontos flutuantes (que tipo de variável é capaz de
fazer isso?), ​end_valor1​ e ​end_valor2​. Essa função deve trocar o conteúdo dos endereços
armazenados nessas variáveis, ou seja, o conteúdo armazenado no primeiro endereço
(​end_valor1​) deve ser armazenado no endereço do segundo parâmetro (​end_valor2​)​,​ e
vice-versa.

b)​ Resolva o Exercício ​3​ usando a função ​troca​.
=======================================================================================*/
#include <stdio.h>

void troca(float *end_valor1, float *end_valor2) {
    float aux;
    aux = *end_valor2;
    *end_valor2 = *end_valor1;
    *end_valor1 = aux;
}

void main() {
    float x, y;

    scanf("%f %f", &x, &y);
    /* float aux = x;
    x = y;
    y = aux; */

    troca(&x, &y);

    printf("\nx = %f\ny = %f", x, y);
}