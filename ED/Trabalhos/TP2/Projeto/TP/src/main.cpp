#include <iostream>
#include <string>
#include <sstream>

#include "../include/ordenacao_externa.h"
#include "../include/memlog.h"

using namespace std;

memlog_tipo ml;

int main(int argc, char const *argv[])
{
    string entrada, saida;
    int NUM_ENTIDADES;

    char* desempenho = "desempenho.out";
    char* localidade_referencia = "localidade.out";
    string FlagRef = "-l";

    entrada = argv[1];
    saida = argv[2];
    stringstream s(argv[3]);
    s >> NUM_ENTIDADES;

    if (argc == 5 && (FlagRef.compare(argv[4]) == 0))
    {
        iniciaMemLog(localidade_referencia);
        ativaMemLog();
    }
    else
    {
        iniciaMemLog(desempenho);
        desativaMemLog();
    }

    OrdenacaoExterna(entrada, saida, NUM_ENTIDADES);
    
    return finalizaMemLog();
}