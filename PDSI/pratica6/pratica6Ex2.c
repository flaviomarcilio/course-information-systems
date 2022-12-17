/*==================== Exercício 2: Calculador de conceito ================================
O conceito de um aluno é calculado a partir de sua nota, seguindo a tabela abaixo. Faça um
programa que lê a nota de um aluno do teclado e imprime seu conceito. Assuma que alunos só
podem receber notas inteiras (isto é, sem decimais). Você deve usar o comando ​switch​ para
verificar a nota lida.
Nota    Conceito
0 a 4      F
  5        E
  6        D
  7        C
  8        B
  9+       A
===========================================================================================*/
#include <stdio.h>

int main() {

    int nota = 0;
    char conceito = 'A';

    do {
        printf("\nDigite sua nota (numero inteiro): ");
        scanf("%d", &nota);
    } while (nota < 0);
    

    switch (nota) { // case 0 ... 4:
        case 0:
        case 1:
        case 2:
        case 3:
        case 4:
            conceito++;
        case 5:
            conceito++;
        case 6:
            conceito++;
        case 7:
            conceito++;
        case 8:
            conceito++;
    }

    printf("\nSeu conceito: %c", conceito);
    printf("\n");
    return 0;
}
