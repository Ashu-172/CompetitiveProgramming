/*/////////////////////////////////// Q 37: Babbar450 : Spirally traversing a matrix ///////////////////////////////
Given a matrix mat[][] of size M*N. Traverse and print the matrix in spiral form.

Input:
The first line of the input contains a single integer T, denoting the number of test cases. Then T test cases follow. Each testcase has 2 lines. First line contains M and N respectively separated by a space. Second line contains M*N values separated by spaces.

Output:
Elements when travelled in Spiral form, will be displayed in a single line.

Constraints:
1 <= T <= 100
2 <= M,N <= 10
0 <= Ai <= 100

Example:
Input:
2
4 4
1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16
3 4
1 2 3 4 5 6 7 8 9 10 11 12

Output:
1 2 3 4 8 12 16 15 14 13 9 5 6 7 11 10
1 2 3 4 8 12 11 10 9 5 6 7

//////////////////////////////////////////////////////////////////////////////////////////*/
#include <iostream>

using namespace std;

void traverseSpirally(int **input, int rows, int columns)
{

    int cStart = 0, cEnd = columns - 1;
    int rStart = 0, rEnd = rows - 1;
    int c = cStart, r = rStart;
    while (rStart <= rEnd && cStart <= cEnd)
    {
        r = rStart;
        c = cStart;
        // Traversing row from left to right
        while (c <= cEnd)
            cout << input[r][c++] << " ";

        c = cEnd;
        r = rStart + 1;
        // Traversing column from up to down
        while (r <= rEnd)
            cout << input[r++][c] << " ";

        r = rEnd;
        c = cEnd - 1;
        //Traversing row from right to left
        // for rStart = rEnd we have already traversed the same row from left to right
        while (c >= cStart && rStart != rEnd)
            cout << input[r][c--] << " ";

        c = cStart;
        r = rEnd - 1;
        //traversing column from down to up
        // for cStart = cEnd we have already traversed the same row grom p to down
        while (r > rStart && cStart != cEnd)
            cout << input[r--][c] << " ";

        cStart++;
        rStart++;
        cEnd--;
        rEnd--;
    }
}

//time complexity for this solution is O(rowa * columns).
/* we can also use recursive function for rhis problem, in the above 
function instead of outer while loop we can call same function passing 
new values of rStart, rEnd, cStart and cEnd.
Base condition for recursion will be rStart>rEnd or cStart > cEnd.*/

int main()
{
    int rows, columns;
    cin >> rows;
    cin >> columns;
    int *input[rows];

    for (int i = 0; i < rows; i++)
    {
        input[i] = new int[columns];
        for (int j = 0; j < columns; j++)
            cin >> input[i][j];
    }
    traverseSpirally(input, rows, columns);
}
