#include <stdio.h>
#include "pratica4.h"

void test_Ex1(float entrada, float esperado) {

    float saida;
    saida = paraMetrosPorSegundo(entrada);

    if (saida != esperado) {
        printf("\nTeste falhou para %f: esperado = %f - saida = %f", entrada, esperado, saida);
    }

    printf("\nTeste passou!");
}

void test_Ex2(float entrada, float esperado) {

    float saida;
    saida = areaCirculo(entrada);

    if (saida != esperado) {
        printf("\nTeste falhou para %f: esperado = %f - saida = %f", entrada, esperado, saida);
    }

    printf("\nTeste passou!");
}

void test_Ex3(int entrada1, int entrada2, int entrada3, int esperado) {

    int saida;
    saida = maior3(entrada1, entrada2, entrada3);

    if (saida != esperado) {
        printf("\nTeste falhou para [%d, %d, %d]: esperado = %d - saida = %d",
                entrada1, entrada2, entrada3, esperado, saida);
    }

    printf("\nTeste passou!");
}

void test_Ex4(int entrada, int esperado) {

    int saida;
    saida = ehPar(entrada);

    if (saida != esperado) {
        printf("\nTeste falhou para %d: esperado = %d - saida = %d", entrada, esperado, saida);
    }

    printf("\nTeste passou!");
}

void test_Ex5(int entrada, int esperado) {

    int saida;
    saida = ehDivisivelPor3ou5(entrada);

    if (saida != esperado) {
        printf("\nTeste falhou para %d: esperado = %d - saida = %d", entrada, esperado, saida);
    }

    printf("\nTeste passou!");
}

void test_Ex6(char entrada1, float entrada, float esperado) {

    float saida;
    saida = PesoIdeal(entrada, entrada1);

    if (saida != esperado) {
        printf("\nTeste falhou para [%c, %f]: esperado = %f - saida = %f",
                entrada1, entrada, esperado, saida);
    }

    printf("\nTeste passou!");
}

void test_Ex8(int entrada, int esperado) {

    int saida;
    saida = somaImpares(entrada);

    if (saida != esperado) {
        printf("\nTeste falhou para %d: esperado = %d - saida = %d", entrada, esperado, saida);
    }

    printf("\nTeste passou!");
}

void test_Ex9(int entrada, double esperado) {

    double saida;
    saida = fatorial(entrada);

    if (saida != esperado) {
        printf("\nTeste falhou para %d: esperado = %.0lf - saida = %.0lf", entrada, esperado, saida);
    }

    printf("\nTeste passou!");
}

void test_Ex10(int entrada, int esperado) {

    int saida;
    saida = somaNumerosDiv3ou5(entrada);

    if (saida != esperado) {
        printf("\nTeste falhou para %d: esperado = %d - saida = %d", entrada, esperado, saida);
    }

    printf("\nTeste passou!");
}

void test_Ex11(int en1, int en2, int en3, int op, float esperado) {

    float saida;
    saida = calculaMedia(en1, en2, en3, op);

    if (saida != esperado) {
        printf("\nTeste falhou para [%d, %d, %d] operacao = %d: esperado = %f - saida = %f",
                en1, en2, en3, op, esperado, saida);
    }

    printf("\nTeste passou!");
}

void test_Ex12(int entrada, int esperado) {

    int saida;
    saida = numeroDivisores(entrada);

    if (saida != esperado) {
        printf("\nTeste falhou para %d: esperado = %d - saida = %d", entrada, esperado, saida);
    }

    printf("\nTeste passou!");
}

void test_Ex13(int entrada, int esperado) {

    int saida;
    saida = enesimoFibonacci(entrada);

    if (saida != esperado) {
        printf("\nTeste falhou para %d: esperado = %d - saida = %d", entrada, esperado, saida);
    }

    printf("\nTeste passou!");
}

void test_Ex14(unsigned int en1, unsigned int en2, int esperado) {

    int saida;
    saida = mdc(en1, en2);

    if (saida != esperado) {
        printf("\nTeste falhou para [%u, %u]: esperado = %d - saida = %d", en1, en2, esperado, saida);
    }

    printf("\nTeste passou!");
}

void test_Ex15(unsigned int en1, unsigned int en2, int esperado) {

    int saida;
    saida = mmc(en1, en2);

    if (saida != esperado) {
        printf("\nTeste falhou para [%u, %u]: esperado = %d - saida = %d", en1, en2, esperado, saida);
    }

    printf("\nTeste passou!");
}

