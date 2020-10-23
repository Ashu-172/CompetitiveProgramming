/*///////////////////////////////// Q4: Babbar450 : Sort an array of 0s, 1s and 2s /////////////////////////////

Given an array A of size N containing 0s, 1s, and 2s; you need to sort the array in ascending order.

Input:
The first line contains an integer 'T' denoting the total number of test cases. Then T testcases follow. Each testcases contains two lines of input. The first line denotes the size of the array N. The second lines contains the elements of the array A separated by spaces.

Output: 
For each testcase, print the sorted array.

Constraints:
1 <= T <= 500
1 <= N <= 106
0 <= Ai <= 2

Example:
Input :
2
5
0 2 1 2 0
3
0 1 0

Output:
0 0 1 2 2
0 0 1

////////////////////////////////////////////////////////////////////////////////////////////*/

#include <iostream>

using namespace ::std;

///////////////////////////////////////////// Solution 1 (Best Approach) /////////////////////////////////////

void sortArray(int input[], int size)
{

    int counter[3] = {0}; //initializing array with 0

    for (int i = 0; i < size; i++)
    {
        counter[input[i]]++; // counting the occurrences of 0, 1 and 2.
    }

    int k = 0; //keep track of next location in input array while copying values

    for (int i = 0; i < 3; i++) // iterating for 0,1,2
    {
        for (int j = 0; j < counter[i]; j++) // iterating for number of occurrences of 0, 1 and 2.
            input[k++] = i;
    }
}
/**
 * Best Concievable  RunTime (BCR) will be O(n) because in order to put every element at right place we need atleast one travesal.
 * 
 * time complexity for solution 1 is calculated as follows
 *        time complexity for filling counter array = O(n)
 *        time complexity for filling up result array(i.e. input[]) using counter array = O(3)*O(k)
 *                          where k is the maximum count present in counter array, 
 *                              in avrg/best case k = n/3 (when number of 0s,1s and 2s are equal).
 *                              in worst case k = n (when only 0s or 1s or 2s are present).
 * 
 *                          final Time Complexity = O(n) + O(3) * O(k)
 *                                                = O(n) + O(n/3) (avrg case)  or O(n) + O(n) (worst case)
 *                                                = O(n)
 */

////////////////////////////// Solution 2 (Dutch National Flag Algorithm or 3-way partitioning )////////////////////////////////
/*
Three Colours

The problem was posed with three colours, here `0', `1' and `2'. The array is divided into four sections:

    a[1..Lo-1] zeroes (red)
    a[Lo..Mid-] ones (white)
    a[Mid..Hi] unknown
    a[Hi+1..N] twos (blue)
The unknown region is shrunk while maintaining these conditions

    Lo := 1; Mid := 1; Hi := N;
    while Mid <= Hi do
    Invariant: a[1..Lo-1]=0 and a[Lo..Mid-1]=1 and a[Hi+1..N]=2; a[Mid..Hi] are unknown.
    case a[Mid] in
        0: swap a[Lo] and a[Mid]; Lo++; Mid++
        1: Mid++
        2: swap a[Mid] and a[Hi]; Hi--
--- Dutch National Flag Algorithm, or 3-way Partitioning ---
*/
void threeWayPartition(int input[], int size)
{

    int low = 0, mid = 0, high = size - 1;

    while (mid < high)
    {
        switch (input[mid])
        {
        case 0:
            swap(input[low++], input[mid++]);
            break;

        case 1:
            mid++;
            break;

        case 2:
            swap(input[mid], input[high--]); //mid we are not incrementing because new value can be 0 or 1,
                                             //has to be checked in next iteration
            break;
        }
    }
}
//Time complexity for this solution will be O(2n/3) = O(n) for avrg case when number of 2s are 1/3rd of size then loop will iterate 2/3 times of n.
// for worst case complexity will be O(n) when there no 2 present in array.
int main()
{
    int input[] = {1, 2, 0, 0, 1, 1, 2, 1, 0};
    int size = sizeof(input) / sizeof(int);

    //sortArray(input, size);
    threeWayPartition(input, size);

    for (int i : input)
        cout << i << " ";
}