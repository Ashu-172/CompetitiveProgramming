/*//////////////////////////////// Q 325: Babbar450: Minimum Cost of ropes ////////////////////////////////////
There are given N ropes of different lengths, we need to connect these ropes into one rope. The cost to connect two ropes is equal to sum of their lengths. The task is to connect the ropes with minimum cost.

Example 1:

Input:
n = 4
arr[] = {4, 3, 2, 6}
Output: 
29
Explanation:
For example if we are given 4 ropes of lengths 4, 3, 2 and 6. We can connect the ropes in following ways.
1) First connect ropes of lengths 2 and 3.
Now we have three ropes of lengths 4, 6 and 5.
2) Now connect ropes of lengths 4 and 5.
Now we have two ropes of lengths 6 and 9.
3) Finally connect the two ropes and all ropes have connected.
Total cost for connecting all ropes is 5 + 9 + 15 = 29. This is the optimized cost for connecting ropes. 
Other ways of connecting ropes would always have same or more cost. For example, if we connect 4 and 6 first 
(we get three strings of 3, 2 and 10), then connect 10 and 3 (we get two strings of 13 and 2). Finally we
connect 13 and 2. Total cost in this way is 10 + 13 + 15 = 38.

Expected Time Complexity : O(nlogn)
Expected Auxilliary Space : O(n)

Constraints:
1 ≤ N ≤ 100000
1 ≤ arr[i] ≤ 10^6
/////////////////////////////////////////////////////////////////////////////////////////////////////////////*/
#include <iostream>
#include <queue>

using namespace std;
/*
if we observe the problem, we can see that the same rope is contributing in the cost many times. the early a rope is connected, the more number of times it'll get added to the cost. so the idea is to connect the smallest ropes first and the larger ropes in the end.
To get the smallest rope from the list we can use min Heap, because its root will always give the smallest rope (we need to extract two smallest ropes from the heap). Here one more thing is to observe is, once we connected two ropes the resulting rope size will be larger so inorder to get the smallest two rows to connect in the next iteration, we need to put the resulting row back in the heap in current iteration.

Algorithm: 
 
    1. Create a min-heap and insert all lengths into the min-heap.
    2. Do following while the number of elements in min-heap is not one. 
        1. Extract the minimum and second minimum from min-heap
        2. Add the above two extracted values and insert the added value to the min-heap.
        3. Maintain a variable for total cost and keep incrementing it by the sum of extracted values.
    3. Return the value of this total cost.

*/
long long minCost(long long arr[], long long n)
{
    // Your code here
    priority_queue<long long, vector<long long>, greater<long long>> minHeap(arr, arr + n);
    long long first, second;
    long long totalCost = 0;

    while (minHeap.size() != 1)
    {
        first = minHeap.top();
        minHeap.pop();
        second = minHeap.top();
        minHeap.pop();
        minHeap.push(first + second);
        totalCost += (first + second);
    }
    return totalCost;
}
int main()
{

    long long n;
    cin >> n;
    long long i, a[n];
    for (i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    cout << minCost(a, n) << endl;

    return 0;
}