#include <math.h>
#include "pratica4.h"

/*================================= Exercício 1 =====================================
Implementar uma função que recebe como parâmetro uma velocidade em km/h (quilômetros
por hora) e retorne a mesma convertida para m/s (metros por segundo). A fórmula de
conversão é M = K/3.6, sendo K a velocidade em km/h e M a velocidade em m/s.
=====================================================================================*/

float paraMetrosPorSegundo(float v) {

    return v / 3.6;

}

/*================================= Exercício 2 =========================================
Implementar uma função que recebe como parâmetro o raio de um círculo e retorne a área do
círculo correspondente. A área do círculo é A = pi*raio^2 , sendo que pi = 3.141592.
========================================================================================*/

float areaCirculo(float raio) {

    float pi = 3.141592;
    return pi * raio * raio;
}

/*================================ Exercício 3 ===========================================
Implementar uma função que recebe três números inteiros como parâmetro e retorna o maior
entre eles.
==========================================================================================*/

int maior3(int n1, int n2, int n3) {

    if (n1 > n2) {
        if (n1 > n3) {
            return n1;
        } else {
            return n3;
        }
    } else {
        if (n2 > n3) {
            return n2;
        } else {
            return n3;
        }
    }
}

/*=================================== Exercício 4 =======================================
Implementar uma função que recebe como parâmetro um número inteiro ​n​ e retorne ​1​ se ele
for par e ​0​ caso ele seja ímpar.
=========================================================================================*/

int ehPar(int n) {
    if (n % 2 == 0)     {
        return 1;
    } else {
        return 0;
    }
}

/*=================================== Exercício 5 ===============================================
Implementar uma função que recebe como parâmetro um número inteiro ​n​ e retorne​ 1​ se ele
for divisível por ​3​ ou por ​5​, mas não simultaneamente pelos dois, ou ​0​ caso contrário (divisível
por ​3​ e ​5​ ou por nenhum dos dois).
=================================================================================================*/

int ehDivisivelPor3ou5(int n) {

    if (n % 3 == 0 && n % 5 == 0) {
        return 0;
    } else {
        if (n % 3 == 0 || n % 5 == 0) {
            return 1;
        }
        return 0;
    }

    // if (n % 3 == 0 || n % 5 == 0)
    //     if (n % 3 != 0 || n % 5 != 0)
    //         return 1;
    // return 0;

}

/*=================================== Exercício 6 =======================================
Implemente uma função que recebe como parâmetro a altura h em metros (exemplo: 1.70) e o
sexo (​'M'​ para masculino e ​'F'​ para feminino) de uma pessoa e retorne o seu peso ideal PI,
sendo que PI = (72.7*h)-58 caso o sexo seja masculino e PI = (62.1*h)-44.7 caso feminino.
=========================================================================================*/

float PesoIdeal(float h, char sexo) {

    if (h <= 0) {
        return 0;
    } else {
        if (sexo == 'M') {
            return (72.7 * h) - 58.0;
        } else {
            return (62.1 * h) - 44.7;
        }
    }
    
}

/*=================================== Exercício 8 =====================================
Implementar uma função que recebe como parâmetro um número inteiro ​N​ e retorne a soma
dos números ímpares de ​0​ até ​N​ (incluindo ​N​, se ​N​ for ímpar).
=======================================================================================*/

int somaImpares(int N) {

    int soma = 0;

    // int i = 0;
    // while (i <= N) {

    //     if (ehPar(i)) {
    //         i++;
    //     } else {
    //         soma += i;
    //         i++;
    //     }
    // }

    for (int i = 0; i <= N; i++) {
        
        if (!ehPar(i)) {
            soma += i;
        }

    }
    
    return soma;
    
}

/*================================== Exercício 9 =======================================
Implementar uma função que recebe como parâmetro um número inteiro e retorne o seu
fatorial.
========================================================================================*/

double fatorial(int N) {

    double fat = 1;

    // while (N > 0)
    // {
    //     fat *= N;
    //     N--;
    // }

    for (int i = 2; i <= N; i++)
    {
        fat *= i;
    }
    
    return fat;
    
}

/*================================== Exercício 10 ==========================================
Implementar uma função que recebe como parâmetro um número inteiro ​N​ e retorne a soma de
todos os números positivos menores ou iguais a ​N​ que são divisíveis por ​3​ ou por ​5​, mas não
por ambos.
============================================================================================*/

