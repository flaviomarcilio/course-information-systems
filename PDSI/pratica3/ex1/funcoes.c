#include "funcoes.h"

float parteInteira(float x) {
    return (int)x;
}

float parteFracionaria(float x) {
    return x - (int)x;
}

float divInts(int x, int y) {
    return (float)x / y;
}