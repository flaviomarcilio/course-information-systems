#ifndef ORDENACAO_H_
#define ORDENACAO_H_

#include <iostream>

#include "memlog.h"

using std::cout;
using std::endl;

enum Method {quickSort, mergeSort, heapSort};

template <class T>
class Ordenacao
{
    private:
        void Particao(int Esq, int Dir, int *i, int *j, T **A, int ID_QUICKSORT);
        void Ordena(int Esq, int Dir, T **A, int ID_QUICKSORT);
        void QuickSort(T **A, int n, int ID_QUICKSORT);
        int MedianaDeTres(int i, int j, T **A);
    public:
        Ordenacao(T **A, int n, Method metodo, int ID_QUICKSORT);
};

#include "../src/ordenacao.cpp"

#endif