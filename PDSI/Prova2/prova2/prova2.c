#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX_TAM 100
#define DEBUG 0


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

typedef struct Bloco {
	int linha, coluna, tam;
} Bloco;

void imprimeMatriz(int M[][MAX_TAM], int n) {
	int i, j;	
	printf("\n");
	for(i=0; i<n; i++) {
		for(j=0; j<n; j++)
			printf("%2d ", M[i][j]);
		printf("\n");
	}
}

//1)

void zeraMatriz(int M[][MAX_TAM], int n) {

	int i, j;
	for(i=0; i<n; i++)
		for(j=0; j<n; j++)
			M[i][j] = 0;
}

//2)

int insereBloco(int M[][MAX_TAM], int n, Bloco b) {

	if(b.coluna < 0 || b.coluna+b.tam > n || b.linha < 0 || b.linha+b.tam > n)
		return 0;

	int i, j;
	for(i=b.linha; i<b.linha+b.tam; i++)
		for(j=b.coluna; j<b.coluna+b.tam; j++) 
			M[i][j] = 1;

	return 1;
}


//3)

int testaBlocoTam(int M[][MAX_TAM], int n, int i, int j, int tam) {
	int ii, jj;
	for(ii=i; ii<i+tam; ii++) {
		for(jj=j; jj<j+tam; jj++) {
			if(M[ii][jj] != 1)
				return 0;
		}
	}
	return 1;
}

Bloco maiorBloco(int M[][MAX_TAM], int n, int i, int j) {

	Bloco b;
	b.tam = 0;
	b.linha = i;
	b.coluna = j;

	if(i < 0 || i >= n || j < 0 || j >= n)
		return b;

	
	while(testaBlocoTam(M, n, i, j, b.tam))
		b.tam++;

	b.tam--;
	return b;
	
}


//4)

void marcaBloco(int M[][MAX_TAM], int n, Bloco b) {
	int i, j;
	for(i=b.linha; i<b.linha+b.tam; i++) {
		for(j=b.coluna; j<b.coluna+b.tam; j++) {
			M[i][j] = -1;
		}
	}
}

void encontraBlocos(int M[][MAX_TAM], int n, Bloco blocos[], int *numBlocos) {

	int i=0, j=0, tam;
	Bloco b;

	for(i=0; i<n; i++) {

		for(j=0; j<n; j++) {

			if(M[i][j] == 1) {
				b = maiorBloco(M, n, i, j);
				marcaBloco(M, n, b);
				blocos[*numBlocos] = b;
				*numBlocos += 1;
			}

		}
	}

}

//5) 

int somaVetor(int vec[], int n) {
	int i;
	int soma = 0;
	for(i=0; i<n; i++)
		soma += vec[i];

	return soma;
}

int numCharsDiferentes(char str[]) {

	int check[256];
	int i=0;

	for(i=0; i<256; i++)
		check[i] = 0;

	i=0;
	while(str[i] != '\0') {
		check[toupper(str[i])] = 1;
		i++;
	}

	if(DEBUG) {
		for(i=0; i<256; i++)
			if(check[i]) printf("(%d,%c)", i, i);		
	}

	return somaVetor(check, 256);

}

// 6


float dist(float x1, float y1, float x2, float y2) {
	return sqrt(pow(x1 - x2,2) + pow(y1 - y2,2));
}

int colisaoCirculoRetangulo(Circulo cir, Retangulo ret) {

	if(cir.centro.x >= ret.sup_esq.x && cir.centro.x <= ret.inf_dir.x) {

		if(cir.centro.y + cir.raio >= ret.sup_esq.y && cir.centro.y - cir.raio <= ret.inf_dir.y) {
			return 1;
		}

	}  

	if(cir.centro.y >= ret.sup_esq.y && cir.centro.y <= ret.inf_dir.y) {

		if(cir.centro.x + cir.raio >= ret.sup_esq.x && cir.centro.x - cir.raio <= ret.inf_dir.x) {
			return 1;
		}

	}  	

	if(dist(cir.centro.x, cir.centro.y, ret.sup_esq.x, ret.sup_esq.y) <= cir.raio ||
	   dist(cir.centro.x, cir.centro.y, ret.sup_esq.x, ret.inf_dir.y) <= cir.raio ||
	   dist(cir.centro.x, cir.centro.y, ret.inf_dir.x, ret.sup_esq.y) <= cir.raio ||
	   dist(cir.centro.x, cir.centro.y, ret.inf_dir.x, ret.inf_dir.y) <= cir.raio)
		return 1;

	return 0;	
}

