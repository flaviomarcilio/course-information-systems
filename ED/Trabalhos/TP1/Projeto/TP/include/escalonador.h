#ifndef ESCALONADOR_H_
#define ESCALONADOR_H_

#include <string>

#include "fila_encadeada.h"
#include "lista_encadeada.h"
#include "url.h"

using std::string;

struct Host {
    string host;
    ListaEncadeada<Url> *urls;
};

class Escalonador
{
    public:
        /**
         * @brief Constrói um novo Escalonador
         * 
         */
        Escalonador();

        /**
         * @brief Destrói o Escalonador
         * 
         */
        ~Escalonador();

        /**
         * @brief Configura o nome do arquivo de saída
         * 
         * @param output Nome do arquivo de saída
         */
        void setOutput(string output);

        /**
         * @brief Insere uma URL ao Escalonador
         * 
         * @param url 
         */
        void AddUrl(Url url);

        /**
         * @brief Escalona todas as URLs presentes no Escalonador
         * 
         */
        void EscalonaTudo();

        /**
         * @brief Escalona todas as URLs presentes utilizando a estratégia breadth-first
         * 
         */
        void EscalonaTudoBreadth();

        /**
         * @brief Escalona apenas um limite de URLs definida por quantidade
         * 
         * @param quantidade Quantidade de URLs a serem escalonadas
         */
        void Escalona(int quantidade);

        /**
         * @brief Escalona uma quantidade limitada de URLs seguindo a estratégia breadth-first
         * 
         * @param quantidade Quantidade de URLs a serem escalonadas
         */
        void EscalonaBreadth(int quantidade);

        /**
         * @brief Escalona apenas URLs de um host específico
         * 
         * @param host Host a ser escalonado
         * @param quantidade Quantidade de URLs a serem escalonadas do host
         */
        void EscalonaHost(string host, int quantidade);

        /**
         * @brief Exibe todas as URLs do host, na ordem de prioridade
         * 
         * @param host 
         */
        void VerHost(string host);

        /**
         * @brief Exibe todos os hosts, seguindo a ordem em que foram conhecidos
         * 
         */
        void ListaHosts();

        /**
         * @brief Exclui a lista de URLs do host
         * 
         * @param host Host que será limpo
         */
        void LimpaHost(string host);

        /**
         * @brief Exclui todos os hosts e as suas URLs
         * 
         */
        void LimpaTudo();

    private:
        string output_;
        FilaEncadeada<Host> *hosts_;
        ListaEncadeada<Url> *PesquisaHost(string host);
};

#endif