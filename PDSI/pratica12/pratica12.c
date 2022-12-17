/*========================================= Exercícios ==============================================
O professor armazena as notas de cada disciplina que leciona em um arquivo diferente 
(GAAL.txt, AEDS1.txt etc). Formato dos arquivos: matrícula, nome, nota1, nota2
O programa pratica12.c está incompleto, então você deve modificá-lo para implementar as seguintes 
funcionalidades:

Exercício 1: permitir que o professor possa escolher se deseja ou não que a média das notas seja 
exibida junto com a listagem do conteúdo do arquivo.

Exercício 2: permitir que o nome do arquivo e seu modo de exibição sejam opções definidas como 
parâmetros de execução do programa.

Exercício 3: permitir que as notas dos alunos possam ser modificadas.

- Parâmetros do Programa

	● O programa pode ser chamado com as opções –d, –m,
	-l e -e.
	● -d para indicar a disciplina
	● -m para mostrar ou não a média das notas
	● -l para ler a informação de n alunos
	● -e para editar a nota de um aluno

O programa pode ser chamado com as opções –d, –m,
-l e -e. Estas opções podem ser seguidas por parâmetros
	● -d SIGLA_DA_DISCIPLINA (ex: -d AEDS1)
	● -m [S ou N] (ex: -m S)
	● -l NUM_ALUNOS (ex: -l 5)
	● -e (sem parâmetro)
	● Assim, uma chamada possível ao programa seria: a.exe –d GAAL –m N -e
	● Neste caso, argc = 6.

Desafio para os (muito) fortes!
	● Implementar um procedimento que ordena um arquivo pelo número de matrícula.
	● O arquivo CALC.txt deve, por exemplo, ficar assim:
	4,Stannis Baratheon, 8.5, 4.8
	17,Maria Capitolina, 5.0, 4.4
	23,Michael Jordan, 9.0, 9.0
	55,Luke Skywalker, 7.5, 6.1
=====================================================================================================*/

#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TAM 100

/*
Linhas com a expressao [CODIGO_AQUI] indicam que voce 
precisa implementar algo na linha.
*/
typedef struct Aluno {
	int mat;
	char nome[MAX_TAM];
	float nota1, nota2;
} Aluno;

void copiaNome(char nomeAluno[], char *nomeLido) {
	int i = 0;
	char c;

	do {
		c = nomeLido[i];
        nomeAluno[i] = c;
        i++;
    } while (c != '\0');
}

void ordenaVetor(Aluno vet[], Aluno vet_ord[], int n) {
	// Ordenação por Contagem
	int i = 0, j = 0;
	int cont[100];

	for (j = 0; j < n; j++) {
		cont[j] = 0;
		for (i = 0; i < n; ++i) {
			if (vet[i].mat < vet[j].mat) {
				cont[j]++;
			}
		}
		vet_ord[cont[j]] = vet[j];
	}
}

void ordenaMatricula(char nome_arquivo[]) {
	int registros = 0, i = 0;
	char buf[MAX_TAM];
	FILE *arq, *temp;
	Aluno alunos[MAX_TAM], alunosOrd[MAX_TAM];

	arq = fopen(nome_arquivo,"r");
	if(arq == NULL) {
		printf("\nErro ao abrir o arquivo!");
		return;
	}

	printf("\nOrdenando...");

	fgets(buf, MAX_TAM, arq);
	while(!feof(arq)) {
		alunos[i].mat = atoi(strtok(buf, ","));
		copiaNome(alunos[i].nome, strtok(NULL, ","));
		alunos[i].nota1 = atof(strtok(NULL, ","));
		alunos[i].nota2 = atof(strtok(NULL, ","));

		printf("\n%d \t %20s \t %4.1f \t %4.1f", alunos[i].mat, alunos[i].nome, alunos[i].nota1, alunos[i].nota2);
		
		fgets(buf, MAX_TAM, arq);
		i++;
	}
	registros = i;
	ordenaVetor(alunos, alunosOrd, registros);

	temp = fopen("temp.txt", "w");
	for (i = 0; i < registros; i++) {
		fprintf(temp, "%d,%s,%4.1f,%4.1f\n", alunosOrd[i].mat, alunosOrd[i].nome, alunosOrd[i].nota1, alunosOrd[i].nota2);
	}

	fclose(arq);
	fclose(temp);
	printf("\nArquivo ordenado.\n");
	//remove o arquivo antigo
	remove(nome_arquivo);
	//renomeia o arquivo temporario
	rename("temp.txt", nome_arquivo);

}

