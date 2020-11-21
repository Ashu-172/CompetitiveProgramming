#include <iostream>

using namespace std;

int partition(int **input, int columns, int begin, int end)
{
    int piv = input[end / columns][end % columns];

    int i = begin;
    for (int j = begin; j < end; j++)
    {
        if (input[j / columns][j % columns] <= piv)
        {
            int temp = input[i / columns][i % columns];
            input[i / columns][i % columns] = input[j / columns][j % columns];
            input[j / columns][j % columns] = temp;
            i++;
        }
    }
    int temp = input[i / columns][i % columns];
    input[i / columns][i % columns] = input[end / columns][end % columns];
    input[end / columns][end % columns] = temp;

    return i;
}

void quickSort(int **input, int columns, int begin, int end)
{
    if (begin <= end)
    {
        int pivot = partition(input, columns, begin, end);

        quickSort(input, columns, begin, pivot - 1);
        quickSort(input, columns, pivot + 1, end);
    }
}

int main()
{
    int m, n;
    cin >> m;
    cin >> n;

    int *input[m];
    for (int i = 0; i < m; i++)
    {
        input[i] = new int[n];
        for (int j = 0; j < n; j++)
            cin >> input[i][j];
    }

    quickSort(input, n, 0, m * n - 1);

    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
            cout << input[i][j] << " ";
}