/*//////////////////////////////// Q 316: Babbar450: find Kth smallest and Largest element ////////////////////////////////
Given an array and a number k where k is smaller than size of array, we need to find the k’th smallest/largest element in the given array. It is given that all array elements are distinct.

Examples:  
// smallest
Input: arr[] = {7, 10, 4, 3, 20, 15} 
k = 3 
Output: 7

Input: arr[] = {7, 10, 4, 3, 20, 15} 
k = 4 
Output: 10 
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////*/
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int KthSmallest(int arr[], int n, int k)
{
    priority_queue<int, vector<int>, greater<int>> minHeap;
    for (int i = 0; i < n; i++)
    {
        minHeap.push(arr[i]);
    }

    for (int i = 1; i < k; i++)
    {
        minHeap.pop();
    }
    return minHeap.top();
}

int KthLargest(int arr[], int n, int k)
{
    priority_queue<int> maxHeap;
    for (int i = 0; i < n; i++)
    {
        maxHeap.push(arr[i]);
    }

    for (int i = 1; i < k; i++)
    {
        maxHeap.pop();
    }
    return maxHeap.top();
}

//////////////////////// Solution 1 (using heap) ///////////////////////
/*
1. create a max heap with given data
2. pop k-1 elements from heap and while popping check heap size, if it is equals to k then it means only k elements left in the heap, so the top element will be Kth smallest element (this case will occur only if k > n/2, in this case before popping all k alements, size will become k).
3. after popping K-1 elements top of the heap will be Kth largest element because we have popped K-1 largest element.
4. if in step 2, heap size did not became K, means Kth smallest element did not occur on top of heap (when k < n/2), we'll pop more elements until size of heap becomes K. then top of heap will be Kth smallest element.
*/
void KthLargestSmallest(int arr[], int n, int k, int &largest, int &smallest)
{
    priority_queue<int> maxHeap;
    smallest = -1;
    largest = -1;
    for (int i = 0; i < n; i++)
    {
        maxHeap.push(arr[i]);
    }

    for (int i = 1; i < k; i++)
    {
        if (maxHeap.size() == k)
            smallest = maxHeap.top();
        maxHeap.pop();
    }
    largest = maxHeap.top();
    if (smallest == -1)
    {
        while (maxHeap.size() != k)
            maxHeap.pop();
        smallest = maxHeap.top();
    }
}

/////////////////////////////////////////// solution (sorting) ///////////////////////////////
/*
A simple solution is to sort the given array using a O(N log N) sorting algorithm like Merge Sort, Heap Sort, etc and return the element at index k-1 as smallest and n-k as largest in the sorted array. 
Time Complexity of this solution is O(N Log N) 
*/
void KthSmallestLargestSorting(int arr[], int n, int k, int &kSmall, int &kLarge)
{
    sort(arr, arr + n);
    kSmall = arr[k - 1];
    kLarge = arr[n - k];
}

/////////////////////////////////////////// Solution (QuickSelect) //////////////////////////
/*
In QuickSort, we pick a pivot element, then move the pivot element to its correct position and partition the surrounding array. The idea is, not to do complete quicksort, but stop at the point where pivot itself is k’th smallest element. Also, not to recur for both left and right sides of pivot, but recur for one of them according to the position of pivot. The worst case time complexity of this method is O(n^2), but it works in O(n) on average. 
*/
int partitionInc(int arr[], int start, int end)
{
    int pivot = end;
    int i = start;
    int j = start;

    while (j < end)
    {
        if (arr[j] <= arr[pivot])
        {
            swap(arr[i], arr[j]);
            i++;
        }
        j++;
    }
    swap(arr[i], arr[pivot]);
    return i;
}

void QuickSelectSmallest(int arr[], int start, int end, int k)
{
    if (end > start)
    {
        int pivot = partitionInc(arr, start, end);
        if (pivot == k - 1)
            return;
        else if (pivot < k - 1)
            QuickSelectSmallest(arr, pivot + 1, end, k);
        else
            QuickSelectSmallest(arr, start, pivot - 1, k);
    }
}

int partitionDec(int arr[], int start, int end)
{
    int pivot = end;
    int i = start;
    int j = start;

    while (j < end)
    {
        if (arr[j] >= arr[pivot])
        {
            swap(arr[i], arr[j]);
            i++;
        }
        j++;
    }
    swap(arr[i], arr[pivot]);
    return i;
}

void QuickSelectLargest(int arr[], int start, int end, int k)
{
    if (end > start)
    {
        int pivot = partitionDec(arr, start, end);
        if (pivot == k - 1)
            return;
        else if (pivot < k - 1)
            QuickSelectLargest(arr, pivot + 1, end, k);
        else
            QuickSelectLargest(arr, start, pivot - 1, k);
    }
}

int KthSmallestQuick(int arr[], int n, int k)
{
    QuickSelectSmallest(arr, 0, n - 1, k);
    return arr[k - 1];
}
int KthLargestQuick(int arr[], int n, int k)
{
    QuickSelectLargest(arr, 0, n - 1, k);
    return arr[k - 1];
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
    cout << KthSmallest(arr, n, k) << endl;
    cout << KthLargest(arr, n, k) << endl;

    int largest, smallest;
    KthLargestSmallest(arr, n, k, largest, smallest);
    cout << largest << " " << smallest << endl;

    // KthSmallestLargestSorting(arr, n, k, largest, smallest);
    // cout << largest << " " << smallest << endl;

    cout << KthSmallestQuick(arr, n, k) << endl;
    cout << KthLargestQuick(arr, n, k) << endl;
}