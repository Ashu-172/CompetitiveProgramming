/*//////////////////////////// Q 21: Babbar450 : find if there is any subarray with sum zero  /////////////////////////
Given an array a[] of N positive and negative numbers. Find if there is a subarray (of size at-least one) with 0 sum.
Input:
The first line of input contains an integer T denoting the number of test cases. Then T test cases follow. Each test case contains an integer n denoting the size of the array. The next line contains N space separated integers forming the array.
Output:
Print "Yes" ( without quotes) if there exist a subarray of size at least one with sum equal to 0 or else print "No" (without quotes).
Constraints:
1 <= T <= 100
1 <= N <= 104
-105 <= a[i] <= 105
Example:
Input:
2
5
4 2 -3 1 6
5
4 2 0 1 6
Output:
Yes
Yes
Explanation:
Testcase 1: 2, -3, 1 is the subarray with sum 0.

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////*/
#include <iostream>
#include <chrono>
#include <unordered_map>

using namespace std;
using namespace std::chrono;

//////////////////////////////////////////// Solution 1 ///////////////////////////
string findZeroSumSubString(int input[], int size)
{
    int sum;
    for (int i = 0; i < size - 1; i++)
    {
        sum = 0;
        int num = -input[i];
        //checking if number itself is zero
        if (input[i] == 0)
            return "yes";
        for (int j = i + 1; j < size; j++)
        {
            sum += input[j];

            //if sum is equal to zero or equal to -input[i] return yes
            if ((sum == 0) || (sum == num))
                return "yes";
        }
    }
    return "no";
}

/*//////////////////////////////// Solution 2 ///////////////////////////////////
we can use hash table to maintain sum from 0 to index i. if e encounter same 
value of sum twice then we can say there is 0 sum sub-array present  endin at i.
///////////////////////////////////////////////////////////////////////////////*/
string findZeroSumSubStringHT(int input[], int size)
{
    unordered_map<int, int> map;
    int sum = 0;
    for (int i = 0; i < size; i++)
    {
        sum += input[i];
        auto itr = map.find(sum);
        if (itr != map.end())
            return "yes";

        map.insert(make_pair(sum, 1));
    }
    return "no";
}

int main()
{
    int input[] = {4, 2, 0, 1, 6};

    int size = sizeof(input) / sizeof(int);
    auto start = high_resolution_clock::now();
    //string res = findZeroSumSubString(input, size);
    string res = findZeroSumSubStringHT(input, size);
    auto end = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(end - start);
    cout << "Time: " << duration.count() << " " << res << endl;
}