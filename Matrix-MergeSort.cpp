#include <iostream>

using namespace std;

void merge(int input[][3], int columns, int begin, int mid, int end)
{
    int lLen = mid - begin + 1;
    int rLen = end - mid;

    int left[lLen];
    int right[rLen];

    for (int i = 0; i < lLen; i++)
    {
        left[i] = input[(begin + i) / columns][(begin + i) % columns];
    }

    for (int i = 0; i < rLen; i++)
    {
        right[i] = input[(mid + 1 + i) / columns][(mid + 1 + i) % columns];
    }

    int i = 0, j = 0, k = begin;
    while (i < lLen && j < rLen)
    {
        if (left[i] < right[j])
        {
            input[k / columns][k % columns] = left[i];
            i++;
            k++;
        }
        else
        {
            input[k / columns][k % columns] = right[j];
            j++;
            k++;
        }
    }
    while (i < lLen)
    {
        input[k / columns][k % columns] = left[i];
        i++;
        k++;
    }
    while (j < rLen)
    {
        input[k / columns][k % columns] = right[j];
        j++;
        k++;
    }
}

void mergeSort(int input[][3], int columns, int begin, int end)
{
    if (begin < end)
    {
        int mid = (begin + end) / 2;

        mergeSort(input, columns, begin, mid);
        mergeSort(input, columns, mid + 1, end);
        merge(input, columns, begin, mid, end);
    }
    return;
}
int main()
{
    int rows = 3, columns = 3;
    int input[rows][3] = {{1, 3, 5}, {2, 6, 9}, {3, 6, 9}};

    mergeSort(input, columns, 0, rows * columns - 1);

    for (int i = 0; i < rows * columns; i++)
        cout << input[i / columns][i % columns] << " ";
}