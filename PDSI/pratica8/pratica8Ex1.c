/*================================== Exercício 1 ============================================
Neste exercício você deve fazer um programa para encontrar sequências de números iguais
consecutivos, tanto na horizontal quanto na vertical, em uma matriz ​m x n​. Depois, você deve
substituir esses números por zeros e colocá-los nas primeiras linhas da matriz. Todo o
programa será implementado a partir das questões a seguir.

1.1)​ Faça um programa para preencher uma matriz ​m x n ​com números aleatórios entre ​1​ e ​k​.
Os valores de ​m​, ​n​ e ​k​ devem ser lidos do teclado. Como ainda não aprendemos alocação
dinâmica de memória, crie uma matriz estaticamente com os limites superiores de ​m​ e ​n​.
Considere que ​m​ e ​n​ não podem ser maiores que ​100​. Não permita que o usuário entre com
valores inválidos para ​m​, ​n​ e ​k.

1.2)​ Procure por sequências com pelo menos três números consecutivos iguais tanto nas linhas
quanto nas colunas da matriz. Substitua todos os números que estão nessas sequências por ​0​.

1.3)​ Imprima na tela o número de zeros que a matriz possui depois do passo ​1.2​.

1.4)​ Altere a matriz colocando todos os zeros nas primeiras linhas das suas respectivas
colunas. Preserve a ordem dos outros números dentro da coluna. Imprima a matriz final.

1.5)​ Repita os procedimentos descritos nos itens 1.2, 1.3 e 1.4 até que a matriz final não 
tenha sequências de tamanho maior ou igual a 3 de números consecutivos maiores que zero.
===========================================================================================*/

#include <stdio.h>
#include <stdlib.h>

#define LINHAS 100
#define COLUNAS 100
#define MAX_ALEATORIO 10

void leNumero(int *num, int minimo, int maximo) {
    do {
        scanf("%d", num);
        if (*num <= minimo || *num > maximo) {
            printf("\nNumero invalido!\n");
        }
    } while (*num <= minimo || *num > maximo);
}

void preencheMatriz(int matriz[][COLUNAS], int linhas, int colunas, int limite) {
    int i = 0, j = 0;

    for (i = 0; i < linhas; i++) {
        for (j = 0; j < colunas; j++) {
            matriz[i][j] = 1 + rand()%limite;
        }
    }
}

void zeraMatriz(int matriz[][COLUNAS], int linhas, int colunas) {
    int i = 0, j = 0;

    for (i = 0; i < linhas; i++) {
        for (j = 0; j < colunas; j++) {
            matriz[i][j] = 0;
        }
    }
}

void imprimeMatriz(int matriz[][COLUNAS], int linhas, int colunas){
    int i = 0, j = 0;

    printf("\n");
    for (i = 0; i < linhas; i++) {
        for (j = 0; j < colunas; j++) {
            printf("%d ", matriz[i][j]);
        }
        printf("\n");
    }
}

int zeraSequencia(int matriz[][COLUNAS], int linhas, int colunas) {
    int i = 0, j = 0, aux = 0, zeros = 0;
    int map[LINHAS][COLUNAS];

    zeraMatriz(map, linhas, colunas);

    // Procura sequencia nas linhas
    int pivo_linha = 0, seq_linha = 1, j_atual = 0;
    for (i = 0; i < linhas; i++) {
        pivo_linha = matriz[i][0];
        j_atual = 0;
        seq_linha = 1;
        for (j = 1; j < colunas; j++) {
            if (pivo_linha != 0 && pivo_linha == matriz[i][j]) {
                seq_linha++;
            } else {
                pivo_linha = matriz[i][j];
                j_atual = j;
                seq_linha = 1;
            }
            if (seq_linha == 3) {
                for (aux = 0; aux < 3; aux++) {
                    map[i][j_atual + aux] = 1;
                }   
            } else if (seq_linha > 3) {
                map[i][j_atual + seq_linha - 1] = 1;
            }
        }
    }
    // Procura sequencia nas colunas
    int pivo_coluna = 0, seq_coluna = 1, i_atual = 0;
    for (j = 0; j < colunas; j++) {
        pivo_coluna = matriz[0][j];
        i_atual = 0;
        seq_coluna = 1;
        for (i = 1; i < linhas; i++) {
            if (pivo_coluna != 0 && pivo_coluna == matriz[i][j]) {
                seq_coluna++;
            } else {
                pivo_coluna = matriz[i][j];
                i_atual = i;
                seq_coluna = 1;
            }
            if (seq_coluna == 3) {
                for (aux = 0; aux < 3; aux++) {
                    map[i_atual + aux][j] = 1;
                }   
            } else if (seq_coluna > 3) {
                map[i_atual + seq_coluna - 1][j] = 1;
            }
        }
    }

    for (i = 0; i < linhas; i++) {
        for (j = 0; j < colunas; j++) {
            if (map[i][j] == 1) {
                matriz[i][j] = 0;
                zeros++;
            }
        }
    }
    return zeros;
}

void moveZeros(int matriz[][COLUNAS], int linhas, int colunas) {
    int i = 0, j = 0, k = 0, aux = 0;

    for (i = 0; i < linhas; i++) {
        for (j = 0; j < colunas; j++) {
            if (matriz[i][j] == 0) {
                for (k = i-1; k >= 0; k--) {
                    aux = matriz[k][j];
                    if (aux == 0) {
                        break;
                    } else {
                        matriz[k][j] = matriz[k+1][j];
                        matriz[k+1][j] = aux;
                    }
                }
            }
        }
    }
}


int main() {
    int linhas = 0, colunas = 0, k = 0, i = 0, j = 0;
    int matriz[LINHAS][COLUNAS], map[LINHAS][COLUNAS];
    int alteracoes = 0, zeros = 0;

    printf("\nDigite o numero m de linhas (1 < m < %d): ", LINHAS);
    leNumero(&linhas, 1, LINHAS);
    printf("\nDigite o numero n de colunas (1 < n < %d): ", COLUNAS);
    leNumero(&colunas, 1, COLUNAS);
    printf("\nDigite o limite k para os numeros aleatorios (1 < k < %d): ", MAX_ALEATORIO);
    leNumero(&k, 1, MAX_ALEATORIO);

    preencheMatriz(matriz, linhas, colunas, k);

    /*
    // Caso de Teste
    linhas = 5;
    colunas = 4;
    matriz[0][0] = 3; matriz[0][1] = 3; matriz[0][2] = 3; matriz[0][3] = 2;
    matriz[1][0] = 3; matriz[1][1] = 2; matriz[1][2] = 2; matriz[1][3] = 3;
    matriz[2][0] = 1; matriz[2][1] = 1; matriz[2][2] = 1; matriz[2][3] = 1;
    matriz[3][0] = 2; matriz[3][1] = 1; matriz[3][2] = 2; matriz[3][3] = 1;
    matriz[4][0] = 2; matriz[4][1] = 3; matriz[4][2] = 3; matriz[4][3] = 1; */
    
    printf("\nMatriz original:");
    imprimeMatriz(matriz, linhas,colunas);

    while (1) {
        alteracoes = zeraSequencia(matriz, linhas, colunas);
        zeros += alteracoes;
        if (!alteracoes) {
            break;
        }
        moveZeros(matriz, linhas, colunas);
    }
    printf("\nMatriz final:");
    imprimeMatriz(matriz, linhas, colunas);

    printf("\nNumero de zeros: %d", zeros);
    printf("\n");

    return 0;
}