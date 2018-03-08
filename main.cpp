#include <iostream>
#include "SortNumbers.h"

void PrintWrong(){
    std::cout << "Missing or wrong arguments, exiting program." << std::endl;
    exit(0);
}

int main(int argc, char* argv[]) {
    SortNumbers sortNumbers;
    std::string command;
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

        }
        int i = 0;
        int *array = new int[size];
        std::cout << "Choose your " << size << " numbers: \n" << std::endl;
        int count = size;
        while((count--)){
            std::cin >> aux;
            array[i] = aux;
            i++;

        }
        sortNumbers.SetTable(array,size);

    }

    std::cout << "Before the sorting: " << std::endl;
    sortNumbers.PrintTable();

    command = argv[2];
    if(command == "-i"){
        sortNumbers.InsertionSort();
    }else if(command ==  "-s")
        sortNumbers.SelectionSort();
    else
        PrintWrong();

    std::cout << "After the sorting by " << (command == "-i"? "Insertion ":"Selection " )<< "Sort:" << std::endl;
    sortNumbers.PrintTable();
    sortNumbers.ClearTable();



    return 0;
}