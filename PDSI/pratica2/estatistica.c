/*=============================== Exercício 1 ==================================
Crie uma função que retorna a função de densidade de probabilidade para cada uma
dessas distribuições, de acordo com as fórmulas abaixo.
a) Cauchy padrão: f(x) = 1/pi(1+x^2)
b) Gumbel: f(x; mu, beta ) = (1/beta)e^{-(z + e^{-z})}
em que: z = {x - mu}/beta
c) Laplace: f(x; mu, b ) = {1}/{2b}e^{-|x - mu|}{b}

Considere usar as funções exp(x) para calcular e^x e fabs(x) para calcular |x|, ambas
funções encontradas na biblioteca math.h .

Exemplos:
fabs(-5.3) retorna 5.3
exp(3) retorna a e^3

Além disso, considere que pi = 3.141592 ou então use a constante M_PI da biblioteca
math.h . Por fim, note que além de x, as funções podem ter outros parâmetros de entrada. 
A função densidade de probabilidade da distribuição de Laplace, por exemplo, tem como
parâmetros de entrada x, mu e b.
================================================================================*/
#include <math.h>
#include "estatistica.h"

#define pi 3.141592

float cauchy(float x) {
    return 1 / (pi * (1 + pow(x, 2)));
}

float gumbel(float x, float mu, float beta) {
    float z = (x - mu) / beta;
    return exp(-(z + exp(-z))) / beta;
}

float laplace(float x, float mu, float b) {
    return exp(-fabs(x - mu) / b) / (2 * b);
}