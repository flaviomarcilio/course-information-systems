#include "Cotacao.hpp"

Cotacao::Cotacao(string data, double valor) {
    this->data = data;
    this->valor = valor;
}

void Cotacao::set_data(string data) {
    this->data = data;
}

string Cotacao::get_data() {
    return this->data;
}

void Cotacao::set_valor(double valor) {
    this->valor = valor;
}

double Cotacao::get_valor() {
    return this->valor;
}