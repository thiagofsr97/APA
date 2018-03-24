 
/** 
 *  @file    SortNumbers.cpp
 *  @author  Thiago Filipe Soares da Rocha
 *  @date    03/05/2018  
 *  @version 1.0 
 *  
 *  @brief Implementation of a plenty of Sorting Methods.
 *
 */

#include <iostream>
#include "SortNumbers.h"
#include "Heap.h"
#include <algorithm>
#include <vector>
#include <iterator>

 /*** 
  * Initialize the arrays with a nullptr and sets size to 0.
  *
  * @param none.
  * @return none
  */

SortNumbers::SortNumbers()
{
    size = 0;
    table = nullptr;
    auxTable = nullptr;
}


bool SortNumbers::IsEmpty() {
    return size == 0? true:false;
}

/*** 
  * Sorts a table of numbers by selecting the greatest and moving
  * to its correct position (at the end of the array).
  * @param none.
  * @return -1 if the table is empty or 0 if the sort was done correctly.
  */
int SortNumbers::SelectionSort()
{
    if (IsEmpty())
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

        /* loops starts at index 1, avoiding one comparison of a number with itself.
         here the greatest number is searched and then assigned to
        the current j index from the outter loop */
        for (int i = 1; i <= j; ++i)
            if (table[i] > greatest)
            {
                index = i;
                greatest = table[index];
            }

        Swap(index, j);
    }
}

/*** 
  * Used as a trigger to the recursive quick sort function.
  *
  * @param none.
  * @return -1 if table is empty or 0 if sort was a success.
  */
int SortNumbers::QuickSort(){ 
    if (IsEmpty())
    {
        PrintError();
        return -1;
    }
    Quick(0, size - 1);
    return 0;
}

/*** 
  * The table will be divided recursively according to the pivot.
  * The selection of the pivot is done by picking always the first member
  * of the partition.
  * The sorting will be done by putting every element smaller than pivot to its left 
  * and greatest to its right side.
  * @param [in] inf the inferior limit of the current partition.
  * @param [in] sup the superior limit of the current partition.
  * @return none.
  */

void SortNumbers::Quick(int inf, int sup)
{
    if (!(inf < sup)) // the partition is already sorted, nothing must be done
        return;
    int pivot = Partition(inf, sup);
    Quick(inf, pivot - 1); // the left partition will be sorted
    Quick(pivot + 1, sup); // the right partition will be sorted
}

/*** 
  * Given a interval in the array, the sorting process is properly done
  * by exchanging elements between smaller and greater number than the pivot. 
  * @param [in] inf the inferior limit of the current partition.
  * @param [in] sup the superior limit of the current partition.
  * @return the correct position of the pivot in the partition.
  */
int SortNumbers::Partition(int inf, int sup)
{
    int left, right, pivot, aux;

    pivot = table[inf]; /// always choosing the first member of the current table
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

    /* At the end of this process, there's one last swap to go:
    put the pivot in its correct position. */

    Swap(inf, right);

    return right; //this will be the new index to the pivot
}

/*** 
  * The array will be recursively divided in the half until a partition contains
  * only one element. After that, the halfs will be merge, sorting the numbers
  * into an auxilary array by intercalation.
  * @param none
  * @return -1 if the table is empty or 0 if sort was a sucess.
  */
int SortNumbers::MergeSort(){
    if(size==0){
        PrintError();
        return -1;
    }
    auxTable = new int[size];
    MSort(0,size - 1);

    delete auxTable; // deallocating space already used.
    return 0;

}

/*** 
  * The divisions in the half are properly done until a partition if one element is reached.
  * @param [in] leftInit the index corresponding to the beginning of the partition.
  * @param [in] rightEnd the index corresponding to the ending of the partition.
  * @return none
  */
void SortNumbers::MSort(int leftInit, int rightEnd)
{
    if (leftInit >= rightEnd) ///base case, there's only one element in the partition, it's already sorted.
        return;
    int center = (leftInit + rightEnd) / 2; ///the center will always be floor of the division (no rounding)

    MSort(leftInit, center);
    MSort(center + 1, rightEnd);

    Merge(leftInit, center, rightEnd);

}

/*** 
  * Intercalation is properly done between the partitions, sorting it.
  * @param [in] leftInit the index corresponding to the beginning of the partition.
  * @param [in] center the index corresponding to the middle of the partition.
  * @param [in] rightEnd the index corresponding to the ending of the partition.
  * @return none
  */

void SortNumbers::Merge(int leftInit, int center, int rightEnd)
{

    int partitionSize;
    int leftEnd;
    int auxPosition;
    int initRight;

    partitionSize = rightEnd - leftInit + 1; ///size of the current partition
    leftEnd = center;
    auxPosition = leftInit;
    initRight = center + 1;

    ///the first step is use the aux table to merge the elements from each partition, sorted.
    while ((leftInit <= leftEnd) && (initRight <= rightEnd))
        if (table[leftInit] <= table[initRight])
            auxTable[auxPosition++] = table[leftInit++];
        else
            auxTable[auxPosition++] = table[initRight++];

    /* the second step is to store the left elements in each partition, now there's no need
    to compare which is greater because one of the partitions will be already copied. */

    while (leftInit <= leftEnd)
        auxTable[auxPosition++] = table[leftInit++];
    while (initRight <= rightEnd)
        auxTable[auxPosition++] = table[initRight++];

    /* the last step it to copy the auxTable back to the original table.
    as the rightEnd is the only index that hasn't changed, it will be used to go through the partition
    in the copying process (being decremented). */
    for (int i = 0; i < partitionSize; i++, rightEnd--)
        table[rightEnd] = auxTable[rightEnd];

}




