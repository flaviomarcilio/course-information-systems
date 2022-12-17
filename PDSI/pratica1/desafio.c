/*============================= Desafio para os fortes ======================================
Dígito verificador ou algarismo de controle é um mecanismo de autenticação utilizado para
verificar a validade e a autenticidade de um valor numérico, evitando dessa forma fraudes ou
erros de transmissão ou digitação. Consiste em um ou mais algarismos acrescentados ao valor
original e calculados a partir deste através de um determinado algoritmo. Números de
documentos de identificação, de matrícula, cartões de crédito e quaisquer outros códigos
numéricos que necessitem de maior segurança utilizam dígitos verificadores. Esse trabalho
consiste em calcular o dígito verificador do CPF. Seu programa deve receber um cpf sem o
dígito verificador do usuário e imprimir o CPF com o dígito verificador. Você pode usar o seu
CPF e de parentes e colegas para testar o programa. A seguir, as regras para o cálculo do
dígito verificador são definidas através de um exemplo. É utilizado como exemplo o número:
123456789.
    1. Calcule a soma dos produtos dos nove dígitos utilizando peso 2 para unidade, peso 3
    para dezena, peso 4 para centena e assim sucessivamente. Exemplo:
    9*2+8*3+7*4+6*5+5*6+4*7+3*8+2*9+1*10 = 210.

    2. A dezena do número verificador é 0 caso o resto da divisão por 11 da soma dos
    produtos seja 0 ou 1; caso contrário a dezena corresponde a subtrair de 11 o resto da
    divisão por 11 da soma dos produtos.

    3. Calcule a soma dos produtos dos dez dígitos, onde o dígito menos significativo passa a
    ser a dezena dos dígitos verificadores, utilizando os seguintes pesos: 2, 3, 4, 5, 6, 7, 8,
    9, 10, 11;

    4. A unidade do número verificador é 0 caso o resto da divisão da soma dos produtos seja
    0 ou 1; caso contrário a unidade corresponde a 11 menos o resto da divisão por 11 da
    soma dos produtos. Exemplo: resto da divisão de 255 por 11 é 2 então a unidade do
    número verificador é 11-2=9
    
Dica: para resolver esse problema, você precisa aprender três conceitos que ainda não foram
ensinados em sala de aula: leitura de dados a partir do teclado, resto da divisão entre dois
números, e processamento condicional. Para o primeiro conceito, procure saber como funciona
a função scanf , que é da biblioteca stdio.h . Para o segundo conceito, procure saber como
funciona o operador % , ou mod . Por fim, e mais difícil que os conceitos anteriores, procure
saber como funciona o comando if e else da linguagem C. O aprendizado de uma linguagem
depende muito da sua iniciativa de correr atrás das soluções. Esse exercício é uma forma de
incentivar a autodidática.
===============================================================================================*/
#include <stdio.h>

int ultimoNumero(int numero) {
    return numero % 10;
}

int verificador(int soma) {
    if (soma % 11 == 0 || soma % 11 == 1)
    {
        return 0;
    }
    else
    {
        return 11 - (soma % 11);
    }
}

void main() {

    int cpfInput, somaProduto, resto, dezenaVerificador, unidadeVerificador;

    printf("\nEntre com o numero do CPF (sem o digito verificador): ");

    scanf("%i", &cpfInput);

    printf("\nCPF sem verificador: %i\n", cpfInput);

    somaProduto = ultimoNumero(cpfInput) * 2;
    resto = cpfInput / 10;

    for (int i = 3; i < 11; i++)
    {
        somaProduto += ultimoNumero(resto) * i;
        resto = resto / 10;

    }
    // printf("\nSoma do produto: %d", somaProduto);

    dezenaVerificador = verificador(somaProduto);
    
    // printf("\nDezena do verificador: %d\n", dezenaVerificador);

    somaProduto = dezenaVerificador * 2;
    resto = cpfInput;

    for (int i = 3; i < 12; i++)
    {
        somaProduto += ultimoNumero(resto) * i;
        resto = resto / 10;

    }
    // printf("\nSoma do produto: %d", somaProduto);

    unidadeVerificador = verificador(somaProduto);

    // printf("\nUnidade do verificador: %d\n", unidadeVerificador);

    printf("\nCPF com verificador: %d-%d%d\n", cpfInput, dezenaVerificador, unidadeVerificador);

}