/*================================== Exercício 7 ========================================
Implemente um programa para ler o sexo, a altura, e o peso do usuário e informar quantos
quilogramas ele deve ganhar ou perder para alcançar o seu peso ideal. Use a função
pesoIdeal ​do exercício anterior.
==========================================================================================*/

#include <stdio.h>
#include <ctype.h>
#include <math.h>

#include "pratica4.h"

void main() {

    char sexo;
    float altura, peso, PI;

    do {
        printf("\nDigite seu sexo (M ou F): ");
        scanf("%c", &sexo);
        sexo = toupper(sexo);
        if (sexo != 'M' && sexo != 'F') {
            printf("Valor invalido.\n");
        }
    } while (sexo != 'M' && sexo != 'F');
    

    printf("\nDigite sua altura (m) e o peso (kg): ");
    scanf("%f %f", &altura, &peso);

    PI = PesoIdeal(altura, sexo);

    if (fabs(PI - peso) <= 0.001) {
        printf("\nParabens! Voce esta no seu peso ideal.");
        printf("\n");
    } else if (peso > PI) {
        printf("\nVoce deve perder %.2f kg", peso - PI);
        printf("\n");
    } else {
        printf("\nVoce deve ganhar %.2f kg", PI - peso);
        printf("\n");
    }

}