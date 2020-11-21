/*/////////////////////////////////// Q 42 A: Babbar450 : Maximum Area Rectangle  ///////////////////////////////
Given a binary matrix. Find the maximum area of a rectangle formed only of 1s in the given matrix.

Example 1:

Input:
n = 4, m = 4
M[][] = {{0 1 1 0},
         {1 1 1 1},
         {1 1 1 1},
         {1 1 0 0}}
Output: 8
Explanation: For the above test case the
matrix will look like
0 1 1 0
1 1 1 1
1 1 1 1
1 1 0 0
the max size rectangle is 
1 1 1 1
1 1 1 1
and area is 4 *2 = 8.
Your Task: 
Your task is to complete the function maxArea which returns the maximum size rectangle area in a binary-sub-matrix with all 1’s. The function takes 3 arguments the first argument is the Matrix M[ ] [ ] and the next two are two integers n and m which denotes the size of the matrix M. 

Expected Time Complexity : O(n*m)
Expected Auixiliary Space : O(m)

Constraints:
1<=n,m<=1000
0<=M[][]<=1

Note:The Input/Ouput format and Example given are used for system's internal purpose, and should be used by a user for Expected Output only. As it is a function problem, hence a user should not read any input from stdin/console. The task is to complete the function specified, and not to write the full code.
*/
///////////////////////////////////////////////////////////////////////////////////////////////////////////////

#include <iostream>
#include <vector>
#include <stack>

using namespace std;

int maxHistogramArea(vector<int> input)
{
    int size = input.size();
    stack<int> stk;
    int maxArea = 0;
    int i = 0;

    while (i < size)
    {
        if (stk.empty() || input[i] >= input[stk.top()])
            stk.push(i++);
        else
        {
            int top = input[stk.top()];
            stk.pop();

            int area = top * (stk.empty() ? i : (i - stk.top() - 1));
            if (area > maxArea)
            {
                maxArea = area;
            }
        }
    }
    while (stk.empty() != true)
    {
        int top = input[stk.top()];
        stk.pop();

        int area = top * (stk.empty() ? i : (i - stk.top() - 1));
        if (area > maxArea)
        {
            maxArea = area;
        }
    }

    return maxArea;
}

int getMaxRectangle(vector<vector<int>> input)
{
    int row = input.size();
    if (row == 0 || input[0].empty())
        return 0;
    int col = input[0].size();
    int maxArea = 0;

    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            //From 2nd row add num from prev row to current row if its not 0
            //if num at [i][j] is 0, don't add prev row num, since Histogram
            //ended at last row itself.
            if (i > 0)
                if (input[i][j])
                    input[i][j] += input[i - 1][j];
        }

        maxArea = max(maxArea, maxHistogramArea(input[i]));
    }

    return maxArea;
}

int main()
{
    int n, m;
    cin >> m >> n;
    vector<vector<int>> input(m, vector<int>(n));
    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
            cin >> input[i][j];

    cout << getMaxRectangle(input) << endl;
}