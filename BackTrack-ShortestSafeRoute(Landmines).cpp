/*////////////////////////////////// Q 265: Babbar450: Find Shortest safe route in area with landmines ///////////////////////////////////
Given a path in the form of a rectangular matrix having few landmines arbitrarily placed (marked as 0), calculate length of the shortest safe route possible from any cell in the first column to any cell in the last column of the matrix. We have to avoid landmines and their four adjacent cells (left, right, above and below) as they are also unsafe. We are allowed to move to only adjacent cells which are not landmines. i.e. the route cannot contains any diagonal moves.

Examples:  

Input: 
A 12 x 10 matrix with landmines marked as 0

[ 1  1  1  1  1  1  1  1  1  1 ]
[ 1  0  1  1  1  1  1  1  1  1 ]
[ 1  1  1  0  1  1  1  1  1  1 ]
[ 1  1  1  1  0  1  1  1  1  1 ]
[.1 .1 .1 .1  1  1  1  1  1  1 ]
[ 1  1  1 .1  1  0  1  1  1  1 ]
[ 1  0  1 .1  1  1  1  1  0  1 ]
[ 1  1  1 .1 .1 .1 .1 .1  1  1 ]
[ 1  1  1  1  1  1  1 .1 .1 .1 ]
[ 0  1  1  1  1  0  1  1  1  1 ]
[ 1  1  1  1  1  1  1  1  1  1 ]
[ 1  1  1  0  1  1  1  1  1  1 ]

Output:  
Length of shortest safe route is 13 (Highlighted with .)
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////*/
#include <iostream>
#include <vector>

using namespace std;

////////////////////////////////////////////////////////// Solution ////////////////////////////////////////////////////
/*
in this problem we need to find out all the paths from first column to last column. for this we need to iterate over all the rows using a loop.
every iteration will find the path from ith element in the first column to last column recursively. we need to keep track of the length of the path in order to find the smallest path.

while finding a path for a particular iteration for every move there are 4 possible moves from which we need to find the safe move which can lead to the solution for this we need to try out all 4 moves using a loop.


since we have 4 choices for each position while finding a path. and there are m levels of recursive calls so The time complexity will be O(4^m) for a path. But we are trying n paths in order to find the final shortest path so the total time complexity will be O(n* (4^m))

Space complexity :
here in every call of findPath method we are creating an n*m matrix and there are total  4^m  recursive calls of findPath function for a path. so the space complexity will be O(4^m *(n*m)) which is not good.
*/
bool isSafe(vector<vector<int>> &input, vector<vector<int>> &path, int row, int col, vector<pair<int, int>> &moves)
{
    if (row < 0 || col < 0 || row >= input.size() || col >= input[0].size() || path[row][col] == 1)
        return false;
    else
    {
        for (int i = 0; i < moves.size(); i++)
        {
            int r = row + moves[i].first;
            int c = col + moves[i].second;
            if (r < input.size() && r >= 0 && c < input[0].size() && c >= 0 && input[r][c] == 0)
                return false;
        }
    }
    return true;
}

void printPath(vector<vector<int>> path, int n, int m)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cout << path[i][j] << "  ";
        }
        cout << endl;
    }
    cout << endl;
}

bool findPath(vector<vector<int>> &input, int n, int m, vector<vector<int>> &path, int row, int col, int &len, vector<pair<int, int>> &moves)
{
    if (col == m)
        return true;

    int localMinLen = INT_MAX;
    vector<vector<int>> minLenPath; // can not modify path variable for each iteration so need a new variable

    if (isSafe(input, path, row, col, moves) == true)
    {
        path[row][col] = 1;
        len++;
        int locLen;
        vector<vector<int>> locPath;
        for (int i = 0; i < 4; i++)
        {
            locLen = len;
            locPath = path;
            if (findPath(input, n, m, locPath, row + moves[i].first, col + moves[i].second, locLen, moves) == true)
            {
                if (locLen < localMinLen)
                {
                    localMinLen = locLen;
                    minLenPath = locPath;
                }
            }
        }
    }

    if (minLenPath.empty() != true)
    {
        path = minLenPath;
        len = localMinLen;
        return true;
    }
    return false;
}

