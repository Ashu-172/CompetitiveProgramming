/*/////////////////////////////////// Q 38: Babbar450 : Search an element in a matrix ///////////////////////////////
Write an efficient algorithm that searches for a value in an m x n matrix. This matrix has the following properties:

Integers in each row are sorted from left to right.
The first integer of each row is greater than the last integer of the previous row
*/
#include <iostream>
#include <vector>

using namespace std;
//Finding row in which number can be present
//Binary search for correct row
int binarySearchColumn(vector<vector<int>> input, int column, int start, int end, int num)
{
    if (start <= end)
    {
        int mid = (start + end) / 2;

        if (input[mid][0] <= num && input[mid][column - 1] >= num)
            return mid;

        if (num < input[mid][0])
            return binarySearchColumn(input, column, start, mid - 1, num);
        else
            return binarySearchColumn(input, column, mid + 1, end, num);
    }
    return -1;
}

//binary search number in a row
bool binarySearchRow(vector<vector<int>> input, int row, int start, int end, int num)
{
    if (start <= end)
    {
        int mid = (start + end) / 2;

        if (input[row][mid] == num)
            return true;

        if (num < input[row][mid])
            return binarySearchRow(input, row, start, mid - 1, num);
        else
            return binarySearchRow(input, row, mid + 1, end, num);
    }
    return false;
}

/*///////////////////////// Brute Force Solution (Linear Search) ////////////////////////////////////
time complexity = O(n*m)
*/
bool searchLinearly(vector<vector<int>> input, int num)
{
    int m = input.size();
    int n = 0;

    if (m == 0)
        return false;
    else
        n = input[0].size();

    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
            if (input[i][j] == num)
                return true;
    return false;
}

//////////////////////////////////////////////// Solution 1 /////////////////////////////////////////
/* we can search for the row in which number is present and then Binary search that Row for the Number
Time complexity = O(m)+O(log n)  = O(m)
*/
bool searchLinearBinary(vector<vector<int>> input, int num)
{
    int m = input.size();
    int n = 0;

    if (m == 0)
        return false;
    else
        n = input[0].size();

    if (n == 0)
        return false;
    int c = n - 1, row = 0;
    for (row = 0; row < m; row++)
    {
        if (num == input[row][c])
            return true;
        if (num < input[row][c])
            break;
    }
    if (row < m)
        return binarySearchRow(input, row, 0, n - 1, num);
    else
        return false;
}

/*///////////////////////////////////////////// Solution 2 /////////////////////////////////////
We can find the correct row in  which number is present using column wise Binary Search, 
and then search the number in that row using Row wise Binary Search .
Time complexity = O(log m) + O( log n)
*/
bool searchBinaryBinary(vector<vector<int>> input, int num)
{
    int m = input.size();
    int n = 0;

    if (m == 0)
        return false;
    else
        n = input[0].size();

    if (n == 0)
        return false;
    int row = binarySearchColumn(input, n, 0, m - 1, num);
    if (row == -1)
        return false;
    return binarySearchRow(input, row, 0, n - 1, num);
}

/*////////////////////////////////////////// Solution 3 binary search as a 1-D Array/////////////////////////////////////////
We can apply Binary search on entire matrix at once, by  calculating row as index/n and column as index%n

Time complexity for this solution is O(log n*m)
*/
bool searscMatrix(vector<vector<int>> input, int num)
{
    int m = input.size();
    int n = 0;

    if (m == 0)
        return false;
    else
        n = input[0].size();

    int begin = 0, end = m * n - 1;
    while (begin <= end)
    {
        int mid = (begin + end) / 2;
        //i = mid/n   j = mid%n
        int midVal = input[mid / n][mid % n];
        if (midVal == num)
            return true;
        else if (midVal < num)
            begin = mid + 1;
        else
            end = mid - 1;
    }
    return false;
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

    int num;
    cin >> num;

    cout << searchLinearly(input, num) << endl;
    cout << searchLinearBinary(input, num) << endl;
    cout << searchBinaryBinary(input, num) << endl;
}
