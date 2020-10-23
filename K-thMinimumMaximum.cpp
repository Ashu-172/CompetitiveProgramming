/*///////////////////////////////// Q3: Babbar450 : Kth Maximum-minimum element in array /////////////////////////////
Given an array arr[] and a number K where K is smaller than size of array, the task is to find the Kth smallest element in the given array. It is given that all array elements are distinct.

Input:
The first line of input contains an integer T, denoting the number of testcases. Then T test cases follow. Each test case consists of three lines. First line of each testcase contains an integer N denoting size of the array. Second line contains N space separated integer denoting elements of the array. Third line of the test case contains an integer K.

Output:
Corresponding to each test case, print the kth smallest element in a new line.

Expected Time Complexity: O(N).
Expected Auxiliary Space: O(1).

Constraints:
1 <= T <= 100
1 <= N <= 105
1 <= arr[i] <= 105
1 <= K <= N

Example:
Input:
2
6
7 10 4 3 20 15
3
5
7 10 4 20 15
4
Output:
7
15
/////////////////////////////////////////////////////////////////////////////////////////////////////////*/

#include <iostream>
#include <algorithm>

using namespace ::std;

/////////////////////////////////////// Solution 1 (using sorting) ////////////////////////////////////////
void mearge(int input[], int start, int mid, int end)
{
    int sizeL = mid - start + 1;
    int sizeR = end - mid;
    int left[sizeL];
    int right[sizeR];

    for (int i = 0; i < sizeL; i++)
    {
        left[i] = input[start + i];
    }
    for (int i = 0; i < sizeR; i++)
    {
        right[i] = input[mid + 1 + i];
    }

    int i = 0, j = 0, k = start;
    while (i < sizeL && j < sizeR)
    {
        if (left[i] < right[j])
        {
            input[k] = left[i];
            i++;
        }
        else
        {
            input[k] = right[j];
            j++;
        }
        k++;
    }
    while (i < sizeL)
    {
        input[k] = left[i];
        i++;
        k++;
    }
    while (j < sizeR)
    {
        input[k] = right[j];
        j++;
        k++;
    }
}

void meargeSort(int input[], int start, int end)
{
    if (end > start)
    {
        int mid = (start + end) / 2;
        meargeSort(input, start, mid);
        meargeSort(input, mid + 1, end);

        mearge(input, start, mid, end);
    }
}
/*
complexity for merge sort is (n log n). for merge function complexity is O(n), where n is (end - start +1) which is number of elements it is merging.
each call to mergesort() is calling merge() exactly once.
mergesort() is dividing array into two parts at every level, for example if n=4, then at first level there will be one mergesort() call for n=4 elements. at second level there wil be 2 mergesort() call for n/2=2 elements each, at level three there will be 4 mergesort() calls for n/4 = 1 element.

Time complexity for each level will be O(n) because at each level total number of elements will be n only. for example at level 2 merge will be called 2 times with complexity O(n/2).
at level 2 time complexity  = O(n/2) + O(n/2) = O(n)

there are total log n levels present hence final time cmplexity will be   log n * O(n)  = O(n log n)
*/

///////////////////////////////////////// Solution 2 (using Quock Select) //////////////////////////////////

void swap(int *first, int *second)
{
    int temp = *first;
    *first = *second;
    *second = temp;
}

int partition(int input[], int start, int end)
{
    int pivot = input[end];

    int i = start;
    for (int j = start; j < end; j++)
    {
        if (input[j] <= pivot)
        {
            swap(&input[i], &input[j]);
            i++;
        }
    }
    swap(input[i], input[end]);
    return i;
}

int randPartition(int input[], int start, int end)
{
    int pivot = rand() % (end - start + 1);
    swap(input[start + pivot], input[end]);
    return partition(input, start, end);
}

bool quickSelect(int input[], int start, int end, int k)
{
    if (end >= start)
    {
        //int pivotLoc = partition(input, start, end);  //QuickSelect with end as pivot
        int pivotLoc = randPartition(input, start, end); //Quickselectt with random pivot

        if (pivotLoc == k)
        {
            return true;
        }

        else if (pivotLoc > k)
            return quickSelect(input, start, pivotLoc - 1, k);
        else
            return quickSelect(input, pivotLoc + 1, end, k);
    }
    return false;
}

#if 0 // not a good solution, very complex to implement and test
/////////////////////////////////////// Solution 3 Modified Quick select with median /////////////////////////

int getMedian(int input[], int end)
{
    sort(input, input + 5);
}

int searchPartition(int input[], int start, int end, int median)
{
    int pivot;
    //it is similar to randomized pivot selection, here we are searching median in the array and then putting it at end
    for (int i = start; i <= end; i++)
    {
        if (input[i] == median)
        {
            swap(input + i, input + end);
            break;
        }
    }
    return partition(input, start, end);
}

int kthMinimum(int input[], int start, int end, int k)
{
    int size = end - start + 1;
    int median[(size + 4) / 5];
    int i;
    for (i = 0; i < size / 5; i++)
        median[i] = getMedian(input + start + i * 5, 5); //passing pointer to locations from where sorting has to be done

    if (i * 5 < size)
    {
        median[i] = getMedian(input + start + i * 5, size - i * 5);
        i++;
    }

    int medOfMed = (i == 1) ? median[i - 1] : kthMinimum(median, 0, i - 1, i / 2); //i/2 is less then i

    int pivot = searchPartition(input, start, end, medOfMed);

    if (pivot == k)
        return input[pivot];
    if (pivot < k)
        return kthMinimum(input, pivot + 1, end, k);

    return kthMinimum(input, start, pivot - 1, k-pivot+start-1);
}
#endif
int main()
{
    int input[] = {1, 4, 17, 11, 2, 15, 88, 14, 119, 66, 101};
    int k = 9;
    int size = sizeof(input) / sizeof(int);
    //  for first solution
    //  meargeSort(input, 0, size - 1);

    //  for second solution
    quickSelect(input, 0, size - 1, k - 1);

    cout << endl
         << "K th Min: " << input[k - 1]; // << " K th Max: " << input[size - k];
}

/*
for merge sort solution time complexity will be O(n log n) in worst case.
for QuickSelect Solution worst case complexity wil be O(n^2) same as QuickSort. (when array is already sorted)
for avrg and best case QuickSelect solution has complixity of O(n) because k th number can occurr as pivot sooner.
*/