int somaNumerosDiv3ou5(int N) {

    int soma = 0;

    while (N > 2)
    {
        if (ehDivisivelPor3ou5(N)) {
            soma += N;
        }
        N--;
    }

    return soma;
    
}

/*==================================== Exercício 11 ===========================================
Implemente uma função que recebe como parâmetro três números inteiros maiores que zero
(não precisa testar) ​x,y,z​ e uma operação numérica que pode assumir os valores ​1,2,3​ e ​4​.
Caso a operação seja ​1​, a função deve calcular a média geométrica, caso seja ​2​, a média
ponderada, caso seja ​3​, a média harmônica e, por fim, caso seja ​4​, a média aritmética. Confira
a tabela abaixo para as fórmulas.
===============================================================================================*/

float calculaMedia(int x, int y, int z, int operacao) {
    // if (operacao == 1) {

    //     return pow(x*y*z, 1.0/3.0);

    // } else if (operacao == 2) {

    //     return (x + 2*y + 3*z)/6.0;

    // } else if (operacao == 3) {

    //     return 3.0/(1.0/x + 1.0/y + 1.0/z);

    // } else if (operacao == 4) {

    //     return (x + y + z)/3.0;

    // }

    switch (operacao) {
        case 1:
            return pow(x * y * z, 1.0/3.0);
        case 2:
            return (x + 2*y + 3*z)/6.0;
        case 3:
            return 3.0/(1.0/x + 1.0/y + 1.0/z);
        case 4:
            return (x + y + z)/3.0;
    }
    
}

/*==================================== Exercício 12 ==========================================
Implementar uma função que recebe como parâmetro um número inteiro ​N ​e retorne o seu número 
de divisores.
==============================================================================================*/

int numeroDivisores(int N) {

    int divisores = 0;

    // int i = 1;
    // while (i <= N) {
    //     if (N % i == 0) {
    //         divisores++;
    //     }
    //     i++;
    // }

    for (int i = 1; i <= N; i++) {
        if (N % i == 0) {
            divisores++;
        }
    }
    
    return divisores;
}

/*====================================== Exercício 13 ========================================
Implementar uma função que recebe como parâmetro um número inteiro positivo ​N​ e retorne o
enésimo termo da sequência de Fibonacci. Essa sequência começa no termo de ordem zero e,
a partir do segundo termo, seu valor é dado pela soma dos dois termos anteriores. 
===============================================================================================*/

int enesimoFibonacci(int N) {

    int fibo, fibo1, fibo2;

    fibo1 = 0;
    fibo2 = 1;

    if (N == 1) {
        return fibo1;
    } else if (N == 2) {
        return fibo2;
    } else {
        while (N > 2) {
            fibo = fibo1 + fibo2;
            fibo1 = fibo2;
            fibo2 = fibo;
            N--;
        }
        return fibo;
    }
}

/*====================================== Exercício 14 =========================================
Escreva uma ​função ​que retorna o máximo divisor comum (MDC) entre dois números inteiros.
O MDC entre dois números é o maior número inteiro que os divide.
===============================================================================================*/

int mdc(unsigned int x, unsigned int y) {

    // unsigned int resto, numerador, denominador;

    // if (x > y) {
    //     numerador = x;
    //     denominador = y;
    // } else {
    //     numerador = y;
    //     denominador = x;
    // }
    // resto = numerador % denominador;
    // while (resto > 0) {
    //     numerador = denominador;
    //     denominador = resto;
    //     resto = numerador % denominador;
    // }
    // return denominador;

    unsigned int menor, maximo;
    if (x < y) {
        menor = x;
    } else {
        menor = y;
    }
    for (int i = 1; i <= menor; i++) {
        if (x % i == 0 && y % i == 0) {
            maximo = i;
        }
    }
    return maximo;
}

/*====================================== Exercício 15 =========================================
Escreva uma ​função​ que retorna o mínimo múltiplo comum (MMC) entre dois números
inteiros. O MMC entre dois números é o menor número inteiro que é múltiplo de ambos, ou
seja, que tem como divisores os dois números.
================================================================================================*/

int mmc(unsigned int x, unsigned int y) {

    return (x * y) / mdc(x, y);

}