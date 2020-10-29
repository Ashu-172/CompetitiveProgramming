/*////////////////////////////////////// Q 15: Babbar450 : Merge Intervals. //////////////////////////////////
Implement next permutation, which rearranges numbers into the lexicographically next greater permutation of numbers.

If such an arrangement is not possible, it must rearrange it as the lowest possible order (i.e., sorted in ascending order).

The replacement must be in place and use only constant extra memory.

Example 1:
Input: nums = [1,2,3]
Output: [1,3,2]

Example 2:
Input: nums = [3,2,1]
Output: [1,2,3]

Example 3:
Input: nums = [1,1,5]
Output: [1,5,1]
////////////////////////////////////////////////////////////////////////////////////////////////////////////*/

#include <iostream>
#include <algorithm>

using namespace std;

void getNextPermutation(int input[], int size)
{
    /*
 find the first pair of two successive numbers a[i] and a[i-1], from the right, 
 which satisfy a[i] > a[i-1].  Now, no rearrangements to the right of a[i-1] 
 can create a larger permutation since that subarray consists of numbers in 
 descending order. Thus, we need to rearrange the numbers to the right of a[i-1] including itself.
*/
    int start = -1;
    for (int i = size - 1; i > 0; i--)
    {
        if (input[i] > input[i - 1])
        {
            start = i - 1;
            break;
        }
    }
    cout << start << endl;
    /*we need to replace the number a[i-1] with the number which is just larger than 
    itself among the numbers lying to its right section, say a[j].*/
    //starting from end because elements after start are already sorted in descending order
    if (start >= 0)
    {
        for (int j = size - 1; j > start; j--)
        {
            if (input[j] > input[start])
            {
                swap(input[j], input[start]);
                cout << input[j] << " " << j << " " << input[start] << endl;
                break;
            }
        }
    }
    /*We swap the numbers a[i-1] and a[j]. We now have the correct number at index i-1. 
    But still the current permutation isn't the permutation that we are looking for. We 
    need the smallest permutation that can be formed by using the numbers only to the 
    right of a[i−1]. Therefore, we need to place those numbers in ascending order to get
    their smallest permutation.

    But, recall that while scanning the numbers from the right, we simply kept 
    decrementing the index until we found the pair a[i]a[i] and a[i−1] where, 
    a[i] > a[i-1]. Thus, all numbers to the right of a[i−1] were already sorted in 
    descending order. Furthermore, swapping a[i-1]and a[j] didn't change that order. 
    Therefore, we simply need to reverse the numbers following a[i-1] to get the 
    next smallest lexicographic permutation.*/

    for (int i = start + 1, j = size - 1; i < j; i++, j--)
    {
        swap(input[i], input[j]);
    }
}

int main()
{
    int input[] = {1, 3, 2};
    int size = sizeof(input) / sizeof(int);
    getNextPermutation(input, size);
    for (int num : input)
        cout << num << ", ";
}