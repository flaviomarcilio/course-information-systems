#ifdef LISTA_ENCADEADA_H_

#include <iostream>

#include "../include/memlog.h"

using std::cout;
using std::endl;

template <class T>
ListaEncadeada<T>::ListaEncadeada(int id)
{
    id_ = id;
    length_ = 0;
    head_ = new Celula();
    ESCREVEMEMLOG((long int)(head_), sizeof(Celula), id_);
    tail_ = head_;
}

template <class T>
ListaEncadeada<T>::~ListaEncadeada()
{
    if (length_ > 0 )
        clear();

    delete head_;
}

template <class T>
int ListaEncadeada<T>::size()
{
    return length_;
}

template <class T>
bool ListaEncadeada<T>::empty()
{
    return length_ == 0;
}

template<class T> 
T ListaEncadeada<T>::get_item(int pos)
{
    if (length_ == 0) throw ExcecaoEmpty{"Lista vazia"};

    if (pos <= 0 || pos > length_)
        throw ExcecaoInvalidPosition{"Posicao invalida", 1, length_, pos};

    Celula *aux = head_;
    LEMEMLOG((long int)(aux), sizeof(Celula), id_);

    for (int i = 1; i <= pos; i++)
    {
        aux = aux->next_;
        LEMEMLOG((long int)(aux), sizeof(Celula), id_);
    }

    T *item = aux->item_;
    LEMEMLOG((long int)(item), sizeof(T), id_+100);

    return *item;
}

template<class T> 
void ListaEncadeada<T>::set_item(T &item, int pos)
{
    if (length_ == 0) throw ExcecaoEmpty{"Lista vazia"};

    if (pos <= 0 || pos > length_)
        throw ExcecaoInvalidPosition{"Posicao invalida", 1, length_, pos};

    Celula *aux = head_;
    LEMEMLOG((long int)(aux), sizeof(Celula), id_);

    for (int i = 1; i <= pos; i++)
    {
        aux = aux->next_;
        LEMEMLOG((long int)(aux), sizeof(Celula), id_);
    }

    T *p = aux->item_;
    LEMEMLOG((long int)(p), sizeof(T), id_+100);

    aux->item_ = new T(item);
    ESCREVEMEMLOG((long int)(aux->item_), sizeof(T), id_+100);
    delete p;
}

template <class T>
void ListaEncadeada<T>::push_front(T &item)
{
    Celula *celula = new Celula();
    ESCREVEMEMLOG((long int)(celula), sizeof(Celula), id_);

    celula->item_ = new T(item);
    ESCREVEMEMLOG((long int)(celula->item_), sizeof(T), id_+100);

    celula->next_ = head_->next_;
    LEMEMLOG((long int)(celula->next_), sizeof(Celula), id_);

    head_->next_ = celula;

    length_++;

    if (celula->next_ == nullptr)
        tail_ = celula;
}

template <class T>
void ListaEncadeada<T>::push_back(T& item)
{
    Celula *celula = new Celula();
    ESCREVEMEMLOG((long int)(celula), sizeof(Celula), id_);

    celula->item_ = new T(item);
    ESCREVEMEMLOG((long int)(celula->item_), sizeof(T), id_+100);

    tail_->next_ = celula;
    tail_ = celula;
    length_++;

}

template <class T>
void ListaEncadeada<T>::insert_at(T& item, int pos)
{
    if (length_ == 0) throw ExcecaoEmpty{"Lista vazia"};

    if (pos <= 0 || pos > length_)
        throw ExcecaoInvalidPosition{"Posicao invalida", 1, length_, pos};

    Celula *aux = head_;
    LEMEMLOG((long int)(aux), sizeof(Celula), id_);

    for (int i = 1; i < pos; i++)
    {
        aux = aux->next_;
        LEMEMLOG((long int)(aux), sizeof(Celula), id_);
    }

    Celula *celula = new Celula();
    ESCREVEMEMLOG((long int)(celula), sizeof(Celula), id_);

    celula->item_ = new T(item);
    ESCREVEMEMLOG((long int)(celula->item_), sizeof(T), id_+100);

    celula->next_ = aux->next_;
    aux->next_ = celula;
    length_++;

    if (celula->next_ == nullptr)
        tail_ = celula;
}

