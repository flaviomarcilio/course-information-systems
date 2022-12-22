#ifndef HEAP_H_
#define HEAP_H_

#include <iostream>

#include "memlog.h"

using namespace std;

template <class T>
class Heap
{
    public:
        Heap(T **A, int Count, int id);
        void add(T *item);
        bool empty() { return HeapSize == 0; };
        T* pop();
    private:
        int id_;
        T **HeapArrayPtr;
        int MaxHeapSize;
        int HeapSize;
        void FilterDown(int StartIndex);
        void FilterUp(int StartIndex);
        int Parent(int CurrentIndex) { return (CurrentIndex - 1) / 2; }
        int RightChild(int CurrentIndex) { return 2 * (CurrentIndex + 1); }
        int LeftChild(int CurrentIndex) { return 2 * CurrentIndex + 1; }
};

#include "../src/heap.cpp"

#endif