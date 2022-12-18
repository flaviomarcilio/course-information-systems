
// NÃO ALTERE ESSA LINHA
#include "avaliacao_basica_bovespa.hpp"

int main() {
  
    // NÃO ALTERE ESSA LINHA
    avaliacao_basica();


    string sigla, data;
    double valor;
    HistoricoBovespa *historico = new HistoricoBovespa();

    while (cin >> sigla >> data >> valor) {
        historico->inserir_cotacao(sigla, data, valor);
    }

    historico->imprimir_estatisticas_completas();

    delete historico;

    return 0;
}