/** 
 *  @file    Heap.h
 *  @author  Thiago Filipe Soares da Rocha
 *  @date    03/05/2018  
 *  @version 1.0 
 *  
 *  @brief Header file of Heap class.
 *
 */

#ifndef APA_HEAP_H
#define APA_HEAP_H
#define CMP(a,b) ((a) > (b))

enum HeapLabel{MAX ,MIN};

class Heap {
private:
    int *heapTable;
    int size;
    int length;
    void Swap(int, int);
    HeapLabel isMaxHeap;
public:    
    ~Heap();    
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
    const int & GetHeap();
    int Insert(int);
    int ExtractTop(bool*);
    void ClearHeap();
};


#endif //APA_HEAP_H
