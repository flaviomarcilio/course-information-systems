/*======================================== Programas Recursivos ==========================================
1)​ Escreva uma função recursiva que calcule a soma dos primeiros ​n​ cubos:
    S = 1³ + 2³ + … + n³.

2)​ Escreva um procedimento recursivo para imprimir todos os números naturais de ​0 até ​N​ em ordem crescente.

3)​ Escreva um procedimento recursivo para imprimir todos os números naturais de ​0 até ​N​ em ordem decrescente.

4)​ Crie uma função recursiva que retorne a soma dos elementos de um vetor de inteiros.

5)​ Crie uma função recursiva que retorne a média dos elementos de um vetor de inteiros.

6)​ Escreve uma função recursiva que receba por parâmetro dois valores inteiros ​x​ e ​y​ e calcule e retorne o 
resultado de ​x^y​ (​x​ elevado a ​y​) para o programa principal, considere ​x​ e ​y​ inteiros positivos. Você não 
pode usar a função ​pow​.

7)​ Escreva uma função que recebe uma string como parâmetro e a imprima invertida.

8)​ Escreva uma função recursiva que receba um valor inteiro ​x​(positivo) e o retorne invertido. 
Exemplo: se ​x = 123​, a função deve retornar ​321​.

9)​ Escreva uma função recursiva que receba um valor inteiro(positivo) em base decimal e o imprima em base 
binária.

10)​ Escreva uma função recursiva que retorne o menor elemento em um vetor.
==========================================================================================================*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Ex.1 - Retorna a soma dos primeiros cubos até n
int somaCubos(int n) {
    if (n == 1) {
        return 1;
    }
    return pow(n, 3) + somaCubos(n - 1);
}

// Ex.2 - Imprime todos os naturais até n (ordem crescente)
void imprimeNaturaisAsc(int n) {
    if (n == 0) {
        printf("%d ", n);
        return;
    }
    imprimeNaturaisAsc(n - 1);
    printf("%d ", n);
    return;
}

// Ex.3 - Imprime todos os naturais até n (ordem decrescente)
void imprimeNaturaisDesc(int n) {
    if(n == 0) {
        printf("%d", n);
        return;
    }
    printf("%d ", n);
    imprimeNaturaisDesc(n - 1);
    return;
}

// Ex.4 - Retorna a soma dos termos do vetor v de inteiros de tamanho n
int somaTermosVetor(int *v, int n) {
    if (n == 1) {
        return v[0];
    }
    return v[n - 1] + somaTermosVetor(v, n - 1);
}

// Ex.5 - Retorna a média dos termos do vetor v de inteiros de tamanho n
// e iniciando no indice i
float mediaTermosVetor(int *v, int n, int i) {
    if (i == n - 1) {
        return (float)v[n - 1] / n;
    }
    return (float)v[i] / n + mediaTermosVetor(v, n, i + 1);
}

// Ex.6 - Retorna a potencia y de x, ou seja, x^y
int potencia(int x, int y) {
    if (y == 0) {
        return 1;
    }
    return x * potencia(x, y - 1);
}

// Ex.7 - Imprime uma string str invertida
void inverteString(char *str) {
    if (*str == '\0') {
        return;
    }
    inverteString(str + 1);
    printf("%c", *str);
    return;
}

// Ex.8 - Retorna um numero inteiro n invertido
// Ex: 123 -> 321
int inverteNumero(int n, int *soma) {
    int resto = 0;
    if (n == 0) {
        return *soma;
    }
    resto = n % 10;
    *soma *= 10;
    *soma += resto;
    inverteNumero(n / 10, soma);
    return *soma;
}

// Ex.9 - Converte um número decimal em binário e imprime na tela
void decimalBinario(int n) {
    int bit;
    if (n <= 1) {
        bit = n;
    } else if (n % 2 == 0) {
        decimalBinario(n / 2);
        bit = 0;
    } else {
        decimalBinario(n / 2);
        bit = 1;
    }
    printf("%d", bit);
}

// Ex. 10 - Retorna o menor elemento de um vetor v de inteiros de tamanho n
int menorTermo(int *v, int n) {
    int atual = v[n - 1];
    int menor;
    if (n - 1 == 0) {
        return v[0];
    }
    menor = menorTermo(v, n - 1);
    if (menor <= atual) {
        return menor;
    } else {
        return atual;
    }
}

int main(int argc, char const *argv[])
{
    int ex = 0, n = 0, x = 0, y = 0, i = 0, resultado = 0;
    int vetor[] = { 1, 2, 0, 4, 5};
    char string[128], c;

    scanf("%d", &ex);
    switch (ex) {
        case 1:
            scanf("%d", &n);
            printf("\nSoma dos %d primeiros cubos: %d", n, somaCubos(n));
            break;
        case 2:
            scanf("%d", &n);
            printf("\nNumero naturais de 0 a %d\n", n);
            imprimeNaturaisAsc(n);
            break;
        case 3:
            scanf("%d", &n);
            printf("\nNumeros naturais de %d a 0\n", n);
            imprimeNaturaisDesc(n);
            break;
        case 4:
            printf("\nSoma dos termos do vetor: %d", somaTermosVetor(vetor, 5));
            break;
        case 5:
            printf("\nMedia dos termos do vetor: %.1f", mediaTermosVetor(vetor, 5, 0));
            break;
        case 6:
            printf("\nDigite a base x e a potencia y: ");
            scanf("%d %d", &x, &y);
            printf("\n(%d^%d) = %d", x, y, potencia(x, y));
            break;
        case 7:
            printf("\nDigite um texto terminado com '.':\n");
            do {
                c = getc(stdin);
                string[i] = c;
                i++;
            } while (c != '.');

            string[i-1] = '\0';
            inverteString(string);
            break;
        case 8:
            scanf("%d", &n);
            printf("\nNumero %d invertido: %d", n, inverteNumero(n, &resultado));
            break;
        case 9:
            scanf("%d", &n);
            printf("\nO Numero decima %d em binario eh: ", n);
            decimalBinario(n);
            break;
        case 10:
            printf("\nMenor termo do vetor: %d", menorTermo(vetor, 5));
            break;
        default:
            break;
    }
    return 0;
}