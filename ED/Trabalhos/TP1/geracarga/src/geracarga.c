//---------------------------------------------------------------------
// Arquivo      : geracarga.c
// Conteudo     : gerador de carga para o escalonador de URLs 
// Autor        : Wagner Meira Jr. (meira@dcc.ufmg.br)
// Historico    : 2021-12-13 - arquivo criado
//---------------------------------------------------------------------

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <limits.h>
#include <float.h>
#include <unistd.h>
#include <getopt.h>
#include "msgassert.h"

const double DBL_EPS_COMP = 1 - DBL_EPSILON; 

double RandU() 
// Descricao: gera um numero aleatorio (distribuicao uniforme) entre 0 e 1
// Entrada: nenhuma
// Saida: numero aleatorio
{
    return DBL_EPSILON + ((double) rand()/RAND_MAX);
}

double RandN2(double mu, double sigma) 
// Descricao: gera um numero aleatorio 
//            (distribuicao normal, media mu e variancia sigma)
// Entrada: mu e sigma
// Saida: numero aleatorio
{
  return mu+(rand()%2?-1.0:1.0)*sigma*pow(-log(DBL_EPS_COMP*RandU()),0.5);
}

double RandN() 
// Descricao: gera um numero aleatorio 
//            (distribuicao normal, media 0 e variancia 1)
// Entrada: nenhuma
// Saida: numero aleatorio
{
    return RandN2(0, 1.0);
}

// estrutura de dados que contem os parametros
typedef struct prm{
  char nomesaida[1000];
  double servidores, urls, varurls, prof, varprof;
} prmGeracao;

// estrutura de dados que contem os parametros do servidor
typedef struct serv{
  int nurl;
  double purl;
  char nome[1000];
} Servidor;

void uso()
// Descricao: imprime as instrucoes de uso do programa
// Entrada:  N/A
// Saida: instrucoes
{
  fprintf(stderr,"geracarga\n");
  fprintf(stderr,"\t-o <arq>\t(arquivo de saida) \n");
  fprintf(stderr,"\t-s <num>\t(numero de servidores)\n");
  fprintf(stderr,"\t-u <num>\t(URLs por host)\n");
  fprintf(stderr,"\t-v <num>\t(variancia URLs por host)\n");
  fprintf(stderr,"\t-p <num>\t(profundidade URL)\n");
  fprintf(stderr,"\t-q <num>\t(variancia profundidade URL)\n");
  fprintf(stderr,"\t-h\t(opcoes de uso)\n");
}

void parse_args(int argc,char ** argv, prmGeracao * prm)
// Descricao: analisa a linha de comando a inicializa variaveis
// Entrada: argc e argv
// Saida: prm
{
     extern char * optarg;
     extern int optind;
     int c ;
     // valores padrao
     prm->nomesaida[0] = 0;
     prm->servidores = 10;
     prm->urls = 3;
     prm->varurls = 1;
     prm->prof = 3;
     prm->varprof = 1;
     // percorre a linha de comando buscando identificadores
     while ((c = getopt(argc, argv, "o:s:u:v:p:q:h")) != EOF)
       switch(c) {
         case 'o':
	          // arquivo de saida
	          strcpy(prm->nomesaida,optarg);
                  break;
         case 's':
	          // numero de servidores
	          prm->servidores = atof(optarg);
		  break;
         case 'u':
	          // numero medio de urls
	          prm->urls = atof(optarg);
		  break;
         case 'v':
	          // variancia de urls por servidor
	          prm->varurls = atof(optarg);
		  break;
         case 'p':
	          // profundidade media 
	          prm->prof = atof(optarg);
		  break;
         case 'q':
	          // variancia da profundidade media
	          prm->varprof = atof(optarg);
		  break;
         case 'h':
         default:
                  uso();
                  exit(1);

       }
       // verifica apenas o nome do arquivo de saida
       erroAssert(prm->nomesaida[0],"Arquivo de saida nao definido.");
}

void gerapalavra(int tam, char * ret)
// Descricao: gera uma palavra aleatoria 
// Entrada: tam
// Saida: ret
{
  int i;
  for (i=0; i<tam; i++){
    ret[i] = (char)(rand()%26)+'a';
  }
  ret[tam] =0;
}


int main(int argc, char ** argv){
  int i,j,k,nurls,szserv,tampal,auxprof,retclose;
  prmGeracao prm;
  double auxsum,pserv;
  char auxstr[1000],auxurl[1000];
  FILE * out;
  Servidor * servvet;

  parse_args(argc,argv,&prm);

  out = fopen(prm.nomesaida,"wt");
  erroAssert(out!=NULL,"Erro no fopen");

  servvet = (Servidor *) malloc (prm.servidores*sizeof(Servidor));
  erroAssert(servvet!=NULL,"Malloc falhou");

  nurls = 0;
  // inicializa o vetor de servidores
  for (i=0; i<prm.servidores; i++){
    // numero de arquivos estimado por servidor
    servvet[i].nurl = (int) RandN2(prm.urls,prm.varurls);
    nurls+= servvet[i].nurl;
    // nome do servidor
    strcpy(servvet[i].nome,"http://");
    szserv = (int) RandN2(3.0,1.0);
    szserv=(szserv==0?1:szserv);
    for (j=0; j<szserv; j++){
      tampal = (int) RandN2(6.0,2.0);
      tampal=(tampal<3?3:tampal);
      gerapalavra(tampal,auxstr); 
      strcat(servvet[i].nome,auxstr);
      strcat(servvet[i].nome,".");
    }
    strcat(servvet[i].nome,"com/");
  }
  // inicializa probabilidade cumulativa para roleta
  auxsum = 0.0;
  for (i=0; i<prm.servidores; i++){
    auxsum += (servvet[i].nurl*1.0)/nurls; 
    servvet[i].purl = auxsum; 
  }

  // gera carga de trabalho
  fprintf(out,"ADD_URLS %d\n",nurls);
  for (i=0; i<nurls; i++){
    // sorteia o servidor de acordo com a sua probabilidade de ocorrência
    pserv = RandU();
    j=0;
    while ((j<prm.servidores)&&(pserv>servvet[j].purl)) j++;
    j = (j>=prm.servidores?prm.servidores-1:j);
    // sorteia a profundidade
    auxprof = (int) RandN2(prm.prof,prm.varprof);
    // gera a URL
    strcpy(auxurl,servvet[j].nome);
    for (k=0;k<auxprof;k++){
      tampal = (int) RandN2(6.0,2.0);
      gerapalavra(tampal,auxstr); 
      strcat(auxurl,auxstr);
      strcat(auxurl,"/");
    }
    // sempre termina com um arquivo html
    tampal = (int) RandN2(6.0,2.0);
    gerapalavra(tampal,auxstr); 
    strcat(auxurl,auxstr);
    strcat(auxurl,".html");
    fprintf(out,"%s\n",auxurl);
  }
  // gera as demais tarefas
  fprintf(out,"LISTA_HOSTS\n");
  fprintf(out,"ESCALONA_TUDO\n");
  fprintf(out,"LIMPA_TUDO\n");
  retclose = fclose(out);
  erroAssert(retclose==0,"Erro no fclose");
  free(servvet);
  return 0;
}
