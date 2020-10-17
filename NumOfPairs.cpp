///////////////////////////// CtCI P45 Example ///////////////////////////
/*////////////////////////// Problem Statement //////////////////////////
Given an array of distinct integer values, count  the number of the pairs of 
integers that have difference k. for examole, given {1, 7, 5, 9, 2, 12, 3}
and the difference k=2, there are four pairs with difference 2:
(1,3), (3, 5), (5, 7), (7, 9).
//////////////////////////////////////////////////////////////////////*/
#include <iostream>

using namespace std;

bool binarySearch(int start, int end, int num, int arr[])
{
    if (end >= start)
    {
        int mid = (start + end) / 2;
        if (arr[mid] == num)
        {
            return true;
        }
        if (arr[mid] < num)
        {
            return binarySearch(mid + 1, end, num, arr);
        }
        return binarySearch(start, mid - 1, num, arr);
    }
    return false;
}

void merge(int input[], int start, int mid, int end)
{
    int lLen = mid - start + 1;
    int rLen = end - mid;

    int left[lLen];
    int right[rLen];

    for (int i = 0; i < lLen; i++)
    {
        left[i] = input[start + i];
    }

    for (int i = 0; i < rLen; i++)
    {
        right[i] = input[mid + 1 + i];
    }

    int i = 0, j = 0, k = start;
    while (i < lLen && j < rLen)
    {
        if (left[i] > right[j])
        {
            input[k++] = right[j++];
        }
        else
        {
            input[k++] = left[i++];
        }
    }
    while (i < lLen)
    {
        input[k++] = left[i++];
    }
    while (j < rLen)
    {
        input[k++] = right[j++];
    }
}

void mergeSort(int input[], int start, int end)
{
    if (end > start)
    {
        int mid = (start + end) / 2;

        mergeSort(input, start, mid);
        mergeSort(input, mid + 1, end);
        merge(input, start, mid, end);
    }
    return;
}

int main()
{
    int len = 0;
    cin >> len;
    int arr[len];
    for (int i = 0; i < len; i++)
    {
        cin >> arr[i];
    }

    int diff;
    cin >> diff;

    mergeSort(arr, 0, len - 1);

    // for (int index = 0; index < len; index++)
    //     cout << arr[index] << endl;

    for (int i = 0; i < len; i++)
    {
        int first = arr[i];
        int second = first + diff;
        if (binarySearch(i + 1, len - 1, second, arr))
        {
            cout << " ( " << first << ", " << second << ")" << endl;
        }
    }
}