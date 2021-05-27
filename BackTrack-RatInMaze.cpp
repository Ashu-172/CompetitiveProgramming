/*////////////////////////////////// Q 255: Babbar450: Rat In a Maze ///////////////////////////////////
Consider a rat placed at (0, 0) in a square matrix of order N * N. It has to reach the destination at (N - 1, N - 1). Find all possible paths that the rat can take to reach from source to destination in lexicographical order. The directions in which the rat can move are 'U'(up), 'D'(down), 'L' (left), 'R' (right). Value 0 at a cell in the matrix represents that it is blocked and rat cannot move to it while value 1 at a cell in the matrix represents that rat can be travel through it.
Note: In a path, no cell can be visited more than one time.

Example 1:

Input:
N = 4
m[][] = {{1, 0, 0, 0},
         {1, 1, 0, 1}, 
         {1, 1, 0, 0},
         {0, 1, 1, 1}}
Output:
DDRDRR DRDDRR
Explanation:
The rat can reach the destination at (3, 3) from (0, 0) by two paths - DRDDRR and DDRDRR, when printed in sorted order we get DDRDRR DRDDRR.
Example 2:
Input:
N = 2
m[][] = {{1, 0},
         {1, 0}}
Output:
-1
Explanation:
No path exists and destination cell is blocked.

Expected Time Complexity: O((N^2)^4).
Expected Auxiliary Space: O(L * X), L = length of the path, X = number of paths.

Constraints:
2 ≤ N ≤ 5
0 ≤ m[i][j] ≤ 1
//////////////////////////////////////////////////////////////////////////////////////////////////////*/
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
/////////////////////////////////////////////// Solution ///////////////////////////////////////////////
/*
in a matrix there can me multiple path possible from start to end cell, he need to try every path from start cell (top left) and if it reaches to the last node (bottom right) we need to put the path in result vector. but while traversing a path if we found that this path can not reach to the end cell (encountered 0) we will back track to the previous cell and try other path, Hence it is a Backtracking problem.

Algorithm:
    1. while traversing we are allowed to move to a cell for which value is 1 and it is not already traversed in current path. to check this we need a function which will tell whether current cell is safe to move or not. since we need info of previous moves in the current path, we need to maintain a matrix which will hold this info.

    2. check current cell m[i][j] is safe of not. if it is then set path[i][j] = 1 indicating we have traversed till m[i][j] in current path.
        2.1. call the function for all possibile moves (left, right, up and down), the info stored in path matrix will be passed to these calls so that previously traversed cells will not get traversed again in the same path.
        2.2. after traversing all the possible paths from current cell m[i][j], its time to back track to previous cell (i.e. parent function call). for this we need to reset value of path[i][j] to 0 again so that other paths from parent function call can traverse m[i][j] again. and from here we can return.

    3. if current cell m[i][j] is not safe then return.
    4. Base condition: when we reach to the last cell m[n-1][n-1] we can put the current path in the result vector and return from there.
*/
bool isSafe(vector<vector<int>> arr, int n, int i, int j, vector<vector<int>> path)
{
    if (i >= 0 && i < n && j >= 0 && j < n && arr[i][j] == 1 && path[i][j] != 1)
        return true;
    return false;
}
void findPathBT(vector<vector<int>> arr, int n, int i, int j, vector<vector<int>> path, string prefix, vector<string> &result)
{
    if (i == n - 1 && j == n - 1)
    {
        result.push_back(prefix);
        return;
    }

    if (isSafe(arr, n, i, j, path))
    {
        path[i][j] = 1;

        findPathBT(arr, n, i + 1, j, path, prefix + 'D', result);
        findPathBT(arr, n, i - 1, j, path, prefix + 'U', result);
        findPathBT(arr, n, i, j + 1, path, prefix + 'R', result);
        findPathBT(arr, n, i, j - 1, path, prefix + 'L', result);

        /* here if we are using int[][] instead of vector<vector<int>> for the path variable, we need to reset the path[i][j] value to 0 since we have traversed it and passed to further calls also, now when we back track after returning, this cell should not be marked as untouched so that it can be traversed again while exploring other path by some parent function call.
        if we don't reset it here, it will remain marked as traversed and will not be considered in any other path by some parent function call.
        this reset is required only when we are using arr[i][i] not vector because while passing arrays to function calls it will be passed as reference so if value is modified in some child function call, value remain modified  for all the subsequent calls so we need to reset it. 
        when using vector, copy constructor will be called while passing to a function call, so after completing the function call that copy will get destroyed and vector will remain as it is in parent call. so no need to reset values. so we can comment path[i][j] = 0 line.

        // path[i][j] = 0;

        But here one more thing is to notice, when we use vector, on every function call a copy of the vector will be created and passed to the function. this copying takes extra space on the stack memory and also take some time to create a copy (which was giving TLE on geeksforgeeks)
        to reduce this we can pass vector by reference so that the original vector reference will be passed and no copy will be created. in this case we need to reset the value of path[i][j] = 0 once we process all the possible paths from the current cell.
        */
        path[i][j] = 0;
    }
}

vector<string> findPath(vector<vector<int>> &m, int n)
{
    int i = 0, j = 0;
    string prefix = "";
    vector<string> result;
    vector<vector<int>> path(n, vector<int>(n, 0));

    if (m[0][0] == 1 && m[n - 1][n - 1] == 1)
        findPathBT(m, n, i, j, path, prefix, result);

    // if lexicographical order is required
    sort(result.begin(), result.end());
    return result;
}
/*
Since we have 3 paths from each cells, the Time complexity for this solution is O(3^N) where N is total number of elements in the metrix which is n*n. so we can say time coplexity = O(3^(n*n))
Space complexity for this solution is O(n*n) since we are using a matrix for tracking the path.
*/

int main()
{
    int n;
    cin >> n;
    vector<vector<int>> m(n, vector<int>(n, 0));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> m[i][j];
        }
    }
    vector<string> result = findPath(m, n);
    if (result.size() == 0)
        cout << -1;
    else
        for (int i = 0; i < result.size(); i++)
            cout << result[i] << " ";
    cout << endl;

    return 0;
}