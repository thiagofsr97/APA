//
// Created by thiagofsr on 16/03/18.
//

#include <cstdio>
#include <algorithm>
#include "Heap.h"
#include <iostream>

#define CMP(a,b) ((a) > (b))

Heap::Heap(int size, const int *table,HeapLabel label) {
    this->heapTable = new int[size];
    std::copy(table,table + size,this->heapTable);
    this->size = size;
    this->length = size;
    isMaxHeap = label;

}

Heap::Heap(int size,HeapLabel label){
    this->heapTable = new int[size];
    this->size = 0;
    this->length = size;
    isMaxHeap = label;
}

void Heap::Swap(int a, int b) {
    int aux;
    aux = heapTable[b];
    heapTable[b] = heapTable[a];
    heapTable[a] = aux;

}

int Heap::GetParent(int i) { 
    if(IsEmpty())
        return -1;
  return (i%2 == 0)? (i/2)-1:(i/2);
}

int Heap::GetLeftChild(int i) {return IsEmpty()? (-1):(2*(i+1))-1;}

int Heap::GetRightChild(int i) {return IsEmpty()? (-1):2*(i+1);}

bool Heap::IsEmpty() {return this->size == 0? true:false;}

bool Heap::IsFull() { return this->size == length? true:false;}

int Heap::GetSize() {return this->size;}

int Heap::GetLenght() { return this->length;}


void Heap::Heapify(int node) {

    int left, right, aux;

    left = GetLeftChild(node);
    right = GetRightChild(node);

    if(isMaxHeap == MAX){
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
        Heapify(aux);
    }

}

void Heap::BuildHeapfied() {

    if(GetSize() == 0) return;

    for(int i = (GetSize()/2) - 1; i>=0;i--)
        Heapify(i);
}

int Heap::Insert(int element){
    if(IsFull())
        return -1;
    heapTable[size++] = element;
    int current,parent;
    current = size-1;
    if(isMaxHeap == MAX){
        while( (parent = GetParent(current)) >-1 && CMP(heapTable[current],heapTable[parent])){
        
            Swap(current,parent);
            current = parent; 
            

        }
    }else{
         while( (parent = GetParent(current)) >= 0 && CMP(heapTable[parent],heapTable[current])){
            Swap(current,parent);
            current = parent; 
        }
    }    
    return 0;
    
}

int Heap::ExtractTop(bool *sucess){
    if(IsEmpty()){
        if(sucess != nullptr)
            *sucess = false;
        return -1;
    }
    if(sucess != nullptr)
        *sucess = true;
    int top = heapTable[0];
    Swap(0,size - 1);
    size--;
    Heapify(0);
    
    return top;

}

int Heap::Sort() {
    if(size == 0)
        return -1;
    BuildHeapfied();
    for(int i = GetSize()-1;i > 0;i--)
    {
        Swap(0,i);
        size--;
        Heapify(0);

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





