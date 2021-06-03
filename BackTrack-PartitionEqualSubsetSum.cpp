/*////////////////////////////////// Q 262: Babbar450: Subset Sum Problem ///////////////////////////////////
Given an array arr[] of size N, check if it can be partitioned into two parts such that the sum of elements in both parts is the same.

Example 1:

Input: N = 4
arr = {1, 5, 11, 5}
Output: YES
Explaination: The two parts are {1, 5, 5} and {11}.

Example 2:

Input: N = 3
arr = {1, 3, 5}
Output: NO
Explaination: This array can never be partitioned into two such parts.

Your Task:
You do not need to read input or print anything. Your task is to complete the function equalPartition() which takes the value N and the array as input parameters and returns 1 if the partition is possible. Otherwise, returns 0.

Expected Time Complexity: O(N*sum of elements)
Expected Auxiliary Space: O(N*sum of elements)

Constraints:
1 ≤ N ≤ 100
1 ≤ arr[i] ≤ 1000
///////////////////////////////////////////////////////////////////////////////////////////////////////////*/
#include <iostream>

using namespace std;
///////////////////////////////////////////////////// Solution ///////////////////////////////////////////////
/*
Here we need to divide the set in two parts such that sum of both the parts is equal.
To do this first we need to calculate the sum of all the numbers. then we need to have two variables for maintaining the sum of each part. initially we can sassume that all the numbers are present in the right part and left part is empty. in this case sum for left will be 0 and sum for right will be equal to the total sum, so in similar way we'll initialize the left and right sum.

now we'll choose numbers from the right part one by one and put them in the left part. since we have n numbers in the right part we'll iterate over them to try out every possiblity. whenever we choose a number from right part we decrese the right part sum by the number and add in the left part. 
after that we compare both the sum whether they are equal or not. if they are equal then we can return (this indicates that the set can be divided into two equal sum partitions)

here two points to observe:
1. the set can be divided in to equal sum partition only if the sum is an evan number, we can check this condition in starting and if the sum is odd we can return false from there without proceeding furthen.
2. In any function call if the sum of the left part is greater than the right part sum, we can say that the current branch of recursive tree can not lead to equal sum partition, so from there we can return false to backtrack.

Algorithm:
1. check if the left and right part is equal, if yes then return true.
2. if left part is grater than the right part, current recursive branch is of no use, so return false for backtracking.
3. try out all the remaining numbers from the right part to move to the left part, repeating following for all remaining elements in the right part of the array (not right set), iterate from the next index.
    a. call the function recursively after movinf ith number from right subset to left subset and pass incremented index so that in next level of recursion, numbers from the next index will be considered.
    b. if function returns true then return true, since we reached to the condition where left == right which is the result.
    c. if false then do nothing and try out next number (backtracking)
4. If no choice in the current level lead to the base condition left == right, then we can say the choice we made in previous level was not correct and we can return false to back track to the parent level.  
*/
class Solution
{
public:
    int findPartition(int arr[], int n, int index, int left, int right)
    {
        if (left == right)
            return true;
        else if (left > right)
            return false;
        else
        {
            for (int i = index; i < n; i++)
            {
                if (findPartition(arr, n, i + 1, left + arr[i], right - arr[i]) == true)
                    return true;
            }
        }
        return false;
    }
    int equalPartition(int n, int arr[])
    {
        int left = 0, right = 0;
        for (int i = 0; i < n; i++)
            right += arr[i];

        if (right % 2 != 0)
            return false;

        int index = 0;
        return findPartition(arr, n, index, left, right);
    }
};
///////////////////////////////////////////////////// Solution 2 /////////////////////////////////////////////////
/*
In this solution the idea is same the only difference is, here instead of maintaining two sum variables for left and right, we are using only one. we'll initialize it with the half of the total sum. and whenever we choose a number to put in the partition we'll decrement this sum.

the base case is when the sum becomes 0, it means we have found the set of numbers which are making sum equal to the hald of the total sum.
*/
class Solution2
{
public:
    int findPartition(int arr[], int n, int index, int sum)
    {
        if (sum == 0)
            return true;
        else if (sum < 0)
            return false;
        else if (index >= n)
            return false;
        else
        {
            for (int i = index; i < n; i++)
            {
                if (findPartition(arr, n, i + 1, sum - arr[i]) == true)
                    return true;
            }
        }
        return false;
    }
    int equalPartition(int n, int arr[])
    {
        int sum = 0;
        for (int i = 0; i < n; i++)
            sum += arr[i];

        if (sum % 2 != 0)
            return false;

        sum = sum / 2;

        int index = 0;
        return findPartition(arr, n, index, sum);
    }
};

int main()
{
    int N;
    cin >> N;
    int arr[N];
    for (int i = 0; i < N; i++)
        cin >> arr[i];

    Solution ob;
    if (ob.equalPartition(N, arr))
        cout << "YES\n";
    else
        cout << "NO\n";
    return 0;
}