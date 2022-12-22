#ifndef LISTA_ENCADEADA_H_
#define LISTA_ENCADEADA_H_

#include "excecao.h"

template <class T>
class ListaEncadeada
{
    public:
        /**
         * @brief Constrói uma nova Lista Encadeada
         * 
         */
        ListaEncadeada(int id);

        /**
         * @brief Destrói a Lista Encadeada
         * 
         */
        ~ListaEncadeada();

        /**
         * @brief Retorna a quantidade de elementos da lista Encadeada
         * 
         * @return int - Tamanho da Lista
         */
        int size();

        /**
         * @brief Verifica se a Lista Encadeada está vazia
         * 
         * @return true or false
         */
        bool empty();

        /**
         * @brief Retorna o elemento da posição especificada
         * 
         * @param pos Posição do elemento a ser retornado
         * @return T - Elemento retornado
         */
        T get_item(int pos);

        /**
         * @brief Substitui o elemento de uma posição
         * 
         * @param item Elemento a ser inserido
         * @param pos Posição do elemento a ser alterado
         */
        void set_item(T& item, int pos);

        /**
         * @brief Insere um elemento na primeira posição
         * 
         * @param item Item a ser inserido
         */
        void push_front(T& item);

        /**
         * @brief Insere um item no final da Lista
         * 
         * @param item
         */
        void push_back(T& item);

        /**
         * @brief Insere um elemento em uma posição específica da Lista
         * 
         * @param item Elemento a ser inserido
         * @param pos Posição do elemento
         */
        void insert_at(T& item, int pos);

        /**
         * @brief Remove um elemento do início da Lista
         * 
         * @return T - Elemento removido
         */
        T pop_front();

        /**
         * @brief Remove um elemento do final da Lista
         * 
         * @return T - Elemento removido
         */
        T pop_back();

        /**
         * @brief Remove um elemento de uma posição específica da Lista
         * 
         * @param pos Posição do elemento a ser removido
         * @return T - Elemento removido
         */
        T remove_at(int pos);

        /**
         * @brief Pesquisa se um elemento está na Lista
         * 
         * @param item Elemento a ser pesquisado
         * @return A posição do elemento ou -1 caso não esteja na lista
         */
        int find(T& item);

        /**
         * @brief Imprime todos os elementos da Lista
         * 
         */
        void print();

        /**
         * @brief Remove todos os elementos da Lista
         * 
         */
        void clear();
        
    private:
        class Celula {
            friend class ListaEncadeada<T>;
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



#include "../src/lista_encadeada.cpp"
#endif