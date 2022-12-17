/*==================================== Exercício 9: Desafio ================================
Implementar um programa do ​Exercício 8 ​considerando os possíveis erros do usuário:
● O número de espaços entre os nomes pode ser ilimitado. Ex: “Pedro       Olmo”.
● Considerar que o usuário pode trocar letras maiúsculas por minúsculas e vice-versa. Ex:
“Pedro oLMo”.
● Desconsiderar todas as palavras conectoras de nomes: de, da, do, das, dos.
============================================================================================*/
#include <stdio.h>
#include <string.h>

int main() {

    char leitura[128], nome[128], abreviacao[10], c;
    int i = 0, j = 0, k = 0, verifica = 0, valor = 0, espaco = 0, tamanho = 0;

    printf("\nDigite o nome completo terminado com '.': ");

    do {
        c = getc(stdin);
        leitura[i] = c;
        i++;
    } while (c != '.');

    leitura[i] = '\0';
    tamanho = i;

    for (i = 0; i < tamanho; i++) {

        if (leitura[i] >= 97 && leitura[i] <= 122) {
            leitura[i] -= 32;
        }
        if (espaco == 1 && j != 0) {
            nome[j] = leitura[i];
            j++;
        }
        if (leitura[i] == 32) {
            espaco++;
            valor = 0;
        } else {
            nome[j] = leitura[i];
            if (verifica == 1 && (leitura[i] == 'E' || leitura[i] == 'A' || leitura[i] == 'O')) {
                verifica++;
            } else if (verifica == 2 && (leitura[i] == 'S' || leitura[i] == ' ')) {
                verifica++;
            } else if (verifica == 3 && leitura[i+1] == ' ') {
                verifica++;
            }
            if (valor == 0) {
                if (verifica == 2 || verifica == 3 || verifica == 4) {
                    k -= 2;
                    verifica = 0;
                }
                abreviacao[k] = leitura[i];
                k++;
                abreviacao[k] = '.';
                if (leitura[i] == 'D') {
                    verifica++;
                }
                k++;
                valor++;
            }
            j++;
            espaco = 0;
        }
    }

    abreviacao[k + 1] = '\0';
    nome[j+1] = '\0';

    printf("\nNome digitado: %s", nome);
    printf("\nAbreviacao: %s", abreviacao);
    printf("\n");

    return 0;
}