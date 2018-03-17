//
// Created by thiagofsr on 16/03/18.
//

#include <cstdio>
#include <algorithm>
#include "Heap.h"

#define CMP(a,b) ((a) > (b))

Heap::Heap(int size, const int *table) {
    this->heapTable = new int[size];
    std::copy(table,table + size,this->heapTable);
    this->size = size;
    this->length = size;

}

void Heap::Swap(int a, int b) {
    int aux;
    aux = heapTable[b];
    heapTable[b] = heapTable[a];
    heapTable[a] = aux;

}

int Heap::GetParent(int i) { return IsEmpty()?-1:(i/2)-1;}

int Heap::GetLeftChild(int i) {return IsEmpty()? (-1):(2*(i+1))-1;}

int Heap::GetRightChild(int i) {return IsEmpty()? (-1):2*(i+1);}

bool Heap::IsEmpty() {return this->size == 0? true:false;}

bool Heap::IsFull() { return this->size == length? true:false;}

int Heap::GetSize() {return this->size;}

int Heap::GetLenght() { return this->length;}

void Heap::Heapify(Heap::HeapLabel heap, int node) {
    if(size == 0)
        return;

    switch(heap){
        case MAX:
            HeapifyIt(true,node);
            break;
        case MIN:
            HeapifyIt(false,node);
            break;
    }



}

void Heap::HeapifyIt(bool maxHeapify,int node) {

    int left, right, aux;

    left = GetLeftChild(node);
    right = GetRightChild(node);

    if(maxHeapify ){
        if(left < size && CMP(heapTable[left],heapTable[node]))
            aux = left;
        else
            aux = node;

        if(right < size && CMP(heapTable[right],heapTable[aux]))
            aux = right;

    }else{
        if(left < size && CMP(heapTable[node],heapTable[left]))
            aux = left;
        else
            aux = node;
        if(right < size && CMP(heapTable[aux],heapTable[right]))
            aux = right;
    }

    if(aux != node) {
        Swap(aux, node);
        HeapifyIt(maxHeapify,aux);
    }

}

void Heap::BuildHeapfied(Heap::HeapLabel heap) {

    if(GetSize() == 0) return;

    for(int i = (GetSize()/2) - 1; i>=0;i--)
        Heapify(heap,i);
}

int Heap::Sort() {
    if(size == 0)
        return -1;
    BuildHeapfied(MAX);
    for(int i = GetSize()-1;i > 0;i--)
    {
        Swap(0,i);
        size--;
        Heapify(MAX,0);

    }
    size = length;
    return 0;
}


const int *Heap::GetHeap() {

    return this->heapTable;
}

void Heap::ClearHeap() {
    this->length = 0;
    this->size = 0;
    delete []this->heapTable;
}