// 0

void minha_main() {

	
}



//---------------------------------------------

void zeraMatrizPedro(int M[][MAX_TAM], int n) {

	int i, j;
	for(i=0; i<n; i++)
		for(j=0; j<n; j++)
			M[i][j] = 0;
}

int insereBlocoPedro(int M[][MAX_TAM], int n, Bloco b) {

	if(b.coluna < 0 || b.coluna+b.tam > n || b.linha < 0 || b.linha+b.tam > n)
		return 0;

	int i, j;
	for(i=b.linha; i<b.linha+b.tam; i++)
		for(j=b.coluna; j<b.coluna+b.tam; j++) 
			M[i][j] = 1;

	return 1;
}

int insereBlocoSimplesPedro(int M[][MAX_TAM], int n, int i, int j, int tam) {
	Bloco b;
	b.linha = i;
	b.coluna = j;
	b.tam = tam;
	return insereBlocoPedro(M, n, b);
}

int testaBlocoTamPedro(int M[][MAX_TAM], int n, int i, int j, int tam) {
	int ii, jj;
	for(ii=i; ii<i+tam; ii++) {
		for(jj=j; jj<j+tam; jj++) {
			if(M[ii][jj] != 1)
				return 0;
		}
	}
	return 1;
}

Bloco maiorBlocoPedro(int M[][MAX_TAM], int n, int i, int j) {

	Bloco b;
	b.tam = 0;
	b.linha = i;
	b.coluna = j;

	if(i < 0 || i >= n || j < 0 || j >= n)
		return b;

	
	while(testaBlocoTam(M, n, i, j, b.tam))
		b.tam++;

	b.tam--;
	return b;
	
	
}

int verificaMaximalTotal(int M[][MAX_TAM], int n, Bloco blocos[], int numBlocos) {

	int k,i,j;
	Bloco b;
	int maximal = 0, total = 0;

	int M_aux[MAX_TAM][MAX_TAM];

	for(i=0; i<n; i++) {
		for(j=0; j<n; j++) {
			M_aux[i][j] = M[i][j]!=0;
		}
	}	

	//maximal
	for(k=0; k<numBlocos; k++) {
		b = maiorBlocoPedro(M, n, blocos[k].linha, blocos[k].coluna);
		if(b.tam > blocos[k].tam) {
			printf("\nErro: conjunto nao eh maximal!");
			printf("\nBloco encontrado: (%d %d %d)", blocos[k].linha, blocos[k].coluna, blocos[k].tam);
			printf("\nMaior bloco: (%d %d %d)", blocos[k].linha, blocos[k].coluna, b.tam);
			maximal++;
		}

		//para verificar se o conjunto eh total
		for(i=blocos[k].linha; i<blocos[k].linha+blocos[k].tam; i++) {
			for(j=blocos[k].coluna; j<blocos[k].coluna+blocos[k].tam; j++) {
				M_aux[i][j]--;
			}
		}


	}


	//total
	for(i=0; i<n; i++) {
		for(j=0; j<n; j++) {
			if(M_aux[i][j] == 1) {
				printf("\nErro: conjunto nao eh total!");
				printf("\nCelula (%d,%d) nao foi alocada a nenhum bloco.", i, j);
				total++;
			}
			if(M_aux[i][j] < 0) {
				printf("\nErro: conjunto nao eh total!");
				printf("\nCelula (%d,%d) foi alocada a mais de um bloco.", i, j);
				total++;
			}			
		}
	}

	if(total + maximal > 0) {
		printf("\n\nMatriz de entrada:");
		imprimeMatriz(M, n);
		printf("\nBlocos encontrados: ");
		for(k=0; k<numBlocos; k++) {
			printf("(%d %d %d)", blocos[k].linha, blocos[k].coluna, blocos[k].tam);
		}

		printf("\n\nErros por nao ser um conjunto maximal: %d", maximal);
		printf("\nErros por nao ser um conjunto total: %d", total);		

	}

	return total + maximal;

}



void imprimeMatrizCod(int M[MAX_TAM][MAX_TAM], int n) {
	int i, j;
	for(i=0; i<n; i++)
		for(j=0; j<n; j++)
			printf("%d;", M[i][j]);
}


