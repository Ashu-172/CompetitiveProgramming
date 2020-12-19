/*///////////////////// Q 103: Babbar450: Merge Without Extra Space ///////////////////
Given two sorted arrays arr1[] of size N and arr2[] of size M. Each array is sorted in non-decreasing order. Merge the two arrays into one sorted array in non-decreasing order without using any extra space.

Example 1:

Input:
N = 4, M = 5
arr1[] = {1, 3, 5, 7}
arr2[] = {0, 2, 6, 8, 9}
Output: 0 1 2 3 5 6 7 8 9
Explanation: Since you can't use any 
extra space, modify the given arrays
to form 
arr1[] = {0, 1, 2, 3}
arr2[] = {5, 6, 7, 8, 9}

Example 2:

Input:
N = 2, M = 3
arr1[] = {10, 12}
arr2[] = {5, 18, 20}
Output: 5 10 12 18 20
Explanation: Since you can't use any
extra space, modify the given arrays
to form 
arr1[] = {5, 10}
arr2[] = {12, 18, 20}
 
Your Task:
You don't need to read input or print anything. Complete the function merge() which takes the two arrays arr1[], arr2[] and their sizes n and m, as input parameters. The function does not return anything. Use the given arrays to sort and merge arr1[] and arr2[] in-place. 
Note: The generated output will print all the elements of arr1[] followed by all the elements of arr[2].

Expected Time Complexity: O((n+m)*log(n+m))
Expected Auxiliary Space: O(1)

Constraints:
1 <= N, M <= 5*104
0 <= arr1i, arr2i <= 106
/////////////////////////////////////////////////////////////////////////////////////*/
#include <iostream>

using namespace std;

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

NOTE: Other Solutions present in Question 12
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
            swap(arr1[i], arr2[j]);

        reArrange(arr2, size2);
        i++;
    }
}

int main()
{
    int arr1[] = {1, 3, 5, 7};
    int arr2[] = {0, 2, 6, 8, 9};

    int size1 = sizeof(arr1) / sizeof(int);
    int size2 = sizeof(arr2) / sizeof(int);

    merge(arr1, arr2, size1, size2);
    for (int num : arr1)
        cout << num << " ";

    for (int num : arr2)
        cout << num << " ";
    cout << endl;
}