void modificarNotas(char nome_arquivo[]) {
	int num = -1, num_edit, achei = 0;
	char *nome;
	char buf[MAX_TAM];	
	float nota1, nota2;
	FILE *arq, *temp;

	//abrir arquivo nome_arquivo para leitura o colocando na variavel arq:
	arq = fopen(nome_arquivo, "r");

	//verificar se arquivo foi aberto corretamente e retornar (return) caso negativo:
	if (arq == NULL) {
		printf("\nErro ao abrir o arquivo!");
		return;
	}

	printf("\nDigite o numero do aluno a modificar: ");
	scanf("%d", &num_edit);
	
	printf("\nProcurando...");
	
	//abrir um arquivo temporario "temp" (ex: temp.txt) para escrita o colocando na variavel temp:
	temp = fopen("temp.txt", "w");
	
	fgets(buf, MAX_TAM, arq);
	while(!feof(arq)) {
		//ler os quatro campos do arquivo: "num", "nome", "nota1", "nota2":
		num = atoi(strtok(buf, ","));
		nome = strtok(NULL, ",");
		nota1 = atof(strtok(NULL, ","));
		nota2 = atof(strtok(NULL, ","));
		printf("\n%d \t %s \t %4.1f \t %4.1f", num, nome, nota1, nota2);
		
		//verificar se "num" eh igual a "num_edit":
		if (num == num_edit) {
			//se for igual, ler as novas notas (nota1 e nota2) do aluno e marcar que achou o aluno ("achei = 1"):
			printf("\nNota 1: ");
			scanf("%f", &nota1);
			printf("Nota 2: ");
			scanf("%f", &nota2);
			achei = 1;
		}
			
		//escrever os dados lidos do arquivo "nome_arquivo" no arquivo temporario
		fprintf(temp, "%d,%s,%4.1f,%4.1f\n", num, nome, nota1, nota2);
		
		//ler uma nova linha do arquivo nome_arquivo:
		fgets(buf, MAX_TAM, arq);
	}
	
	fclose(arq);
	fclose(temp);
	
	if(achei == 0) 
		printf("\nAluno nao encontrado!");
	
	//remove o arquivo antigo
	remove(nome_arquivo);
	//renomeia o arquivo temporario
	rename("temp.txt", nome_arquivo);
}

void leAluno(char nome_arquivo[], int num_alunos) {
	int num, i = 0;
	char nome[MAX_TAM];
	float nota1, nota2;
	FILE *arq;

	arq = fopen(nome_arquivo, "a");
	if(arq == NULL) {
		printf("\nErro ao abrir o arquivo!");
		return;
	}

	/*
	modificar o codigo abaixo para ler os dados de "num_alunos" 
	alunos ao inves de apenas 1: 
	*/

	for (i = 0; i < num_alunos; i++) {

		printf("\nDigite os dados do novo aluno");
		printf("\nNum: ");
		scanf("%d", &num);
		printf("Nome: ");
		fflush(stdin); // Limpa o buffer
		fgets(nome, MAX_TAM, stdin);
		nome[strlen(nome)-1] = '\0';
		printf("Nota1: ");
		scanf("%f", &nota1);
		printf("Nota2: ");
		scanf("%f", &nota2);	
		
		fprintf(arq, "%d,%s,%4.1f,%4.1f\n", num, nome, nota1, nota2);
	}
	fclose(arq);
}

/*
imprime as notas dos alunos que estao gravados no arquivo
"nome_arquivo" (ex: GAAL.txt):
*/

