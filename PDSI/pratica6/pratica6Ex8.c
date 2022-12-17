/*============================== Exercício 8: Abreviação de nome ==========================
Escreva um programa para ler um nome completo do teclado terminado com um ponto final (‘.’).
Seu programa deve imprimir o mesmo na forma abreviada. Exemplo: o nome “Pedro Olmo
Stancioli Vaz de Melo.” deve ser abreviado para “P.O.S.V.M.”. Note que o processo de
abreviação deve ignorar palavras que começam com caracteres minúsculos. Considere que o
usuário irá inserir apenas nomes válidos, sempre irá terminar o nome com o caractere ‘.’ e o
nome não conterá acentos.
============================================================================================*/
#include <stdio.h>
#include <string.h>

void abreviaNome(char str[]) {
    int tamanho = 0, i = 0;
    
    tamanho = strlen(str) - 1;

    for (i = 0; i < tamanho; i++) {
        if (str[i] >= 65 && str[i] <= 90) {
            printf("%c.", str[i]);
        }
    }
}

int main() {

    char nome[128], c;
    int i = 0;
    printf("\nDigite o nome completo terminado com '.': ");

    do {
        c = getc(stdin);
        nome[i] = c;
        i++;
    } while (c != '.');

    nome[i] = '\0';

    printf("\nNome abreviado: ");

    abreviaNome(nome);

    printf("\n");

    return 0;
}