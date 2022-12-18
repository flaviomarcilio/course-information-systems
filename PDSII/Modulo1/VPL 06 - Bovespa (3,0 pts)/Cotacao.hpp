#pragma once
#include <string>

using std::string;

struct Cotacao {
    string data;
    double valor;

    Cotacao(string data, double valor);
    void set_data(string data);
    string get_data();
    void set_valor(double valor);
    double get_valor();
};