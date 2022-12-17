#include <stdio.h>
#include <math.h>

#include "prova2.h"

void imprimeMatriz(int M[][MAX_TAM], int n) {
    int i = 0, j = 0;
    
    for (i = 0; i < n; i++) {
        printf("\n");
        for (j = 0; j < n; j++) {
            printf("%d ", M[i][j]);
        }
    }
    printf("\n");
}

void imprimeBloco(Bloco bloco) {
    printf("(%d, %d, %d)", bloco.linha, bloco.coluna, bloco.tam);
}

// Ex.1
void zeraMatriz(int M[][MAX_TAM], int n) {
    int i = 0, j = 0;

    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            M[i][j] = 0;
        }
    }
    
}

// Ex.2
int insereBloco(int M[][MAX_TAM], int n, Bloco b) {
    int i = 0, j = 0;

    if (b.linha < n && b.linha + b.tam <= n && b.coluna < n && b.coluna + b.tam <= n) {
        for (i = b.linha; i < b.linha + b.tam; i++) {
            for (j = b.coluna; j < b.coluna + b.tam; j++) {
                M[i][j] = 1;
            }
        }
        return 1;
    }
    return 0;
}

// Ex.3
Bloco maiorBloco(int M[][MAX_TAM], int n, int i, int j) {
    int linha = 0, coluna = 0, celulas = 0, lim_col = n, cont_linha = 0, cont_coluna = 0;
    Bloco b;

    if (M[i][j] == 1) {
        if (M[i][j+1] == 1 && M[i+1][j] == 1) {
            for (linha = i; linha < n; linha++) {
                // printf("\nLinha %d", linha);
                cont_linha++;
                // printf("\nqtd linhas: %d\n", cont_linha);

                cont_coluna = 0;
                for (coluna = j; coluna < lim_col; coluna++) {
                    // printf("\nColuna %d", coluna);
                    if (M[linha][coluna] == 0) {
                        lim_col = coluna;
                        break;
                    }
                    cont_coluna++;
                    // printf("\nqtd colunas: %d\n", cont_coluna);
                    // celulas++;
                }
                if (cont_linha > cont_coluna) {
                    // printf("\nlinha = %d\n", linha);
                    break;
                }
                // printf("\n");

            }
            b.linha = i;
            b.coluna = j;
            if (cont_linha <= cont_coluna) {
                b.tam = cont_linha;
            } else {
                b.tam = cont_linha - 1;
            }
            // b.tam = sqrt(celulas);
            return b;
        }
        b.linha = i;
        b.coluna = j;
        b.tam = 1;
        return b;
    }
    b.linha = i;
    b.coluna = j;
    b.tam = 0;
    return b;
}

// Ex.4
int ehParte(Bloco b, Bloco blocos[], int k) {
    int i = 0;
    Bloco teste;
    printf("\nBloco para testar: ");
    imprimeBloco(b);


    for (i = 0; i <= k; i++) {
        teste = blocos[i];
        printf("\nBloco de comparacao %d: ", i);
        imprimeBloco(teste);
        if (b.linha == blocos[i].linha && b.coluna < blocos[i].coluna + blocos[i].tam) {
            printf("\nreturn 1\n");
            return 1;
        } else if (b.linha < blocos[i].linha + blocos[i].tam && b.coluna == blocos[i].coluna) {
            printf("\nreturn 2\n");
            return 1;
        } else if (b.linha < blocos[i].linha + blocos[i].tam && b.coluna < blocos[i].coluna + blocos[i].tam) {
            printf("\nreturn 3\n");
            return 1;
        }
    }
    printf("\nreturn 4\n");
    return 0;
}

int fazParte(int M[][MAX_TAM], int n, int i, int j) {
    Bloco b;

    if (i < 0 || j < 0) {
        return 0;
    } else {
        b = maiorBloco(M, n, i, j);
    }
    printf("\nBloco de comparacao: ");
    imprimeBloco(b);
    printf("\nFim de comparacao\n");
    if (b.tam >= 2) {
        return 1;
    } else {
        return 0;
    }

}

