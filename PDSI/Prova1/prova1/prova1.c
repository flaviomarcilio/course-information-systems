#include <stdio.h>
#include <math.h>

void imprimePilha(int pilha) {
	int i=1;
	while(i<=pilha) {
		printf("|");
		i++;
	}
	printf("\n");
}

void imprimePilhas(int pilha1, int pilha2, int pilha3) {
	printf("\n%d ", pilha1);
	imprimePilha(pilha1);
	printf("%d ", pilha2);
	imprimePilha(pilha2);
	printf("%d ", pilha3);
	imprimePilha(pilha3);
}

int maior(int x, int y, int z) {
	if(x >= y && x >= z) return x;
	if(y >= x && y >= z) return y;
	return z;
}

void imprimePilhas2(int pilha1, int pilha2, int pilha3) {
	int n = maior(pilha1, pilha2, pilha3);
	int k=n;
	printf("\n");
	while(k >= 1) {
		if(pilha1 >= k) printf("_ "); else printf("  ");
		if(pilha2 >= k) printf("_ "); else printf("  ");
		if(pilha3 >= k) printf("_\n"); else printf(" \n");
		k--;
	}
	printf("%d %d %d\n", pilha1, pilha2, pilha3);
}

void leJogada(int *pilha, int *qtde) {
	printf("Escolha uma pilha (1, 2 ou 3):\n");
	scanf("%d", pilha);
	printf("Quantos palitos gostaria de remover?\n");
	scanf("%d", qtde);
}


int diminuiPilha(int *pilha, int x) {
	
	if(x <=0 || *pilha < x)
		return 0;
	
	*pilha = *pilha - x;
	return 1;
}

int confereJogo(int pilha1, int pilha2, int pilha3) {
	if(pilha1 + pilha2 + pilha3 > 0)
		return 1;
	return 0;
}

int jogo(int pilha1, int pilha2, int pilha3) {
	
	int p, q, jogadas=0, jogador=1, ok=1;
	
	while(confereJogo(pilha1, pilha2, pilha3)) {
		
		imprimePilhas2(pilha1, pilha2, pilha3);
		
		printf("\nJogador %d:\n", jogador);
		leJogada(&p, &q);
		if(p == 1) {
			ok = diminuiPilha(&pilha1, q);
		}
		else if(p == 2) {
			ok = diminuiPilha(&pilha2, q);
		}
		else if(p == 3) {
			ok = diminuiPilha(&pilha3, q);
		}
		else
			ok = 0;
		
		if(ok) jogador += pow(-1, jogador+1);	
		else printf("\nErro! Jogue novamente!\n");
	}		
	return jogador;
}


int principal() {
	
	int p1, p2, p3, vencedor;
	do {
		scanf("%d %d %d", &p1, &p2, &p3);
	} while(p1 <= 0 || p2 <= 0 || p3 <= 0);
	vencedor = jogo(p1, p2, p3);
	return vencedor;
}



int main() {
	
	int ex;
	scanf("%d", &ex);
	
	//inputs;
	int p1, p2, p3, q, ok;
	
	if(ex == 1) {
		scanf("%d %d %d", &p1, &p2, &p3);
		imprimePilhas(p1, p2, p3);
	}
	else if(ex == 2) {
		scanf("%d %d %d", &p1, &p2, &p3);
		imprimePilhas2(p1, p2, p3);
	}	
	else if(ex == 3) {
		leJogada(&p1, &q);
		printf("\n%d %d", p1, q);
	}	
	else if(ex == 4) {
		scanf("%d %d", &p1, &q);
		ok = diminuiPilha(&p1, q);
		printf("\n%d %d", ok, p1);
	}
	else if(ex == 5) {
		scanf("%d %d %d", &p1, &p2, &p3);
		printf("\n%d", confereJogo(p1, p2, p3));
	}	
	else if(ex == 6) {
		scanf("%d %d %d", &p1, &p2, &p3);
		printf("\n%d", jogo(p1, p2, p3));
	}
	else if(ex == 7) {
		printf("\nVencedor: %d", principal(p1, p2, p3));
	}	
	
	
	return 0;
}



/*
double propAurea(int n) {
	
	//long long int x1=1, x2=1, k=2;
	double x1=0.1, x2=0.1; int k=2;
	while(k < n) {
		x2 = x2 + x1;
		x1 = x2 - x1;
		printf("%lf ", x2);
		k++;
	}
	return (double)x2/x1;

}

void main() {
	
	int i, j;
	float x, y;
	
	scanf("%d", &i);
	printf("\n%lf", propAurea(i));
	
}
*/