 
/** 
 *  @file    SortNumbers.h
 *  @author  Thiago Filipe Soares da Rocha
 *  @date    03/05/2018  
 *  @version 1.0 
 *  
 *  @brief Header File of SortNumbers class.
 *
 */

#ifndef APA_SORTNUMBERS_H
#define APA_SORTNUMBERS_H
#define Greatest(arr,size) *(std::max_element(arr,arr + size))
#define PrintError() std::cout << "Invalid table, please generate a new one." << std::endl

class SortNumbers
{

  private:
    int *table;
    int *auxTable;
    int size;
    void Swap(int, int);
    int StepByStep(int);
    void Quick(int, int);
    int Partition(int, int);
    void Merge(int, int, int);
    void MSort(int, int);
    bool IsEmpty();

  public:
    SortNumbers();
    int SelectionSort();
    int MergeSort();
    int QuickSort();
    int InsertionSort();
    int HeapSort();
    int CountingSort();
    int RadixSort();
    void RandomTable(int);
    void SetTable(int *, int);
    void ClearTable();
    void PrintTable();
};

#endif //APA_SORTNUMBERS_H
