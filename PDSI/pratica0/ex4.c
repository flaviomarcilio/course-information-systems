/********************************Exercicio 4*********************************
 * Escreva um programa que imprime na tela todos os arquivos da pasta.      *
 * Use a função “system” da linguagem C (biblioteca “stdlib.h”) e o         *
 * comando “dir” do prompt de comando (ou “ls”, se está em um sistema UNIX).*                                          *
 * **************************************************************************/
#include <stdio.h>
#include <stdlib.h>

void main() {
    printf("%s", system("dir"));
}