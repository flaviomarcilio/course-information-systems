#ifndef EXCECAO_H_
#define EXCECAO_H_

#include <string>

using std::string;

struct ExcecaoEmpty {
    string msg;
};

struct ExcecaoInvalidPosition {
    string msg;
    int first, last, pos;
};

#endif