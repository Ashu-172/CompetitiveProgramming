/*////////////////////////////////// Q 271: Babbar450: Print All Possible Paths in Matrix from start to end ///////////////////////////////////
The problem is to print all the possible paths from top left to bottom right of a mXn matrix with the constraints that from each cell you can either move only to right or down.

Examples : 

Input : 1 2 3
        4 5 6
Output : 1 4 5 6
         1 2 5 6
         1 2 3 6

Input : 1 2 
        3 4
Output : 1 2 4
         1 3 4

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////*/
#include <iostream>
#include <vector>

using namespace std;
////////////////////////////////////////////////////// Solution /////////////////////////////////////////////
/*
To solve this problem we need to try out all the paths and whenever we reach tot the last position in the matrix, we need to print the path. to do that we need to keep track of the path by storing it in a vector and traverse all the paths recursively. since we are only moving in right or down direction we need not to mark the traversed path  in the matrix because we can not go back to any previously visited position without moving up or left side.

Since we have 2 choices for each position in the matrix, the time complexity will be O((n*m) ^ 2).
the maximum possible length of the path can be n+m, hence the space complexity will be O(n+m).
*/
void findAllPaths(vector<vector<int>> &input, int currR, int currC, vector<pair<int, int>> &moves, vector<int> &path)
{
    //  same as (currR == n-1 && currC == m-1) condition
    if (currR == input.size() - 1 && currC == input[0].size() - 1)
    {
        for (int num : path)
            cout << num << "  ";
        cout << endl;
        return;
    }

    for (pair<int, int> move : moves)
    {
        int r = currR + move.first;
        int c = currC + move.second;
        /*
        if (r >= 0 && c >= 0 && r < input.size() && c < input[0].size() && input[r][c] != -1)
        {
            path.push_back(input[r][c]);
            int temp = input[r][c];
            input[r][c] = -1;
            findAllPaths(input, r, c, moves, path);
            path.pop_back();
            input[r][c] = temp;
        }
        */
        if (r < input.size() && c < input[0].size())
        {
            path.push_back(input[r][c]);
            findAllPaths(input, r, c, moves, path);
            path.pop_back();
        }
    }
}

int main()
{
    int n, m;
    cin >> n >> m;
    vector<vector<int>> input(n, vector<int>(m, 0));

    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> input[i][j];

    //vector<pair<int, int>> moves = {{0, 1}, {1, 0}, {-1, 0}, {0, -1}};
    vector<pair<int, int>> moves = {{0, 1}, {1, 0}};
    vector<int> path;
    path.push_back(input[0][0]);
    int temp = input[0][0];
    input[0][0] = -1;
    findAllPaths(input, 0, 0, moves, path);
    input[0][0] = temp;
}