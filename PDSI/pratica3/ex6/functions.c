#include "functions.h"

int ddd(unsigned int number) {
    return number / 100000000;
}

int soma1SePar(unsigned int number) {
    /* if (number % 2 == 0)     {
        number++;
    }
    return number; */
    // Todo numero par em binario termina com o 0
    // Todo numero impar em binario termina com o 1
    // Decimal 1 em binario          0000...0001
    // Decimal 2 em binario          0000...0010
    // Operacao or bit-a-bit: 2 | 1  0000...0011 -> 3
    // Operação or bit-a-bit: 3 | 1  0000...0011 -> 3

    return number | (unsigned int)1;
}

int parOuImpar(unsigned int number) {
    /* if (number % 2 == 0)     {
        return 1;
    } else {
        return 0;
    } */
    // Decimal 1 em binario          0000...0001
    // Decimal 2 em binario          0000...0010
    // Decimal 3 em binario          0000...0011
    // Operacao and bit-a-bit: 2 & 1 0000...0000 -> 0
    // Operação and bit-a-bit: 3 & 1 0000...0001 -> 1
    return !(number & (unsigned int)1);
}