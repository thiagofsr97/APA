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
    if(command == "-i"){
        output = sortNumbers.InsertionSort();
    }else if(command ==  "-s")
        output = sortNumbers.SelectionSort();
    else if(command == "-q")
        output = sortNumbers.QuickSort();
    else if(command == "-m")
        output = sortNumbers.MergeSort();
    else if(command == "-h"){
        output = sortNumbers.HeapSort();
    }
    else if(command == "-c")
        output = sortNumbers.CountingSort();
    else if(command == "-r")
        output = sortNumbers.RadixSort();

    else
        PrintWrong();
    switch(command.at(1)){
        case 'i':
            command = "Insertion";
            break;
        case 'q':
            command = "Quick";
            break;
        case 's':
            command = "Selection";
            break;
        case 'm':
            command = "Merge";
            break;
        case 'h':
            command = "Heap";
            break;
        case 'c':
            command = "Counting";
            break;
        case 'r':
            command = "Radix";
            break;
    }
    if(output== 0){
        std::cout << " \n\nAfter the sorting by " << command << " Sort: \n\n";
        sortNumbers.PrintTable();
    }

    sortNumbers.ClearTable();



    return 0;
}