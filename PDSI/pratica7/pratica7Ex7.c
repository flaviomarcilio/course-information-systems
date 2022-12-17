/*======================== Exercício 7: Teste da Função ​rand() =================================
Uma boa função para geração de números aleatórios deve gerar valores com igual
probabilidade, i.e., se eu quero gerar 100 valores entre 1 e 10, o número de vezes que cada
número é gerado deve ser próximo de 10. Assim, nesta prática você deve criar um programa
para testar a qualidade da função ​rand()​ da linguagem C. Para isso, gere 5.000.000 números
aleatórios entre 0 (inclusive) e 999 (inclusive) e conte quantas vezes cada número foi gerado.
Imprima a diferença entre a maior e a menor contagem. 

Exemplo: se o número 83 foi aquele que mais vezes foi gerado, com 5315 gerações, e o 
número 762 foi aquele que menos vezes foi gerado, com 4802 gerações, então seu programa deve
imprimir 5315 - 4802 = 513.

Dica:​ crie um vetor de inteiros de 1000 posições para armazenar quantas vezes cada número
(entre 0 e 999) é gerado. Assim, cada vez que você gerar aleatoriamente o número k, faça
vet_cont[k]++​.
Exemplo: se você gerar o número 888, faça vet_cont[888]++​. 
No final, ​vetor_contagem[k]​ conterá o número de vezes que o número k foi gerado.
==============================================================================================*/
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define NUMEROS 5000000
#define TAM_VETOR 1000

void zeraVetor(int v[], int n) {
	int i = 0;
	for (i = 0; i < n; i++) {
		v[i] = 0;
	}
}

int random() {
    return rand() % TAM_VETOR;
}

double mediaVetor(int vet[], int n) {
    double media = 0;
    int i = 0;
    
    for (i = 0; i < n; i++) {
        media += vet[i];
    }

    return media / n;
}

double desvioPadrao(int vet[], int n) {
    double media = 0, soma = 0;
    int i = 0;

    media = mediaVetor(vet, n);

    for (i = 0; i < n; i++) {
        soma += (vet[i] - media) * (vet[i] - media);
    }

    return sqrt(soma / n);
}

int main() {

    int num = 0, i = 0, maior = 0, menor = 0;
    int vet_cont[TAM_VETOR];
    double media = 0, desvio = 0;

    zeraVetor(vet_cont, TAM_VETOR);

    for (i = 0; i < NUMEROS; i++) {
		num = random();
		vet_cont[num]++;
	}

    for (i = 0; i < TAM_VETOR; i++) {
        if (vet_cont[i] > vet_cont[maior]) {
            maior = i;
        }
        if (vet_cont[i] < vet_cont[menor]) {
            menor = i;
        }
    }

    printf("\n%d - %d = %d", vet_cont[maior], vet_cont[menor], vet_cont[maior] - vet_cont[menor]);

    media = mediaVetor(vet_cont, TAM_VETOR);
    printf("\nMedia: %.2lf", media);
    
    desvio = desvioPadrao(vet_cont, TAM_VETOR);
    printf("\nDesvio padrao: %.8lf", desvio);
    printf("\n");

    return 0;
}