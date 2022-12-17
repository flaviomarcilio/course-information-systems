#include <stdio.h>

/*============================== Exercicio 1 ==================================*/
void imprimePilhas(int p1, int p2, int p3) {
    
    printf("\n%d ", p1);
    for (int i = 0; i < p1; i++) {// não declarar int i = 0 dentro do for
        printf("|"); // printf("%c", 124)
    }
    printf("\n%d ", p2);
    for (int i = 0; i < p2; i++) {
        printf("|");
    }
    printf("\n%d ", p3);
    for (int i = 0; i < p3; i++) {
        printf("|");
    }
    printf("\n");

}

/*============================== Exercicio 2 ==================================*/
int maior3(int n1, int n2, int n3) {
    int maior;

    /* if (n1 >= n2 && n1 >= n3) return n1
       if (n2 >= n1 && n2 >= n3) return n2
       return n3*/

    if (n1 > n2) {
        if (n1 > n3) {
            maior = n1;
        } else {
            maior = n3;
        }
    } else {
        if (n2 > n3) {
            maior = n2;
        } else {
            maior = n3;
        }
    }
    return maior;
}

void imprimePilhas2(int p1, int p2, int p3) {

    int maior, pilha1, pilha2, pilha3;
    pilha1 = p1;
    pilha2 = p2;
    pilha3 = p3;

    maior = maior3(p1, p2, p3);

    while (maior > 0) {
        printf("\n");
        if (p1 == maior) {
            printf("_"); // printf("%c", 95)
            p1--;
        } else {
            printf(" ");
        }
        if (p2 == maior) {
            printf(" _");
            p2--;
        } else {
            printf("  ");
        }
        if (p3 == maior) {
            printf(" _");
            p3--;
        } else {
            printf("  ");
        }
        maior--;
    }
    
    printf("\n%d %d %d", pilha1, pilha2, pilha3);
    printf("\n");
}

/*============================== Exercicio 3 ==================================*/
void leJogada(int *end_p, int *end_q) {

    int pilha, palitos;

    printf("Escolha uma pilha (1, 2 ou 3):\n");
    scanf("%d", &pilha); //scanf("%d", end_p)
    *end_p = pilha;
    printf("Quantos palitos gostaria de remover?\n");
    scanf("%d", &palitos); //scanf("%d", end_q)
    *end_q = palitos;

}

/*============================== Exercicio 4 ==================================*/
int diminuiPilha(int *end_p, int q) {

    int pilha, palitos;
    pilha = *end_p;
    palitos = q;
    // printf("\ndiminuiPilha: Pilha: %d Palitos: %d", pilha, palitos);

    if (palitos > 0 && palitos <= pilha) {
        pilha = pilha - palitos;
        *end_p = pilha; // *end_p = *end_p - q
        // printf("\nPilha nova: %d", pilha);
        return 1;
    }
    return 0;

}

/*============================== Exercicio 5 ==================================*/
int confereJogo(int p1, int p2, int p3) {
    
    if (p1 != 0 || p2 != 0 || p3 != 0) {// if(p1 + p2 + p3 > 0)
        return 1;
    }
    return 0;

}

/*============================== Exercicio 6 ==================================*/
int jogo(int p1, int p2, int p3) {

    int jogador, jogador1 = 1, jogador2 = 2, i = 1, jogada, p4 = -1;
    int pilha, palitos;

    do {
        // Jogador da vez
        i++;
        jogador = (i % 2 == 0) ? jogador1 : jogador2;
        
        do {
            // Inicio da jogada
            imprimePilhas2(p1, p2, p3);

            printf("\nJogador: %d\n", jogador);

            // Jogada
            leJogada(&pilha, &palitos);
            // printf("\nJogada: Pilha: %d Palitos: %d", pilha, palitos);

            // Executa jogada
            if (pilha == 1) {
                jogada = diminuiPilha(&p1, palitos);
            } else if (pilha == 2) {
                jogada = diminuiPilha(&p2, palitos);
            } else if (pilha == 3) {
                jogada = diminuiPilha(&p3, palitos);
            } else {
                jogada = diminuiPilha(&p4, palitos);// jogada = 0
            }
            /* switch (pilha) {
                case 1:
                    jogada = diminuiPilha(&p1, palitos);
                    break;
                case 2:
                    jogada = diminuiPilha(&p2, palitos);
                    break;
                case 3:
                    jogada = diminuiPilha(&p3, palitos);
                    break;
            } */
            
            // printf("\nApos jogada %d: Pilha: %d Palitos: %d", jogada, pilha, palitos);
            
            if (jogada == 0) {
                printf("\nErro! Jogue novamente!");
                // printf("\nPilha: %d, Palitos: %d", pilha, palitos);
            }/*else {
            		 if(jogador == 1) jogador = 2;
            		 else jogador = 1;*/

        } while (jogada == 0);
        
    } while (confereJogo(p1, p2, p3));

    if (jogador == jogador1) {
        return jogador2;
    }
    return jogador1;
}

/*============================== Exercicio 7 ==================================*/
int main() {// int principal() {}

    int p1, p2, p3, vencedor;

    do
    {
        printf("\nEntre com a quantidade inicial de palitos em cada pilha: ");
        scanf("%d %d %d", &p1, &p2, &p3);

    } while (p1 <= 0 || p2 <= 0 || p3 <= 0);
    
    // Executa o Jogo
    vencedor = jogo(p1, p2, p3);// return vencedor
    printf("\nO jogador vencedor foi: %d", vencedor);
    return 1;

}