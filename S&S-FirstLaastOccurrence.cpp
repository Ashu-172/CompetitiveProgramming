/*///////////////// Q 90: Babbar450: Find First and Last position of an element in dorted array //////////////////
Given a sorted array with possibly duplicate elements, the task is to find indexes of first and last occurrences of an element x in the given array.

Note: If the number x is not found in the array just print '-1'.

Input:
The first line consists of an integer T i.e number of test cases. The first line of each test case contains two integers n and x. The second line contains n spaced integers.

Output:
Print index of the first and last occurrences of the number x with a space in between.

Constraints: 
1<=T<=100
1<=n,a[i]<=1000

Example:
Input:
2
9 5
1 3 5 5 5 5 67 123 125
9 7
1 3 5 5 5 5 7 123 125

Output:
2 5
6 6
////////////////////////////////////////////////////////////////////////////////////////////////////////////////*/
#include <iostream>

using namespace std;

///////////////////////////////// Solution 1 /////////////////////////////
/*
1. First we'll search the number using binary search.
2. if number not present we'll return -1
3. if number found then we'll move backward from loc to find start index,
    and move forward from loc to find end index.

Time complexity for this solution is log(n) + constant
    in worst case where all the elements are equal to num,
    time complexity will be  O(n).
*/
int binarySearch(int input[], int start, int end, int num)
{
    if (start <= end)
    {
        int mid = (start + end) / 2;
        if (input[mid] == num)
            return mid;

        if (input[mid] > num)
            return binarySearch(input, start, mid - 1, num);
        else
            return binarySearch(input, mid + 1, end, num);
    }
    return -1;
}

void find(int input[], int size, int num)
{
    int loc = binarySearch(input, 0, size - 1, num);
    if (loc == -1)
        cout << "-1" << endl;
    else
    {
        int start = loc - 1;
        int end = loc + 1;
        // moving back from loc to find start
        while (start >= 0)
        {
            if (input[start] < num)
                break;
            start--;
        }
        start++;

        // moving forward from loc to find end
        while (end < size)
        {
            if (input[end] > num)
                break;
            end++;
        }
        end--;
        cout << start << " " << end << endl;
    }
}

int main()
{
    int input[] = {1, 2, 2, 2, 2, 3, 4, 7, 8, 8};
    int size = 10;

    int num = 1;

    find(input, size, num);
}