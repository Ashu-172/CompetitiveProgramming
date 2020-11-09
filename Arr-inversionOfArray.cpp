/*////////////////////////////////////// Q 16: Babbar450 : Count Inversion. //////////////////////////////////
Given an array of positive integers. The task is to find inversion count of array.

Inversion Count : For an array, inversion count indicates how far (or close) the array is from being sorted. If array is already sorted then inversion count is 0. If array is sorted in reverse order that inversion count is the maximum. 
Formally, two elements a[i] and a[j] form an inversion if a[i] > a[j] and i < j.
Example:
Input:
1
5
2 4 1 3 5

Output:
3

Explanation:
Testcase 1: The sequence 2, 4, 1, 3, 5 has three inversions (2, 1), (4, 1), (4, 3).
////////////////////////////////////////////////////////////////////////////////////////////////////////////*/

#include <iostream>

using namespace std;
// we need to count every pair of (large,small) number where index of large is less than smaller element
///////////////////////////////// solution 1 (Brute force)  ////////////////////////////////////////////
int getInversionCount(int input[], int size)
{
    int count = 0;

    if (size <= 1)
        return 0;

    for (int i = 0; i < size - 1; i++)
    {
        for (int j = i + 1; j < size; j++)
        {
            //searching index of smallest element
            if (input[i] > input[j])
                count++;
        }
    }
    return count;
}
//////////////////////////////////// solution 2 (enhanced Merge sort) /////////////////////////////
int merge(int input[], int start, int mid, int end)
{
    int sizeL = mid - start + 1;
    int sizeR = end - mid;
    int count = 0;
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
        if (left[i] > right[j])
        {
            input[k++] = right[j++];
            //for  right[j], from left[i] to left[mid] will give inversion which is (mid-(start+i)+1)
            count += (mid - (start + i) + 1);
        }
        else
        {
            input[k++] = left[i++];
        }
    }
    while (i < sizeL)
    {
        input[k++] = left[i++];
    }
    while (j < sizeR)
    {
        input[k++] = right[j++];
    }
    return count;
}

int countInversionMerge(int input[], int start, int end)
{

    if (end > start)
    {
        int mid = (start + end) / 2;

        int countL = countInversionMerge(input, start, mid);
        int countR = countInversionMerge(input, mid + 1, end);

        int count = merge(input, start, mid, end);

        return countL + countR + count;
    }
    return 0;
}

int main()
{
    int input[] = {468, 335, 1, 170, 225, 479, 359, 463, 465, 206, 146, 282, 328, 462, 492, 496, 443, 328, 437, 392, 105, 403, 154, 293, 383, 422, 217, 219, 396, 448, 227, 272, 39, 370, 413, 168, 300, 36, 395, 204, 312, 323};

    int size = sizeof(input) / sizeof(int);
    //int count = getInversionCount(input, size);
    int count = countInversionMerge(input, 0, size - 1);
    cout << count << endl;

    for (int num : input)
        cout << num << ", ";
}