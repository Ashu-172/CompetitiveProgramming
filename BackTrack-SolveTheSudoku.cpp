/*////////////////////////////////// Q 259: Babbar450: Solve The Sudoku ///////////////////////////////////
Given an incomplete Sudoku configuration in terms of a 9 x 9  2-D square matrix (grid[][]), the task to find a solved Sudoku. For simplicity, you may assume that there will be only one unique solution.

Example 1:

Input:
grid[][] = 
[[3 0 6 5 0 8 4 0 0],
[5 2 0 0 0 0 0 0 0],
[0 8 7 0 0 0 0 3 1 ],
[0 0 3 0 1 0 0 8 0],
[9 0 0 8 6 3 0 0 5],
[0 5 0 0 9 0 6 0 0],
[1 3 0 0 0 0 2 5 0],
[0 0 0 0 0 0 0 7 4],
[0 0 5 2 0 6 3 0 0]]
Output:
3 1 6 5 7 8 4 9 2
5 2 9 1 3 4 7 6 8
4 8 7 6 2 9 5 3 1
2 6 3 4 1 5 9 8 7
9 7 4 8 6 3 1 2 5
8 5 1 7 9 2 6 4 3
1 3 8 9 4 7 2 5 6
6 9 2 3 5 1 8 7 4
7 4 5 2 8 6 3 1 9

Your Task:
You need to complete the two functions:
SolveSudoku(): Takes a grid as its argument and returns true if a solution is possible and false if it is not.
printGrid(): Takes a grid as its argument and prints the 81 numbers of the solved Sudoku in a single line with space separation.


Expected Time Complexity: O(9N*N).
Expected Auxiliary Space: O(N*N).


Constraints:
0 ≤ grid[i][j] ≤ 9
/////////////////////////////////////////////////////////////////////////////////////////////////////////*/
#include <iostream>
#include <vector>
#include <unordered_set>
#include <cmath>

using namespace std;

#define UNASSIGNED 0
#define N 9
///////////////////////////////////////////////// Solution /////////////////////////////////////////
/*
    Algorithm:

    1. find place where number has to be filled in the sudoku.
    2. for all the numbers from 1 to N do following:
        a. check if the place is safe to fill i in the sudoku
        b. if it is safe then fill the value i in the current empty place
        c. recursively call SolveSudoku which will fill all the empty places and return true.
        d. if it returns false means i is not the correct value for the current place, so unassign i from current place and repeat same for next value of i.
    3. if no value of i is suitable or safe for current place, return false.
    4. THe base condition is when the there is no more empty places present in the sudoku.

    Complexity Analysis:  
    Time complexity: O(9^(n*n)). 
    For every unassigned index, there are 9 possible options so the time complexity is O(9^(n*n)). 
    Space Complexity: O(n*n). 
    */
class Solution
{
public:
    bool isSafe(int grid[N][N], int num, int i, int j)
    {
        for (int c = 0; c < N; c++)
            if (grid[i][c] == num)
                return false;

        for (int r = 0; r < N; r++)
            if (grid[r][j] == num)
                return false;

        int n = sqrt(N + 1); // for N=9  n should be 3
        // calculating starting of sub matrix
        int rSub = i / n;
        int cSub = j / n;

        int startRow = rSub * n;
        int startCol = cSub * n;

        for (int r = startRow; r < startRow + n; r++)
            for (int c = startCol; c < startCol + n; c++)
            {
                if (grid[r][c] == num)
                    return false;
            }

        return true;
    }

    bool findNextPlace(int grid[N][N], int &row, int &col)
    {
        for (int i = 0; i < N * N; i++)
        {
            if (grid[i / N][i % N] == 0)
            {
                row = i / N;
                col = i % N;
                return true;
            }
        }
        return false;
    }
    //Function to find a solved Sudoku.

    bool SolveSudoku(int grid[N][N])
    {
        int row, col;
        if (findNextPlace(grid, row, col) == false)
            return true;

        for (int i = 1; i <= N; i++)
        {
            if (isSafe(grid, i, row, col))
            {
                grid[row][col] = i;

                if (SolveSudoku(grid) == true)
                    return true;
                else
                    grid[row][col] = UNASSIGNED;
            }
        }
        return false;
    }

    //Function to print grids of the Sudoku.
    void printGrid(int grid[N][N])
    {
        for (int i = 0; i < N * N; i++)
        {
            cout << grid[i / N][i % N] << " ";
        }
    }
};

int main()
{
    int grid[N][N];

    for (int i = 0; i < 9; i++)
        for (int j = 0; j < 9; j++)
            cin >> grid[i][j];

    Solution ob;

    if (ob.SolveSudoku(grid) == true)
        ob.printGrid(grid);
    else
        cout << "No solution exists";

    cout << endl;
    return 0;
}