/*============================ Exercício 3: Conta Poupança =============================
Uma conta poupança foi aberta com um depósito de R$789,54, com rendimentos de 0.56% de
juros ao mês. No segundo mês, R$303,20 reais foram depositados nessa conta poupança. No
terceiro mês, R$58,25 reais foram retirados da conta. Implemente um programa que imprime
quanto haverá nessa conta no quarto mês.
Resposta: A conta terá R$1050,91 no quarto mês.
=========================================================================================*/
#include <stdio.h>

void main() {
    // float capital = 789.54;
    // float taxa = 0.0056;
    // float montanteMes2 = capital * (1 + taxa) + 303.20;
    // float montanteMes3 = montanteMes2 * (1 + taxa) - 58.25;
    // float montanteMes4 = montanteMes3 * (1 + taxa);
    // printf("\nQuantia no quarto mes: %f\n", montanteMes4);

    float poupanca = 789.54, juros = 1.0056;

    // Primeiro mes
    poupanca *= juros;

    // Segundo mes
    poupanca += 303.20;
    poupanca *= juros;

    // Terceiro mes
    poupanca -= 58.25;
    poupanca *= juros;

    // Quarto mes
    printf("\nPoupanca no inicio do quarto mes: R$%.2f\n", poupanca);

}