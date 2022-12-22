#ifdef ORDENACAO_H_

template<class T> 
int Ordenacao<T>::MedianaDeTres(int inicio, int fim, T **A)
{
    int meio = (inicio + fim) / 2;
    T *a = A[inicio];
    T *b = A[meio];
    T *c = A[fim];
    int indicePivo;

    if (a->compara(b) < 0)
    {
        if (b->compara(c) < 0)
            indicePivo = meio;
        else
        {
            if (a->compara(c) < 0)
                indicePivo = fim;
            else
                indicePivo = inicio;
        }
    }
    else
    {
        if (c->compara(b) < 0)
            indicePivo = meio;
        else
        {
            if (c->compara(a) < 0)
                indicePivo = fim;
            else
                indicePivo = inicio;
        }
    }
    return indicePivo;
}

template <class T>
void Ordenacao<T>::Particao(int Esq, int Dir, int *i, int *j, T **A, int ID_QUICKSORT)
{
    *i = Esq; *j = Dir;
    int indicePivo = MedianaDeTres(Esq, Dir, A);

    T *pivo = A[indicePivo];
    LEMEMLOG((long int)(pivo), sizeof(T), ID_QUICKSORT);
    
    do
    {
        while (pivo->compara(A[*i]) < 0) (*i)++;
        while (pivo->compara(A[*j]) > 0) (*j)--;
        if (*i <= *j)
        {
            T *aux = A[*i];
            LEMEMLOG((long int)(aux), sizeof(T), ID_QUICKSORT);

            A[*i] = A[*j];
            LEMEMLOG((long int)(A[*j]), sizeof(T), ID_QUICKSORT);
            ESCREVEMEMLOG((long int)(A[*i]), sizeof(T), ID_QUICKSORT);

            A[*j] = aux;
            ESCREVEMEMLOG((long int)(A[*j]), sizeof(T), ID_QUICKSORT);
            
            (*i)++; 
            (*j)--;
        }
    } while (*i <= *j);
    
}

template <class T>
void Ordenacao<T>::Ordena(int Esq, int Dir, T **A, int ID_QUICKSORT)
{
    int i, j;
    Particao(Esq, Dir, &i, &j, A, ID_QUICKSORT);
    if (Esq < j) Ordena(Esq, j, A, ID_QUICKSORT);
    if (i < Dir) Ordena(i, Dir, A, ID_QUICKSORT);
}

template <class T>
void Ordenacao<T>::QuickSort(T **A, int n, int ID_QUICKSORT)
{
    Ordena(0, n-1, A, ID_QUICKSORT);
}

template <class T>
Ordenacao<T>::Ordenacao(T **A, int n, Method metodo, int ID_QUICKSORT)
{
    switch (metodo)
    {
        case quickSort:
            QuickSort(A, n, ID_QUICKSORT);
            break;
        case mergeSort:
            //TODO: Implementar o método MergeSort
            cout << "Metodo MergeSort" << endl;
            break;
        case heapSort:
            //TODO: Implementar o método HeapSort
            cout << "Metodo HeapSort" << endl;
            break;
        default:
            break;
    }
}

#endif