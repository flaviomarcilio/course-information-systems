/*====================== Exercicio 2 - Introdução à ponteiros ==================================
a)​ Escreva um programa que cria três variáveis, uma do tipo inteiro, outra do tipo ponto
flutuante e outra do tipo caractere. Depois imprima na tela os endereços de memória que essas
variáveis fazem acesso.

b)​ Altere o programa abaixo de forma a fazer com que o mesmo imprima 3 ao invés de 0. Você
não pode executar nenhuma função de atribuição usando a variável ​x​ e nem alterar o comando
printf ​da última linha do corpo da função ​main​.

    #include <stdio.h>
    void ​main() {
        int ​x = 0;
        //coloque seu código aqui:
        printf(“%d”, x);
    } 
c)​ Escreva uma função de nome ​soma1​ que recebe como parâmetro um endereço de memória
de inteiros (ponteiro para inteiro) e que soma 1 ao valor do seu conteúdo. Essa função deve ser
do tipo ​void​. Parte do seu protótipo é:

    void soma1(______________);

d)​ Resolva o exercício ​2b​ usando a função do ​soma1​ do exercício anterior.
====================================================================================================*/
#include <stdio.h>

// Letra c
void soma1(int *numero) {
    *numero = *numero + 1;
    // (*numero)++;
}

void main() {
    int a;
    float b;
    char c;
    // Letra a
    printf("\nEndereco de int a: %p", &a);
    printf("\nEndereco de float b: %p", &b);
    printf("\nEndereco de char c: %p", &c);
    printf("\n");

    int x = 0;
    // Letra b
    /* int *y = &x;
    *y = *y + 3; */

    // Letra d
    soma1(&x);
    soma1(&x);
    soma1(&x);
    printf("%d", x);
}