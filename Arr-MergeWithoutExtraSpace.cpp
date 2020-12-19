/*//////////////////// Q 12: Babbar450 : Merge 2 sorted arrays without using Extra space. /////////////////////
Given two sorted arrays arr1[] of size N and arr2[] of size M. Each array is sorted in non-decreasing order. 
Merge the two arrays into one sorted array in non-decreasing order without using any extra space.
////////////////////////////////////////////////////////////////////////////////////////////////////////////*/

#include <iostream>
#include <algorithm>

using namespace std;

/////////////////////////////// Solution 1 ///////////////////////////////////
/*
we can commpare each value of array 2 with all the values of array 1, and whenever we 
encounter array2 value lessthan array1 value we can swap it, and continue comparing from 
the same location in array2.
*/
void mergeArrays(int input1[], int input2[], int size1, int size2)
{
    for (int j = 0; j < size2; j++)
    {
        for (int i = 0; i < size1; i++)
        {
            if (input2[j] < input1[i])
                swap(input2[j], input1[i]);
        }
    }
    //now array1 has smaller values than array2, in sorted order
    //sort array2
    sort(input2, input2 + size2);
}
// time complexity for this solution is O(n^2) + O(n log n)

////////////////////////////////// Solution 2 //////////////////////////////////////////////
/*
we can iterate over first array and compare each value with the first value present in the 
second array, when we are also maintaining dmallest value of arr2 at oth index.
algo:
1.) iterate over array1, and for each element do following
        compare ith value in array1 with first element of arr2
        if arr1[i] is greater than arr[0], swap values
        and re-arrange values in array2 to maintain smallest
        value at 0th index.
2.) to maintain smallest value at 0th index, we just need to move 
    value present at 0th index to its correct place by moving other 
    elements one step left.

Time complexity for this solution is O(n*m)
*/

void reArrange(int input[], int size)
{
    int temp = input[0];
    int i = 1;
    while (input[i] < temp && i < size)
    {
        input[i - 1] = input[i];
        i++;
    }
    input[i - 1] = temp;
}

void merge(int arr1[], int arr2[], int size1, int size2)
{
    int i = 0, j = 0;
    while (i < size1)
    {
        if (arr1[i] > arr2[j])
        {
            swap(arr1[i], arr2[j]);

            reArrange(arr2, size2);
        }
        i++;
    }
}

///////////////////////////////// Solution 3 (Best) ///////////////////////////////////////
/*
since we have 2 sorted arrays, we have two scenarios 
1.  all the elements in array1 are smaller than array two, 
    then no swapping is required, we can directly return.
2.  some of the elements in array 1 are larger than some 
    elements in array 2, then swapping is required to maintain 
    the  order.

if last element of array1 is smaller than first element of array 2
it is the 1st case. we can directly return.
else we have to reorder elements in arrays by swaooing.

One thing to be noted here is if we start swapping elements from end
of first array with element from start of second array until element 
from array 1 is larger than element in array 2, we'll have all the 
smaller elements in array1 and bigger elements in array2.
for example array1= [1,3,5,7] array2= [0,2,6,8,9]
if we swap 7 with 0 => [1,3,5,0] [7,2,6,8,9]
      swap 5 with 2 => [1,3,2,0] [7,5,6,8,9]
now 3 is not greater than 6 we can stop.
now array 1 has all the smaller elements and array2 has all the larger elements.
we can sort both the arrays and return.

there can be maximum n swaps where n is lesses among N and M
time complexity for putting values in correct arrays O(N)

sorting complexity is Nlog N + M log M

final time complexity  = O(N log N) + O(M log M) + O(N or M)

                       = O( n log n) where n is larger among N and M.
*/

int swapAndSort(int input1[], int input2[], int size1, int size2)
{
    int i = size1 - 1;
    int j = 0;
    while (i >= 0 && j < size2)
    {
        if (input1[i] > input2[j])
            swap(input1[i], input2[j]);

        i--;
        j++;
    }
    sort(input1, input1 + size1);
    sort(input2, input2 + size2);
}

int main()
{
    int input1[] = {1, 3, 5, 7};
    int input2[] = {0, 2, 6, 8, 9};

    int size1 = sizeof(input1) / sizeof(int);
    int size2 = sizeof(input2) / sizeof(int);

    //mergeArrays(input1, input2, size1, size2);

    swapAndSort(input1, input2, size1, size2);
    for (int num : input1)
        cout << num << " ";

    for (int num : input2)
        cout << num << " ";
}