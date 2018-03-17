//
// Created by thiagofsr on 05/03/18.
//

#ifndef APA_SORTNUMBERS_H
#define APA_SORTNUMBERS_H

class SortNumbers
{

  private:
    int *table;
    int *auxTable;
    int size;
    int Swap(int, int);
    void PrintError();
    int StepByStep(int);
    void Quick(int, int);
    int Partition(int, int);
    void Merge(int, int, int);
    void MSort(int, int);

  public:
    SortNumbers();
    int SelectionSort();
    int MergeSort();
    int QuickSort();
    int InsertionSort();
    int HeapSort();
    int RandomTable(int);
    void SetTable(int *, int);
    void ClearTable();
    void PrintTable();
};

#endif //APA_SORTNUMBERS_H
