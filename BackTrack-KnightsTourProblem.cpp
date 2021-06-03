/*////////////////////////////////// Q 263: Babbar450: Knights Tour Problem ///////////////////////////////////
Given a N*N board with the Knight placed on the first block of an empty board. Moving according to the rules of chess knight must visit each square exactly once. Print the order of each the cell in which they are visited.

Example:

Input : 
N = 8
Output:
0  59  38  33  30  17   8  63
37  34  31  60   9  62  29  16
58   1  36  39  32  27  18   7
35  48  41  26  61  10  15  28
42  57   2  49  40  23   6  19
47  50  45  54  25  20  11  14
56  43  52   3  22  13  24   5
51  46  55  44  53   4  21  12
/////////////////////////////////////////////////////////////////////////////////////////////////////////////*/
#include <iostream>

using namespace std;
#define size 8

void printSolution(int solution[size][size])
{
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            cout << solution[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}
////////////////////////////////////////// Solution /////////////////////////////////////////////
/*
Backtracking works in an incremental way to attack problems. Typically, we start from an empty solution vector and one by one add items (Meaning of item varies from problem to problem. In the context of Knight’s tour problem, an item is a Knight’s move). When we add an item, we check if adding the current item violates the problem constraint, if it does then we remove the item and try other alternatives. If none of the alternatives works out then we go to the previous stage and remove the item added in the previous stage. If we reach the initial stage back then we say that no solution exists. If adding an item doesn’t violate constraints then we recursively add items one by one. If the solution vector becomes complete then we print the solution.

Backtracking Algorithm for Knight’s tour 

Following is the Backtracking algorithm for Knight’s tour problem. 

If all squares are visited 
    print the solution
Else
   a) Add one of the next moves to solution vector and recursively 
   check if this move leads to a solution. (A Knight can make maximum 
   eight moves. We choose one of the 8 moves in this step).
   b) If the move chosen in the above step doesn't lead to a solution
   then remove this move from the solution vector and try other 
   alternative moves.
   c) If none of the alternatives work then return false (Returning false 
   will remove the previously added item in recursion and if false is 
   returned by the initial call of recursion then "no solution exists" )


Time Complexity : 
There are n^2 Cells and for each, we have a maximum of 8 possible moves to choose from, so the worst running time is O(8^N) where N = n^2.

Important Note:
No order of the moveR, moveC is wrong, but they will affect the running time of the algorithm drastically. For example, think of the case where 8th choice of the move is the correct one and before that our code ran 7 different wrong paths. It’s always a good idea a have a heuristic than to try backtracking randomly. Like, in this case, we know the next step would probably be in south or east direction, then checking the paths which leads their first is a better strategy.

*/
bool isSafe(int row, int col, int solution[size][size])
{
    if (0 <= row && row < size && 0 <= col && col < size && solution[row][col] == -1)
        return true;

    return false;
}
bool completeTour(int row, int col, int count, int moveR[], int moveC[], int solution[size][size])
{
    if (count == size * size)
        return true;

    int nextR, nextC;
    for (int i = 0; i < size; i++)
    {
        nextR = row + moveR[i];
        nextC = col + moveC[i];

        if (isSafe(nextR, nextC, solution) == true)
        {
            solution[nextR][nextC] = count;
            if (completeTour(nextR, nextC, count + 1, moveR, moveC, solution) == true)
                return true;
            solution[nextR][nextC] = -1;
        }
    }
    return false;
}

int main()
{
    int solution[size][size];

    for (int i = 0; i < size; i++)
        for (int j = 0; j < size; j++)
            solution[i][j] = -1;

    int moveR[size] = {2, 1, -1, -2, -2, -1, 1, 2};
    int moveC[size] = {1, 2, 2, 1, -1, -2, -2, -1};

    int row = 0, col = 0;

    // in start knight is at 0,0 position
    solution[0][0] = 0;

    if (completeTour(row, col, 1, moveR, moveC, solution) == true)
        printSolution(solution);
}