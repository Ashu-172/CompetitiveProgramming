/*//////////////////////////////// Q 317: Babbar450: Merge K Sorted Arrays ////////////////////////////////
Given K sorted arrays arranged in the form of a matrix of size K*K. The task is to merge them into one sorted array.
Example 1:

Input:
K = 3
arr[][] = {{1,2,3},{4,5,6},{7,8,9}}
Output: 1 2 3 4 5 6 7 8 9
Explanation:Above test case has 3 sorted
arrays of size 3, 3, 3
arr[][] = [[1, 2, 3],[4, 5, 6], 
[7, 8, 9]]
The merged list will be 
[1, 2, 3, 4, 5, 6, 7, 8, 9].
Example 2:

Input:
K = 4
arr[][]={{1,2,3,4}{2,2,3,4},
         {5,5,6,6},{7,8,9,9}}
Output:
1 2 2 2 3 3 4 4 5 5 6 6 7 8 9 9 
Explanation: Above test case has 4 sorted
arrays of size 4, 4, 4, 4
arr[][] = [[1, 2, 2, 2], [3, 3, 4, 4],
[5, 5, 6, 6]  [7, 8, 9, 9 ]]
The merged list will be 
[1, 2, 2, 2, 3, 3, 4, 4, 5, 5, 
6, 6, 7, 8, 9, 9 ].

Expected Time Complexity: O(nk Logk)
Expected Auxiliary Space: O(k)

Constraints:
1 <= K <= 100
/////////////////////////////////////////////////////////////////////////////////////////////////////////*/
#include <iostream>
#include <queue>
#include <vector>
#include <set>
#include <list>

using namespace std;

///////////////////////////////////// Solution 1 (using Merge function) //////////////////////////////////
vector<int> merge(vector<int> left, vector<int> right, int lSize, int rSize)
{
    vector<int> result;
    int i = 0, j = 0, k = 0;

    while (i < lSize && j < rSize)
    {
        if (left[i] < right[j])
            result.push_back(left[i++]);
        else
            result.push_back(right[j++]);

        k++;
    }

    while (i < lSize)
    {
        result.push_back(left[i++]);
        k++;
    }

    while (j < rSize)
    {
        result.push_back(right[j++]);
        k++;
    }
    return result;
}
vector<int> mergeKSortedArrays(vector<vector<int>> input, int k)
{
    vector<int> l = input[0];
    for (int i = 1; i < k; i++)
    {
        l = merge(l, input[i], l.size(), k);
    }
    return l;
}

///////////////////////////////// Solution 2 (using minHeap) //////////////////////////////////////
/*
we can use min heap for merging the arrays.
1. insert all elements in the minheap.
2. put top element in result vector and pop it from heap, in this way we'll get next min number from top every time and all elements will be merged in single vector.
time complexity for this soution is O(k*k log n*k)  because inserting an element to heap takes O(log n) time, here total elements are k*k so time complexity is O( k*k log k*k)
*/
vector<int> mergeKArrays(vector<vector<int>> arr, int k)
{

    priority_queue<int, vector<int>, greater<int>> minHeap;
    for (int i = 0; i < k * k; i++)
    {
        minHeap.push(arr[i / k][i % k]);
    }
    vector<int> result;
    for (int i = 0; i < k * k; i++)
    {
        result.push_back(minHeap.top());
        minHeap.pop();
    }
    return result;
}

/////////////////////////////////// Solution 3 ( optimised use of merge) /////////////////////////////
/*
if we merge two vectors at a time and repeat it until we get single vector then  we will get an optimized solution.
1. insert all the vectors in a list, while inserting we can merge two - two vectors.
2. pop two vectors from the front of the list and push the mearged vector from the back in a loop until list size become 1.
3. return the only vector present in the list.

here while inserting we are inserting all the vectors in the list with mearging. time complexity of merge operation is O(2k) and the merge function is called k/2 (while inserting in the list) + k (while merging list elements) times.
        Time complexity = O(k/2 * 2k) + O(k * 2k) = O(k^2).
*/
vector<int> mergeKArrays2(vector<vector<int>> input, int k)
{
    list<vector<int>> inputList;
    int i = 0;
    for (i = 0; i < k - 1; i += 2)
    {
        inputList.push_back(merge(input[i], input[i + 1], input[i].size(), input[i + 1].size()));
    }
    // inserting last vector in case of odd number of vectors
    if (i < k)
        inputList.push_back(input[i]);

    vector<int> l, r;
    while (inputList.size() != 1)
    {
        l = inputList.front();
        inputList.pop_front();
        r = inputList.front();
        inputList.pop_front();

        inputList.push_back(merge(l, r, l.size(), r.size()));
    }

    return inputList.front();
}

////////////////////////// Solution 4 (Optimized version of Heap based solution) ////////////////////
/*
The idea is to create a MinHeap and insert the first element of all the k arrays. Remove the root element of Minheap and put it in the output array and insert the next element from the array of removed element. To get the result the step must continue until there is no element in the MinHeap left. 

1. Create a min Heap and insert the first element of all k arrays.
2. Run a loop until the size of MinHeap is greater than zero.
3. Remove the top element of the MinHeap and print the element.
4. Now insert the next element from the same array in which the removed element belonged.
5. If the array doesn’t have any more elements, then replace root with infinite.After replacing the root, heapify the tree.

Time complexity for this solution is O(N Log k), where n is total elements (k*k).
*/
typedef pair<int, pair<int, int>> valType;
vector<int> mergeWithHeapOptimized(vector<vector<int>> input)
{
    vector<int> result;
    priority_queue<valType, vector<valType>, greater<valType>> minHeap;
    for (int i = 0; i < input.size(); i++)
    {
        minHeap.push(make_pair(input[i][0], make_pair(0, i)));
    }

    while (minHeap.empty() != true)
    {
        valType temp;
        temp = minHeap.top();
        minHeap.pop();
        result.push_back(temp.first);
        if (temp.second.first < input[temp.second.second].size() - 1)
            minHeap.push(make_pair(input[temp.second.second][temp.second.first + 1],
                                   make_pair(temp.second.first + 1, temp.second.second)));
    }
    return result;
}

////////////////////////// Solution 5 (only if all elements are unique) /////////////////////////////
/*
BST always keep elements in sorted order, Set implementation of STL can be used for it if elements are unique.
*/
vector<int> mergeKArraysUsingBST(vector<vector<int>> arr, int k)
{
    set<int> bst;
    for (int i = 0; i < k * k; i++)
    {
        bst.insert(arr[i / k][i % k]);
    }
    vector<int> result;
    for (int num : bst)
        result.push_back(num);
    return result;
}

void printResult(vector<int> result)
{
    for (int num : result)
        cout << num << " ";
    cout << endl;
}

int main()
{
    int k;
    cin >> k;
    int temp;
    vector<vector<int>> input;
    for (int i = 0; i < k; i++)
    {
        vector<int> tempVec;
        for (int j = 0; j < k; j++)
        {
            cin >> temp;
            tempVec.push_back(temp);
        }
        input.push_back(tempVec);
    }

    vector<int> result = mergeKArrays(input, k);
    vector<int> result2 = mergeKArraysUsingBST(input, k);
    vector<int> result3 = mergeKSortedArrays(input, k);
    vector<int> result4 = mergeKArrays2(input, k);
    vector<int> result5 = mergeWithHeapOptimized(input);
    printResult(result);
    printResult(result2);
    printResult(result3);
    printResult(result4);
    printResult(result5);
}