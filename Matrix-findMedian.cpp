/*/////////////////////////////////// Q 39: Babbar450 : Find Median in a Row wise Sorted Matrix ///////////////////////////////
Given a row wise sorted matrix of size RxC where R and C are always odd, find the median of the matrix.

Example 1:

Input:
R = 3, C = 3
M = [[1, 3, 5], 
     [2, 6, 9], 
     [3, 6, 9]]

Output: 5

Explanation:
Sorting matrix elements gives us 
{1,2,3,3,5,6,6,9,9}. Hence, 5 is median. 
 

Example 2:

Input:
R = 3, C = 1
M = [[1], [2], [3]]
Output: 2
*/
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////

////////////////////////////////////// Solution 1 //////////////////////////////////////
/*
first solution is to copy elements of matrix to an array, and sort the array. then 
middle element will  be the median.
Time complecity for this solution will be O(m*n) + O(m*n log m*n) + O(1) = O(m*n log m*n)
Space complecity will be O(m*n)
*/
///////////////////////////////////// Solution 2 ///////////////////////////////////////
/*
we can directly sort 2-d Array without using addition space. time complexity will ve (m*n)log(m*n)
space complexity will be O(1).
following code is written with merge sort, we can also use Matrix-QuickSort for this.
*/

#include <iostream>
#include <vector>
#include <bits/stdc++.h>

using namespace std;

void merge(vector<vector<int>> &input, int columns, int begin, int mid, int end)
{
    int lLen = mid - begin + 1;
    int rLen = end - mid;

    int left[lLen];
    int right[rLen];

    for (int i = 0; i < lLen; i++)
    {
        left[i] = input[(begin + i) / columns][(begin + i) % columns];
    }

    for (int i = 0; i < rLen; i++)
    {
        right[i] = input[(mid + 1 + i) / columns][(mid + 1 + i) % columns];
    }

    int i = 0, j = 0, k = begin;
    while (i < lLen && j < rLen)
    {
        if (left[i] < right[j])
        {
            input[k / columns][k % columns] = left[i];
            i++;
            k++;
        }
        else
        {
            input[k / columns][k % columns] = right[j];
            j++;
            k++;
        }
    }
    while (i < lLen)
    {
        input[k / columns][k % columns] = left[i];
        i++;
        k++;
    }
    while (j < rLen)
    {
        input[k / columns][k % columns] = right[j];
        j++;
        k++;
    }
}
void mergeSort(vector<vector<int>> &input, int columns, int begin, int end)
{
    if (begin < end)
    {
        int mid = (begin + end) / 2;

        mergeSort(input, columns, begin, mid);
        mergeSort(input, columns, mid + 1, end);
        merge(input, columns, begin, mid, end);
    }
    return;
}
int median(vector<vector<int>> &matrix, int r, int c)
{
    mergeSort(matrix, c, 0, r * c - 1);
    int midIndex = r * c / 2;
    if ((r * c) % 2 == 0)
    {
        return (matrix[midIndex / c][midIndex % c] + matrix[(midIndex - 1) / c][(midIndex - 1) % c]) / 2;
    }
    else
        return matrix[midIndex / c][midIndex % c];
}

/////////////////////////////////////////// solution 3 /////////////////////////////////////
/*
An efficient approach for this problem is to use a binary search algorithm. The idea is that for a number to be median there should be exactly (n/2) numbers which are less than this number. So, we try to find the count of numbers less than all the numbers. Below is the step by step algorithm for this approach: 
Algorithm:  

First, we find the minimum and maximum elements in the matrix. The minimum element can be easily found by comparing the first element of each row, and similarly, the maximum element can be found by comparing the last element of each row.
Then we use binary search on our range of numbers from minimum to maximum, we find the mid of the min and max and get a count of numbers less than our mid. And accordingly change the min or max.
For a number to be median, there should be (r*c)/2 numbers smaller than that number. So for every number, we get the count of numbers less than that by using upper_bound() in each row of the matrix, if it is less than the required count, the median must be greater than the selected number, else the median must be less than or equal to the selected number.
*/

int binaryMedian(vector<vector<int>> m, int r, int c)
{
    int min = INT_MAX, max = INT_MIN;
    for (int i = 0; i < r; i++)
    {
        // Finding the minimum element
        if (m[i][0] < min)
            min = m[i][0];

        // Finding the maximum element
        if (m[i][c - 1] > max)
            max = m[i][c - 1];
    }

    int desired = (r * c + 1) / 2;
    while (min < max)
    {
        int mid = min + (max - min) / 2;
        int place = 0;

        // Find count of elements smaller than mid
        for (int i = 0; i < r; ++i) //Adding count of numbers less than equal to mid
            place += upper_bound(m[i].begin(), m[i].end(), mid) - m[i].begin();

        if (place < desired)
            min = mid + 1;
        else
            max = mid;
    }
    return min;
}

int main()
{
    int m, n;
    cin >> m;
    cin >> n;

    vector<vector<int>> input;

    for (int i = 0; i < m; i++)
    {
        vector<int> row;
        int temp;
        for (int j = 0; j < n; j++)
        {
            cin >> temp;
            row.push_back(temp);
        }
        input.push_back(row);
    }
    //cout << median(input, m, n);
    cout << binaryMedian(input, m, n);
}
