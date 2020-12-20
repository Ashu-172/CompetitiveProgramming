/*///////////////////// Q 106: Babbar450: Sort Array By count of Set Bits ///////////////////
Given an array of integers, sort the array (in descending order) according to count of set bits in binary representation of array elements. 

Note: For integers having same number of set bits in their binary representation, sort according to their position in the original array i.e., a stable sort.

 
Example 1:
Input: 
arr[] = {5, 2, 3, 9, 4, 6, 7, 15, 32};
Output:
15 7 5 3 9 6 2 4 32
Explanation:
The integers in their binary
representation are:
15 - 1111
7  - 0111
5  - 0101
3  - 0011
9  - 1001
6  - 0110
2  - 0010
4  - 0100
32 - 10000
hence the non-increasing sorted order is:
{15}, {7}, {5, 3, 9, 6}, {2, 4, 32}
 
Example 2:
Input: 
arr[] = {1, 2, 3, 4, 5, 6};
Output: 
3 5 6 1 2 4
Explanation:
3  - 0110
5  - 0101
6  - 0110
1  - 0001
2  - 0010
4  - 0100
hence the non-increasing sorted order is
{3, 5, 6}, {1, 2, 4}


Your Task:
You don't need to print anything, printing is done by the driver code itself. You just need to complete the function sortBySetBitCount() which takes the array arr[] and its size N as inputs and sort the array arr[] inplace. Use of extra space is prohibited.
 

Expected Time Complexity: O(N.log(N))
Expected Auxiliary Space: O(1)
///////////////////////////////////////////////////////////////////////////////////////////*/
#include <iostream>
#include <algorithm>
#include <map>
#include <vector>

using namespace std;

int oneCount(int input)
{
    int count = 0;
    int temp = input;
    while (temp)
    {
        if (temp & 1)
            count++;
        temp = temp >> 1;
    }

    return count;
}

/////////////////////////// Solution 1 (Based on Counting sort) //////////////////////
/*
This problem can be solved in O(n) time. The idea is similar to counting sort.
Note: There can be a minimum 1 set-bit and only a maximum of 31set-bits in an integer.
Steps (assuming that an integer takes 32 bits):

Create a vector “count” of size 32. Each cell of count i.e., count[i] is another vector that stores all the elements whose set-bit-count is i
Traverse the array and do the following for each element:
Count the number set-bits of this element. Let it be ‘setbitcount’
count[setbitcount].push_back(element)
Traverse ‘count’ in reverse fashion(as we need to sort in non-increasing order) and modify the array.
*/
void SortByBit(int input[], int size)
{
    // Using multimap
    /*
    multimap<int, int> mapping;
    for (int i = 0; i < size; i++)
    {
        int bitCount = oneCount(input[i]);
        mapping.insert(make_pair(bitCount, input[i]));
    }
    int k = 0;
    for (int i = 20; i >= 0; i--)
    {
        auto itr = mapping.equal_range(i);
        while (itr.first != itr.second)
        {
            input[k++] = itr.first->second;
            itr.first++;
        }
    }
    */
    // using vector of<int,<vector<int>>
    vector<vector<int>> count(32);
    int setbitcount = 0;
    for (int i = 0; i < size; i++)
    {
        setbitcount = oneCount(input[i]);
        count[setbitcount].push_back(input[i]);
    }

    int j = 0; // Used as an index in final sorted array

    // Traverse through all bit counts (Note that we
    // sort array in decreasing order)
    for (int i = 31; i >= 0; i--)
    {
        vector<int> v1 = count[i];
        for (int i = 0; i < v1.size(); i++)
            input[j++] = v1[i];
    }
}

/////////////////////////////// Solution 2 (STL stable_sort) ///////////////////////////
/*
we can create a function for comparing bit counts and pass it to STL stable_sort function.
*/
int cmp(int a, int b)
{
    int countA = oneCount(a);
    int countB = oneCount(b);

    // don't swap when countA is less or equal to countB
    if (countA <= countB)
        return false;
    return true;
}

void sortWithSTL(int input[], int size)
{
    stable_sort(input, input + size, cmp);
}

/////////////////////////////////// Solution 3 //////////////////////////////
/*
Method 1: Simple

Create an auxiliary array and store the set-bit counts of all integers in the aux array
Simultaneously sort both arrays according to the non-increasing order of auxiliary array. (Note that we need to use a stable sort algorithm)
Before sort:
int arr[] = {1, 2, 3, 4, 5, 6};
int aux[] = {1, 1, 2, 1, 2, 2}
After sort:
arr = {3, 5, 6, 1, 2, 4}
aux = {2, 2, 2, 1, 1, 1}
*/

int main()
{
    int input[] = {5, 2, 3, 9, 4, 6, 7, 15, 32};
    int size = sizeof(input) / sizeof(int);

    sortWithSTL(input, size);
    for (int i : input)
        cout << i << " ";
}