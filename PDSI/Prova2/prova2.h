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

void imprimeMatriz(int M[][MAX_TAM], int n);
void imprimeBloco(Bloco bloco);

void zeraMatriz(int M[][MAX_TAM], int n);
int insereBloco(int M[][MAX_TAM], int n, Bloco b);
Bloco maiorBloco(int M[][MAX_TAM], int n, int i, int j);
void encontraBlocos(int M[][MAX_TAM], int n, Bloco blocos[], int *numBlocos);
int numCharsDiferentes(char str[]);
float distPontos(Ponto p1, Ponto p2);
int colisaoCirculoRetangulo(Circulo cir, Retangulo ret);