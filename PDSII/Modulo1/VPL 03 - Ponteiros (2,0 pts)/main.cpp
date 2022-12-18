#include <iostream>

int main(){

    // 1) Declare uma variável do tipo inteiro e atribua o valor '5'.
    int a = 5;

    // 2) Declare um vetor de inteiros e inicialize com valores de 0 a 9.
    int vetor[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};

    // 3) Declare um ponteiro para inteiros e inicialize com valor nulo.
    int *b = nullptr;

    // 4) Imprima o ENDEREÇO da variável declarada em (1)
    std::cout << &a << std::endl;

    // 5) Imprima o VALOR da variável declarada em (1)
    std::cout << a << std::endl;

    // 6) Imprima o ENDEREÇO da variável declarada em (2)
    std::cout << &vetor << std::endl;

    // 7) Imprima o ENDEREÇO da variável declarada em (3)
    std::cout << &b << std::endl;
    
    // 8) Imprima o VALOR da variável declarada em (3)
    std::cout << b << std::endl;

    // 9) Atribua o ENDEREÇO da variável declarada em (1) à variável declarada em (3)
    b = &a;

    // 10) Imprima o VALOR da variável declarada em (3)
    std::cout << b << std::endl;

    // 11) Imprima o VALOR guardado no ENDEREÇO apontado por (3)
    std::cout << *b << std::endl;

    // 12) Imprima o resultado da comparação do ENDEREÇO de (1) e do VALOR de (3)
    std::cout << (&a == b) << std::endl;

    // 13) Coloque o VALOR '10' no ENDEREÇO apontado por (3)
    *b = 10;

    // 14) Imprima o VALOR da variável declarada em (1)
    std::cout << a << std::endl;

    // 15) Atribua o ENDEREÇO da variável (2) à variável declarada em (3)
    b = vetor;

    // 16) Imprima o VALOR da variável declarada em (3)
    std::cout << b << std::endl;

    // 17) Imprima o VALOR guardado no ENDEREÇO apontado por (3)
    std::cout << *b << std::endl;

    // 18) Atribua o ENDEREÇO da primeira posição de (2) à variável declarada em (3)
    b = &vetor[0];

    // 19) Imprima o VALOR da variável declarada em (3)
    std::cout << b << std::endl;

    // 20) Imprima o VALOR guardado no ENDEREÇO apontado por (3)
    std::cout << *b << std::endl;

    // 21) Multiplique todos os valores do vetor declarado em (2) por '10', porém manipulando apenas a variável (3)
    for (int i = 0; i < 10; i++)
    {
        *(b+i) *= 10;
    }
    
    // 22) Imprima os elementos de (2) a partir variável do vetor utilizando a notação [] (colchetes)
    for (int i = 0; i < 10; i++)
    {
        std::cout << vetor[i] << " ";
    }
    std::cout << std::endl;

    // 23) Imprima os elementos de (2) a partir variável do vetor utilizando a notação ponteiro/deslocamento
    for (int i = 0; i < 10; i++)
    {
        std::cout << *(vetor+i) << " ";
    }
    std::cout << std::endl;

    // 24) Imprima os elementos de (2) manipulando apenas a variável (3)
    for (int i = 0; i < 10; i++)
    {
        std::cout << *(b+i) << " ";
    }
    std::cout << std::endl;

    // 25) Imprima o resultado da comparação do VALORES armazenado na quinta posição de (2) e no ponteiro (3) incrementado de 4
    std::cout << (vetor[4] == *(b+4)) << std::endl;

    // 26) Atribua o ENDEREÇO da quinta posição de (2) à variável declarada em (3)
    b = &vetor[4];

    // 27) Imprima o VALOR guardado no ENDEREÇO apontado por (3)
    std::cout << *b << std::endl;

    // 28) Imprima o VALOR guardado no ENDEREÇO do ponteiro (3) decrementado de 4
    std::cout << *(b-4) << std::endl;
    
    return 0;
}