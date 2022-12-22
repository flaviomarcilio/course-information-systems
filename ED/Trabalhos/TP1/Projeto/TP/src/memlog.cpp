#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

#include "../include/memlog.h"

/**
 * @brief Calcula a diferença entre t2 e t1 e armazena o resultado em res.
 * 
 * @param t1 Tempo inicial
 * @param t2 Tempo final
 * @param res Intervalo de tempo
 */
void clkDifMemLog(struct timespec t1, struct timespec t2, struct timespec *res)
{
    if (t2.tv_nsec < t1.tv_nsec)
    {
        // ajuste necessario, utilizando um segundo de tv_sec
        res-> tv_nsec = 1000000000+t2.tv_nsec-t1.tv_nsec;
        res-> tv_sec = t2.tv_sec-t1.tv_sec-1;
    } else {
        // nao e necessario ajuste
        res-> tv_nsec = t2.tv_nsec-t1.tv_nsec;
        res-> tv_sec = t2.tv_sec-t1.tv_sec;
    }
}

/**
 * @brief Inicializa o registro de acessos no arquivo passado como parâmetro
 * 
 * @param nome Nome do arquivo
 * @return 0 para sucesso e -1 em caso de erro
 */
int iniciaMemLog(char *nome)
{
    // escolhe modo do relogio
    ml.clk_id = CLOCK_MONOTONIC;

    // abre arquivo de registro e verifica se foi aberto corretamente
    ml.log = fopen(nome, "wt");
    // erroAssert(ml.log != NULL, "Não foi possível abrir o arquivo de Log");

    // captura o tempo inicial do registro
    struct timespec tp;
    int result = clock_gettime(ml.clk_id, &tp);
    ml.inittime.tv_sec = tp.tv_sec;
    ml.inittime.tv_nsec = tp.tv_nsec;

    // inicializa variaveis do TAD
    ml.count = 1;
    ml.ativo = MLATIVO;
    ml.fase = 0;

    // imprime registro inicial
    fprintf(ml.log, "I %ld %ld.%.9ld\n", ml.count, tp.tv_sec, tp.tv_nsec);
    // erroAssert(retprint >= 0, "Nao foi possivel escrever registro");
    return result;
}

/**
 * @brief Ativa o registro de acessos
 * 
 * @return Estado do registro ATIVO
 */
int ativaMemLog()
{
    ml.ativo = MLATIVO;
    return MLATIVO;
}

/**
 * @brief Desativa o registro de acessos
 * 
 * @return Estado do registro INATIVO
 */
int desativaMemLog()
{
    ml.ativo = MLINATIVO;
    return MLINATIVO;
}

/**
 * @brief Define a fase de registro de acessos
 * 
 * @param f Fase de registro
 * @return Valor de f
 */
int defineFaseMemLog(int f)
{
    ml.fase = f;
    return f;
}

/**
 * @brief Registra acesso de leitura de tam bytes na posição pos.
 * 
 * @param pos Posição da memória
 * @param tam Tamanho de memória utilizada
 * @return Resultado da obtençaõ do relógio
 */
int leMemLog(long int pos, long int tam, int id)
{
    // verifica se registro esta ativo
    if (ml.ativo == MLINATIVO) return 0;

    // captura tempo atual
    struct timespec tp, tdif;
    int result = clock_gettime(ml.clk_id, &tp);

    // calcula a diferenca com tempo inicial, para economia de armazenamento
    clkDifMemLog(ml.inittime, tp, &tdif);

    // atualiza contador
    ml.count++;
    // imprime registro
    fprintf(ml.log, "L %d %ld %d %ld.%.9ld %ld %ld\n",
                           ml.fase, ml.count, id, tdif.tv_sec, tdif.tv_nsec, pos, tam);
    // erroAssert(retprint >= 0, "Nao foi possivel escrever registro");
    return result;
}

/**
 * @brief Registra acesso de escrita de tam bytes na posição pos.
 * 
 * @param pos Posição da memória
 * @param tam Tamanho de memória utilizada
 * @return Resultado da obtenção do relógio
 */
int escreveMemLog(long int pos, long int tam, int id)
{
    // verifica se registro esta ativo
    if (ml.ativo == MLINATIVO) return 0;

    // captura tempo atual
    struct timespec tp,tdif;
    int result = clock_gettime(ml.clk_id, &tp);

    // calcula a diferenca com tempo inicial, para economia de armazenamento
    clkDifMemLog(ml.inittime, tp, &tdif);

    // atualiza contador
    ml.count++;

    // imprime registro
    fprintf(ml.log, "E %d %ld %d %ld.%.9ld %ld %ld\n",
                           ml.fase, ml.count, id, tdif.tv_sec, tdif.tv_nsec, pos, tam);
    // erroAssert(retprint >= 0, "Nao foi possivel escrever registro");
    return result;
}

/**
 * @brief Finaliza o registro de acessos a memória
 * 
 * @return Resultado da obtenção do relógio
 */
int finalizaMemLog()
{
    // captura o tempo atual
    struct timespec tp, tdif;
    int result = clock_gettime(ml.clk_id, &tp);

    // calcula a diferenca com tempo inicial, para economia de armazenamento
    clkDifMemLog(ml.inittime,tp, &tdif);

    // atualiza contador
    ml.count++;

    // imprime registro final
    fprintf(ml.log, "F %ld %ld.%.9ld %ld.%.9ld\n",
                           ml.count, tp.tv_sec, tp.tv_nsec, tdif.tv_sec, tdif.tv_nsec);
    // erroAssert(retprint >= 0, "Nao foi possivel escrever registro");

    // fecha arquivo de registro
    fclose(ml.log);
    // erroAssert(retclose == 0, "Nao foi possivel fechar o arquivo de registro");

    // atualiza variavel de estado
    ml.ativo = MLINATIVO;
    return result;
}