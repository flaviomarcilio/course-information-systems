/*========================= Exercício 1 - Jogo Batalha entre guerreiros ================================
Neste exercício, você deve criar um protótipo de um sistema de batalha entre guerreiros de um
jogo. Para isso, implemente os itens a seguir em um módulo separado chamado ​jogo​.

1.1.​ Defina um novo tipo de dados chamado ​Guerreiro​ com os seguintes campos: ​ataque
(inteiro), ​defesa​ (inteiro), ​carisma​ (inteiro), ​pontos_vida​ (inteiro) e ​id_guerreiro
(inteiro).

1.2.​ Escreva uma função de nome ​rolaDados​ que simula a rolagem de três dados de seis
faces tradicionais (1 a 6) e retorna a soma dessas rolagens. Note que somar os valores
resultantes da rolagem de três dados de seis faces é diferente de rolar um dado que retorna um
número entre 3 e 18.

1.3.​ Escreva um procedimento de nome ​criaGuerreiro​ que recebe um ​Guerreiro​ por
passagem de parâmetro por referência e que atribui valores aos seus campos de batalha:
ataque, carisma​ e ​defesa​,​ nessa ordem​. Os seus campos de batalha devem receber um
valor inteiro da função ​rolaDados​. Depois, atribua um valor para o campo ​pontos_vida​,
que deve receber a soma dos valores retornados por três execuções da função ​rolaDados​.
Assuma que o campo ​id_guerreiro​ já foi preenchido fora da função.

1.4.​ Escreva uma função de nome bonusCarisma que recebe um valor de carisma como
parâmetro e retorna o bônus dado por esse valor de carisma. A tabela de bônus funciona da
seguinte maneira:
    - Carisma ​18​: o guerreiro é extremamente carismático e tem todo o apoio da torcida,
    recebendo um bônus de ​+3​.
    - Carisma ​16​ e ​17​: o guerreiro é muito carismático e tem o apoio de quase toda a
    torcida, recebendo um bônus de ​+2​.
    - Carisma ​14​ e ​15​: o guerreiro é carismático e tem o apoio de alguns torcedores,
    recebendo um bônus de ​+1​.
    - Carisma ​6​ e ​7​: o guerreiro é antipático, e tem alguma torcida contra ele, recebendo
    uma penalidade de ​-1​.
    - Carisma ​4​ e ​5​: o guerreiro é muito antipático, e tem quase toda a torcida contra ele,
    recebendo uma penalidade de​ -2​.
    - Carisma ​3​: o guerreiro é extremamente antipático, e tem toda a torcida contra ele,
    recebendo uma penalidade de ​-3​.
    - Para qualquer outro valor de carisma, a sua função deve retornar ​0​.

1.5.​ Escreva um procedimento de nome ​ataca​ que recebe dois ​Guerreiro​s por passagem
de parâmetro por referência e simula um ataque do primeiro guerreiro no segundo. O ataque é
dado da seguinte maneira:
    a. O primeiro guerreiro rola três dados e soma os seus valores com o seu campo ​ataque
    e com o seu ​bônus de carisma​. Essa soma é o valor do ​golpe​ do primeiro guerreiro.
    b. O segundo guerreiro rola três dados e soma os seus valores com o seu campo ​defesa
    e com o seu ​bônus de carisma​. Essa soma é o valor do ​escudo​ do segundo guerreiro.
    c. Faça ​dano​ = ​golpe​ - ​escudo​. Se o ​dano​ for maior que zero, subtraia ​dano​ dos
    pontos_vida​ do segundo guerreiro. Ao subtrair o ​dano​, considere que o campo
    pontos_vida​ não pode ter valores menores que zero.
========================================================================================================*/

#include <stdio.h>
#include <stdlib.h>

#include "jogo.h"

int id_g = 1;

int rolaDado() {
	return 1 + rand()%6;
}

int rolaDados() {
    int d1 = 0, d2 = 0, d3 = 0;

    d1 = rolaDado();
    d2 = rolaDado();
    d3 = rolaDado();

    return d1 + d2 + d3;
}

void criaGuerreiro (Guerreiro *g) {
    int i = 0, vida = 0;

    g->ataque = rolaDados();
    g->carisma = rolaDados();
    g->defesa = rolaDados();
    for (i = 0; i < 3; i++) {
        vida += rolaDados();
    }
    g->pontos_vida = vida;
    g->id_guerreiro = id_g;
    id_g++;
}

int bonusCarisma (int carisma) {
    int bonus = 0;

    switch (carisma) {
        case 18:
            bonus = 3;
            break;
        case 17:
        case 16:
            bonus = 2;
            break;
        case 15:
        case 14:
            bonus = 1;
            break;
        case 7:
        case 6:
            bonus = -1;
            break;
        case 5:
        case 4:
            bonus = -2;
            break;
        case 3:
            bonus = -3;
            break;
    }
    return bonus;
}

void ataca(Guerreiro *g1, Guerreiro *g2) {
    int golpe = 0, escudo = 0, dano = 0;

    golpe = rolaDados() + g1->ataque + bonusCarisma(g1->carisma);
    escudo = rolaDados() + g2->defesa + bonusCarisma(g2->carisma);
    dano = golpe - escudo;
    /* printf("\nGolpe: %d | Escudo: %d", golpe, escudo);
    printf("\n"); */
    if (dano > 0) {
        g2->pontos_vida -= dano;
        if (g2->pontos_vida < 0) {
            g2->pontos_vida = 0;
        }
    }
}