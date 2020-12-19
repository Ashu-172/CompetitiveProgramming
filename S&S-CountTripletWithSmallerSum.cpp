/*///////////////////// Q 102: Babbar450: Count triplets with sum smaller than X ///////////////////
Given an array arr[] of distinct integers of size N and a sum value X, the task is to find count of triplets with the sum smaller than the given sum value X.

Example 1:

Input: N = 6, X = 2
arr[] = {-2, 0, 1, 3}
Output:  2
Explanation: Below are triplets with 
sum less than 2 (-2, 0, 1) and (-2, 0, 3). 

Example 2:

Input: N = 5, X = 12
arr[] = {5, 1, 3, 4, 7}
Output: 4
Explanation: Below are triplets with 
sum less than 12 (1, 3, 4), (1, 3, 5), 
(1, 3, 7) and (1, 4, 5).

Expected Time Complexity: O(N2).
Expected Auxiliary Space: O(1).

Constraints:
3 ≤ N ≤ 103
////////////////////////////////////////////////////////////////////////////////////////////////////////////*/
#include <iostream>
#include <algorithm>

using namespace std;

/*/////////////////////// Solution //////////////////////////
1) Sort the input array in increasing order.
2) Initialize result as 0.
3) Run a loop from i = 0 to n-2.  An iteration of this loop finds all
   triplets with arr[i] as first element.
     a) Initialize other two elements as corner elements of subarray
        arr[i+1..n-1], i.e., j = i+1 and k = n-1
     b) Move j and k toward each other until they meet

    1) if sum of inupt[i], input[j] and input[k] is greater than or equal to
        given sum, move k to left.
    2) if it is less than given sum, then we can conclude that for all values 
        of k from j+1 to current value will give smaller sum triplet for current i and j
        to get the count we can do k-j.
        for example in array [1,3,4,5,7], if sum of values for i=0, j=1 and k=4 is smaller 
        than the given sum, then for k = 2 to k=4 it'll be smaller. so the number of triplets 
        for current i and j will be is k-j = 4-1 = 3. (should be added to result)

        since we have processed current i, j  combinitation, we'll move j to right.
        

*/
long long getSmallerTriplet(long long input[], int size, long long sum)
{
    long long count = 0;
    sort(input, input + size);

    int result = 0;
    for (int i = 0; i < size - 2; i++)
    {
        int j = i + 1, k = size - 1;
        while (j < k)
        {
            if (input[i] + input[j] + input[k] >= sum)
                k--;
            else
            {
                result += k - j;
                j++;
            }
        }
    }
    return result;
}

int main()
{
    long long input[] = {5, 1, 3, 4, 7};
    int size = sizeof(input) / sizeof(long long);
    long long sum = 12;

    cout << getSmallerTriplet(input, size, sum) << endl;
}