void imprimeNotas(char nome_arquivo[]) {
	float notas = 0, media = 0, nota1, nota2;
	char buf[MAX_TAM];
	char *nome;
	int num;
	FILE *arq;

	arq = fopen(nome_arquivo,"r");
	if(arq == NULL) {
		printf("\nErro ao abrir o arquivo!");
		return;
	}

	printf("\nmatricula\t nome\t\t nota1\t nota2\t");

	fgets(buf, MAX_TAM, arq);
	while(!feof(arq)) {
		num = atoi(strtok(buf, ","));
		nome = strtok(NULL, ",");
		nota1 = atof(strtok(NULL, ","));
		nota2 = atof(strtok(NULL, ","));
		printf("\n%d \t %20s \t %4.1f \t %4.1f", num, nome, nota1, nota2);
		notas = notas + 2;
		media = media + nota1 + nota2;
		fgets(buf, MAX_TAM, arq);
	}
	printf("\nmedia = %f",media/notas);
	fclose(arq);
}

int main(int argc, char *argv[]) {

	int i = 0, le_alunos = 0;
	char nome_arquivo[10] = "GAAL.txt";
	char exibe_media='N';
	char edita_aluno = 'N';
	char ordena_arquivo = 'N';
	
	for(i = 0; i < argc; i++) {
		//verifica se ha o parametro -d na lista de parametros:
		if(strcmp(argv[i], "-d") == 0) {
			//caso positivo, coloca o parametro seguinte na variavel nome_arquivo e acrescenta a extensao .txt:
			strcpy(nome_arquivo, argv[i+1]);
			strcat(nome_arquivo, ".txt");
		}
		//verificar se tem o parametro -m na lista:
		else if(strcmp(argv[i], "-m") == 0) {
			//caso positivo, coloca o primeiro caractere (o segundo eh o \0) do parametro seguinte na variavel exibe_media:
			exibe_media = argv[i+1][0];
		}
		//verifica se tem o parametro -e na lista:
		else if(strcmp(argv[i], "-e") == 0) {
			//caso positivo, marcar a variavel edita_aluno com 'S':
			edita_aluno = 'S';
		}
		//verifica se tem o parametro -l na lista:
		else if(strcmp(argv[i], "-l") == 0) {
			//caso positivo, transformar o parametro seguinte em inteiro a partir da funcao atoi, atribuindo ele a variavel le_alunos:
			le_alunos = atoi(argv[i+1]);
		}
		else if(strcmp(argv[i], "-o") == 0) {
			ordena_arquivo = 'S';
		}
		//para exibir a ajuda
		else if(argc == 1 || strcmp(argv[i], "-help") == 0 || argv[i][0] == '?') {
			printf("\n------------------- Parametros do programa -----------------");
			printf("\n-d [XXX] ........ Sigla da disciplina. Ex: -d AEDS1");
			printf("\n-m [S ou N] ..... Exibir media. Ex: -m S");
			printf("\n-l [#] .......... Le informacao sobre # alunos. Ex: -l 4");				
			printf("\n-e .............. Modifica nota de aluno.");
			printf("\n-o .............. Ordena o arquivo pelo numero de matricula.");
			printf("\n------------------------------------------------------------");
			printf("\n");		
			return 1;		
		}
	}
	
	//Chamar os metodos dependendo dos parametros
	if(le_alunos > 0)
		leAluno(nome_arquivo, le_alunos);

	//se "edita_aluno" for 'S', chama o metodo para modificar notas:
	if (edita_aluno == 'S')
		modificarNotas(nome_arquivo);

	// se "ordena_arquivo" for 'S', chama o metodo para ordenar o arquivo pelas matriculas
	if (ordena_arquivo == 'S')
		ordenaMatricula(nome_arquivo);

	//se "exibe_media" for 'S', chama o metodo para imprimir notas:
	if (exibe_media == 'S')
		imprimeNotas(nome_arquivo);
	return 0;
}