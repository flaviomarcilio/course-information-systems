#include <stdio.h>

#include "prova2.h"

int M[MAX_TAM][MAX_TAM];
int n_main;
int numBlocosModelo = 0;
Bloco blocoModelo;
Bloco blocosModelo[MAX_TAM];

void testaZeraMatriz() {
    printf("\nDigite o tamanho da matriz: ");
    scanf("%d", &n_main);
    zeraMatriz(M, n_main);
    imprimeMatriz(M, n_main);
}

void testaInsereBloco() {
    int ok;

    printf("\nDigite um bloco (linha, coluna, tamanho) para ser inserido na matriz: ");
    scanf("%d %d %d", &blocoModelo.linha, &blocoModelo.coluna, &blocoModelo.tam);
    ok = insereBloco(M, n_main, blocoModelo);
    imprimeMatriz(M, n_main);
    printf("\nretorno: %d", ok);
}

void testaMaiorBloco() {
    int linha = 0, coluna = 0;
    Bloco bloco;

    printf("\nDigite a linha e coluna para pesquisar maior bloco: ");
    scanf("%d %d", &linha, &coluna);
    bloco = maiorBloco(M, n_main, linha, coluna);
    imprimeBloco(bloco);
}

void testaEncontraBlocos() {
    int i = 0, qtd = 0;

    printf("\nQuantos blocos quer incluir? ");
    scanf("%d", &qtd);
    for (i = 0; i < qtd; i++) {
        testaInsereBloco();
    }
    encontraBlocos(M, n_main, blocosModelo, &numBlocosModelo);
    printf("\nBlocos encontrados\n");
    for (i = 0; i < numBlocosModelo; i++) {
        imprimeBloco(blocosModelo[i]);
    }
}

void testaNumCharsDiferentes() {
    char str[256];

    printf("\nDigite uma string: ");
    fgets(str, 256, stdin);
    printf("Caracteres diferentes: %d", numCharsDiferentes(str));
}

void testaColisaoCirculoRetangulo() {
    Circulo cir;
    Retangulo ret;

    printf("Digite o centro (x, y) e o raio do circulo: ");
    scanf("%f %f %f", &cir.centro.x, &cir.centro.y, &cir.raio);

    printf("Digite as coordenadas do ponto superior esquerdo do retangulo: ");
    scanf("%f %f", &ret.sup_esq.x, &ret.sup_esq.y);

    printf("Digite as coordenadas do ponto inferior direito do retangulo: ");
    scanf("%f %f", &ret.inf_dir.x, &ret.inf_dir.y);
    printf("\nColisao: %d", colisaoCirculoRetangulo(cir, ret));
}

void main() {

    int ex;
    printf("\nQual exercicio quer testar (1, 2, 3, 4, 5, 6): ");
    scanf("%d", &ex);

    //inputs
    int n, i, j, tam, ok, numBlocos;
    char str[MAX_TAM];
    Bloco bloco;
    Circulo circulo;
    Retangulo retangulo;
    
    // matriz
    int M[MAX_TAM][MAX_TAM];

    switch (ex) {
        case 1:
            printf("\n******* Exercicio 1 *******\n");
            testaZeraMatriz();
            break;
        case 2:
            printf("\n******* Exercicio 2 *******\n");
            testaZeraMatriz();
            testaInsereBloco();
            break;
        case 3:
            printf("\n******* Exercicio 3 *******\n");
            testaZeraMatriz();
            testaInsereBloco();
            testaMaiorBloco();
            break;
        case 4:
            printf("\n******* Exercicio 4 ********\n");
            testaZeraMatriz();
            testaEncontraBlocos();
            break;
        case 5:
            printf("\n******** Exercicio 5 *******\n");
            testaNumCharsDiferentes();
            break;
        case 6:
            printf("\n******* Exercicio 6 *******\n");
            testaColisaoCirculoRetangulo();
            break;
        default:
            break;
    }
}