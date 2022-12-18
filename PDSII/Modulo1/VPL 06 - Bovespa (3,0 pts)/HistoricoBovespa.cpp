#include "HistoricoBovespa.hpp"

// Construtor padrão sem parâmetros
HistoricoBovespa::HistoricoBovespa() {
    
}
// Insere um novo histórico de cotação para uma determinada ação.
void HistoricoBovespa::inserir_cotacao(string sigla, string data, double valor) {
    // Cotacao cotacao = Cotacao(data, valor);

    // it = mapa.find(sigla);
    // if (it != mapa.end()) {
    //     it->second.push_back(cotacao);
    // } else {
    //     vector<Cotacao> *cotacoes = new vector<Cotacao>;
    //     cotacoes->push_back(cotacao);
    //     mapa.insert(std::pair<string, vector<Cotacao>>(sigla, *cotacoes));
    // }

    // Solução do Professor
    this->mapa[sigla].push_back(Cotacao(data, valor));
        
}

// Calcula o valor médio das cotações para uma determinada ação. 
double HistoricoBovespa::calcular_valor_medio_acao(string sigla) {
    // double media = 0;
    // it = mapa.find(sigla);
    // for (Cotacao &cotacao: it->second) {
    //     media = media + cotacao.valor;
    // }
    
    // return media / it->second.size();

    // Solução do Professor
    double total = 0;
    std::vector<Cotacao> aux = this->mapa[sigla];
    for (unsigned int i = 0; i < aux.size(); ++i) {
        total += aux[i].get_valor();
    }

    return total/aux.size();
}

bool criterio_comparacao(const Cotacao& i, const Cotacao& j) {
    return i.valor < j.valor; 
}
// Encontra e retorna um ponteiro para a cotação de MAIOR valor 
// associada a ação informada. Se a ação (sigla) não possuir 
// histórico retorna 'nullptr'.
Cotacao* HistoricoBovespa::recuperar_cotacao_maxima_acao(string sigla) {
    // Cotacao *cotacao = nullptr;

    // it = mapa.find(sigla);
    // if (it == mapa.end()) {
    //     return cotacao;
    // } 

    // cotacao = &(*std::max_element(it->second.begin(), it->second.end(), criterio_comparacao));
    // return cotacao;

    // Solução do Professor
    std::vector<Cotacao> aux = this->mapa[sigla];
    int idx_max = 0;
    for (unsigned int i = 0; i < aux.size(); ++i) {
        if (aux[i].get_valor() > aux[idx_max].get_valor()) {
            idx_max = i;
        }
    }

    return &this->mapa[sigla][idx_max];

}

// Encontra e retorna um ponteiro para a cotação de MENOR valor 
// associada a ação informada. Se a ação (sigla) não possuir 
// histórico retorna 'nullptr'.
Cotacao* HistoricoBovespa::recuperar_cotacao_minima_acao(string sigla) {
    // Cotacao *cotacao = nullptr;

    // it = mapa.find(sigla);
    // if (it == mapa.end()) {
    //     return cotacao;
    // } 

    // cotacao = &(*std::min_element(it->second.begin(), it->second.end(), criterio_comparacao));
    // return cotacao;

    // Solução do Professor
    if (this->mapa.count(sigla) == 0)
        return nullptr;

    Cotacao *min = &this->mapa[sigla][0];
    for (auto &cotacao : this->mapa[sigla]) {
        if (cotacao.get_valor() < min->get_valor()) {
            min = &cotacao;
        }
    }
    return min;
}

// Imprime um sumário completo das ações, onde para cada ação (sigla) 
// lista os valores informados das cotações, seguido pelos valores 
// MÍNIMO, MAXIMO e MÉDIO.
// Exemplo: BRKM5 56.40 54.40 55.00 | 54.40 56.40 55.27
void HistoricoBovespa::imprimir_estatisticas_completas() {

    // for (it = mapa.begin(); it != mapa.end(); ++it) {
    //     cout << it->first << " ";

    //     it = mapa.find(it->first);
    //     for (auto &i : it->second) {
    //         cout << i.valor << " ";
    //     }

    //     cout << "|";
    //     cout << " " << this->recuperar_cotacao_minima_acao(it->first)->valor;
    //     cout << " " << this->recuperar_cotacao_maxima_acao(it->first)->valor;
    //     cout << " " << this->calcular_valor_medio_acao(it->first) << endl;
    // }

    // Solução do Professor
    // PAIR <CHAVE, VALOR>
    std::map<string, vector<Cotacao>>::iterator it;
    for (it = this->mapa.begin(); it != this->mapa.end(); ++it) {

        string sigla = it->first;
        vector<Cotacao> aux = it->second;

        cout << sigla << " ";

        for (unsigned int i = 0; i < aux.size(); i++) {
            cout << aux[i].get_valor() << " ";
        }
        cout << "| ";

        Cotacao *min = this->recuperar_cotacao_minima_acao(sigla);
        Cotacao *max = this->recuperar_cotacao_maxima_acao(sigla);
        double valor_medio = this->calcular_valor_medio_acao(sigla);

        cout << min->get_valor() << " " << max->get_valor() << " " << valor_medio;

    }
    cout << endl;
}