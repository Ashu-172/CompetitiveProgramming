#include <iostream>

using namespace std;

void rotateArr(int input[], int size)
{
    if (size > 0)
    {
        int temp = input[size - 1];

        for (size_t i = size - 1; i > 0; i--)
        {
            input[i] = input[i - 1];
        }
        input[0] = temp;
    }
}

int main()
{

    int input[] = {1, 7, 2, 9, 11};
    int size = sizeof(input) / sizeof(int);
    rotateArr(input, size);
    for (int n : input)
        cout << n << " ";
    cout << endl;
}