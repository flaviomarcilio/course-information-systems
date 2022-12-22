#ifndef FILA_ENCADEADA_H_
#define FILA_ENCADEADA_H_

#include "excecao.h"

template <class T>
class FilaEncadeada
{
    public:
        /**
         * @brief Constrói uma nova Fila Encadeada
         * 
         */
        FilaEncadeada(int id);

        /**
         * @brief Destrói a Fila Encadeada
         * 
         */
        ~FilaEncadeada();

        /**
         * @brief Retorna a quantidade de elementos na Fila Encadeada
         * 
         * @return int - Quantidade de elementos
         */
        int size();

        /**
         * @brief Verifica se a Fila Encadeada está vazia
         * 
         * @return true or false
         */
        bool empty();

        /**
         * @brief Insere um novo elemento no final da Fila Encadeada
         * 
         * @param item Elemento a ser inserido
         */
        void push_back(T& item);

        /**
         * @brief Remove o primeiro elemento da Fila Encadeada
         * 
         * @return T - Elemento removido
         */
        T pop_front();   

        /**
         * @brief Imprime os elementos da Fila Encadeada
         * 
         */
        void print();

        /**
         * @brief Exclui todos os elementos da Fila Encadeada
         * 
         */
        void clear();

    private:
        class Celula {
            friend class FilaEncadeada<T>;
            private:
                T *item_;
                Celula *next_;
                Celula() { item_ = nullptr; next_ = nullptr; };
                ~Celula() { if (item_ != nullptr)  delete item_; };
        };
        int id_;
        int length_;
        Celula *head_, *tail_;
};

#include "../src/fila_encadeada.cpp"
#endif