int main() {


	int ex;
	scanf("%d", &ex);
	//inputs;
	int n, i, j, tam, ok, numBlocos;
	Bloco b;
	char str[MAX_TAM];

	Circulo c;
	Retangulo r;

	//matrix:
	int M[MAX_TAM][MAX_TAM];
	
	if(ex == 1) {
		scanf("%d", &n);
		zeraMatriz(M, n);
		imprimeMatrizCod(M, n);

	}
	else if(ex == 2) {
		scanf("%d %d %d %d", &n, &b.linha, &b.coluna, &b.tam);
		zeraMatrizPedro(M, n);
		ok = insereBloco(M, n, b);
		printf("retorno: %d\n", ok);
		imprimeMatrizCod(M, n);
	}
	else if(ex == 3) {
		scanf("%d %d %d %d", &n, &b.linha, &b.coluna, &b.tam);
		zeraMatrizPedro(M, n);
		insereBlocoPedro(M, n, b);
		int ii, jj;
		scanf("%d %d", &ii, &jj);

		if(DEBUG)
			imprimeMatriz(M, n);

		b = maiorBloco(M, n, ii, jj);
		printf("tam: %d", b.tam);
	}		
	else if(ex == 4) {
		scanf("%d", &n);
		zeraMatrizPedro(M, n);

		Bloco blocos[MAX_TAM];
		numBlocos = 0;
		for(i=0; i<MAX_TAM; i++) {
			scanf("%d %d %d", &blocos[numBlocos].linha, &blocos[numBlocos].coluna, &blocos[numBlocos].tam);
			if(blocos[numBlocos].tam > 0) {
				insereBlocoPedro(M, n, blocos[numBlocos]);
				//apaga o bloco
				blocos[numBlocos].linha = rand();
				blocos[numBlocos].coluna = rand();
				blocos[numBlocos].tam = rand();				
				numBlocos++;
			}
			else
				break;
		}

		if(DEBUG)
			imprimeMatriz(M, n);

		numBlocos = 0;
		encontraBlocos(M, n, blocos, &numBlocos);
		if(!verificaMaximalTotal(M, n, blocos, numBlocos))
			printf("\nSucesso!");



		/*for(i=0; i<numBlocos; i++) {
			printf("(%d %d %d)\n", blocos[i].linha, blocos[i].coluna, blocos[i].tam);
		}*/		
	}	
	else if(ex == 5) {
	    scanf(" ");
		fgets(str, MAX_TAM, stdin);
		n = strlen(str);
		str[n-1] = '\0';
		printf("%d", numCharsDiferentes(str));
	}
	else if(ex == 6) {

		scanf("%f %f %f", &c.centro.x, &c.centro.y, &c.raio);
		scanf("%f %f %f %f", &r.sup_esq.x, &r.sup_esq.y, &r.inf_dir.x, &r.inf_dir.y);

		printf("\n%d", colisaoCirculoRetangulo(c, r));

	}
	else {
	    printf("\nChamando a sua funcao minha_main():");
	    printf("\n-> Use esta funcao para testar qualquer coisa!");
	    minha_main();
	}

	return 0;
}

/*

	int M[MAX_TAM][MAX_TAM];
	int n = 6, numBlocos = 0;
	int i=0;
	zeraMatriz(M, n);
	imprimeMatriz(M, n);
	insereBlocoSimples(M, n, 0, 0, 2);
	insereBlocoSimples(M, n, 0, 4, 2);
	insereBlocoSimples(M, n, 2, 0, 1);
	insereBlocoSimples(M, n, 2, 1, 2);
	insereBlocoSimples(M, n, 3, 3, 3);
	insereBlocoSimples(M, n, 4, 0, 2);
	imprimeMatriz(M, n);

	Bloco blocos[MAX_TAM];
	encontraBlocos(M, n, blocos, &numBlocos);

	for(i=0; i<numBlocos; i++) {
		printf("\n (%d %d %d)", blocos[i].linha, blocos[i].coluna, blocos[i].tam);
	}

	char texto[] = "Ola, tudo bem? Tudo joia?";
	printf("\n\n%d", numCharsDiferentes(texto));

	Circulo c;
	Retangulo r;

	c.centro.x = 0;
	c.centro.y = 0;
	c.raio = 10;

	r.sup_esq.x = -5;
	r.sup_esq.y = 10.1;
	r.inf_dir.x = 5;
	r.inf_dir.y = 20;

	printf("\n%d", colisaoCirculoRetangulo(c, r));

	r.sup_esq.x = -5;
	r.sup_esq.y = 20;
	r.inf_dir.x = 5;
	r.inf_dir.y = 9.9;

	printf("\n%d", colisaoCirculoRetangulo(c, r));	




	return 0;
}
*/