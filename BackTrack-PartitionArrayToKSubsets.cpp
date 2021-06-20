/*////////////////////////////////// Q 272: Babbar450: Partition Array to K Subsets ///////////////////////////////////
Given an integer array a[ ] of N elements and an integer K, the task is to check if the array a[ ] could be divided into K non-empty subsets with equal sum of elements.
Note: All elements of this array should be part of exactly one partition.
Example 1:

Input: 
N = 5
a[] = {2,1,4,5,6}
K = 3
Output: 
1
Explanation: we can divide above array 
into 3 parts with equal sum as (2, 4), (1, 5), (6)

Example 2:

Input: 
N = 5 
a[] = {2,1,5,5,6}
K = 3
Output: 
0
Explanation: It is not possible to divide above array into 3 parts with equal sum.

Expected Time Complexity: O(N*2N).
Expected Auxiliary Space: O(2N).

Constraints:
1 ≤ K ≤ N ≤ 10
1 ≤ a[i] ≤ 100
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////*/
#include <iostream>

using namespace std;

///////////////////////////////////////////////////// Solution /////////////////////////////////////////////////////
/*
In this problem we need to form sets of numbers which has equal sum and numbers are not repeated. since we need to generate k sets of equal sum value, we can find the sum of a set by dividing the totsl sum of all the numbers by k.
if the total sum is divisible by k, then only we can generate k sets with equal sum from the given numbers, other wise sets can not be generated.

if the total sum is divisible by k, we need to find all the k sets of numbers for which sum is equal to totalSum/k where numbers are not repeated.
this we can find out by trying all the combinitions of numbers recursively using back tracking.

example : 
n = 7
arr = {1 2 3 4 5 6 }
k = 3

here total sum is 21 and we need to find 3 sets so we need to find 3 sets of sum 21/3 = 7.
first set we can find is {1 2 4} but after this we can not find any other set with sum  = 7 so here we need to discard it and back track.
the solution is {{1 6}, {2 4}, {3 4}}.

To handle above case, in our code we need to keep track of the count of the sets, we'll return true only when we find all k sets with 
sum = totalSum/k.

Algorithm:
1. calculate total sum of the elements in array and check whether it is divisible by k or not, if not then return false.
2. iterate over the array and select an element at each iteration by marking it visited and add it to the sum so far. then call the fuction recursively for remaining unvisited elements. if function return true then it means current choosen number lead to the solution so we'll return true, else we'll back track to find other combinitions.
3. if sum so far is greater than totalsum/k, number at current index can not lead to the solution so we'll return false to back track.
4. Base Condition:
    a. if sum of elements so far is equal to total/k then decrement k by one to indicate that we found one set of desired sum.
    b. if k became 0 then it means we found all k sets of sum total/k. so we'll return true. else we'll set the sum so far to 0 and index to 0 and repeat the same process with remaining unvisited elements to find next set of elements with desired sum.

Time complexity will depend on the total number of combination that can be made with the given numbers. which means total sets in the power set.
so the time complexity will be O(2^n) in worst case.
*/

bool findPartition(int arr[], int n, int k, int total, int currSum, int index)
{
    if (currSum == total)
    {
        k--;
        if (k == 0)
            return true;

        currSum = 0;
        index = 0;
    }
    else if (currSum > total)
        return false;

    for (int i = index; i < n; i++)
    {
        if (arr[i] != -1)
        {
            int temp = arr[i];
            arr[i] = -1;
            if (true == findPartition(arr, n, k, total, currSum + temp, i))
                return true;
            arr[i] = temp;
        }
    }
    return false;
}

bool isKPartitionPossible(int a[], int n, int k)
{
    int sum = 0;
    for (int i = 0; i < n; i++)
        sum += a[i];

    if (sum % k != 0)
        return false;
    else
    {
        int total = sum / k;
        int currSum = 0;

        return findPartition(a, n, k, total, currSum, 0);
    }
    return false;
}

int main()
{
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++)
        cin >> a[i];
    int k;
    cin >> k;
    cout << isKPartitionPossible(a, n, k) << endl;
}