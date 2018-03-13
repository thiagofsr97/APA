//
// Created by thiagofsr on 05/03/18.
//

#include <iostream>
#include "SortNumbers.h"

SortNumbers::SortNumbers()
{
    size = 0;
    table = nullptr;
    auxTable = nullptr;
}

/* the algorithm will sort the numbers by selecting the greatest and putting in your correct position,
     which means in the last positions. */
/* the same can be done by selecting the smallest number */

int SortNumbers::SelectionSort()
{
    if (size == 0)
    {
        PrintError();
        return -1;
    }
    int index, greatest;
    // int z = 0;

    /* loops that decrements, limiting the inner loop.*/
    for (int j = size - 1; j > 0; --j)
    {

        //always assume that the greatest is in the first position of the array.
        greatest = table[0];
        index = 0;

        // z = StepByStep(z);

        // loops starts at index 1, avoiding one comparison of a number with itself.
        /* here the greatest number is searched and then assigned to 
        the current j index from the outter loop */
        for (int i = 1; i <= j; ++i)
            if (table[i] > greatest)
            {
                index = i;
                greatest = table[index];
            }

        Swap(index, j);
    }

    return 0;
}

int SortNumbers::QuickSort()
{ // this function will be used as a trigger to the recursive quick sort function
    if (size == 0)
    {
        PrintError();
        return -1;
    }
    Quick(0, size - 1);
}
void SortNumbers::Quick(int inf, int sup)
{
    if (!(inf < sup)) // the partition is already sorted, nothing must be done
        return;
    int pivot = Partition(inf, sup);
    Quick(inf, pivot - 1); // the left partition will be sorted
    Quick(pivot + 1, sup); // the right partition will be sorted
}

int SortNumbers::Partition(int inf, int sup)
{
    int left, right, pivot, aux;

    pivot = table[inf]; // always choosing the first member of the current table
    left = inf;
    right = sup;
    while (left < right)
    {
        while (left < sup && table[left] <= pivot) /*advancing while the number is smaller than the pivot
                                                   and the left marker is smaller than the sup index (in case
                                                   all the numbers are smaller than the pivot)*/
            left++;

        while (table[right] > pivot) //there's no need to check if right > inf
            right--;                 //because the pivot is the first number in the current partition

        if (left < right) //that means the numbers are not in the correct partition, then they must be swaped
            Swap(left, right);
    }

    //At the end of this process, there's one last swap to go:
    //put the pivot in its correct position.

    Swap(inf, right);

    return right; //this will be the new index to the pivot
}

//Trigger function to the merge sort method, that will also allocate space to the auxilary table.
int SortNumbers::MergeSort(){
    if(size==0){
        PrintError();
        return -1;
    }
    auxTable = new int[size];
    MSort(0,size - 1);

    delete auxTable; // deallocating space already used.


}

// Function that will merge two partitions, intercalating between them.

void SortNumbers::Merge(int leftInit, int center, int rightEnd)
{

    int partitionSize;
    int leftEnd;
    int auxPosition;
    int initRight;

    partitionSize = rightEnd - leftInit + 1; //size of the current partition
    leftEnd = center;
    auxPosition = leftInit;
    initRight = center + 1;

    //the first step is use the aux table to merge the elements from each partition, sorted.
    while ((leftInit <= leftEnd) && (initRight <= rightEnd))
        if (table[leftInit] <= table[initRight])
            auxTable[auxPosition++] = table[leftInit++];
        else
            auxTable[auxPosition++] = table[initRight++];

    //the second step is to store the left elements in each partition, now there's no need
    //to compare which is greater because one of the partitions will be already copied.

    while (leftInit <= leftEnd)
        auxTable[auxPosition++] = table[leftInit++];
    while (initRight <= rightEnd)
        auxTable[auxPosition++] = table[initRight++];

    //the last step it to copy the auxTable back to the original table.
    // as the rightEnd is the only index that hasn't changed, it will be used to go through the partition
    // in the copying process (being decremented).
    for (int i = 0; i < partitionSize; i++, rightEnd--)
        table[rightEnd] = auxTable[rightEnd];
}

//Recursive function that will be dividing the table into partitions until it gets to 1 element
// then will merge them.
void SortNumbers::MSort(int leftInit, int rightEnd)
{
    if (leftInit >= rightEnd) //base case, there's only one element in the partition, it's already sorted.
        return;
    int center = (leftInit + rightEnd) / 2; // the center will always be floor of the division (no rounding)
    
    MSort(leftInit, center);
    MSort(center + 1, rightEnd);
   
    Merge(leftInit, center, rightEnd);
    
}

/* the algorithm will go through the entire array and by incrementing the index will sort the numbers from
the beggining until this index */

int SortNumbers::InsertionSort()
{

    if (size == 0)
    {
        PrintError();
        return -1;
    }
    int i, aux;
    // int z  = 0;
    /* loop that limits the beginning of the inner loop, telling where to start from.
    This way the idea of insertion is shown.*/
    for (int j = 1; j < size; j++)
    {
        // z = StepByStep(z);
        aux = table[j];
        /* loop that checks all the numbers from the current j index (that increments 1 by 1)
         until the beginning, sorting the numbers*/
        for (i = j; i > 0; i--)
        {
            /* at each interaction, there will be two parts in the array,
             the sorted one (left side) and the unsorted one (right side) */
            /*this means that if a number in the position i - 1 is not greater 
            than the number in the position i, then the loop can break, once the same will happen with 
            the left numbers in the sorted side. */

            if (aux < table[i - 1])
            {
                table[i] = table[i - 1]; /* if the previous number is greater than the current, it must
                 be assigned to the current i position. note that the smallest number is saved in the aux
                 variable. */
            }
            else
                break;
        }
        table[i] = aux; /* at the end of the inner loop, the smallest number
        in the comparisons made is assigned to its correct position. */
    }

    return 0;
}

int SortNumbers::Swap(int i, int j)
{

    int aux;
    aux = table[i];
    table[i] = table[j];
    table[j] = aux;
    return 0;
}

int SortNumbers::RandomTable(int size)
{
    table = new int[size];
    this->size = size;

    srand((unsigned)time(0));

    for (int i = 0; i < size; i++)
    {
        table[i] = (rand() % (size * 2)) + 1;
    }

    std::cout << "Here's your random table..." << std::endl;
    PrintTable();

    return 0;
}

void SortNumbers::SetTable(int *table, int size)
{
    this->table = table;
    this->size = size;
}

/* Function to deallocate memory of the dynamic array */
void SortNumbers::ClearTable()
{
    delete[] table;
    size = 0;
}

void SortNumbers::PrintError()
{
    std::cout << "Invalid table, please generate a new one." << std::endl;
}

void SortNumbers::PrintTable()
{
    if (size == 0)
        std::cout << "The table is empty!" << std::endl;

    else
    {
        for (int i = 0; i < size; ++i)
            std::cout << table[i] << " ";
    }
    std::cout << std::endl;
}

/* Function used to debug, showing the processing of sorting step by step*/
int SortNumbers::StepByStep(int count)
{
    std::cout << "Step " << count + 1 << ":";
    for (int i = 0; i < size; i++)
    {
        std::cout << " " << table[i] << " ";
    }
    std::cout << std::endl;
    return count + 1;
}
