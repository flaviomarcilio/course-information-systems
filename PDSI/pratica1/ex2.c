/*============================== Exercício 2: Troca de valores=============================
Considere o programa abaixo:
    #include <stdio.h>
    void main() {
        float a = 3.14159, b = 2.71828;
        printf (“\nPI = %f”, b);
        printf (“\nEULER = %f”, a);
    }
Note que o programador trocou as variáveis que deveriam ser exibidas em cada printf. Assim,
altere o programa acima de forma a corrigir o erro do programador. O problema é que o
programador proibiu que você altere o que ele escreveu e também que digite os valores das
constantes novamente. Então, faça isso (1) sem alterar nenhuma linha que o programador
escreveu e (2) sem escrever novamente as constantes 3.14159 e 2.71828 . Dica : troque os
valores armazenados em cada variável.
==========================================================================================*/
#include <stdio.h>
void main() {
    float a = 3.14159, b = 2.71828;
    float aux = b;
    b = a;
    a = aux;
    printf ("\nPI = %f", b);
    printf ("\nEULER = %f", a);
}