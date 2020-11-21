/*/////////////////////////////////// Q 42 B: Babbar450 : Maximal Squar of 1s  ///////////////////////////////
Given a binary matrix, find out the maximum size square sub-matrix with all 1s.

Input:

The first line of input contains an integer T denoting the number of test cases.
The first line of each test case is n and m,n is the number of rows and m is the number of columns.
The second line of each test case contains array C[n][m] in row major form.

Output:

Print maximum size square sub-matrix.

Constraints:

1 ≤ T ≤ 100
1 ≤ n,m ≤ 50
0 ≤ C[n][m] ≤ 1

Example:

Input:
3
5 6
0 1 0 1 0 1 1 0 1 0 1 0 0 1 1 1 1 0 0 0 1 1 1 0 1 1 1 1 1 1
2 2
1 1 1 1
2 2
0 0 0 0

Output:
3
2
0
*/
//////////////////////////////////////////////////////////////////////////////////

#include <iostream>
#include <vector>

using namespace std;

////////////////////////////////////// Solution 1 (Dynamic Programming)////////////////////////////////////////
/*
The idea here is, if 1 present at an index (i,j) is forming a square of size k, 
then positions (i-1, j), (i, j-1) and (i-1, j-1) would be definitely forming 
Squares of minimum size k-1.
we can start from top left corner (0,0) position and calculate max square size.
Reference: Tushar Roy Video (link in the Sheet)
Time complexity for this solution is O(m*n)
*/

int getMaxSquar(vector<vector<int>> input)
{
    int row = input.size();
    if (row == 0 || input[0].empty())
        return 0;
    int col = input[0].size();
    int area = 0;
    for (int i = 0; i < row; i++)
        for (int j = 0; j < col; j++)
        {
            if (input[i][j] == 1)
            {
                if (i > 0 && j > 0)
                    input[i][j] = min(input[i - 1][j], min(input[i][j - 1], input[i - 1][j - 1])) + 1;
                area = max(area, input[i][j]);
            }
        }

    return area;
}

int main()
{
    int row, col;
    cin >> row >> col;

    vector<vector<int>> input(row, vector<int>(col));
    for (int i = 0; i < row; i++)
        for (int j = 0; j < col; j++)
            cin >> input[i][j];

    cout << getMaxSquar(input) << endl;
}