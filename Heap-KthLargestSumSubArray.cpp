/*//////////////////////////////// Q 319: Babbar450: K-th Largest Sum Contiguous Subarray ////////////////////////////////
Given an array of integers. Write a program to find the K-th largest sum of contiguous subarray within the array of numbers which has negative and positive numbers.

Examples: 

Input: a[] = {20, -5, -1} 
        k = 3
Output: 14
Explanation: All sum of contiguous 
subarrays are (20, 15, 14, -5, -6, -1) 
so the 3rd largest sum is 14.

Input: a[] = {10, -10, 20, -40} 
         k = 6
Output: -10 
Explanation: The 6th largest sum among 
sum of all contiguous subarrays is -10.
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////*/
#include <iostream>
#include <queue>

using namespace std;

/////////////////////////////////////////////// Solution /////////////////////////////////////
/*
A brute force approach is to store all the contiguous sums in another array and sort it, and print the k-th largest. But in case of number of elements being large, the array in which we store the contiguous sums will run out of memory as the number of contiguous subarrays will be large (quadratic order)
An efficient approach is store the pre-sum of the array in a sum[] array. We can find sum of contiguous subarray from index i to j as sum[j]-sum[i-1] 
Now for storing the Kth largest sum, use a min heap (priority queue) in which we push the contiguous sums till we get K elements, once we have our K elements, check if the next sum value is greater than the Kth element (top of the heap). if it is then we'll insert it in the heap with popping out the top element in the min-heap, else we'll not insert. At the end the top element in the min-heap will be the answer (kth largest sum).
*/
int findKthminSum(int input[], int size, int k)
{
    int sum[size + 1];
    sum[0] = 0;
    for (int i = 1; i <= size; i++)
    {
        sum[i] = sum[i - 1] + input[i - 1];
    }

    int temp;
    priority_queue<int, vector<int>, greater<int>> minHeap;
    //for (int i = 0, j = k; j <= size; i++, j++) // when contigious subarray size is also given as k
    for (int i = 0; i < size; i++)
        for (int j = i + 1; j <= size; j++)
        {
            temp = sum[j] - sum[i];
            if (minHeap.size() < k)
                minHeap.push(temp);
            else
            {
                if (minHeap.top() < temp)
                {
                    minHeap.pop();
                    minHeap.push(temp);
                }
            }
        }
    if (minHeap.size() > 0)
        return minHeap.top();
    return -1;
}
/*
Time complexity: O(n^2 log (k)) 
Auxiliary Space : O(k) for min-heap and we can store the sum array in the array itself as it is of no use.
*/
int main()
{
    int n;
    cin >> n;
    int input[n];
    for (int i = 0; i < n; i++)
    {
        cin >> input[i];
    }

    int k;
    cin >> k;

    cout << findKthminSum(input, n, k);
}