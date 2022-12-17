/*==================================== Exercício 2 - Editor de Textos ====================================
Implemente um programa para ler um texto de tamanho indefinido, armazená-lo em uma variável e imprimi-lo 
novamente na tela.

Passo a passo
1) Você deve ler caractere por caractere usando a função ​getche()​. Para ler um caractere
usando essa função, faça ​char c = getche()​.

2) Todo o texto lido deve ser armazenado na memória a partir de alocação dinâmica. Crie
um ponteiro para caractere (​char *texto​) para apontar para essa área de memória.

3) Antes de alocar memória para os caracteres, você deve armazenar temporariamente os
caracteres lidos em um vetor de caracteres (​char buffer[BUFFER_TAM]​) de ​BUFFER_TAM
posições. Para isso, conte os caracteres lidos usando uma variável (ex: ​int contBuffer​) e
armazene-os no vetor fazendo ​buffer[contBuffer]=c​. Faça ​#define BUFFER_TAM 5​.

4) Quando o vetor ​buffer​ estiver cheio, aloque dinamicamente outro espaço em memória e
transfira todo o conteúdo do ​buffer​ para este espaço. Ao final, variável ​texto​ deverá
receber o endereço para essa memória alocada:
​   texto = (char*)malloc((contBuffer)*sizeof(char));

Os detalhes desse processo são descritos a seguir. Sempre que vetor ​buffer​ estiver cheio,
aloque um novo espaço em memória para receber o conteúdo do ​buffer​ ​mais​ o conteúdo
apontado pela variável ​texto​. Crie um apontador de caracteres temporário de nome ​char
*textoaux​ para apontar para esse espaço de memória. Transfira para esse espaço o
conteúdo apontado por ​texto​ (caso exista) e, em seguida, o conteúdo de ​buffer​.

5) Depois de fazer a transferência do item anterior, libere a memória apontada pelo
apontador ​texto​ (que contém o texto desatualizado) e faça o apontador ​texto​ receber o
endereço apontado por ​textoaux​ (que contém o texto atualizado). Dessa maneira, o
apontador ​texto​ apontará para um espaço em memória que contém todo o texto digitado até
o momento.

6) Este processo deve se repetir até que o caractere ​'#'​ seja digitado pelo usuário. Esse
caractere não deve ser armazenado mas, ao invés dele, deve-se armazenar o caractere ​'\0'​,
delimitando o fim da ​string​.

7) ​Observação importante:​ No Windows, se você apertar a tecla ENTER, os caracteres
'\r'​ e ​'\n'​ serão enviados do teclado para a função ​char c = getche()​. Dessa
maneira, a variável ​c​ receberá somente '​\r'​, que retorna para o início da linha. Para fazer a
quebra de linha corretamente, use o seguinte código após ler o caractere ​c​:
    if(c == '\r'){
        c = '\n';
        printf("\n");
    }
==========================================================================================================*/

#include <stdio.h>
#include <stdlib.h>

#define BUFFER_TAM 5

int main(int argc, char const *argv[])
{
    int i = 0, tamTexto = 0, contBuffer = 0;
    char buffer[BUFFER_TAM], c;
    char *texto = NULL, *textoaux;

    do {
        c = getchar();
        if (c == '\r') {
            c = '\n';
            printf("\n");
        }
        if (contBuffer < BUFFER_TAM) {
            buffer[contBuffer] = c;
            contBuffer++;
        } 
        if (contBuffer == BUFFER_TAM || c == '#') {
            textoaux = (char *)malloc(contBuffer * sizeof(char) + tamTexto);
            tamTexto += contBuffer;
            
            for (i = 0; i < tamTexto-contBuffer; i++) {
                textoaux[i] = texto[i];
            }
            for (i = 0; i < contBuffer; i++) {
                textoaux[i + tamTexto-contBuffer] = buffer[i];
            }
            if (texto != NULL) {
                free(texto);
            }
            texto = textoaux;
            contBuffer = 0;
        }
        
    } while (c != '#');
    texto[tamTexto - 1] = '\0';

    printf("\n%s\n", texto);
    
    free(texto);
    
    return 0;
}
