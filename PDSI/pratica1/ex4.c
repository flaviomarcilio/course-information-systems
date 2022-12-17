/*============================== Exercício 4: IMC ===========================================
Brutus e Olívia foram ao médico, que disse a eles que ambos estão fora do peso ideal. Ambos
discordaram veementemente da afirmação do médico. Para provar que estava certo, o médico
mostrou o Índice de Massa Corporal (IMC) de ambos, considerando que Brutus tem 1,84m e
pesa 122kg e que Olívia tem 1,76m e pesa 45kg. Implemente um programa para mostrar o IMC
de Brutus e Olívia e qual é a quantidade mínima de quilos que Brutus e Olívia devem perder ou
ganhar para atingirem um peso saudável segundo a classificação do IMC. Use a seguinte
fórmula para cálculo do IMC:
IMC = peso/altura × altura
A tabela abaixo descreve a classificação para as faixas de IMC.
IMC         |     Classificação
< 16        |     Magreza grave
16 a < 17   |    Magreza moderada
17 a < 18.5 |      Magreza leve
18.5 a < 25 |        Saudável
25 a < 30   |        Sobrepeso
30 a < 35   |     Obesidade grau I
35 a < 40   | Obesidade grau II (severa)
≥ 40        | Obesidade grau III (mórbida)

Resposta: O IMC do Brutus é 36,03 e o IMC da Olívia é 14,53. Brutus precisa perder, no
mínimo, (aproximadamente) 37 quilos e Olívia precisa ganhar, no mínimo, (aproximadamente)
12 quilos.
==============================================================================================*/
#include <stdio.h>

void main() {
    float alturaBrutus = 1.84, pesoBrutus = 122;
    float alturaOlivia = 1.76, pesoOlivia = 45;

    float imcBrutus = pesoBrutus/(alturaBrutus * alturaBrutus);
    float imcOlivia = pesoOlivia/(alturaOlivia * alturaOlivia);

    float pesoIdealBrutus = (alturaBrutus * alturaBrutus) * 24.9;
    float pesoIdealOlivia = (alturaOlivia * alturaOlivia) * 18.5;

    printf("\nIMC do Brutus: %5.2f, precisa perder no minimo: %.1f Kg", imcBrutus, pesoBrutus - pesoIdealBrutus);
    printf("\nIMC da Olivia: %5.2f, precisa ganhar no minimo: %.1f Kg", imcOlivia, pesoIdealOlivia - pesoOlivia);
    printf("\n");
}