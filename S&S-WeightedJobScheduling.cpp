/*///////////////////// Q 108: Babbar450: weighted Job Scheduling ///////////////////
Given N jobs where every job is represented by following three elements of it.

Start Time
Finish Time
Profit or Value Associated
Find the maximum profit subset of jobs such that no two jobs in the subset overlap.

Example:

Input: Number of Jobs n = 4
       Job Details {Start Time, Finish Time, Profit}
       Job 1:  {1, 2, 50} 
       Job 2:  {3, 5, 20}
       Job 3:  {6, 19, 100}
       Job 4:  {2, 100, 200}
Output: The maximum profit is 250.
We can get the maximum profit by scheduling jobs 1 and 4.
Note that there is longer schedules possible Jobs 1, 2 and 3 
but the profit with this schedule is 20+50+100 which is less than 250.  
///////////////////////////////////////////////////////////////////////////////////////////////////////////*/

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

bool comp(vector<int> a, vector<int> b)
{
    if (a[0] < b[0])
        return true;
    return false;
}
////////////////// Solution 1 (Back tracking) //////////////////////
/*
the idea here is to iterate over the sorted array.
for each iteration we'll calculaete maxProfit for remaining next processes.
for this we need to pass current profit and end Time for current processes, 
because after current process only other process can start if start time is 
greater or equal for that process.
for whichever iteration we'll find profit greater than maxProfit, will reset 
maxProfit to that profit.

in worst case, max profit will contain all the profits, so total function 
calls will be n* (n+1)/2
for example, if there are 4 processes and all the processes are included in 
maxProfit then total function calls are at level 1 will be 4, at level 2 
calls will be 3, at level 3 calls will be 2 aand level 4 calls will be 1.
            Total calls are 4+3+2+1 = 10
*/
int getMaxProfit(vector<vector<int>> input, int start, int prevProfit, int jobStop)
{
    int size = input.size();
    int maxProfit = prevProfit;
    for (int i = start; i < size; i++)
    {
        if (input[i][0] >= jobStop) // start time is greater or equal to previous stop time
        {
            //int jobEnd = jobStop + input[i][1];
            int currProfit = prevProfit + input[i][2];
            int profit = getMaxProfit(input, i + 1, currProfit, input[i][1]);
            if (profit > maxProfit)
                maxProfit = profit;
        }
    }
    return maxProfit;
}

/////////////////////// Solution 2 (Recursion) /////////////////////////////
/*
total number of levels = n
total function calls at ith level = 2^i
Time complexity = 2^1 + 2^2 + 2^3 + ....+ 2^n
                = 2(2^n -1)/(2-1)
                = 2(2^n -1)
                = 2^n
*/
int calculateMaxProfit(vector<vector<int>> input, int start, int prevProfit, int jobStop)
{
    int size = input.size();
    int pLeft = 0;

    //base condition
    if (start >= size)
        return prevProfit;

    if (input[start][0] >= jobStop)
        pLeft = calculateMaxProfit(input, start + 1, prevProfit + input[start][2], input[start][1]);

    int pRight = calculateMaxProfit(input, start + 1, prevProfit, jobStop);

    return max(pLeft, pRight);
}

int main()
{
    vector<vector<int>> input{{1, 19, 2}, {15, 18, 9}, {7, 19, 1}, {11, 16, 19}, {1, 10, 5}, {3, 8, 7}, {16, 19, 3}, {2, 8, 19}};
    int m = 8;
    int n = 3;
    sort(input.begin(), input.end(), comp);
    cout << getMaxProfit(input, 0, 0, 1) << endl;
    cout << calculateMaxProfit(input, 0, 0, 1) << endl;
}