/*** 
  * Goes through the entire array and by incrementing the index will sort the numbers from
  * the beggining until this index.
  * @param none
  * @return -1 if table is empty or 0 if sort was a sucess.
  */
int SortNumbers::InsertionSort()
{
    if (IsEmpty())
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

/*** 
  * Uses either a max heap or min heap to sort a table of numbers.
  * The only process needed to be done is the extraction of the top. (greatest or smallest)
  * @param none
  * @return -1 if table is empty or 0 if sort was a sucess.
  */

int SortNumbers::HeapSort() {
    if(IsEmpty()){
        PrintError();
        return -1;
    }
    Heap heap(size,MAX);
    for(int i = 0; i<size;i++)
        heap.Insert(table[i]);

    for(int i = size -1; i>=0;i--){
        table[i] = heap.ExtractTop(nullptr);
    }
    heap.ClearHeap();
    return 0;
}

/*** 
  * There's no comparisons in this method. The sorting is done by a process of calculating
  * the frequency of exibition of a element and how many there're smaller than it.
  * @param none
  * @return -1 if table is empty or 0 if sort was a sucess.
  */
int SortNumbers::CountingSort(){
     if(IsEmpty()){
        PrintError();
        return -1;
    }

    /* Additional loop to check if there's negative number in the table, which will not work
    with the method. */
    for(int i = 0; i<size;i++){
        if(table[i]<0){
            std::cout << "This method doesn't work with negative numbers" << std::endl;
            return -1;
        }
    }

    int biggestElement = Greatest(table,size);
    auxTable = new int[biggestElement + 1]();

    int sortedTable[size];

    /// Calculating the frequency of repetetion of the numbers in the array
    for(int i=0; i<size;i++){
        auxTable[table[i]]++;
    }


    /// Making acumulative calculation to know where each number must stand.
    for(int i = 1; i<biggestElement+1;i++){
        auxTable[i]+=auxTable[i-1];
    }

    /* Filling the sortedTable according to each position determined by the acumlative calculation.
    As the array is 0 indexed, so the access in the sortedTable must be decremented by 1. */
    for(int i = size;i>=0;i--){
        sortedTable[auxTable[table[i]]-1] = table[i];
        auxTable[table[i]]--;
    }

    std::copy(sortedTable,sortedTable +size,table);

    delete []auxTable;
    return 0;

}

/*** 
  * There's no comparisons in this method. The sorting is done by dividing each number
  * into groups of digits (i.e units, tens, hundreds...), this way being sorted from the less
  * significative digits to the most significative. This process is supported by the Counting Sort
  * method.
  * @param none
  * @return -1 if table is empty or 0 if sort was a sucess.
  */

int SortNumbers::RadixSort(){
    if(IsEmpty()){
        PrintError();
        return -1;
    }

    //Additional loop to check if there's negative number in the table, which will not work
    //with the method.
    for(int i = 0; i<size;i++){
        if(table[i]<0){
            std::cout << "This method doesn't work with negative numbers" << std::endl;
            return -1;
        }
    }

    int greatest = Greatest(table,size); /// needed to know how many digits there're in a number at most.

    /* this loop will run untils all groups of digits are sorted by the counting sort method. */
    for(int exp = 1;(greatest/exp) > 0;exp*=10){
        auxTable = new int[10]();
        int *sortedArray = new int[size]();

        for(int i = 0; i<size;i++){
            auxTable[(table[i]/exp)%10]++;
        }

        for(int i = 1; i<10;i++){
            auxTable[i]+=auxTable[i-1];
        }

        for(int i = size -1;i>=0;i--){
            sortedArray[auxTable[(table[i]/exp)%10]-1] = table[i];
            auxTable[(table[i]/exp)%10]--;
        }

        std::copy(sortedArray,sortedArray + size,table);

        delete[]sortedArray;
        delete[]auxTable;

    }

    return 0;

}


/*** 
  * Utilitary function to swap position between two numbers in the array.
  * @param [in] i first index.
  * @param [in] j second index.
  * @return none.
  */
void SortNumbers::Swap(int i, int j)
{
    int aux;
    aux = table[i];
    table[i] = table[j];
    table[j] = aux;
    
}

/*** 
  * Utilitary function to generate a random array of numbers.
  * @param [in] size how many numbers the arrray will hold.
  * @return none.
  */
void SortNumbers::RandomTable(int size)
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
}

/*** 
  * It sets a already existing table as the table from the object.
  * @param [in] table pointer to an array.
  * @param [in] size how many numbers the arrray holds.
  * @return none.
  */
void SortNumbers::SetTable(int *table, int size)
{
    this->table = table;
    this->size = size;
}

/*** 
  * Deallocates the dynamic array and sets size to 0.
  * @param none.
  * @return none.
  */
void SortNumbers::ClearTable()
{
    delete[] table;
    size = 0;
}

/*** 
  * It prints an entire table.
  * @param none.
  * @return none.
  */
void SortNumbers::PrintTable()
{
    if (IsEmpty())
        std::cout << "The table is empty!" << std::endl;

    else
    {
        for (int i = 0; i < size; ++i)
            std::cout << table[i] << " ";
    }
    std::cout << "\n\n";
}

/*** 
  * Used to debug, showing the processing of sorting step by step by the method Selection
  * and Insertion Sort.
  * @param [in] count Current Step of the method.
  * @return count + 1 the next step of the method.
  */
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

