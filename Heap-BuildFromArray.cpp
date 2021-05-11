/*///////////////////// Q 312: Babbar450: Implement Min/Max Heap from array ///////////////////
Given an array of N elements. The task is to build a Binary Heap from the given 
array. The heap can be either Max Heap or Min Heap.
/////////////////////////////////////////////////////////////////////////////////////////////*/
#include <iostream>

using namespace std;

/////////////////////// Solution ////////////////////
/*
we can call the heapify method for all the elements in the array, to convert it into min heap.
Time complexity for this approach will be O(n log n), because minHeapify will take log n time and it is called n times.

we can optimise it by calling minHeapify function n/2 times, for leaf nodes we don't need to call minHeapify.
*/
void minHeapify(int input[], int index, int size)
{
    int l = 2 * index + 1;
    int r = 2 * index + 2;
    int min = index;
    if (l < size && input[l] < input[index])
        min = l;
    if (r < size && input[r] < input[min])
        min = r;

    if (min != index)
    {
        swap(input[min], input[index]);
        minHeapify(input, min, size);
    }
}

void printHeap(int input[], int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << input[i] << " ";
    }
    cout << endl;
}
int main()
{
    int size;
    cin >> size;
    int input[size];
    for (int i = 0; i < size; i++)
    {
        cin >> input[i];
    }

    for (int i = size / 2; i >= 0; i--)
    {
        minHeapify(input, i, size);
    }

    printHeap(input, size);
}