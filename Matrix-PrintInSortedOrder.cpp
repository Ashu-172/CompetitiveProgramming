/*/////////////////////////////////// Q 41: Babbar450 : Print Elements in Sorted order  ///////////////////////////////
Given an n x n matrix, where every row and column is sorted in non-decreasing order. Print all elements of matrix in sorted order.

Input:
The first line of input contains an integer T denoting the number of test cases. Then T test cases follow. Each test case contains an integer n denoting the size of the matrix. Then the next line contains the n x n elements in row wise order.

Output:
Print the elements of the matrix in sorted order.

Constraints:
1<=T<=100
1<=n<=100
1<=a[n][n]<=100

Example:
Input:
2
4
10 20 30 40 15 25 35 45 27 29 37 48 32 33 39 50
3
1 3 4 2 6 7 5 8 9

Output:
10 15 20 25 27 29 30 32 33 35 37 39 40 45 48 50 
1 2 3 4 5 6 7 8 9
*/
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
#include <iostream>
#include <vector>

using namespace std;
//////////////////////////////////////////// Solution 1 //////////////////////////////////////////
/*
We can use Young Tableau to solve the above problem. The idea is to consider given 2D array as Young Tableau and call extract. 
Time complexity of extractMin function is O(n) which is called n * n times, 
Total Time Complexity is O(n^3).
*/
//moving next smallest element to index (0, 0)
void youngify(vector<vector<int>> &input, int row, int col)
{
    int size = input.size();
    int down = (row + 1) < size ? input[row + 1][col] : INT_MAX;
    int right = (col + 1) < size ? input[row][col + 1] : INT_MAX;

    if (down == INT_MAX && right == INT_MAX)
        return;

    //move smaller value among right and down to [row][col]
    if (down < right)
    {
        input[row][col] = down;
        input[row + 1][col] = INT_MAX;
        youngify(input, row + 1, col);
    }
    else
    {
        input[row][col] = right;
        input[row][col + 1] = INT_MAX;
        youngify(input, row, col + 1);
    }
}

int extractMin(vector<vector<int>> &input)
{
    int num = input[0][0];
    input[0][0] = INT_MAX;
    youngify(input, 0, 0);
    return num;
}

int printSorted(vector<vector<int>> &input)
{
    int size = input.size();
    for (int i = 0; i < size * size; i++)
        cout << extractMin(input) << " ";
}

////////////////////////////////////////////////// Solution 2 /////////////////////////////////////////
/*
Better solution is to sort the Matrix with merge sort or quik sort, time complexity for 
this solution will be O( n^2 log n^2).
*/
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
int main()
{
    int m;
    cin >> m;
    vector<vector<int>> input(m, vector<int>(m));
    for (int i = 0; i < m; i++)
        for (int j = 0; j < m; j++)
            cin >> input[i][j];

    //printSorted(input);
    mergeSort(input, m, 0, m * m - 1);
    for (int i = 0; i < m; i++)
        for (int j = 0; j < m; j++)
            cout << input[i][j] << " ";
}