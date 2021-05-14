/*//////////////////////////////// Q 314: Babbar450: Max Of All SubArray of K length ////////////////////////////////
Given an array arr[] of size N and an integer K. Find the maximum for each and every contiguous subarray of size K.

Example 1:

Input:
N = 9, K = 3
arr[] = 1 2 3 1 4 5 2 3 6
Output: 
3 3 4 5 5 5 6 
Explanation: 
1st contiguous subarray = {1 2 3} Max = 3
2nd contiguous subarray = {2 3 1} Max = 3
3rd contiguous subarray = {3 1 4} Max = 4
4th contiguous subarray = {1 4 5} Max = 5
5th contiguous subarray = {4 5 2} Max = 5
6th contiguous subarray = {5 2 3} Max = 5
7th contiguous subarray = {2 3 6} Max = 6
Example 2:

Input:
N = 10, K = 4
arr[] = 8 5 10 7 9 4 15 12 90 13
Output: 
10 10 10 15 15 90 90
Explanation: 
1st contiguous subarray = {8 5 10 7}, Max = 10
2nd contiguous subarray = {5 10 7 9}, Max = 10 
3rd contiguous subarray = {10 7 9 4}, Max = 10 
4th contiguous subarray = {7 9 4 15}, Max = 15
5th contiguous subarray = {9 4 15 12}, Max = 15 
6th contiguous subarray = {4 15 12 90}, Max = 90 
7th contiguous subarray = {15 12 90 13}, Max = 90 


Expected Time Complexity: O(N)
Expected Auxiliary Space: O(N)

Constraints:
1 ≤ N ≤ 10^7
1 ≤ K ≤ N
0 ≤ arr[i] <= 10^7
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////*/
#include <iostream>
#include <algorithm>
#include <vector>
#include <list>
#include <deque>

using namespace std;

/////////////////////////////// Solution 1 (nested Loop) ///////////////////////////
/*
1. Create a nested loop, the outer loop from starting index to n – k th elements. The inner loop will run for k iterations.
2. Create a variable to store the maximum of k elements traversed by the inner loop.
3. Find the maximum of k elements traversed by the inner loop, and put in result vector.

Time Complexity: O(N * K). 
The outer loop runs n-k+1 times and the inner loop runs k times for every iteration of outer loop. So time complexity is O((n-k+1)*k) which can also be written as O(N * K).
*/
vector<int> max_of_subarrays(int arr[], int n, int k)
{
    vector<int> result;
    for (int i = 0; i < n - k + 1; i++)
    {
        int max = 0;
        for (int j = i; j < i + k; j++)
        {
            if (arr[j] > max)
                max = arr[j];
        }
        result.push_back(max);
    }
    return result;
}

////////////////////////////// Solution 2 (Sliding Window) ////////////////////////////////////
/*
This problem can be solved by using sliding window approach. as we want to get the max for each K size window we need to store data present in current window and get the max of it.

1. we'll store current window's data in a buffer.
2. we can observe that the potential candidates for max are the numbers greater than the current element present at index j, where j is the element which will be included in the window when it slides. so from the buffer we can remove all the elements which are lesser than jth elements. this will also ensure that for current window max element will be present at front of the buffer.
3. now we can insert jth element in the buffer (extending window from right side).
4. when the window size became equal to k, we'll put max (from front of the buffer) in the result vector.
5. after this we need to move i (start of window) to right by one step. before doing that we need to remove i's data from buffer also if it is present (if it is present then it'll be present at front so we can compare it with front and remove).

Note: here instead of storing data in the buffer we'll store indexes in the buffer, because if we store data in the buffer we can not identify whether i's data present in the buffer or not while removing (step 4), in the case when same data is repeated in the same window. if we store indexes, it'll always be different.

Node: for buffer List or DeQue can be used, because both support operations on both ends.

Reference: https://www.youtube.com/watch?v=xFJXtB5vSmM

Time complexity for this solution in O(N) and space complexity is O(N).
*/
/////////////////////// using List /////////////////////////
vector<int> findMaxOfSubArrays(int arr[], int n, int k)
{
    list<int> maxList;
    vector<int> result;
    for (int i = 0, j = 0; i < n - k + 1 && j < n; j++)
    {
        while ((maxList.size() > 0 && arr[maxList.back()] <= arr[j]))
        {
            maxList.pop_back();
        }

        maxList.push_back(j);

        if (j - i + 1 == k)
        {
            result.push_back(arr[maxList.front()]);

            // sliding window
            if (maxList.front() == i)
                maxList.pop_front();

            i++;
        }
    }
    return result;
}
/////////////////// Using Deque ///////////////////
vector<int> maxSlidingWindow(vector<int> &nums, int k)
{
    deque<int> buffer;
    vector<int> res;

    for (auto i = 0; i < nums.size(); ++i)
    {
        while (!buffer.empty() && nums[i] >= nums[buffer.back()])
            buffer.pop_back();
        buffer.push_back(i);

        if (i >= k - 1)
        {
            res.push_back(nums[buffer.front()]);

            if (buffer.front() <= i - k + 1)
                buffer.pop_front();
        }
    }
    return res;
}

