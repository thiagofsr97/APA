 
/** 
 *  @file    main.cpp
 *  @author  Thiago Filipe Soares da Rocha
 *  @date    03/05/2018  
 *  @version 1.0 
 *  
 *  @brief Sorting of tables of numbers by using the most classic
 *  sorting methos.
 *  
 *  @section DESCRIPTION
 *  
 *  This is a little program that reads a list of numbers from
 *  a specified file or from standard input and then sorts
 *  them in ascending order and prints them to standard
 *  output.
 * 
 *  Command line arguments are used to specify which method
 *  is going to be used, the source of the input. In case the
 *  standard input is chosen, so it needs to be specified also 
 *  the size of the list and if is going to be used a random generated
 *  selection or not.
 *
 */

#include <iostream>
#include "SortNumbers.h"

void PrintWrong(){
    std::cout << "Missing or wrong arguments, exiting program." << std::endl;
    exit(0);
}

int main(int argc, char* argv[]) {
    SortNumbers sortNumbers;
    std::string command;
    int output;
    if(argc < 4) {
        PrintWrong();
    }

    command = argv[1];
    if(command != "-sort")
        PrintWrong();

    command = argv[3];
    if(command == "-r"){
        sortNumbers.RandomTable(atoi(argv[4]));
    }
    else if((command == "-c") || command == "-f") {
        int aux = 0;
        int size = 0;
        if(command == "-f"){
            std::cin >> size;
        }else{
            command = argv[4];
            size = atoi(command.c_str());
            std::cout << "Choose your " << size << " numbers: \n" << std::endl;

        }
        int i = 0;
        int *array = new int[size];

        int count = size;
        while((count--)){
            std::cin >> aux;
            array[i] = aux;
            i++;

        }
        sortNumbers.SetTable(array,size);

    }

    std::cout << "Before the sorting: \n\n";
    sortNumbers.PrintTable();

    command = argv[2];        
    switch(command.at(1)){
        case 'i':
            output = sortNumbers.InsertionSort();
            command = "Insertion";
            break;
        case 'q':
            output = sortNumbers.QuickSort();
            command = "Quick";
            break;
        case 's':
            output = sortNumbers.SelectionSort();
            command = "Selection";
            break;
        case 'm':
            output = sortNumbers.MergeSort();
            command = "Merge";
            break;
        case 'h':
            output = sortNumbers.HeapSort();
            command = "Heap";
            break;
        case 'c':
            output = sortNumbers.CountingSort();
            command = "Counting";
            break;
        case 'r':
            output = sortNumbers.RadixSort();
            command = "Radix";
            break;
        default:
            PrintWrong();

    }
    if(output== 0){
        std::cout << " \n\nAfter the sorting by " << command << " Sort: \n\n";
        sortNumbers.PrintTable();
    }

    sortNumbers.ClearTable();



    return 0;
}