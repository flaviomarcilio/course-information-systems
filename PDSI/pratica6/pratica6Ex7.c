/*============================= Exercício 7: Inversão de string ===========================
Escreva um programa para ler um texto do teclado e imprimir o inverso dele. Use o ponto final
para indicar o término do texto, ou seja, o usuário deve terminar o texto sempre com um ponto
final. Leia um caractere do texto por vez usando a função getc como a seguir:
    char c = getc(stdin);
===========================================================================================*/
#include <stdio.h>
#include <string.h>

void inverteTexto(char str[]) {
    int tamanho = 0, i = 0, j = 0;
    
    tamanho = strlen(str);
    j = tamanho - 1;
    printf("\n");
    
    for (i = 0; i < tamanho; i++) {
        printf("%c", str[j]);
        j--;
    }
}

int main() {

    char texto[128], c;
    int i = 0;
    printf("\nDigite um texto terminado com '.':\n");
    do {
        c = getc(stdin);
        texto[i] = c;
        i++;
    } while (c != '.');

    texto[i] = '\0';
    printf("\nTexto invertido:");
    inverteTexto(texto);
    printf("\n");

    return 0;
    
}