/////////////////////////////////////////// Solution 3 (Max Heap) /////////////////////////////////////////////
/*
we can use maxHeap to solve this problem.
1. insert elements from the input array to a max heap.
2. when heap size reaches to k, do following for every next velue in input array.
    1. insert the root (max) element of the heap in the result vector.
    2. remove the i-k th element from the heap.
    3. insert ith element in the heap
*/
class max_heap
{
    int size = 0;
    int capacity = 0;
    int *data;

public:
    max_heap(int capacity)
    {
        this->capacity = capacity;
        this->size = 0;
        this->data = new int[capacity];
    }

    int getMax()
    {
        return data[0];
    }
    int parent(int index)
    {
        return (index - 1) / 2;
    }
    int getSize()
    {
        return size;
    }
    void maxHeapify(int index)
    {
        if (index < size)
        {
            int left = index * 2 + 1;
            int right = index * 2 + 2;
            int max = index;

            if (left < size && data[left] > data[max])
                max = left;

            if (right < size && data[right] > data[max])
                max = right;

            if (max != index)
            {
                swap(data[max], data[index]);
                maxHeapify(max);
            }
        }
    }

    /* deleteNode function analysis
    time complexity of this function is O(iterating over heap array) + O(heapify the node position which matched)
                                         = O(k) + O(log k)
    1. in worst case for loop can iterate maximum k times in this case the location of matched node in if condition will be last which means time complexity for iteration will be O(k) but time complexity for heapify will be O(1) because there will be no swapping.
    2. in best case loop will iterate only once which means the location of the matched node will be at index 0 (root). in this case time complexity for iteration will be O(1) but time complexity for heapify can be O(log k) at max.

                    total time complexity (in worst case) = O(k)
    Ex. when k = 2^32
    1. if matching node found at index 0 then time complexity          = O(1) + O(log 2^32) = 32 units
    2. if matching node found at index 2^32 -1 then time complexity    = O(2^32) + O(1)     = 2^32 units
    3. if matching node found at middle position then time complexity  = O(2^31) + O(log 2^31) = 2^31 + 31 units

    */
    void deleteNode(int num)
    {
        for (int i = 0; i < size; i++)
        {
            if (data[i] == num)
            {
                swap(data[size - 1], data[i]);
                size--;
                maxHeapify(i);
                break;
            }
        }
    }
    /*insertNode function analysis
    Time complexity for this function will be O(log k) in worst case
    */
    bool insertNode(int num)
    {
        if (size >= capacity)
        {
            return false;
        }
        int index = size;
        size++;
        data[index] = num;
        while (index > 0 && data[parent(index)] < data[index])
        {
            swap(data[parent(index)], data[index]);
            index = parent(index);
        }
        return true;
    }
};

/*   complexity analysis
1. loop is iterating for n times. for each iteration wither if part will get executed or the else part.
2. time complexity for if part is O(log k) in wrost case.
3. time complexity for else part is O(k) in worst case

final time complexity for this function will be O(n*k) in worst case but amortized time complexity will 
be much lesser because worst case will not occur for each value in the input array.

*/
vector<int> findMaxOfSubArraysHeap(int input[], int n, int k)
{
    max_heap heap(k);
    vector<int> result;
    for (int i = 0; i < n; i++)
    {
        if (heap.getSize() < k)
        {
            heap.insertNode(input[i]);
            if (heap.getSize() == k)
                result.push_back(heap.getMax());
        }
        else
        {
            heap.deleteNode(input[i - k]);
            heap.insertNode(input[i]);
            result.push_back(heap.getMax());
        }
    }

    return result;
}
int main()
{
    int n;
    cin >> n;
    int input[n];
    int k;
    cin >> k;
    for (int i = 0; i < n; i++)
    {
        cin >> input[i];
    }

    //vector<int> result = findMaxOfSubArrays(input, n, k);
    vector<int> result = findMaxOfSubArraysHeap(input, n, k);
    for (int x : result)
        cout << x << " ";
}