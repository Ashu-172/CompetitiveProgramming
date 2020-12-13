/*///////////////// Q 91: Babbar450: Find First and Last position of an element in dorted array //////////////////
Given an array of n distinct integers sorted in ascending order, write a function that returns a Fixed Point in the array, if there is any Fixed Point present in array, else returns -1. Fixed Point in an array is an index i such that arr[i] is equal to i. Note that integers in array can be negative.    
Examples:

  Input: arr[] = {-10, -5, 0, 3, 7}
  Output: 3  // arr[3] == 3 

  Input: arr[] = {0, 2, 5, 8, 17}
  Output: 0  // arr[0] == 0 


  Input: arr[] = {-10, -5, 3, 4, 7, 9}
  Output: -1  // No Fixed Point
  ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////*/
#include <iostream>

using namespace std;

////////////// Solution 1 (Linear Search) //////////////
int linearSearch(int input[], int size)
{
    int i = 0;
    for (i = 0; i < size; i++)
    {
        if (input[i] == i)
            return i;
    }
    return -1;
}

////////////////////// Solution 2 (Binary Search) ///////////////////
int binarySearch(int input[], int size, int start, int end)
{
    if (start <= end)
    {
        int mid = (start + end) / 2;
        if (input[mid] == mid)
            return mid;

        if (input[mid] < mid)
            return binarySearch(input, size, mid + 1, end);
        else
            return binarySearch(input, size, start, mid - 1);
    }
    return -1;
}

main()
{
    int input[] = {-10, -1, 0, 3, 10, 11, 30, 50, 100};
    int size = sizeof(input) / sizeof(input[0]);
    cout << linearSearch(input, size) << endl;
    cout << binarySearch(input, size, 0, size - 1) << endl;
    return 0;
}
