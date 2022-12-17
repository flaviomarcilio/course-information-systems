/*=============================== Exercício 5: Conversão de caixa =========================
Faça um programa que leia um ​string​ e modifique todos os caracteres minúsculos por
caracteres maiúsculos.
Dica: os caracteres minúsculos tem o código ASCII entre 97 e 122 e os caracteres maiúsculos
tem o código ASCII entre 65 e 90.
===========================================================================================*/
#include <stdio.h>

int main() {
    int i = 0;

    char string[128];
    printf("Digite uma string:\n");
    fgets(string, 128, stdin);

    for (i = 0; i <= 128; i++) {
        if (string[i] >= 97 && string[i] <= 122)
            string[i] -= 32;
        if (string[i] == 0)
            break;
    }

    printf("\nString em CAIXA ALTA:\n%s", string);
    return 0;
}