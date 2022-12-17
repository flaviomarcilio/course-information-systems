/*======================================== Desafio - Campeonato ========================================
Escreva um programa que simula um campeonato entre 16 guerreiros. Este campeonato deve
ser do tipo mata-mata, ou seja, eliminatório. Na primeira rodada, simule 8 batalhas entre os 16
guerreiros, em que o guerreiro 1 enfrenta o 2, o 3 enfrenta o 4, e assim por diante. Depois,
simule batalhas entre os vencedores dos confrontos, ou seja, o vencedor do confronto 1
enfrenta o vencedor do confronto 2, o vencedor do confronto 3 enfrenta o vencedor do
confronto 4, e assim por diante. Repita esse procedimento até chegar no campeão. Imprima o
seu identificador e a sua quantidade de pontos de vida. Este exercício deve usar o módulo
jogo​ criado no exercício anterior e deve ser implementado no arquivo ​testacampeonato.c​.
========================================================================================================*/

#include <stdio.h>

#include "jogo.h"

#define MAX_JOGADORES 16

void fase_campeonato(Guerreiro *fase[], Guerreiro *prox_fase[], int tam_fase) {
    Guerreiro *aux, *atacante, *defensor;
    int cont = 0, i = 0, round = 1;;
    
    for (i = 0; i < tam_fase; i+=2) {
        atacante = fase[i];
        defensor = fase[i+1];
        printf("\nGuerreiro %d X Guerreiro %d", atacante->id_guerreiro, defensor->id_guerreiro);
        round = 1;
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
        printf("\nVencedor: Guerreiro %d | Vida restante: %d", atacante->id_guerreiro, atacante->pontos_vida);
        printf("\n");
        prox_fase[cont] = atacante;
        cont++;

    }
}

int main() {
    int i = 0, fase = 1;
    int count_players = MAX_JOGADORES;
    Guerreiro guerreiros[MAX_JOGADORES];
    Guerreiro *jogadores[MAX_JOGADORES], *vencedores[MAX_JOGADORES];

    for (i = 0; i < MAX_JOGADORES; i++) {
        criaGuerreiro(&guerreiros[i]);
        vencedores[i] = &guerreiros[i];
        printf("\nGuerreiro %d - ", guerreiros[i].id_guerreiro);
        printf("Vida: %d | Ataque: %d | Defesa: %d | Carisma: %d",
            guerreiros[i].pontos_vida, guerreiros[i].ataque, guerreiros[i].defesa, guerreiros[i].carisma);
        printf("\n");
    }

    while (count_players > 1) {
        printf("\n###### FASE %d ######\n", fase);
        for (i = 0; i < count_players; i++) {
            jogadores[i] = vencedores[i];
        }
        fase_campeonato(jogadores, vencedores, count_players);
        count_players /= 2;
        fase++;
    }
    printf("\n###### FIM DE JOGO ######");
    printf("\nCAMPEAO: Guerreiro %d", vencedores[0]->id_guerreiro);
    printf("\n");

    return 0;
}