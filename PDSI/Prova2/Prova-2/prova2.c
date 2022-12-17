#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX_TAM 100

typedef struct Bloco {
	int linha, coluna, tam;
} Bloco;

typedef struct Ponto {
    float x, y;
} Ponto;

typedef struct Circulo {
	Ponto centro;
	float raio;
} Circulo;

typedef struct Retangulo {
	Ponto sup_esq, inf_dir; 
} Retangulo;

//1)

void zeraMatriz(int M[][MAX_TAM], int n) {
    int i = 0, j = 0;
    
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            M[i][j] = 0;
        }
    }
}

//2)

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

//3)

Bloco maiorBloco(int M[][MAX_TAM], int n, int i, int j) {
    int linha = 0, coluna = 0, lim_col = n, cont_linha = 0, cont_coluna = 0;
    Bloco b;
    
    if (M[i][j] == 1) {
        if (M[i][j+1] == 1 && M[i+1][j] == 1) {
            for (linha = i; linha < n; linha++) {
                cont_linha++;
                cont_coluna = 0;
                for (coluna = j; coluna < lim_col; coluna++) {
                    if (M[linha][coluna] == 0) {
                        lim_col = coluna;
                        break;
                    }
                    cont_coluna++;
                }
                if (cont_linha > cont_coluna) {
                    break;
                }
            }
            b.linha = i;
            b.coluna = j;
            if (cont_linha <= cont_coluna) {
                b.tam = cont_linha;
            } else {
                b.tam = cont_linha - 1;
            }
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

//4)

void encontraBlocos(int M[][MAX_TAM], int n, Bloco blocos[], int *numBlocos) {
    int i = 0, j = 0;
    int matriz[MAX_TAM][MAX_TAM];
    Bloco b;
    
    zeraMatriz(matriz, n);
    
    *numBlocos = 0;
    
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            b = maiorBloco(M, n, i, j);
            if (b.tam != 0 && matriz[i][j] == 0) {
                blocos[*numBlocos] = b;
                (*numBlocos)++;
                insereBloco(matriz, n, b);
            }
        }
    }
}

//5) 

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
            cont++;
        }
        car++;
        c = str[car];
    }
    return cont;
}

// 6

float distPontos(Ponto p1, Ponto p2) {
    return sqrt(pow(p2.x - p1.x, 2) + pow(p2.y - p1.y, 2));
}

int colisaoCirculoRetangulo(Circulo cir, Retangulo ret) {
    float dist = 0;
    Ponto p1, p2;
    
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
            p2.x = ret.sup_esq.y;
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
    
    dist = distPontos(p1, p2);
    
    if (dist <= cir.raio) {
        return 1;
    }
    return 0;
}

// 0

void minha_main() {
    //Voce pode simular uma funcao main nesta funcao. Use-a para testar o que quiser. 
    //Para isso, execute a sua prova e entre com o exercicio 0.
    //Isso fara com que esta funcao (minha_main) seja chamada pelo VPL.
    //Importante: esta funcao NAO sera avaliada!!! No entanto, erros de compilacao nesta funcao invalidam (nota 0!) TODA a prova!
    
    printf("\nPor enquanto nao estou fazendo nada :(");
    
}

