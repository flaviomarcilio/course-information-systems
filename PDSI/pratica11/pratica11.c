/*========================================== Exercício ==========================================
Problema
Você recebeu um arquivo ​cartelas.txt​ contendo 1 milhão de apostas feitas na mega-sena.
Neste exercício, você deve verificar duas coisas. Primeiro, conte e imprima o número de
cartelas que foram vencedoras. Os números sorteados foram: 6, 9, 22, 23, 48, 52. Depois, à
título de curiosidade, você deve contar quantas pessoas apostaram nos números do seriado
Lost, que são: 4, 8, 15, 16, 23, 42.

DESAFIO PARA OS FORTES
Além dos vencedores, imprimir também o número de cartelas que conseguiram a quadra
(acertar quatro números) e a quina (acertar cinco números).
=================================================================================================*/

#include <stdio.h>

int SENA[] = {6, 9, 22, 23, 48, 52};
int LOST[] = {4, 8, 15, 16, 23, 42};

void ordenaCont(int vet[], int vet_ord[], int n) {
	// Ordenação por Contagem
	int i = 0, j = 0;
	int cont[6];

	for (j = 0; j < n; j++) {
		cont[j] = 0;
		for (i = 0; i < n; ++i) {
			if (vet[i] < vet[j]) {
				cont[j]++;
			}
		}
		vet_ord[cont[j]] = vet[j];
	}
}

int ehVencedora(int apostaOrd[], int apostaVencedora []) {
    int i = 0;

    for (i = 0; i < 6; i++) {
        if (apostaOrd[i] != apostaVencedora[i]) {
            return 0;
        }
    }
    return 1;
}

int acertos(int apostaOrd[], int apostaVencedora[]) {
    int i = 0, j = 0, acertos = 0;

    if (ehVencedora(apostaOrd, apostaVencedora)) {
        return 6;
    }
    for (i = 0; i < 6; i++) {
        for (j = 0; j < 6; j++) {
            if (apostaOrd[i] == apostaVencedora[j]) {
                acertos++;
                break;
            }
        }
    }
    return acertos;
}

int main(int argc, char const *argv[]) {
    int numAcertos = 0, i = 0, vencedoras = 0, apostaLost = 0, quadra = 0, quina = 0;
    int aposta[6], apostaOrd[6];

    FILE *cartelas;
    cartelas = fopen("cartelas.txt", "r");


    while (!feof(cartelas)) {

        numAcertos = 0;

        if (fscanf(cartelas, "%d", &aposta[0]) == 1) {

            for (i = 1; i < 6; i++) {
                fscanf(cartelas, "%d", &aposta[i]);
            }

            ordenaCont(aposta, apostaOrd, 6);
            numAcertos = acertos(apostaOrd, SENA);

            if (numAcertos == 6) {
                vencedoras++;
            } else if (numAcertos == 5) {
                quina++;
            } else if (numAcertos == 4) {
                quadra++;
            }
            numAcertos = acertos(apostaOrd, LOST);
            if (numAcertos == 6) {
                apostaLost++;
            }
        }
    }
    printf("\nApostas vencedoras: %d", vencedoras);
    printf("\nAcertadores da Quina: %d", quina);
    printf("\nAcertadores da Quadra: %d", quadra);
    printf("\nLost na veia: %d", apostaLost);
    printf("\n");

    fclose(cartelas);
    return 0;
}