template <class T>
T ListaEncadeada<T>::pop_front()
{
    if (length_ == 0) throw ExcecaoEmpty{"Lista vazia"};

    Celula *cell = head_->next_;
    LEMEMLOG((long int)(cell), sizeof(Celula), id_);

    head_->next_ = cell->next_;
    length_--;
    if (head_->next_ == nullptr)
        tail_ = head_;

    T item = *(cell->item_);
    LEMEMLOG((long int)(cell->item_), sizeof(T), id_+100);
 
    delete cell;
    return item;
}

template<class T> 
T ListaEncadeada<T>::pop_back()
{
    if (length_ == 0) throw ExcecaoEmpty{"Lista vazia"};

    Celula *aux = head_;
    LEMEMLOG((long int)(aux), sizeof(Celula), id_);

    for (int i = 1; i < length_; i++)
    {
        aux = aux->next_;
        LEMEMLOG((long int)(aux), sizeof(Celula), id_);
    }

    aux->next_ = nullptr;
    length_--;

    T item = *(tail_->item_);
    LEMEMLOG((long int)(tail_->item_), sizeof(T), id_+100);

    delete tail_;
    tail_ = aux;

    return item;
}

template<class T> 
T ListaEncadeada<T>::remove_at(int pos)
{
    if (length_ == 0) throw ExcecaoEmpty{"Lista vazia"};
    
    if (pos <= 0 || pos > length_)
        throw ExcecaoInvalidPosition{"Posicao invalida", 1, length_, pos};

    Celula *aux = head_;
    LEMEMLOG((long int)(aux), sizeof(Celula), id_);

    for (int i = 1; i < pos; i++)
    {
        aux = aux->next_;
        LEMEMLOG((long int)(aux), sizeof(Celula), id_);
    }

    Celula *cell = aux->next_;
    LEMEMLOG((long int)(cell), sizeof(Celula), id_);

    aux->next_ = cell->next_;
    LEMEMLOG((long int)(aux->next_), sizeof(Celula), id_);

    length_--;

    T item = *(cell->item_);
    LEMEMLOG((long int)(cell->item_), sizeof(T), id_+100);

    delete cell;

    if (aux->next_ == nullptr)
        tail_ = aux;

    return item;
}

template<class T> 
int ListaEncadeada<T>::find(T &item)
{
    if (length_ == 0) throw ExcecaoEmpty{"Lista vazia"};
    
    Celula *cell = head_->next_;
    LEMEMLOG((long int)(cell), sizeof(Celula), id_);

    for (int i = 1; i <= length_; i++)
    {
        if (*(cell->item_) == item)
        {
            return i;
        }
        cell = cell->next_;
        LEMEMLOG((long int)(cell->item_), sizeof(T), id_+100);
        LEMEMLOG((long int)(cell), sizeof(Celula), id_);
    }
    return -1;
}

template <class T>
void ListaEncadeada<T>::print()
{
    if (length_ == 0) throw ExcecaoEmpty{"Lista vazia"};

    Celula *celula = head_->next_;
    LEMEMLOG((long int)(celula), sizeof(Celula), id_);

    while (celula != nullptr)
    {
        cout << *(celula->item_) << endl;
        celula = celula->next_;
        LEMEMLOG((long int)(celula->item_), sizeof(T), id_+100);
        LEMEMLOG((long int)(celula), sizeof(Celula), id_);
    }
}

template <class T>
void ListaEncadeada<T>::clear()
{
    if (length_ == 0) throw ExcecaoEmpty{"Lista vazia"};
    
    Celula *aux = head_->next_;
    LEMEMLOG((long int)(aux), sizeof(Celula), id_);

    while (aux != nullptr) {
        head_->next_ = aux->next_;
        delete aux;
        aux = head_->next_;
        LEMEMLOG((long int)(aux), sizeof(Celula), id_);
    }
    tail_ = head_;
    length_ = 0;
}

#endif