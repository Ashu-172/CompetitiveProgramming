/*//////////////////////////////// Q 315: Babbar450: find K Largest Elements ////////////////////////////////
Given an array Arr of N positive integers, find K largest elements from the array.  The output elements should be printed in decreasing order.

Example 1:

Input:
N = 5, K = 2
Arr[] = {12, 5, 787, 1, 23}
Output: 787 23
Explanation: 1st largest element in the
array is 787 and second largest is 23.
Example 2:

Input:
N = 7, K = 3
Arr[] = {1, 23, 12, 9, 30, 2, 50}
Output: 50 30 23
Explanation: 3 Largest element in the
array are 50, 30 and 23.
Your Task:
You don't need to read input or print anything. Your task is to complete the function kLargest() which takes the array of integers arr, n and k as parameters and returns an array of integers denoting the answer. The array should be in decreasing order.

Expected Time Complexity: O(N)
Expected Auxiliary Space: O(K*logK)

Constraints:
1 ≤ K ≤ N ≤ 10^5
1 ≤ Arr[i] ≤ 10^6
/////////////////////////////////////////////////////////////////////////////////////////////*/
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

vector<int> kLargest(int arr[], int n, int k)
{

    /*   //using min heap
       priority_queue<int, vector<int>, greater<int>> minHeap;
	   for(int i=0; i<n; i++)
	   {
	       minHeap.push(arr[i]);
	       
	       if(minHeap.size()>k)
	            minHeap.pop();
	   }
	   
	   vector<int> result;
	   while(minHeap.size() > 0)
	   {
	       result.push_back(minHeap.top());
	       minHeap.pop();
	   }
	   
	   for(int i=0, j=result.size()-1; i<j; i++, j--)
	   {
	       swap(result[i], result[j]);
	   }
	   return result;
	   */

    // using max Heap
    /*
    1.  push all the elements in the max heap
    2.  pop top k elements from the max heap and put in the result vector.

    Time complexity for this solution is O(n log n) // inserting all the elements in the heap
    */
    priority_queue<int> maxHeap;

    for (int i = 0; i < n; i++)
    {
        maxHeap.push(arr[i]);
    }
    vector<int> result;
    for (int i = 0; i < k; i++)
    {
        result.push_back(maxHeap.top());
        maxHeap.pop();
    }
    return result;
}

int main()
{
    int n, k;
    cin >> n >> k;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    vector<int> largest = kLargest(arr, n, k);
    for (int num : largest)
    {
        cout << num << " ";
    }
    cout << endl;
}