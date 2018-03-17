//
// Created by thiagofsr on 16/03/18.
//

#ifndef APA_HEAP_H
#define APA_HEAP_H


class Heap {
private:
    int *heapTable;
    int size;
    int length;
    void HeapifyIt(bool,int);
    void Swap(int, int);
public:
    Heap(int,const int*);
    enum HeapLabel{MAX ,MIN};
    void Heapify(HeapLabel ,int);
    int GetParent(int);
    int GetLeftChild(int);
    int GetRightChild(int);
    bool IsEmpty();
    bool IsFull();
    int GetSize();
    int GetLenght();
    void BuildHeapfied(HeapLabel);
    int Sort();
    const int* GetHeap();
    void ClearHeap();
};


#endif //APA_HEAP_H
