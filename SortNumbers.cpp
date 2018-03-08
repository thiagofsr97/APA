//
// Created by thiagofsr on 05/03/18.
//

#include <iostream>
#include "SortNumbers.h"

SortNumbers::SortNumbers() {
    size = 0;
    table = nullptr;

}

int SortNumbers::SelectionSort() {
    if(size==0){
        PrintError();
        return -1;
    }
    int index, greatest;
    for (int j = size -1; j > 0 ; --j) {
        greatest = table[0];
        index = 0;

        for (int i = 1; i <= j ; ++i)
            if(table[i] > greatest){
                index = i;
                greatest = table[index];
            }
        Swap(index,j);

    }

    return 0;
}

int SortNumbers::InsertionSort() {

    if(size == 0) {
        PrintError();
        return -1;
    }
    int i,aux;
    for(int j = 1; j < size;j++){

        aux = table[j];

        for(i = j; i > 0 ; i--) {
            if (aux < table[i - 1]) {
                table[i] = table[i - 1];

            }
            else
                break;
        }
        table[i] = aux;
    }



    return 0;
}

int SortNumbers::Swap(int i, int j) {

    int aux;
    aux = table[i];
    table[i] = table[j];
    table[j] = aux;
    return 0;
}

int SortNumbers::RandomTable(int size) {
    table = new int[size];
    this->size = size;

    srand((unsigned)time(0));

    for(int i=0; i<size; i++){
        table[i] = (rand()%(size*2))+1;
    }

    std::cout << "Here's your random table..." << std::endl;
    PrintTable();

    return 0;
}

void SortNumbers::SetTable(int *table, int size) {
    this->table = table;
    this->size = size;
}

void SortNumbers::ClearTable() {
    delete []table;
    size = 0;
}

void SortNumbers::PrintError() {
    std::cout << "Invalid table, please generate a new one." << std::endl;

}

void SortNumbers::PrintTable() {
    if(size == 0)
        std::cout << "The table is empty!" << std::endl;

    else{
        for(int i = 0; i < size; ++i)
            std::cout << table[i] << " ";
    }
    std::cout << std::endl;

}
