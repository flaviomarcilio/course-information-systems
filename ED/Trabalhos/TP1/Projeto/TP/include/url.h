#ifndef URL_H_
#define URL_H_

#include <iostream>
#include <string>

using std::string;
using std::ostream;

class Url
{
    public:
        /**
         * @brief Constrói uma nova URL
         * 
         */
        Url();

        /**
         * @brief Constrói uma nova URL a partir de uma string
         * 
         * @param url String a ser convertida para URL
         */
        Url(string &url);

        /**
         * @brief Imprime a URL
         * 
         */
        void print();

        /**
         * @brief Retorna o protocolo da URL
         * 
         * @return string 
         */
        string GetProtocol();

        /**
         * @brief Retorna o host da URL
         * 
         * @return string 
         */
        string GetHost();

        /**
         * @brief Retorna o path da URL
         * 
         * @return string 
         */
        string GetPath();

        /**
         * @brief Retorna a profundidade da URL
         * 
         * @return int 
         */
        int GetDepth();

        /**
         * @brief Verifica se a URL é válida pelos critérios adotados
         * 
         * @return true or false
         */
        bool isValid();

        friend ostream& operator<< (ostream& os, Url &url);
        friend bool operator== (Url& a, Url& b);

    private:
        int depth_;
        string protocol_;
        string www_;
        string host_;
        string path_;
        string query_;
};

#endif