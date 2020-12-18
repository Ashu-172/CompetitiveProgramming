/*////////////////////////// Q 99: Babbar450: Find Pair Given Difference ////////////////////////
Given an unsorted array Arr[] and a number N. You need to write a program to find if there exists a pair of elements in the array whose difference is N.

Input:
First line of input contains an integer T which denotes the number of test cases. Then T test cases follows. First line of each test case contains two space separated integers L and N where L denotes the length of array or the number of elements in the array and N denotes the difference between two elements. Second line of each test case contains L space separated integers which denotes the elements of the array.

Output:
For each test case, in a new line print 1 if the pair is found otherwise print -1 if there does not exist any such pair.

Constraints:
1<=T<=100
1<=L<=104
1<=Arr[i]<=105

Example:
Input:
2
6 78
5 20 3 2 5 80
5 45
90 70 20 80 50
Output:
1
-1
///////////////////////////////////////////////////////////////////////////////////////////////*/
#include <iostream>
#include <algorithm>

using namespace std;

////////////////////////////// Solution 1 (Binary Search with Sorting) //////////////////////////
/*
The first step is to sort the array in ascending order. Once the array is sorted, traverse the array from left to right, and for each element arr[i], binary search for arr[i] + n in arr[i+1..n-1]. If the element is found, return the pair.
Both first and second steps take O(nLogn). So overall complexity is O(nLogn).
*/
bool binarySearch(int input[], int start, int end, int num)
{
    while (start <= end)
    {
        int mid = (start + end) / 2;
        if (input[mid] == num)
            return true;

        if (num < input[mid])
            end = mid - 1;
        else
            start = mid + 1;
    }
    return false;
}

int checkPair(int input[], int size, int diff)
{
    sort(input + 0, input + size);
    for (int i = 0; i < size - 1; i++)
    {
        int pairLarge = input[i] + diff;

        if (binarySearch(input, i + 1, size - 1, pairLarge))
            return 1;
    }
    return -1;
}

//////////////////////////////////// Solution 2 (Linear search with sorting) /////////////////////////////////
/*
The second step of the above algorithm can be improved to O(n). The first step remain same. The idea for second step is take two index variables i and j, initialize them as 0 and 1 respectively. Now run a linear loop. If arr[j] – arr[i] is smaller than n, we need to look for greater arr[j], so increment j. If arr[j] – arr[i] is greater than n, we need to look for greater arr[i], so increment i.
*/
int checkPairLinear(int input[], int size, int diff)
{
    int i = 0, j = 1;
    sort(input + 0, input + size);

    while (i < j && j < size)
    {
        if ((input[j] - input[i]) == diff)
            return 1;

        if ((input[j] - input[i]) < diff)
            j++;
        else
            i++;
    }
    return -1;
}

int main()
{
    int size;
    cin >> size;
    int input[size];
    for (int i = 0; i < size; i++)
    {
        cin >> input[i];
    }
    int diff;
    cin >> diff;

    cout << checkPair(input, size, diff) << endl;
    cout << checkPairLinear(input, size, diff) << endl;
}
