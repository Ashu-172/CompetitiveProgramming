/*///////////////////////////////// Q5: Babbar450 : Move All Negative elements to one side of array /////////////////////////////
An array contains both positive and negative numbers in random order. Rearrange the array elements so that all negative numbers appear before all positive numbers.
*/
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

////////////////////////////////// Solution 1 (Dutch National Flag or 2-way partition) //////////////////////////////////
/**
 * Two Colours
 * It is easiest to consider just two "colours", {zero,one}, first. The algorithm maintains three sections (possibly empty) in the array a[ ]:

        a[1..Lo-1] zeroes
        a[Lo..Hi] unknown
        a[Hi+1..N] ones
    The unknown section is shrunk while maintaining these conditions:
    Lo := 1; Hi := N;
    while Lo <= Hi do
    Invariant: a[1..Lo-1] are all zero and a[Hi+1..N] are all one; a[Lo..Hi] are unknown.
        if a[Lo] = 0 then Lo++
        else swap a[Lo] and a[Hi]; Hi--
--- 2-way Partitioning ---
//////////////////////////////////////////////////////////////////
We can convert this problem to a varient of Dutch National Flag problem for 2 colours

a[1..lo-1] negatives
a[Lo..Hi] unknown
a[Hi+1..N] positive

Lo=0; Hi=end;
while Lo<Hi
    if a[Lo] < 0 
        Lo++;
    else
        swap(a[Lo], a[Hi]);
        Hi--;

*/
/////////////////////////////////////////////////////////////////////
#include <iostream>

using namespace ::std;

void moveNegatives(int input[], int size) // it can also be  considered as double-pointer approach
{
    int low = 0, high = size;
    while (low < high)
    {
        if (input[low] < 0)
            low++;
        else
            swap(input[low], input[high--]); //not incrementing low because swapped value should also be checked against 0
    }
}

/**
 * Time complexity for this problem is O(n/2) in best case when there are equal number of positives and negatives in the  array
 * Time complexity for this probelm is O(n) in worst case  when all the numbers are either negative or positive in the array
 * 
*/

/////////////////////////////////////////////// Solution 2 (Using Quick Sort Partition)/////////////////////////////////////
/*
by using  standard partition method with 0 instead of pivot, this problem can be solved
*/
void reArrange(int input[], int size)
{
    int pivot = 0;
    int i = 0; //start is 0 since array is from 0 to size
    for (int j = 0; j < size; j++)
    {
        if (input[j] < pivot)
        {
            swap(input[i], input[j]);
            i++;
        }
    }
}
/**
 * Time complexity for Solution 2 is O(n), since it is iterating over all elements of array;
 * 
*/

int main()
{
    int input[] = {-1, 7, -3, 0, 9};
    int size = sizeof(input) / sizeof(int);

    //moveNegatives(input, size - 1); //Solution 1
    reArrange(input, size - 1); //Solution 2
    for (int i : input)
    {
        cout << i << " ";
    }
}