/*///////////////////////////////// Q 287:Babbar 450-Largest Rectangle Area in an Histogram ////////////////////////////
Find the largest rectangular area possible in a given histogram where the largest rectangle can be made of a number of contiguous bars. For simplicity, assume that all bars have the same width and the width is 1 unit.

Input:
The first line contains an integer 'T' denoting the total number of test cases. T test-cases follow. In each test case, the first line contains an integer 'N' denoting the size of the array. The second line contains N space-separated integers A1, A2, ..., AN denoting the elements of the array. The elements of the array represent the height of the bars.

Output:
For each test-case, in a separate line, the maximum rectangular area possible from the contiguous bars.

User Task:
The task is to complete the function getMaxArea() which finds the largest rectangular area possible and returns the answer.

Expected Time Complexity: O(N).
Expected Auxiliary Space: O(N).

Constraints:
1 <= T <= 100
1 <= N <= 106
1 <= A[i] <= 1018

Example:
Input: 
2
7
6 2 5 4 5 1 6
8
7 2 8 9 1 3 6 5
Output:
12
16
*/
/////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////// Solution ///////////////////////////////////
/*
lets say in an array [6 2 5 4 5 1 6] each number is showing a bar in histogram of width 1 and hight as number.
maximum possible rectangle area at any position is the maximum of value of that position, area of rectangle formed with previous index (if height of previous bar is greated or equal) and so on until we reach st index where bsr height id less than current bar.

for this we can use stack, we'll keep on inserting indexes in the stack for larger numbers, and when we encounter a smaller number, we know that last number will form a rectangle, we can pop the index for that numnber from stack and calculate the area.
area will be  input(top) * (current index - new Stacktop - 1)

here top is the previous number's index
     current index is new number's index
     new StackTop is the top of the stack after popping last largest number (top)


Following is the complete algorithm.

1) Create an empty stack.

2) Start from first bar, and do following for every bar ‘hist[i]’ where ‘i’ varies from 0 to n-1.
……a) If stack is empty or hist[i] is higher than the bar at top of stack, then push ‘i’ to stack.
……b) If this bar is smaller than the top of stack, then keep removing the top of stack while top of the stack is greater. Let the removed bar be hist[tp]. Calculate area of rectangle with hist[tp] as smallest bar. For hist[tp], the ‘left index’ is previous (previous to tp) item in stack and ‘right index’ is ‘i’ (current index).

3) If the stack is not empty, then one by one remove all bars from stack and do step 2.b for every removed bar.
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////*/
#include <iostream>
#include <stack>
#include <vector>

using namespace std;

int getMaxArea(vector<int> input)
{
    int n = input.size();
    stack<int> stk;
    int maxArea = 0, i = 0;
    while (i < n)
    {
        //pushing to the stack
        if (stk.empty() || input[stk.top()] <= input[i])
            stk.push(i++);
        else
        {
            //keep on popping and calculating area when top of stack is greater than ith mun
            int topVal = input[stk.top()];
            stk.pop();
            int area = topVal * (stk.empty() ? i : (i - stk.top() - 1));
            maxArea = max(maxArea, area);
        }
    }

    //Removing all bars from the stack and calculate area.Here i = n
    while (stk.empty() != true)
    {
        int topVal = input[stk.top()];
        stk.pop();
        int area = topVal * (stk.empty() ? i : (i - stk.top() - 1));
        maxArea = max(maxArea, area);
    }
    return maxArea;
}

int main()
{
    int n;
    cin >> n;
    vector<int> input;
    for (int i = 0; i < n; i++)
    {
        int temp;
        cin >> temp;
        input.push_back(temp);
    }

    //cout << getMaximumArea(input, n) << endl;
    cout << getMaxArea(input) << endl;
}
