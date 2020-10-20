/////////////////////////////////// Q2: Babbar450 : Maximum-minimum element in array /////////////////////////////
//Write a function to return minimum and maximum in an array. You program should make minimum number of comparisons.
///////////////////////////////////////////////////////////////////////////////////////////////////////////

#include <iostream>

using namespace ::std;

void getMaxMin(int input[], int size, int &min, int &max)
{
    min = input[0];
    max = input[0];

    for (int i = 1; i < size; i++)
    {
        if (input[i] > max)
        {
            max = input[i];
        }
        else if (input[i] < min)
        {
            min = input[i];
        }
    }
}

int main()
{
    int input[] = {1, 7, 19, 11, 64, 14};
    int size = sizeof(input) / sizeof(int);

    int min = 0;
    int max = 0;

    getMaxMin(input, size, min, max);
    cout << "min: " << min << " max: " << max << endl;
}

/*///////////////
since we are traversing only once, time Complexity will be O(n).,
/////////////////

/////////////////
other solution is to sort the array and take values as min = input[0], max=input[size-1];
but for this Time Complexity will be O(n * log n).
*/