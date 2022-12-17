/*=================================== Exercício 3 ===========================================
Implemente um programa que use o módulo criado do exercício anterior para calcular e exibir a
função densidade de probabilidade nos seguintes pontos:
cauchy(x=-2) [resultado para conferência: 0.063662]
gumbel(x=0, $\mu$=0.5, $\beta$=2) [resultado para conferência: 0.177786]
laplace(x=-6, $\mu$=-5, $b$=4) [resultado para conferência: 0.097350]
==============================================================================================*/
#include <stdio.h>
#include "estatistica.h"

void main() {
    printf("\nCauchy(-2): %f", cauchy(-2));
    printf("\nGumbel(0, 0.5, 2): %f", gumbel(0, 0.5, 2));
    printf("\nLaplace(-6, -5, 4): %f", laplace(-6, -5, 4));
    printf("\n");
}