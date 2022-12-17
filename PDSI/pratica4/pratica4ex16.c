/*=================================== Exercício 16 =======================================
Escreva um ​programa​ que lê dois números inteiros do teclado e imprime na tela o máximo
divisor comum (MDC) e o mínimo múltiplo comum (MMC) entre eles. Caso o usuário insira
qualquer valor menor ou igual a zero, o programa deve informar isso a ele e pedir um novo
número. Esse processo deve se repetir enquanto qualquer qualquer um dos números lidos seja
menor ou igual a zero.
===========================================================================================*/

#include <stdio.h>

#include "pratica4.h"

void main() {

    int x, y;

    do
    {
        printf("\nDigite dois numeros inteiros maiores que zero: ");
        scanf("%d %d", &x, &y);
        if (x <= 0 || y <= 0) {
            printf("Numero menor ou igual a zero!\n");
        }
        
    } while (x <= 0 || y <= 0);

    printf("\nMDC(%d, %d) = %d", x, y, mdc(x, y));
    printf("\nMMC(%d, %d) = %d", x, y, mmc(x, y));
    printf("\n");

}