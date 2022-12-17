/*============================ Exercício 6: Detector de palíndromos =======================
Implemente código C para testar se uma ​string​ é um palíndromo. Um palíndromo é uma palavra
idêntica quando lida de trás para frente, como "arara", "radar" e "reviver".
===========================================================================================*/
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int palindromo(char str[]) {
    int tamanho = 0, i = 0, j = 0, meio;
    
    tamanho = strlen(str) - 1;
    // printf("\nTamanho da palavra: %d", tamanho);
    j = tamanho - 1;
    meio = tamanho / 2;

    for (i = 0; i <= meio; i++) {
        // printf("\nstr[%d]: %c, str[%d]: %c", i, str[i], j, str[j]);
        if (toupper(str[i]) != toupper(str[j])) {
            return 0;
        }
        j--;
    }

    return 1;
}

int main() {

    char palavra[128];
    printf("\nDigite uma palavra: ");
    fgets(palavra, 128, stdin);

    if (palindromo(palavra)) {
        printf("\nEssa palavra eh um palindromo.");
    } else {
        printf("\nEssa palavra nao eh um palindromo.");
    }
    printf("\n");
    return 0;
}