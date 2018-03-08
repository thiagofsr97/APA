//
// Created by thiagofsr on 05/03/18.
//

#ifndef APA_SORTNUMBERS_H
#define APA_SORTNUMBERS_H


class SortNumbers {

private:
    int* table;
    int size;
    int Swap(int, int);
    void PrintError();
    int StepByStep(int);


public:
    SortNumbers();
    int SelectionSort();
    int InsertionSort();
    int RandomTable(int);
    void SetTable(int*,int);
    void ClearTable();
    void PrintTable();

};


#endif //APA_SORTNUMBERS_H
