/*///////////////////// Q 101: Babbar450: maximum sum such that no 2 elements are adjacent ///////////////////
Stickler the thief wants to loot money from a society having n houses in a single line. He is a weird person and follows a certain rule when looting the houses. According to the rule, he will never loot two consecutive houses. At the same time, he wants to maximize the amount he loots. The thief knows which house has what amount of money but is unable to come up with an optimal looting strategy. He asks for your help to find the maximum money he can get if he strictly follows the rule. Each house has a[i] amount of money present in it.

Input:
The first line of input contains an integer T denoting the number of test cases. T testcases follow. Each test case contains an integer n which denotes the number of houses. Next line contains space separated numbers denoting the amount of money in each house.

Output:
For each testcase, in a newline, print an integer which denotes the maximum amount he can take home.

Constraints:
1 <= T <= 200
1 <= n <= 104
1 <= a[i] <= 104

Example:
Input:
2
6
5 5 10 100 10 5
3
1 2 3
Output:
110
4

Explanation:
Testcase1:
5+100+5=110
Testcase2:
1+3=4
////////////////////////////////////////////////////////////////////////////////////////////////////////////*/
#include <iostream>

using namespace std;

///////////////////////////// Solution 1 (Recursion) //////////////////////////
/*
Example : [10, 17, 100, 11, 80, 150]
Hypothesis:
    we can define a function which will give the Max SUm for input array from start index to end.
Induction:
    to get the max sum we have three cases
    1. input[start] + maxSum(start+2) can be the maximum sum for start
    2. input[start] + maxSum(start-3) can be the maximum sum for start
    3. maxSum(start+1) can be the maximum sum for start

    Example [100, 11, 80, 150], start =0
        case 1: 100 + maxSum(80) = 100+150 = 250
        case 2: 100 + maxSum(150) = 100 + 150 = 250
        case 3: maxSum(11) = 161.

    we'll get these three results and choose maximum among these as maxSum for Start.

Base Conditions:
    1. if input size is 1 then number itself will be maxSum.
    2. if input size is 2 then we'll get max among them as result.
    3. if input size is 3 then we'll return max(input[start]+input[end], input[start+1])
*/
int getMaxSum(int input[], int start, int size)
{
    if (start < size)
    {
        if (start == size - 1)
            return input[start];

        if (size - start == 2) // only two elements
            return max(input[start], input[start + 1]);

        if (size - start == 3) // only 3 elements present
            return max(input[start] + input[size - 1], input[start + 1]);

        int sum1 = getMaxSum(input, start + 1, size);
        int sum2 = getMaxSum(input, start + 2, size) + input[start];
        int sum3 = getMaxSum(input, start + 3, size) + input[start];
        return max(sum1, max(sum2, sum3));
    }
    return 0;
}

///////////////////////////// Solution 2 (Dynamic Programming) ///////////////////////
/*
In the recursive solution we are calculating same values again and again, which makes
it slower, we can store results in an array and use those precalculated values for 
further iterations, so now we need to call the recursive function only once.
*/
void getMaxSumDP(int input[], int start, int size, int maxSum[])
{
    if (start < size)
    {
        if (start == size - 1)
        {
            maxSum[start] = input[start];
            return;
        }

        if (size - start == 2) // only two elements
            maxSum[start] = max(input[start], input[start + 1]);

        if (size - start == 3) // only 3 elements present
            maxSum[start] = max((input[start] + input[size - 1]), input[start + 1]);

        getMaxSumDP(input, start + 1, size, maxSum);
        if (size - start > 3)
            maxSum[start] = max(maxSum[start + 1], max(maxSum[start + 2], maxSum[start + 3]) + input[start]);
    }
}

//////////////////////////// Solution 3 (Iterative Approach) ///////////////////////
/*
Above DP solution can be further improved by using a loop instead of recursive function 
call, it'll save function call stack memory.
along with that we can save memory uses by using same input array for storing maxSum,
instead of creating new array, because we are not going to use an input value after 
calculating  max sum for it.
*/
void getMaxSumItrative(int input[], int size)
{
    if (size == 1)
        return;
    input[size - 2] = max(input[size - 2], input[size - 1]);
    if (size == 2)
        return;
    input[size - 3] = max(input[size - 3] + input[size - 1], input[size - 2]);

    for (int i = size - 4; i >= 0; i--)
    {
        int maxInc = input[i] + max(input[i + 2], input[i + 3]);
        input[i] = max(maxInc, input[i + 1]);
    }
}

int main()
{
    int input[] = {10, 17, 100, 11, 80, 150};
    int size = sizeof(input) / sizeof(int);
    int maxSum[size] = {0};
    cout << getMaxSum(input, 0, size) << endl;
    getMaxSumDP(input, 0, size, maxSum);
    cout << maxSum[0] << endl;

    getMaxSumItrative(input, size);
    cout << input[0] << endl;
}