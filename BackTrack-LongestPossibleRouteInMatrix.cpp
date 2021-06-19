/*////////////////////////////////// Q 270: Babbar450: Longest Possible Route in a Matrix with Hurdles  ///////////////////////////////////
Given an M x N matrix, with a few hurdles arbitrarily placed, calculate the length of longest possible route possible from source to destination within the matrix. We are allowed to move to only adjacent cells which are not hurdles. The route cannot contains any diagonal moves and a location once visited in a particular path cannot be visited again.

Example: 

         .1 .1  1 .1..1  1 .1..1..1..1 
             .     .  .     .        .
         .1 .1  0 .1  1  0 .1 .1  0 .1 
         .         .  .     .  .     .
         .1..1..1..1 .1..1..1 .1..1..1 
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////*/
#include <iostream>
#include <vector>

using namespace std;

/////////////////////////////////////////////////////////// Solution ////////////////////////////////////////////////////////////////
/*
The idea is to use Backtracking. We start from the source cell of the matrix, move forward in all four allowed directions and recursively checks if they leads to the solution or not. If destination is found, we update the value of longest path else if none of the above solutions work we return false from our function.

Time complexity = O((n*m) ^ 3)  since the maximum length of a branch in recursive tree can be n*m and from any node we have atmost 3 options to move further.
*/
void findPath(vector<vector<int>> &input, int currR, int currC, pair<int, int> &end, int &len, int &maxLen, vector<pair<int, int>> &moves)
{
    if (currR == end.first && currC == end.second)
    {
        if (len > maxLen)
        {
            maxLen = len;
            return;
        }
    }

    for (pair<int, int> move : moves)
    {
        int r = currR + move.first;
        int c = currC + move.second;

        if (r >= 0 && r < input.size() && c >= 0 && r < input[0].size() && input[r][c] == 1)
        {
            input[r][c] = -1;
            len++;
            findPath(input, r, c, end, len, maxLen, moves);
            len--;
            input[r][c] = 1;
        }
    }
}

int findLongestPath(vector<vector<int>> &input, pair<int, int> start, pair<int, int> end)
{
    int maxLen = 0;
    int len = 0;
    vector<pair<int, int>> moves{{0, 1}, {1, 0}, {-1, 0}, {0, -1}};

    findPath(input, start.first, start.second, end, len, maxLen, moves);
    return maxLen;
}

int main()
{
    int n, m;
    cin >> n >> m;
    vector<vector<int>> input(n, vector<int>(m, 0));

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> input[i][j];
        }
    }

    pair<int, int> start, end;
    cin >> start.first >> start.second;
    cin >> end.first >> end.second;
    int len = findLongestPath(input, start, end);
    cout << len;
}