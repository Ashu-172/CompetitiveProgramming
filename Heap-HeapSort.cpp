/*//////////////////////////////// Q 313: Babbar450: Heap Sort ////////////////////////////////
Given an array of size N. The task is to sort the array elements by completing functions heapify() and buildHeap() which are used to implement Heap Sort.


Example 1:

Input:
N = 5
arr[] = {4,1,3,9,7}
Output:
1 3 4 7 9
Explanation:
After sorting elements
using heap sort, elements will be
in order as 1,3,4,7,9.
Example 2:

Input:
N = 10
arr[] = {10,9,8,7,6,5,4,3,2,1}
Output:
1 2 3 4 5 6 7 8 9 10
Explanation:
After sorting elements
using heap sort, elements will be
in order as 1, 2,3,4,5,6,7,8,9,10.

Your Task :
You don't have to read input or print anything. Your task is to complete the functions heapify(), buildheap() and heapSort() where heapSort() and buildheap() takes the array and it's size as input and heapify() takes the array, it's size and an index i as input. Complete and use these functions to sort the array using heap sort algorithm.


Expected Time Complexity: O(N * Log(N)).
Expected Auxiliary Space: O(1).


Constraints:
1 <= N <= 106
1 <= arr[i] <= 10^6
/////////////////////////////////////////////////////////////////////////////////////////////*/
#include <iostream>
#include <algorithm>

using namespace std;

void heapify(int arr[], int n, int i)
{
    int l = i * 2 + 1;
    int r = i * 2 + 2;
    int max = i;

    if (l < n && arr[l] > arr[max])
        max = l;
    if (r < n && arr[r] > arr[max])
        max = r;

    if (max != i)
    {
        swap(arr[i], arr[max]);
        heapify(arr, n, max);
    }
}

void buildHeap(int arr[], int n)
{
    for (int i = n / 2; i >= 0; i--)
    {
        heapify(arr, n, i);
    }
}

void heapSort(int arr[], int n)
{
    buildHeap(arr, n);
    while (n > 0)
    {
        swap(arr[0], arr[n - 1]);
        n--;
        heapify(arr, n, 0);
    }
}

void printArr(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main()
{
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    printArr(arr, n);
    heapSort(arr, n);
    printArr(arr, n);
}