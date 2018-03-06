# APA
APA activity. Implementation of sorting methods: Selection Sort and Insertion Sort.

# How to use it!

- The compilation of the file is as simple as it follows:
Go straight to the root of the project using the terminal and enter the command make.
- In order to run the program properly, you must run it from the terminal by typing the following parameters according to which sorting method and which way to select the numbers you want to use: ./SortingNumbers "1st param" "2nd param" "3rd param" "4th param"
  
- The parameters must be chosen as it follows:
  - 1st: "-sort".
  - 2nd: "-s" or "-i" indicating Selection Sort or Insertion Sort.
  - 3rd: "-r" or "-c" indicating Random Selection or Chosen Selection of numbers.
  - 4th: "Integer Number" indicating how many numbers you want to sort.
  
 # Examples of usage
   - ./SortingNumbers -sort -s -r 10 ---> Here you will sort an amount of 10 numbers chosen randomly by using the Selection Sort method.
   - ./SortingNumbers -sort -i -c 20 ---> On the other hand, you will have to choose 20 numbers that will be sorted by the Insertion Sort method.
 