void findShortestSafePath(vector<vector<int>> &input, int n, int m, vector<vector<int>> &result)
{
    vector<vector<int>> minLenPath;
    vector<vector<int>> path;
    vector<pair<int, int>> moves{{0, 1}, {1, 0}, {-1, 0}, {0, -1}};

    int minLen = INT_MAX;
    for (int i = 0; i < n; i++)
    {
        path = result;
        int len = 0;
        if (findPath(input, n, m, path, i, 0, len, moves) == true)
        {
            if (len < minLen)
            {
                minLen = len;
                minLenPath = path; // copying path
            }
        }
        //printPath(path, n, m);
    }
    cout << endl
         << endl;
    result = minLenPath;
}

///////////////////////////////////////////////////////// Solution 2 /////////////////////////////////////////////////////
/*
Following is the Optimize solution, approach is similar to the above solution but here we are creating only a single matrix to track the travrsed cells, instead of copying it again and again in every recursive call.
The main difference in the implementation is, in previous solution we were first checking whether the current cell is safe or not, if it is then we were marking it as visited in the same function call. But in this solution we are checking the cell is safe or not and then we are marking it as visited in the next function call. we are always checking safty of the nearby cells which can be visited, not the current cell (like previous solution).

Time complexity for this solution will be same O(n*(4^m)) but it is much faster than the previous solution since we added some conditions to check whether we are on a correct path or not.
Space complexity in this solution is very less as compared to the previous solution. we are using only one matrix "visited" to track the path so the space complexity will be O(n*m).
*/

bool isSafePlace(vector<vector<int>> &input, vector<pair<int, int>> &moves, int row, int col, vector<vector<int>> &visited)
{
    if (row < 0 || col < 0 || row >= input.size() || col >= input[0].size() || visited[row][col] == 1)
        return false;
    else
    {
        for (int i = 0; i < moves.size(); i++)
        {
            int r = row + moves[i].first;
            int c = col + moves[i].second;
            if (r < input.size() && r >= 0 && c < input[0].size() && c >= 0 && input[r][c] == 0)
                return false;
        }
    }
    return true;
}
void findShortestPathUtil(vector<vector<int>> &input, vector<vector<int>> &result, vector<vector<int>> &visited, vector<pair<int, int>> &moves, int row, int col, int &minDist, int dist)
{
    // reached to the end
    if (col == input[0].size() - 1)
    {
        visited[row][col] = 1; // when reached to last column
        if (dist < minDist)
        {
            minDist = dist;
            result = visited;
        }
        //printPath(visited, visited.size(), visited[0].size());
        return;
    }

    // if current path is greater than the smallest path found till now, then no need to check further
    if (dist > minDist)
        return;

    visited[row][col] = 1;
    for (int i = 0; i < 4; i++)
    {
        int r = row + moves[i].first;
        int c = col + moves[i].second;
        if (isSafePlace(input, moves, r, c, visited) == true)
        {
            findShortestPathUtil(input, result, visited, moves, r, c, minDist, dist + 1);
        }
    }
    visited[row][col] = 0;
}
void findShortestPath(vector<vector<int>> &input, vector<vector<int>> &result, int n, int m)
{
    int minDis = INT_MAX;

    vector<vector<int>> visited = result;
    vector<pair<int, int>> moves{{0, 1}, {1, 0}, {-1, 0}, {0, -1}};
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            for (int k = 0; k < m; k++)
            {
                visited[j][k] = 0;
            }
        }
        // safety check for (i,0)
        if (isSafePlace(input, moves, i, 0, visited) == true)
            findShortestPathUtil(input, result, visited, moves, i, 0, minDis, 0);

        // if shortest possible path found then no need to search further
        if (minDis == m - 1)
            break;
    }
    return;
}

int main()
{
    int n, m;
    cin >> n >> m;

    vector<vector<int>> input;

    for (int i = 0; i < n; i++)
    {
        vector<int> temp;
        int num;
        for (int j = 0; j < m; j++)
        {
            cin >> num;
            temp.push_back(num);
        }
        input.push_back(temp);
    }

    vector<vector<int>> result(n, vector<int>(m, 0));

    //findShortestSafePath(input, n, m, result);
    findShortestPath(input, result, n, m);
    printPath(result, n, m);
}
