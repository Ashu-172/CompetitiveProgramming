/*///////////////// Q 92: Babbar450: search element in Rotated Sorted Array //////////////////
You are given an integer array nums sorted in ascending order, and an integer target.

Suppose that nums is rotated at some pivot unknown to you beforehand (i.e., [0,1,2,4,5,6,7] might become [4,5,6,7,0,1,2]).

If target is found in the array return its index, otherwise, return -1.

 

Example 1:

Input: nums = [4,5,6,7,0,1,2], target = 0
Output: 4
Example 2:

Input: nums = [4,5,6,7,0,1,2], target = 3
Output: -1
Example 3:

Input: nums = [1], target = 0
Output: -1
 

Constraints:

1 <= nums.length <= 5000
-10^4 <= nums[i] <= 10^4
All values of nums are unique.
nums is guranteed to be rotated at some pivot.
-10^4 <= target <= 10^4
////////////////////////////////////////////////////////////////////////////////////////////*/
#include <iostream>

using namespace std;

///////////////////////// Solution 1 //////////////////////////
/*
if we divide the array in to parts by calculating middle, we can 
    observe following points
1.  one of the two parts will always be in sorted order, hence we 
    can perform binary search on that part.
2.  other part can also be divided again in the same manner, one of
    the new two subparts will be again insorted order.

To find out the part which is already sorted we can check following conditions.
1.  if input[mid] is larger than input[start], then number of rotations are 
    greater than size/2 so the first part (start to mid) is sorted.
2.  if input[mid] is smaller than input[start], then number of rotations are
    lesser than size/2 so the second part (mid to end) is sorted.

Time complecity for this solution is same as log n for the given constraint.
*/
int binarySearch(int input[], int start, int end, int num)
{
    if (start <= end)
    {
        int mid = (start + end) / 2;
        if (input[mid] == num)
            return mid;

        if (input[mid] < num)
            return binarySearch(input, mid + 1, end, num);
        else
            return binarySearch(input, start, mid - 1, num);
    }
    return -1;
}

int findElementBinary(int input[], int start, int end, int num)
{
    if (start <= end)
    {
        int mid = (start + end) / 2;
        int result = -1;

        if (input[mid] == num)
            return mid;

        if (input[start] < input[mid]) //left part is sorted part
        {
            result = binarySearch(input, start, mid - 1, num);
            if (result == -1)
                return findElementBinary(input, mid + 1, end, num);
            else
                return result;
        }
        else
        {
            result = binarySearch(input, mid + 1, end, num);
            if (result == -1)
                return findElementBinary(input, start, mid - 1, num);
            else
                return result;
        }
    }
    return -1;
}

////////////////////////////// Solution 2 (Better solution -leet code) /////////////////////////////
int search(int A[], int n, int target)
{
    int lo = 0, hi = n - 1;
    // find the index of the smallest value using binary search.
    // Loop will terminate since mid < hi, and lo or hi will shrink by at least 1.
    // Proof by contradiction that mid < hi: if mid==hi, then lo==hi and loop would have been terminated.
    while (lo < hi)
    {
        int mid = (lo + hi) / 2;
        if (A[mid] > A[hi])
            lo = mid + 1;
        else
            hi = mid;
    }
    // lo==hi is the index of the smallest value and also the number of places rotated.
    int rot = lo;
    lo = 0;
    hi = n - 1;
    // The usual binary search and accounting for rotation.
    while (lo <= hi)
    {
        int mid = (lo + hi) / 2;
        int realmid = (mid + rot) % n;
        if (A[realmid] == target)
            return realmid;
        if (A[realmid] < target)
            lo = mid + 1;
        else
            hi = mid - 1;
    }
    return -1;
}

int main()
{
    int input[] = {4, 5, 6, 7, 0, 1, 2};
    int size = sizeof(input) / sizeof(int);
    int num = 0;

    cout << findElementBinary(input, 0, size - 1, num) << endl;
    cout << search(input, size, num) << endl;
}