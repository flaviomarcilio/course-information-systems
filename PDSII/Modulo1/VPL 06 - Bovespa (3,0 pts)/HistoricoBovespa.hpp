#pragma once
#include <map>
#include <vector>
#include <algorithm>
#include <iostream>

#include "Cotacao.hpp"

using std::map;
using std::vector;
using std::cout;
using std::endl;


struct HistoricoBovespa {
    map<string, vector<Cotacao>> mapa;
    map<string, vector<Cotacao>>::iterator it;

    HistoricoBovespa();
    void inserir_cotacao(string sigla, string data, double valor);
    double calcular_valor_medio_acao(string sigla);
    Cotacao* recuperar_cotacao_maxima_acao(string sigla);
    Cotacao* recuperar_cotacao_minima_acao(string sigla);
    void imprimir_estatisticas_completas();
};