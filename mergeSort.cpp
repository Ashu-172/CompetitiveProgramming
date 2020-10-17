#include <iostream>

using namespace std;

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

    mergeSort(arr, 0, len - 1);

    for (int index = 0; index < len; index++)
        cout << arr[index] << endl;
}