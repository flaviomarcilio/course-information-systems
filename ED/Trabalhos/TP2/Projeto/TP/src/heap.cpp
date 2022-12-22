#ifdef HEAP_H_

/**
 * @brief Constrói um novo Heap
 * 
 * @tparam T 
 * @param A Arranjo
 * @param Count Quantidade de elementos do Heap
 * @param id Identificador no Heap
 */
template <class T>
Heap<T>::Heap(T **A, int Count, int id)
{
    id_ = id;
    int CurrentPosition;
    if (Count <= 0)
    {
        cerr << "Não é possível contruir um heap com tamanho 0 ou menos." << endl;
        exit(1);
    }
    MaxHeapSize = Count;
    HeapSize = Count;
    HeapArrayPtr = A;
    
    CurrentPosition = (HeapSize - 2) / 2;
    while (CurrentPosition >= 0)
    {
        FilterDown(CurrentPosition);
        CurrentPosition--;
    }
}

/**
 * @brief Retira o item de maior prioridade
 * 
 * @tparam T 
 * @return T* 
 */
template <class T>
T* Heap<T>::pop()
{
    T *Temp;
    if (HeapSize == 0)
    {
        cerr << "Não é possível retirar um elemento de Heap vazio!" << endl;
        exit(1);
    }
    Temp = HeapArrayPtr[0];
    LEMEMLOG((long int)(Temp), sizeof(T), id_);

    HeapArrayPtr[0] = HeapArrayPtr[HeapSize - 1];
    LEMEMLOG((long int)(HeapArrayPtr[HeapSize - 1]), sizeof(T), id_);
    ESCREVEMEMLOG((long int)(HeapArrayPtr[0]), sizeof(T), id_);

    HeapSize--;
    FilterDown(0);
    return Temp;
}

/**
 * @brief Percorre o Heap da raiz para a folha
 * 
 * @tparam T 
 * @param StartIndex 
 */
template <class T>
void Heap<T>::FilterDown(int StartIndex)
{
    int CurrentPosition, ChildPosition, RightChildPosition;
    T *Target;

    CurrentPosition = StartIndex;
    Target = HeapArrayPtr[StartIndex];
    LEMEMLOG((long int)(Target), sizeof(T), id_);

    ChildPosition = LeftChild(CurrentPosition);

    while (ChildPosition < HeapSize)
    {
        RightChildPosition = ChildPosition + 1;
        if ((RightChildPosition < HeapSize) && 
            (HeapArrayPtr[ChildPosition]->compara(HeapArrayPtr[RightChildPosition]) < 0))
        {
            ChildPosition = RightChildPosition;
        }
        if (Target->compara(HeapArrayPtr[ChildPosition]) >= 0)
            break;
        HeapArrayPtr[CurrentPosition] = HeapArrayPtr[ChildPosition];
        LEMEMLOG((long int)(HeapArrayPtr[ChildPosition]), sizeof(T), id_);
        ESCREVEMEMLOG((long int)(HeapArrayPtr[CurrentPosition]), sizeof(T), id_);

        CurrentPosition = ChildPosition;
        ChildPosition = LeftChild(CurrentPosition);
    }
    HeapArrayPtr[CurrentPosition] = Target;
    ESCREVEMEMLOG((long int)(HeapArrayPtr[CurrentPosition]), sizeof(T), id_);
}

/**
 * @brief Percorre o Heap da folha para a raiz
 * 
 * @tparam T 
 * @param StartIndex 
 */
template <class T>
void Heap<T>::FilterUp(int StartIndex)
{
    int CurrentPosition, ParentPosition;
    T *Target;

    CurrentPosition = StartIndex;
    ParentPosition = Parent(CurrentPosition);
    Target = HeapArrayPtr[StartIndex];
    LEMEMLOG((long int)(Target), sizeof(T), id_);

    while (CurrentPosition != 0)
    {
        if (HeapArrayPtr[ParentPosition]->compara(Target) >= 0)
            break;

        HeapArrayPtr[CurrentPosition] = HeapArrayPtr[ParentPosition];
        LEMEMLOG((long int)(HeapArrayPtr[ParentPosition]), sizeof(T), id_);
        ESCREVEMEMLOG((long int)(HeapArrayPtr[CurrentPosition]), sizeof(T), id_);
        
        CurrentPosition = ParentPosition;
        ParentPosition = Parent(CurrentPosition);
    }

    HeapArrayPtr[CurrentPosition] = Target;
    ESCREVEMEMLOG((long int)(HeapArrayPtr[CurrentPosition]), sizeof(T), id_);
}

/**
 * @brief Adiciona um novo item ao Heap
 * 
 * @tparam T 
 * @param item 
 */
template <class T>
void Heap<T>::add(T *item)
{
    if (HeapSize == MaxHeapSize)
    {
        cerr << "Não é possível inserir novo elemento em Heap cheio." << endl;
        exit(1);
    }
    HeapArrayPtr[HeapSize] = item;
    ESCREVEMEMLOG((long int)(HeapArrayPtr[HeapSize]), sizeof(T), id_);
    
    FilterUp(HeapSize);
    HeapSize++;
}

#endif