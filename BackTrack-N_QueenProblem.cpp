/*////////////////////////////////// Q 256: Babbar450: N-Queen Problem ///////////////////////////////////
The n-queens puzzle is the problem of placing n queens on a (n×n) chessboard such that no two queens can attack each other.
Given an integer n, find all distinct solutions to the n-queens puzzle. Each solution contains distinct board configurations of the n-queens’ placement, where the solutions are a permutation of [1,2,3..n] in increasing order, here the number in the ith place denotes that the ith-column queen is placed in the row with that number. For eg below figure represents a chessboard [3 1 4 2].

Example 1:

Input:
1
Output:
[1]
Explaination:
Only one queen can be placed in the single cell available.

Example 2:

Input:
4
Output:
[2 4 1 3 ] [3 1 4 2 ]
Explaination:
These are the 2 possible solutions.

Expected Time Complexity: O(n!)
Expected Auxiliary Space: O(n2) 
////////////////////////////////////////////////////////////////////////////////////////////////////////*/
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/*
The idea here is to fill the chess board (matrix) with 1 for all the places where the current queen can attack after giving the queen a place. so whenever we want to insert a new queen in the matrix we just need to check if the place is not filled with 1 by any other previously placed queen.

attacking positions are the row, column and the diagonals.
In each function call we'll try to put the queen for all possible indexes in the next row after putting in the current row.
Algorithm:
    1. check if the current position is safe, if not the returrn. if it is safe then do following:
        a. place the queen at current position by putting the current column value in vector to maintain current arrangement of queens.
        b. fill the row, column and diagonals for the currently placed queen to bloack attacking positions.
        c. if the placed queen is in the last row, then pot arrangement in the result vector and return because we had already put all the queens in the matrix.
        d. call the method resursively in the loop for all the columns present in the next row.


Time complexity for this solution is as following:
                                        O(n)   filling the row
                                        O(n)   filling the column
                                        O(2n)  filling the diagonals
                                        O(n * complexity of function call)   recursively selecting queen 
    since there is a recursive call (for  first queen there is n possibilities, for second queen n-1 possibilities and it'll go to 1.)
                            Total complexity = !n       //(actually O(!n * (n+n+2n))

Here all the complixity of filling the matrix is making this solution very slow.

*/
bool isSafe(int i, int j, int n, vector<vector<int>> matrix)
{
    if (i >= 0 && i < n && j >= 0 && j < n && matrix[i][j] != 1)
        return true;
    return false;
}

void fillRow(int i, int n, vector<vector<int>> &safetyMatrix)
{
    for (int j = 0; j < n; j++)
        safetyMatrix[i][j] = 1;
}

void fillCol(int j, int n, vector<vector<int>> &safetyMatrix)
{
    for (int i = 0; i < n; i++)
        safetyMatrix[i][j] = 1;
}

void fillDia(int i, int j, int n, vector<vector<int>> &safetyMatrix)
{
    for (int ti = i, tj = j; ti >= 0 && tj >= 0; ti--, tj--)
        safetyMatrix[ti][tj] = 1;

    for (int ti = i, tj = j; ti >= 0 && tj < n; ti--, tj++)
        safetyMatrix[ti][tj] = 1;

    for (int ti = i, tj = j; ti < n && tj >= 0; ti++, tj--)
        safetyMatrix[ti][tj] = 1;

    for (int ti = i, tj = j; ti < n && tj < n; ti++, tj++)
        safetyMatrix[ti][tj] = 1;
}

void putQueens(vector<vector<int>> &result, vector<int> &curr, int i, int j, vector<vector<int>> safetyMatrix, int n)
{
    if (isSafe(i, j, n, safetyMatrix))
    {
        curr[i] = j + 1;
        fillRow(i, n, safetyMatrix);
        fillCol(j, n, safetyMatrix);
        fillDia(i, j, n, safetyMatrix);

        // Base condition
        if (i == n - 1)
        {
            result.push_back(curr); // internally a copy will be inserted
            return;
        }

        for (int j = 0; j < n; j++)
        {
            putQueens(result, curr, i + 1, j, safetyMatrix, n);
        }
    }
}
vector<vector<int>> nQueen(int n)
{
    vector<int> curr(n, 0);
    vector<vector<int>> result;
    vector<vector<int>> safetyMatrix(n, vector<int>(n, 0));
    int row = 0;
    for (int col = 0; col < n; col++)
        putQueens(result, curr, row, col, safetyMatrix, n);
    return result;
}

///////////////////////////////////////////////////////// Solution 2 ///////////////////////////////////////////////////////
/* 
in this solution we have done optimization in isSafe method.
Attacking conditions for two queens located at (i,j) and (k,l)
    1. if i == k  (same row)
    2. if j == l  (same column)
    3. if abs(i-k) == abs(j-l)    (same diagonal)

1. The idea here is to check in every recursive call for a valid position of queen in the current row. each recursive call will represent a row in the solution matrix.
2. In each function call (row), iterate over all the columns and search for a valid position by calling isSafe method. this method will check above mentioned attacking conditions, if there is no attack possible on the current position from any of the previously places queens the current position will be considered safe.
3. If current position is safe, insert it in the curr vector which is holding current set of valid positions of queens in previously traversed rows.
4. call the function with incremented i value to search a valid location for queen in the next row.
5. once search is completed, remove the current position from the curr vector to back track.
6. The base condition will met when we traversed the last row (n-1 th) in the result matrix, in this case we'll put current arrangement of queens in the result vector and return.

since there are total n queens and one arrangement looks like [2 4 1 3] for 4 queens, maximum possible ways of arranging the queens can be !n. so the time complexity will be O(!n) or O(!n) * n (here n is for isSafe).
*/
bool isSafe(int i, int j, vector<int> curr, int n)
{
    for (int k = 0; k < curr.size(); k++)
    {
        int l = curr[k];
        if (i == k || j == l || abs(i - k) == abs(j - l))
            return false;
    }
    return true;
}
void setQueens(vector<vector<int>> &result, vector<int> curr, int i, int n)
{
    if (i == n)
    {
        result.push_back(curr);
        return;
    }

    for (int j = 1; j <= n; j++)
    {
        if (isSafe(i, j, curr, n))
        {
            curr.push_back(j);
            setQueens(result, curr, i + 1, n);
            curr.pop_back();
        }
    }
}
vector<vector<int>> nQueen2(int n)
{
    vector<int> curr;
    vector<vector<int>> result;
    int index = 0;
    setQueens(result, curr, index, n);
    return result;
}

int main()
{
    int n;
    cin >> n;

    vector<vector<int>> ans = nQueen2(n);
    if (ans.size() == 0)
        cout << -1 << "\n";
    else
    {
        for (int i = 0; i < ans.size(); i++)
        {
            cout << "[";
            for (int u : ans[i])
                cout << u << " ";
            cout << "] ";
        }
        cout << endl;
    }
    return 0;
}