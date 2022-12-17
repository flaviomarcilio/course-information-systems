/*================= Exercicio 3 - Atribuição dinâmica de valores ==============================
A função ​scanf​ permite que o usuário entre com valores para serem armazenados em
endereços da memória. Caso você tenha variáveis no seu programa, a função ​scanf​ pode
atribuir os valores que o usuário entrar diretamente nos endereços das suas variáveis, ou seja,
atribui valores às próprias variáveis.
Considere o programa abaixo, em que o usuário entra com dois valores ponto flutuante, que
são atribuídos aos endereços das variáveis ​x​ e ​y​. Altere este programa de forma a trocar os
valores das duas variáveis. Você não pode alterar o último ​printf​.
    #include <stdio.h>
    void ​main() {
    float ​x,y;
    scanf(“%f %f”, &x, &y);
    //coloque seu código aqui:
    printf(“\nx = %f\ny = %f”, x, y);
    }
=============================================================================================*/
#include <stdio.h>

void main() {

    float x, y;
    scanf("%f %f", &x, &y);

    // float aux = x;
    // x = y;
    // y = aux;

    float *ptr_x, *ptr_y;
    float aux;
    ptr_x = &x;
    ptr_y = &y;
    aux = *ptr_x;
    *ptr_x = *ptr_y;
    *ptr_y = aux;

    printf("\nx = %f\ny = %f", x, y);
    
}