void encontraBlocos(int M[][MAX_TAM], int n, Bloco blocos[], int *numBlocos) {
    int i = 0, j = 0;
    int matriz[MAX_TAM][MAX_TAM];
    Bloco b1;

    zeraMatriz(matriz, n);

    *numBlocos = 0;
    
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            b1 = maiorBloco(M, n, i, j);
            // printf("\nMaior bloco: ");
            // imprimeBloco(b1);

            if (b1.tam != 0 && matriz[i][j] == 0) {
                blocos[*numBlocos] = b1;
                (*numBlocos)++;
                insereBloco(matriz, n, b1);
            }
            // if (b1.tam != 0 && !fazParte(M, n, i-1, j-1) && !fazParte(M, n, i-1, j) && !fazParte(M, n, i, j-1)) {
            //     blocos[*numBlocos] = b1;
            //     (*numBlocos)++;
            // }

            // if (b1.tam != 0 && !ehParte(b1, blocos, *numBlocos)) {
            //     blocos[*numBlocos] = b1;
            //     (*numBlocos)++;
            // }
        }
    }
}

// Ex.5
int numCharsDiferentes(char str[]) {
    char c;
    int i = 0, car = 0, cont = 0, caractere[126];

    for (i = 0; i < 126; i++) {
        caractere[i] = 0;
    }

    c = str[car];
    while (c != '\0') {
        if (c >= 97 && c <= 122) {
            c -= 32;
        }
        if (caractere[c] == 0) {
            caractere[c] = 1;
            printf("\n%c", c);
            cont++;
        }
        car++;
        c = str[car];
    }
    return cont;
}

// Ex. 6
float distPontos(Ponto p1, Ponto p2) {
    return sqrt(pow(p2.x - p1.x, 2) + pow(p2.y - p1.y, 2));
}

int colisaoCirculoRetangulo(Circulo cir, Retangulo ret) {
    float dist = 0;
    Ponto p1, p2;
    
    //printf("\nCentro circulo = (%f, %f)", cir.centro.x, cir.centro.y);
    //printf("\nsup_esq = (%f, %f)", ret.sup_esq.x, ret.sup_esq.y);
    //printf("\ninf_dir = (%f, %f)", ret.inf_dir.x, ret.inf_dir.y);
    if (cir.centro.x < ret.sup_esq.x) {
        if (cir.centro.y < ret.sup_esq.y) {
            p1 = cir.centro;
            p2 = ret.sup_esq;
        } else if (cir.centro.y > ret.inf_dir.y) {
            p1 = cir.centro;
            p2.x = ret.sup_esq.x;
            p2.y = ret.inf_dir.y;
        } else {
            p1 = cir.centro;
            p2.x = ret.sup_esq.x;
            p2.y = cir.centro.y;
        }
    } else if (cir.centro.x > ret.inf_dir.x) {
        if (cir.centro.y < ret.sup_esq.y) {
            p1 = cir.centro;
            p2.x = ret.inf_dir.x;
            p2.y = ret.sup_esq.y;
        } else if (cir.centro.y > ret.inf_dir.y) {
            p1 = cir.centro;
            p2 = ret.inf_dir;
        } else {
            p1 = cir.centro;
            p2.x = ret.inf_dir.x;
            p2.y = cir.centro.y;
        }
    } else if (cir.centro.y < ret.sup_esq.y) {
        p1 = cir.centro;
        p2.x = cir.centro.x;
        p2.y = ret.sup_esq.y;
    } else if (cir.centro.y > ret.inf_dir.y) {
        p1 = cir.centro;
        p2.x = cir.centro.x;
        p2.y = ret.inf_dir.y;
    } else {
        return 1;
    }
    //printf("\nPonto 1 = (%f, %f)", p1.x, p2.y);
    //printf("\nPonto 2 = (%f, %f)", p2.x, p2.y);
    dist = distPontos(p1, p2);
    //printf("\ndist = %f", dist);
    if (dist <= cir.raio) {
        return 1;
    }
    return 0;
}