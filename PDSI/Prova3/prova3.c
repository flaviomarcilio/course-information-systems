#include <stdio.h>
#include <stdlib.h>

// Ex.1
int contaLinhasArquivo(char nome_arquivo[]) {
    int linhas = 0;
    int c;

    FILE *arq;
    arq = fopen(nome_arquivo, "r");

    do {
        
        c = fgetc(arq);
        // if (feof(arq)) {
        //     break;
        // }
        if (c == '\n') {
            linhas++;
            // printf(" Linha: %d ", linhas);
        }
        // printf("%c", c);
        
    } while (!feof(arq));

    fclose(arq);
    linhas++;

    return linhas;
}

// Ex.2
void imprimeVetor(char vetor[], int dimensao) {
    int i = 0;
    if (dimensao == 1) {
        // printf("%c", vetor[0]);
        printf("\n");
        return;
    }

    for (i = 0; i < dimensao; i++) {
        printf("%c", vetor[i]);
    }
    return;
}

char** carregaPoema(char nome_arquivo[]) {
    char **poema;
    char c;
    int linhas, *colunas;
    int i = 0, j = 0;

    FILE *arq;

    arq = fopen(nome_arquivo, "r");

    linhas = contaLinhasArquivo(nome_arquivo);
    printf("\nContando a quantidade de caracteres por linha...\n");

    colunas = (int *)malloc(linhas * sizeof(int));
    for (i = 0; i < linhas; i++) {
        colunas[i] = 0;
        // printf("\n%d", colunas[i]);
    }
    i = 0;
    do {
        
        c = fgetc(arq);
        // if (feof(arq)) {
        //     break;
        // }
        colunas[i]++;

        if (c == '\n') {
            printf("\nColunas: %d ", colunas[i]);
            i++;
        }        
    } while (!feof(arq));

    colunas[i] = 1;
    printf("\nColunas: %d ", colunas[i]);

    fclose(arq);

    printf("\n\nAlocando memoria para o poema...\n");
    poema = (char **)malloc(linhas * sizeof(char *));

    for (i = 0; i < linhas; i++) {
        poema[i] = (char *)malloc(colunas[i] * sizeof(char));
        printf("\nLinha: %d Colunas: %d", i, colunas[i]);
    }

    printf("\n\nColocando o poema na memoria...\n\n");
    i = 0;
    j = 0;
    arq = fopen(nome_arquivo, "r");
    do {
        
        c = fgetc(arq);
        poema[i][j] = c;
        printf("[%d][%d] %c\n", i, j, c);

        // if (feof(arq)) {
        //     break;
        // }
        if (c == '\n') {
            i++;
            j = -1;
        }
        
        j++;
        
    } while (!feof(arq));

    printf("\nLinhas: %d\n", linhas);

    poema[linhas - 1] = NULL;
    fclose(arq);

    printf("\nImprimindo poema...\n");

    for (i = 0; i < linhas; i++) {
        // printf("\nVerso: %d Caracteres %d - ", i, colunas[i]);
        imprimeVetor(poema[i], colunas[i]);
    }

    return poema;
}

// Ex.3
void imprimeVersoInvertido(char *verso) {
    if (*verso == '\n') {
        printf("\n");
        return;
    }
    imprimeVersoInvertido(verso + 1);
    printf("%c", *verso);
    return;
}

void imprimePoemaInvertido(char **poema) {
    if (*poema == NULL) {
        return;
    }
    imprimePoemaInvertido(poema+1);
    imprimeVersoInvertido(*poema);
    return;
}

// Ex.4
int numeroTriangular(int n) {
    if (n == 1) {
        return n;
    }
    return n + numeroTriangular(n - 1);
}

// Ex.5
float serieDois(int n) {
    if (n == 1) {
        return n;
    }
    return 1.0/numeroTriangular(n) + serieDois(n - 1);
}

// Main
int main(int argc, char const *argv[])
{
    char nomeArquivo[] = "poema.txt";
    char **meupoema;
    int ex = 0, numTri;
    scanf("%d", &ex);

    switch (ex) {
        case 1:
            printf("\nNumero de linhas: %d\n", contaLinhasArquivo(nomeArquivo));
            break;
        case 2:
            meupoema = carregaPoema(nomeArquivo);
            printf("\nPoema carregado\n");
            break;
        case 3:
            meupoema = carregaPoema(nomeArquivo);
            printf("\nPoema Invertido\n");
            imprimePoemaInvertido(meupoema);
            break;
        case 4:
            scanf("%d", &numTri);
            printf("\n%d-esimo numero triangular: %d", numTri, numeroTriangular(numTri));
            break;
        case 5:
            scanf("%d", &numTri);
            printf("\nSoma dos reciprocos com %d termos: %f", numTri, serieDois(numTri));
            break;
        default:
            break;
    }
    

    return 0;
}
