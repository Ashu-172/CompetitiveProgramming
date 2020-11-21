/*/////////////////////////////////// Q 40: Babbar450 : Find Row with Max Number of 1s ///////////////////////////////
Given a boolean 2D array of n x m dimensions where each row is sorted. Find the 0-based index of the first row that has the maximum number of 1's.

Example 1:

Input: 
N = 4 , M = 4
Arr[][] = {{0, 1, 1, 1},
           {0, 0, 1, 1},
           {1, 1, 1, 1},
           {0, 0, 0, 0}}
Output: 2
Explanation: Row 2 contains 4 1's (0-based
indexing).

Example 2:

Input: 
N = 2, M = 2
Arr[][] = {{0, 0}, {1, 1}}
Output: 1
Explanation: Row 1 contains 2 1's (0-based
indexing).
*/
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
#include <iostream>
#include <vector>

using namespace std;

/*///////////////////////////////////////// Solution //////////////////////////////////
A simple method is to do a row wise traversal of the matrix, count the number of 1s in each row and compare the count with max. Finally, return the index of row with maximum 1s. The time complexity of this method is O(m*n) where m is number of rows and n is number of columns in matrix.

We can do better. Since each row is sorted, we can use Binary Search to count of 1s in each row. We find the index of first instance of 1 in each row. The count of 1s will be equal to total number of columns minus the index of first 1.
*/

int binarySearchUpperBound(vector<int> row, int start, int end, int num)
{
    if (start == end)
    {
        /* start == end we be true when 
            1. we found 1st 1, in this case return start
            2. we didn't find any 1 and reached to last index, 
                in this case return start+1 which is nothing but cols*/
        if (row[start] > num)
            return start;
        else
            return start + 1;
    }
    int mid = (start + end) / 2;

    if (row[mid] > num)
        return binarySearchUpperBound(row, start, mid, num);
    else
        return binarySearchUpperBound(row, mid + 1, end, num);
}

int rowWithMax1s(vector<vector<int>> input, int rows, int cols)
{
    int max = 0, maxIndex = 0;
    bool isPresent = false; //to check we found any 1 or not
    for (int i = 0; i < rows; i++)
    { // if 1 is not present in current row, result will be cols, count  = 0
        int count = cols - binarySearchUpperBound(input[i], 0, cols, 0);
        if (count > max)
        {
            max = count;
            maxIndex = i;
            isPresent = true;
        }
    }
    //if 1 is not present in any row, return -1
    if (isPresent != true)
        return -1;
    return maxIndex;
}

int main()
{
    int m, n;
    cin >> m >> n;
    vector<vector<int>> input(m, vector<int>(n));
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> input[i][j];
        }
    }
    cout << rowWithMax1s(input, m, n);
}