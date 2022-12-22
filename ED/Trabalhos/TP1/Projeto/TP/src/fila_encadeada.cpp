#ifdef FILA_ENCADEADA_H_

#include <iostream>

#include "../include/memlog.h"

using std::cout;
using std::endl;

template <class T>
FilaEncadeada<T>::FilaEncadeada(int id)
{
    id_ = id;
    length_ = 0;
    head_ = new Celula();
    ESCREVEMEMLOG((long int)(head_), sizeof(Celula), id_);
    tail_ = head_;
}

template <class T>
FilaEncadeada<T>::~FilaEncadeada()
{
    if (length_ > 0)
        clear();

    delete head_;
}

template <class T>
int FilaEncadeada<T>::size()
{
    return length_;
}

template <class T>
bool FilaEncadeada<T>::empty()
{
    return length_ == 0;
}

template<class T> 
void FilaEncadeada<T>::push_back(T &item)
{
    Celula *cell = new Celula();
    cell->item_ = new T(item);
    tail_->next_ = cell;
    tail_ = cell;
    length_++;

    ESCREVEMEMLOG((long int)(cell), sizeof(Celula), id_);
    ESCREVEMEMLOG((long int)(cell->item_), sizeof(T), id_+100);
}

template<class T> 
T FilaEncadeada<T>::pop_front()
{
    if (length_ == 0) throw ExcecaoEmpty{"Fila vazia"};
    
    T *item = head_->next_->item_;
    LEMEMLOG((long int)(item), sizeof(T), id_+100);

    Celula *cell = head_;
    LEMEMLOG((long int)(cell), sizeof(Celula), id_);

    head_ = head_->next_;
    ESCREVEMEMLOG((long int)(head_), sizeof(Celula), id_);

    delete cell;
    length_--;

    return *item;
}

template <class T>
void FilaEncadeada<T>::print()
{
    if (length_ == 0) throw ExcecaoEmpty{"Fila vazia"};

    Celula *cell = head_->next_;
    LEMEMLOG((long int)(cell), sizeof(Celula), id_);

    while (cell != nullptr)
    {
        cout << *(cell->item_) << endl;
        LEMEMLOG((long int)(cell->item_), sizeof(T), id_+100);

        cell = cell->next_;
        LEMEMLOG((long int)(cell), sizeof(Celula), id_);
    }
}

template <class T>
void FilaEncadeada<T>::clear()
{
    if (length_ == 0) throw ExcecaoEmpty{"Fila vazia"};

    Celula *cell = head_->next_;
    LEMEMLOG((long int)(cell), sizeof(Celula), id_);
    
    while (cell != nullptr)
    {
        head_->next_ = cell->next_;
        LEMEMLOG((long int)(cell->next_), sizeof(Celula), id_);

        delete cell;
        cell = head_->next_;
        LEMEMLOG((long int)(cell), sizeof(Celula), id_);
    }
    length_ = 0;
    head_ = tail_;
}

#endif