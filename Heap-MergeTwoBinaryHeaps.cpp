/*//////////////////////////////// Q 318: Babbar450: Merge Two Binary max Heaps ////////////////////////////////
Given two binary max heaps as arrays, merge the given heaps, after merging the two arrays.
The task is very simple to merge the two arrays firstly keep all the elements of first array than elements second array, than apply the merge operation of heaps.

Input:
First line consists of T test cases. First line of every test case consists of 2 integers N and M, denoting the number elements of two arrays (MAX HEAP). Second and third line of every test cases consists of elements of 2 Heaps respectively.

Output:
Single line output, print the merged max heap.

Constraints:
1<=T<=100
1<=N,M<=100

Example:
Input:
1
4 3
10 5 6 2
12 7 9
Output:
12 10 9 2 5 7 6 
/////////////////////////////////////////////////////////////////////////////////////////////////////////////*/
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

///////////////////////////////// Solution 1 ///////////////////////
/*
1. both the input arrays are already Max Heaps, so we can put 2nd input's elements in vector 1 and then we can call make_heap method which will create heap from the vector.
*/
vector<int> mergeHeap(vector<int> input1, vector<int> input2)
{
    for (int num : input2)
        input1.push_back(num);

    make_heap(input1.begin(), input1.end());
    return input1;
}

//////////////////////////////////// Solution 2 //////////////////////////
/*
create a heap from inputs and then pop all elements from Heap and push in result vector
*/
vector<int> mergeHeap2(vector<int> input1, vector<int> input2)
{
    priority_queue<int> heap(input1.begin(), input1.end());
    for (int num : input2)
        heap.push(num);

    vector<int> result;
    int temp;
    while (heap.size() != 0)
    {
        temp = heap.top();
        heap.pop();
        result.push_back(temp);
    }
    return result;
}

/////////////////////////////////// Solution 3 ////////////////////////////////
/*
put all elements from second array to first array and use maxHeapify method to create Heap. (similar to solution 1)
*/

void maxHeapify(vector<int> &input, int index)
{
    int l = 2 * index + 1;
    int r = 2 * index + 2;

    int max = index;

    if (l < input.size() && input[l] > input[max])
        max = l;
    if (r < input.size() && input[r] > input[max])
        max = r;

    if (max != index)
    {
        swap(input[index], input[max]);
        maxHeapify(input, max);
    }
}
vector<int> mergeHeap3(vector<int> input1, vector<int> input2)
{
    for (int num : input2)
        input1.push_back(num);

    for (int i = input1.size() / 2 - 1; i > 0; i--)
        maxHeapify(input1, i);
    return input1;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int a, b;
        cin >> a >> b;

        vector<int> input1;
        vector<int> input2;
        int temp;
        for (int i = 0; i < a; i++)
        {
            cin >> temp;
            input1.push_back(temp);
        }

        for (int i = 0; i < b; i++)
        {
            cin >> temp;
            input2.push_back(temp);
        }

        vector<int> result = mergeHeap3(input1, input2);

        for (int num : result)
            cout << num << " ";
        cout << endl;
    }
    return 0;
}