/*================================== Exercício 2 - Simulação da Batalha ==================================
Escreva um programa que simula a batalha até a morte entre dois guerreiros. Para isso, crie
dois guerreiros, um com ​id_guerreiro = 1​ e outro com ​id_guerreiro = 2​. Depois,
atribua valores aleatórios para os seus campos de batalha a partir da função ​criaGuerreiro
e inicie ataques intercalados entre esses guerreiros, ou seja, comece com o guerreiro ​1
atacando o ​2​, depois o ​2​ atacando o ​1,​ depois o ​1​ atacando o ​2,​ e assim por diante. Para
simular um ataque, use a função ​ataca​. A batalha deve acabar quando um dos jogadores, o
perdedor, alcançar ​0​ ​pontos_vida​. Imprima na tela “\nVencedor: “ e logo em seguida o
identificador do guerreiro vencedor (exemplo de impressão: “\nVencedor: 1”). Imprima também
“\nPontos de vida restantes: ” e os pontos de vida restantes do guerreiro vencedor. Este
exercício deve usar o módulo ​jogo​ criado no exercício anterior e deve ser implementado no
arquivo ​testajogo.c​.
==========================================================================================================*/

#include <stdio.h>

#include "jogo.h"

int main() {
    int round = 1;
    Guerreiro g1, g2;
    Guerreiro *aux, *atacante, *defensor;

    criaGuerreiro(&g1);
    printf("\nGuerreiro %d - Vida: %d | Ataque: %d | Defesa: %d | Carisma: %d",
            g1.id_guerreiro, g1.pontos_vida, g1.ataque, g1.defesa, g1.carisma);
    printf("\n");

    criaGuerreiro(&g2);
    printf("\nGuerreiro %d - Vida: %d | Ataque: %d | Defesa: %d | Carisma: %d",
            g2.id_guerreiro, g2.pontos_vida, g2.ataque, g2.defesa, g2.carisma);
    printf("\n");

    atacante = &g1;
    defensor = &g2;
    while (1) {
        printf("\nRound %d: Atacante: %d - vida: %d | Defensor: %d - vida: %d", round,
                atacante->id_guerreiro, atacante->pontos_vida,
                defensor->id_guerreiro, defensor->pontos_vida);
        round++;
        ataca(atacante, defensor);
        if (defensor->pontos_vida == 0) {
            break;
        }
        aux = atacante;
        atacante = defensor;
        defensor = aux;
    }

    printf("\nVencedor: %d | Vida restante: %d", atacante->id_guerreiro, atacante->pontos_vida);
    printf("\n");

    return 0;
}