void main() {

    // Velocidade (km/h, m/s)
    printf("\nTeste do Exercicio 1");
    test_Ex1(0, 0);
    test_Ex1(3.6, 1);
    test_Ex1(-3.6, -1);
    test_Ex1(180, 50);
    printf("\n");

    // Area do círculo (raio, area)
    printf("\nTeste do Exercicio 2");
    test_Ex2(1, 3.141592);
    test_Ex2(10, 314.159210);
    test_Ex2(0.1, 0.031416);
    test_Ex2(0, 0);
    printf("\n");

    // Maior entre 3 numeros
    printf("\nTeste do Exercicio 3");
    test_Ex3(-10, 10, 20, 20);
    test_Ex3(-10, -1, 0, 0);
    test_Ex3(10, 20, 30, 30);
    test_Ex3(-10, -20, -30, -10);
    test_Ex3(50, 50, 50, 50);
    test_Ex3(100, 100, 30, 100);
    test_Ex3(0, 0, 0, 0);
    printf("\n");

    // Par = 1, Impar = 0
    printf("\nTeste do Exercicio 4");
    test_Ex4(0, 1);
    test_Ex4(24, 1);
    test_Ex4(-2, 1);
    test_Ex4(1, 0);
    test_Ex4(-15, 0);
    test_Ex4(153, 0);
    printf("\n");

    // Divisivel por 3 ou 5 = 1
    printf("\nTeste do Exercicio 5");
    test_Ex5(3, 1);
    test_Ex5(5, 1);
    test_Ex5(15, 0);
    test_Ex5(-3, 1);
    test_Ex5(-5, 1);
    test_Ex5(-15, 0);
    test_Ex5(0, 0);
    test_Ex5(4, 0);
    test_Ex5(30, 0);
    printf("\n");

    // Peso Ideal
    printf("\nTeste do Exercicio 6");
    test_Ex6('M', 1.65, 61.954998);
    test_Ex6('M', 0, 0);
    test_Ex6('F', 0, 0);
    test_Ex6('F', 1.65, 57.764999);
    printf("\n");

    // Soma impares até N
    printf("\nTeste do Exercicio 8");
    test_Ex8(10, 25);
    test_Ex8(9, 25);
    printf("\n");

    // Fatorial de N
    printf("\nTeste do Exercicio 9");
    test_Ex9(5, 120);
    test_Ex9(0, 1);
    test_Ex9(1, 1);
    test_Ex9(6, 720);
    test_Ex9(7, 5040);
    printf("\n");

    // Soma dos divisiveis por 3 ou 5 ate N
    printf("\nTeste do Exercicio 10");
    test_Ex10(20, 83);
    test_Ex10(3, 3);
    test_Ex10(5, 8);
    test_Ex10(0, 0);
    printf("\n");

    // Medias entre 3 numeros
    // op | Media
    // 1  | Geometrica
    // 2  | ponderada
    // 3  | Harmonica
    // 4  | Aritmetica
    printf("\nTeste do Exercicio 11");
    test_Ex11(3, 3, 3, 1, 3);
    test_Ex11(3, 3, 3, 2, 3);
    test_Ex11(3, 3, 3, 3, 3);
    test_Ex11(3, 3, 3, 4, 3);
    printf("\n");

    // Numero de Divisores de N
    printf("\nTeste do Exercicio 12");
    test_Ex12(66, 8);
    test_Ex12(6, 4);
    test_Ex12(1, 1);
    test_Ex12(2, 2);
    test_Ex12(0, 0);
    test_Ex12(3, 2);
    test_Ex12(4, 3);
    printf("\n");

    // Numero de Fibonacci
    printf("\nTeste do Exercicio 13");
    test_Ex13(8, 13);
    test_Ex13(1, 0);
    test_Ex13(2, 1);
    test_Ex13(3, 1);
    test_Ex13(4, 2);
    test_Ex13(5, 3);
    printf("\n");

    // MDC entre dois numeros
    printf("\nTeste do Exercicio 14");
    test_Ex14(18, 12, 6);
    test_Ex14(18, 6, 6);
    test_Ex14(20, 24, 4);
    test_Ex14(15, 5, 5);
    test_Ex14(2, 3, 1);
    test_Ex14(3, 5, 1);
    printf("\n");

    // MMC entre dois numeros
    printf("\nTeste do Exercicio 15");
    test_Ex15(18, 12, 36);
    test_Ex15(18, 6, 18);
    test_Ex15(20, 24, 120);
    test_Ex15(15, 5, 15);
    test_Ex15(2, 3, 6);
    test_Ex15(3, 5, 15);
    printf("\n");

}