/*============================ Exercício 4: Tamanho de uma string =========================
Implemente um programa que leia um ​string​ e conte o número de caracteres. ​Não​ use a função
strlen​. Para ler uma ​string​ de até 127 caracteres do teclado, use o seguinte código:

    char linha[128];
    printf("digite uma linha:\n");
    fgets(linha, 128, stdin); 
===========================================================================================*/
#include <stdio.h>

int main() {

    int i = 0;
    char linha[128];
    printf("\nDigite uma linha:\n");
    fgets(linha, 128, stdin);

    for (i = 0; i <= 128; i++) {
        if (linha[i] == 0)
            break;
    }
    
    printf("\nString com %d caracteres.\n", i-1);

    return 0;
}