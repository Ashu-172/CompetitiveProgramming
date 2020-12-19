/*///////////////////// Q 104: Babbar450: Zero Sum Sub Array ///////////////////
You are given an array A[] of size N. Find the total count of sub-arrays having their sum equal to 0.
Example 1:

Input:
N = 6
A[] = {0,0,5,5,0,0}
Output: 6
Explanation: The 6 subarrays are 
[0], [0], [0], [0], [0,0], and [0,0].

Example 2:

Input:
N = 10
A[] = {6,-1,-3,4,-2,2,4,6,-12,-7}
Output: 4
Explanation: The 4 subarrays are [-1 -3 4]
[-2 2], [2 4 6 -12], and [-1 -3 4 -2 2]

Your Task:
You don't need to read input or print anything. Complete the function findSubarray() that takes the array A and its size N as input parameters and returns the total number of sub-arrays with 0 sum. 

Expected Time Complexity : O(N)
Expected Auxilliary Space : O(N)

Constraints:    
1<= N <= 10^7
-10^10 <= Ai <= 10^10

//////////////////////////////////////////////////////////////////////////////*/
#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <vector>

using namespace std;

/////////////////////////// Solution 1 ////////////////////////
long long findSubarray(long long input[], long size)
{
    long long count = 0;
    for (long i = 0; i < size; i++)
    {
        long long sum = 0;
        for (long j = i; j < size; j++)
        {
            sum += input[j];
            if (sum == 0)
                count++;
        }
    }
    return count;
}

/////////////////////////// Solution 2 ////////////////////
/*
Example: Input:  arr = [6, 3, -1, -3, 4, -2, 2, 4, 6, -12, -7]

In the input arrar we can observe that  if we traverse the arraya and
calculate sum so far, value of sum will repeat if there is any sub array 
present with 0 sum.
in the above example sum till index 1 is 6+3 = 9 
and sum till index 4 is 6+3-1-3+4 = 9 which is same, because there is a 
subarray [-1, -3, 4] whose sum is 0.

for each sum so far we can maintain a mapping for the indexes, where it has occurred.

we can iterate the map for each sum, and count all pairs of indexes for each sum value.
Note that for key = 0 in the map, we need to include the count of positions when it has occurred
for example: [0 1 -1], for this input, map will have entry as 
            0 -> 0, 2 
    so it will give count as 1, but here we have 3 subarrays here sum is 0
            [0], [-1, 1] [0, -1, 1]
*/

long long findPairsHT(long long input[], long size)
{
    unordered_map<long long, vector<long>> hTable;
    long long sum = 0;
    long long count = 0;
    for (long i = 0; i < size; i++)
    {
        sum += input[i];
        auto itr = hTable.find(sum);
        if (itr == hTable.end())
        {
            vector<long> temp;
            temp.push_back(i);
            hTable.insert(make_pair(sum, temp));
        }
        else
        {
            itr->second.push_back(i);
        }
    }

    for (auto itr = hTable.begin(); itr != hTable.end(); itr++)
    {
        long vecSize = itr->second.size();
        if (vecSize > 1)
        {
            for (int i = 0; i < vecSize - 1; i++)
                for (int j = i + 1; j < vecSize; j++)
                {
                    count++;
                }
        }
        if (itr->first == 0)
            count += itr->second.size();
    }
    return count;
}

int main()
{
    long long input[] = {0, 0, 5, 5, 0, 0};
    long size = sizeof(input) / sizeof(long long);

    cout << findSubarray(input, size) << endl;
    cout << findPairsHT(input, size) << endl;
}