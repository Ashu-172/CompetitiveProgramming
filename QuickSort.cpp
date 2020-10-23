#include <iostream>
#include <math.h>
using namespace ::std;

/*
keep an index i = start and  pivot = input[end]
now we'll start comparing elements from j = i+1 to j = end-1 index with the pivot, if any number is less than pivot we'll put it at index i (by swapping with j) and increment i so that index i can have next smaller element.
in this way all the elements less than pivot will be places at i++ position and the end of the loop all the elements less than pivot will be places from index start to i-1, now we can swap element at i with pivot so that pivot will be at its correct place.
*/

void swap(int input[], int first, int second)
{
    int temp = input[first];
    input[first] = input[second];
    input[second] = temp;
}

int partition(int input[], int start, int end)
{
    int pivot = input[end]; //choosing end as pivot
    int i = start;
    for (int j = start; j < end; j++)
    {
        if (input[j] <= pivot) //sorting is ascending
        {
            swap(input, i, j);
            i++;
        }
    }
    swap(input, i, end);

    return i;
}
int partitionRand(int input[], int start, int end)
{
    int pivot = rand() % (end - start + 1);
    //cout << "loc: " << pivot << endl;
    swap(input, start + pivot, end);
    return partition(input, start, end);
}
void QuickSort(int input[], int start, int end)
{
    if (end > start)
    {
        //int pivot = partition(input, start, end);    //uses end index as pivot
        int pivot = partitionRand(input, start, end); // uses random index as pivot

        QuickSort(input, start, pivot - 1);
        QuickSort(input, pivot + 1, end);
    }
}

int main()
{
    int input[] = {7, 2, 11, 19, 8, 71, 1, 1, 8, 8, 8};
    int size = sizeof(input) / sizeof(int);

    QuickSort(input, 0, size - 1);

    for (int num : input)
    {
        cout << num << " ";
    }
}