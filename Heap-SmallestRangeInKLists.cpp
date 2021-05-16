/*//////////////////////////////// Q 322: Babbar450: Smallest Range in K Sorted Lists ////////////////////////////////////
Given K sorted lists of integers of size N each, find the smallest range that includes at least one element from each of the K lists. If more than one such range's are found, find the first such range found.

Example 1:

Input:
N = 5, K = 3
KSortedArray[][] = {{1 3 5 7 9},
                    {0 2 4 6 8},
                    {2 3 5 7 11}}
Output: 1 2
Explanation: K = 3
A:[1 3 5 7 9]
B:[0 2 4 6 8]
C:[2 3 5 7 11]
Smallest range is formed by number 1
present in first list and 2 is present
in both 2nd and 3rd list.

Expected Time Complexity : O(n * k *log k)
Expected Auxilliary Space  : O(k)

Constraints:
1 <= K,N <= 500
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////*/
#include <iostream>
#include <queue>
#define N 500
using namespace std;

/////////////////////////////////////////// Solution 1 (Naive Approach) ////////////////////////////////
/*
Algorithm: 
1. Create an extra space ptr of length k to store the pointers and a variable minrange initialized to a maximum value.
2. Initially the index of every list is 0, therefore initialize every element of ptr[0..k] to 0, the array ptr will store the index of the elements in the range.
3. Repeat the following steps until atleast one list exhausts: 
    1. Now find the minimum and maximum value among the current elements of all the list pointed by the ptr[0...k] array.
    2. Now update the minrange if current (max-min) is less than minrange.
    3. Increment the pointer pointing to current minimum element.


Complexity Analysis: 
Time complexity : 
    O(n * k2), to find the maximum and minimum in an array of length k the time required is O(k), and to traverse all the k arrays of length n (in worst case), the time complexity is O(n*k), then the total time complexity is O(n*k2).

Space complexity: 
    O(k), an extra array is required of length k so the space complexity is O(k)
*/
pair<int, int> findSmallestRange(int arr[][N], int n, int k)
{
    int ptr[k] = {0};
    int max = INT_MIN, min = INT_MAX;
    int minListIndex = -1;
    int minRange = INT_MAX;
    int low, high;
    bool flag = false;

    while (1)
    {
        /*
        in every iteration we are processing one element from each array and searching for minimum value, once we found it we need to reset the min and max variable and the list index which had smallest value in previous iteration.
        */
        max = INT_MIN;
        min = INT_MAX;
        minListIndex = -1;

        for (int i = 0; i < k; i++)
        {
            // once we reach to end of any of the list, it indicates that all of its elements are removed from to range in order to minimize the range, but last element has to be included so we will come out of loop and set flag using which we'll break the outer loop so that last element will not get extracted from the range.
            if (ptr[i] == n)
            {
                flag = true;
                break;
            }
            /*
            in the result range maximum value will not change while shrinking, only min will change so we need to keep track of the list from which min was extracted from the range, and for that list we'll increment the pointer.
            */
            if (arr[i][ptr[i]] < min)
            {
                minListIndex = i; //final value of minIndex will be choosen
                min = arr[i][ptr[i]];
            }

            if (arr[i][ptr[i]] > max)
                max = arr[i][ptr[i]];
        }

        if (flag == true)
            break;

        ptr[minListIndex]++; // pointing to the next min value in ith list

        if (max - min < minRange) // if range size is reduced we'll change low and high
        {
            minRange = max - min;
            low = min;
            high = max;
        }
    }
    return make_pair(low, high);
}

///////////////////////////////////////////////////////// Solution 2 (using minHeap) //////////////////////////////////////////////////
/*
In the above approach we are searching min and max in the elements pointed by ptr which takes O(k) time.
we can put these elements in a min heap which will give us the min element in log k time.
remaining things are same as previous one.

Complexity Analysis: 
Time complexity : O(n * k *log k). 
    To find the maximum and minimum in an Min Heap of length k the time required is O(log k), and to traverse all the k arrays of length n (in worst case), the time complexity is O(n*k), then the total time complexity is O(n * k *log k).
Space complexity: O(k). 
    The priority queue will store k elements so the space complexity os O(k)
*/

pair<int, int> findSmallestRangeUsingHeap(int arr[][N], int n, int k)
{
    // min heap will store structure <element,<index of list, index of element>>
    priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> minHeap;
    int min = INT_MAX, max = INT_MIN;
    int minRange = INT_MAX;
    int minIndex = -1, listIndex = -1;
    int low, high;

    for (int i = 0; i < k; i++)
    {
        minHeap.push(make_pair(arr[i][0], make_pair(i, 0)));
        if (arr[i][0] > max)
            max = arr[i][0];
    }

    while (1)
    {
        pair<int, pair<int, int>> minNode = minHeap.top();
        minHeap.pop();

        minIndex = minNode.second.second; // will be used to get next value from same list, to insert in the heap
        listIndex = minNode.second.first; // to track the list from which minimum node belogs
        min = minNode.first;

        // calculation for low and high needs to be done with previous max, before calculating new max (if any)
        if (max - min < minRange)
        {
            minRange = max - min;
            low = min;
            high = max;
        }

        // if all elements extracted from any of the list, current min will be considered for the result and next insertion can not be done (break) because we have already removed last element from current list (listIndex).
        if (minIndex == n - 1)
            break;
        else
        {
            // current list still has elements, next element needs to be inserted in min heap for further decreasing the range.
            minHeap.push(make_pair(arr[listIndex][minIndex + 1], make_pair(listIndex, minIndex + 1)));

            // if next element in the current list is greater than the max then max has to be modified, otherwise when the new min will be removed from the heap in future it'll still be compared with the old max.
            if (arr[listIndex][minIndex + 1] > max)
                max = arr[listIndex][minIndex + 1];
        }
    }
    return make_pair(low, high);
}

int main()
{
    int n, k;
    cin >> n >> k;
    int arr[N][N];
    pair<int, int> range;
    for (int i = 0; i < k; i++)
        for (int j = 0; j < n; j++)
            cin >> arr[i][j];
    range = findSmallestRangeUsingHeap(arr, n, k);
    cout << range.first << " " << range.second << endl;

    return 0;
}