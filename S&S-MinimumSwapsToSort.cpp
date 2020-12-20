/*///////////////////// Q 107: Babbar450: minimum no. of swaps required to sort the array ///////////////////
Given an array of size N. Find the minimum number of swaps required to sort the array in non-decreasing order.

Example 1:

Input: 
N = 5
arr = {1 5 4 3 2}
Output: 2
Explaination: swap 2 with 5 and 3 with 4.
 
Example 2:

Input: 
N = 4
arr[] = {8 9 16 15}
Output: 1
Explaination: swap 16 and 15.

Your Task:
You do not need to read input or print anything. Your task is to complete the function minSwaps() which takes the array arr[] and its size N as input parameters and returns an integer denoting the minimum number of swaps required to sort the array. If the array is already sorted, return 0. 

Expected Time Complexity: O(NlogN)
Expected Auxiliary Space: O(N)

Constraints:
1 <= N <= 105
1 <= A[] <= 106
///////////////////////////////////////////////////////////////////////////////////////////////////////////*/
#include <iostream>
#include <algorithm>
#include <array>

using namespace std;

///////////////////////////////// Solution 1 ///////////////////////
/*
we can get the count of total swap required by comparing array with its sorted version.
1) first we copy the original array in temporary array and sort the temporary array.
2) now we'll search input array's i th element's location in sorted temp array to 
    findout its desired location.
    a) if number is present aat same location (ith index) in both the array, it means 
        ith element in input array is already present aat its corrent place.
    b) if element have different locations in both arrays, it means we need to put ith 
        element of input array at the position where it is present in sorted array, 
        for this we'll swap the numbers present at both the location in input array.
        
        Here since we have swapped values, we need to repeat the process for the new
        number which came at i th position after swapping. so we will not increment i.

since temp array is sorted, we can seaarch i th element from input array, in temp array 
using binary search algorithm.

Time complexity: initial sorting time complexity + searching location in temp for each element.
                    O(n log n) + n * O(log n)
                    2 * O(n log n)
                    O(n log n)

Example: input = [1 5 4 2 3]                temp = [1 2 3 4 5]
         i=0           loc(1) = 0           i == loc => i++                          [1 5 4 2 3]
         i=1           loc(5) = 4           i != loc => swap(input[i], input[loc])   [1 3 4 2 5]  count = 1
         i=1           loc(3) = 2           i != loc => swap(input[i], input[loc])   [1 4 3 2 5]  count = 2
         i=1           loc(4) = 3           i != loc => swap(input[i], input[loc])   [1 2 3 4 5]  count = 3
         i=1           loc(2) = 1           i == loc => i++                          [1 2 3 4 5]
         i=2           loc(3) = 2           i == loc => i++                          [1 2 3 4 5]
         i=3           loc(4) = 3           i == loc => i++                          [1 2 3 4 5]
         i=4           loc(5) = 4           i == loc => i++                          [1 2 3 4 5]
         


*/

int binarySearch(int input[], int size, int num)
{
    int start = 0;
    int end = size - 1;
    while (start <= end)
    {
        int mid = (start + end) / 2;
        if (input[mid] == num)
            return mid;
        else if (input[mid] < num)
            start = mid + 1;
        else
            end = mid - 1;
    }
    return -1;
}

int countRequiredSwaps(int input[], int size)
{
    int temp[size];
    copy(input, input + size, temp);
    sort(temp, temp + size);
    int count = 0;

    for (int i = 0; i < size;)
    {
        int loc = binarySearch(temp, size, input[i]);
        if (loc != i)
        {
            swap(input[i], input[loc]);
            count++;
        }
        else
            i++;
    }
    return count;
}

int main()
{
    int input[] = {1, 5, 4, 2, 3};
    int size = sizeof(input) / sizeof(int);

    cout << countRequiredSwaps(input, size) << endl;
}