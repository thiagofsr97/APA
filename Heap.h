//
// Created by thiagofsr on 16/03/18.
//

#ifndef APA_HEAP_H
#define APA_HEAP_H

enum HeapLabel{MAX ,MIN};

class Heap {
private:
    int *heapTable;
    int size;
    int length;
    void Swap(int, int);
    HeapLabel isMaxHeap;
public:    
    
    Heap(int,const int*,HeapLabel);
    Heap(int,HeapLabel);
    void Heapify(int);
    int GetParent(int);
    int GetLeftChild(int);
    int GetRightChild(int);
    bool IsEmpty();
    bool IsFull();
    int GetSize();
    int GetLenght();
    void BuildHeapfied();
    int Sort();
    const int* GetHeap();
    int Insert(int);
    int ExtractTop(bool*);
    void ClearHeap();
};


#endif //APA_HEAP_H
