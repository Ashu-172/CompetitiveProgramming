/*///////////////// Q 98: Babbar450: Searching in an array where adjacent differ by at most k //////////////////
A step array is an array of integer where each element has a difference of at most k with its neighbor. Given a key x, we need to find the index value of x if multiple element exist return the first occurrence of the key.

Examples:

Input : arr[] = {4, 5, 6, 7, 6}
           k = 1
           x = 6
Output : 2
The first index of 6 is 2.

Input : arr[] = {20, 40, 50, 70, 70, 60}  
          k = 20
          x = 60
Output : 5
The index of 60 is 5
//////////////////////////////////////////////////////////////////////////////////////////////////////////////*/
#include <iostream>

using namespace std;

///////////////////////////////////// Solution 1 (Linearly) //////////////////////////////////////////
int searchLinearly(int input[], int diff, int num, int size)
{
    for (int i = 0; i < size; i++)
    {
        if (input[i] == num)
            return i;
    }
    return -1;
}

///////////////////////////////// Solution 2 (linear with Jumps) /////////////////////////////////////
/*
we can use the fact that difference between two adjacent elements is maximum k.
The idea is to start comparing from the leftmost element and find the difference between current array element and x. Let this difference be ‘diff’. From the given property of array, we always know that x must be at-least ‘diff/k’ away, so instead of searching one by one, we jump ‘diff/k’.
*/
int searchLinearWithJumps(int input[], int k, int num, int size)
{
    for (int i = 0; i < size;)
    {
        if (input[i] == num)
            return i;

        int diff = abs(input[i] - num);
        if (diff > k)
            i += diff / k;
        else
            i++;
    }
    return -1;
}

int main()
{
    int input[] = {20, 40, 50, 70, 70, 60};
    int diff = 20;
    int num = 60;

    int size = sizeof(input) / sizeof(int);

    cout << searchLinearly(input, diff, num, size) << endl;
    cout << searchLinearWithJumps(input, diff, num, size) << endl;
}