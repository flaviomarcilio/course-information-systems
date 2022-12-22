#ifndef ORDENACAO_EXTERNA_H_
#define ORDENACAO_EXTERNA_H_

#include <iostream>
#include <fstream>
#include <string>

#include "../include/item.h"
#include "../include/heap.h"
#include "../include/ordenacao.h"

using namespace std;

class OrdenacaoExterna
{
    private:
        void Intercala(int qtdeFitas, string output);
        bool writeFile(ofstream&, string);
        bool readFile(ifstream&, string);
    public:
        OrdenacaoExterna(string entrada, string saida, int numEntidades);
};

#endif