/*//////////////////////////////// Q 327: Babbar450: convert Min Heap to Max Heap ////////////////////////////////////
Given array representation of min Heap, convert it to max Heap in O(n) time. 
Example : 
 

Input: arr[] = [3 5 9 6 8 20 10 12 18 9]
         3
      /     \
     5       9
   /   \    /  \
  6     8  20   10
 /  \   /
12   18 9 


Output: arr[] = [20 18 10 12 9 9 3 5 6 8] OR 
       [any Max Heap formed from input elements]

         20
       /    \
     18      10
   /    \    /  \
  12     9  9    3
 /  \   /
5    6 8 
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////*/
#include <iostream>

using namespace std;

//////////////////////////////////////////////// Solution /////////////////////////////////////////////////
/*
The idea is very simple – we simply build Max Heap without caring about the input. We start from bottom-most and rightmost internal mode of min Heap and heapify all internal modes in bottom up way to build the Max heap.
In this way the time complexity will be O(n).
*/
void maxHeapify(int input[], int n, int index)
{
    int l = 2 * index + 1;
    int r = 2 * index + 2;
    int max = index;

    if (l < n && input[l] > input[max])
        max = l;
    if (r < n && input[r] > input[max])
        max = r;

    if (max != index)
    {
        swap(input[max], input[index]);
        maxHeapify(input, n, max);
    }
}
void convertToMaxHeap(int input[], int n)
{
    int start = (n / 2) - 1;
    for (int i = start; i >= 0; i--)
    {
        maxHeapify(input, n, i);
    }
}
int main()
{
    int n;
    cin >> n;

    int input[n];
    for (int i = 0; i < n; i++)
    {
        cin >> input[i];
    }

    convertToMaxHeap(input, n);
    for (int i = 0; i < n; i++)
    {
        cout << input[i] << " ";
    }
}