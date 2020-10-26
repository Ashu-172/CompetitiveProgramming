/*////////////////////// Q 8,Q 13: Babbar450 : Largest sum contigious SubArray (kadane's algo) /////////////////////////////

Given an array arr of N integers. Find the contiguous sub-array with maximum sum.
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////*/
#include <iostream>
#include <climits>
using namespace std;

/*////////////// Solution 1 (works only if there is atlease one non negative value) //////////////
This solutin gives time complexity of O(n) since loop is iterating only once. This can also give 
start and end index for max sum SubArray.
NOTE:  Based on the next solution which is a version of this solution, for all Negative case also
Max and locations can be found, Improvement in this code is Pending.
*/
////////////////////////////////////////////////////////////////////////////////////////////////
int getStartIndex(int input[], int size, int loc)
{
    if (loc < size)
    {
        //moving index to next positive value
        for (int i = loc; i < size; i++)
        {
            if (input[i] > 0)
                return i;
        }
        return size - 1; //last index
    }
    else
        return loc; // current index
}

int findMaxSum(int input[], int size)
{
    int gStart = 0, gEnd = 0, gMax = 0, sum = 0;
    int start = getStartIndex(input, size, 0);

    for (int i = start; i < size;)
    {
        if (input[i] <= 0) //if current value is -ve
        {
            //capturing data for Max Sum
            if (gMax < sum) // if max is less than current sum
            {
                gMax = sum;
                gStart = start;
                gEnd = i - 1;
            }
        }
        sum += input[i];
        if (sum <= 0) //resetting start and sum when current sum is 0 or -ve
        {
            start = getStartIndex(input, size, i);
            if (start != i)
                i = start;
            else
                i++;
            sum = 0;
        }
        else
            i++;
    }
    //capturing data for max sum
    if (gMax < sum) // if current sum is larger than max
    {
        gMax = sum;
        gStart = start;
        gEnd = size - 1;
    }
    return gMax;
}

/////////////////////////////////////////////// Solution 2 ///////////////////////////////////////////////
int findMaxSumUpdated(int input[], int size)
{
    int gStart = 0, gEnd = 0, gMax = 0, sum = 0;
    int MaxNegative = -INT_MAX;
    bool allNegative = true;
    for (int i = 0; i < size; i++)
    {
        if (input[i] < 0) //if current value is -ve
        {
            //capturing data for Max Sum
            if (gMax < sum) // if max is less than current sum
                gMax = sum;

            //if all elemnents are negative, capturing max value
            if (input[i] > MaxNegative && allNegative == true)
                MaxNegative = input[i];
        }
        else
        {
            if (sum < 0) //resetting start and sum when current sum is 0 or -ve
                sum = 0;
            allNegative = false;
        }
        sum += input[i]; //adding current val to sum for each iteration
    }
    //if all numbers are negative, returning max
    if (allNegative)
        return MaxNegative;
    else
    {
        //capturing data for max sum
        if (gMax < sum) // if current sum is larger than max
            gMax = sum;

        return gMax;
    }
}
/*
In this solution we are iterating the array only once, hence time complexity will be O(n).
*/

/*////////////////////////////////////// Solution 3 (Kadane's Algorithm) /////////////////////////////////
Initialize:
    max_so_far = 0  or sum = 0
    max_ending_here = 0  or gMax = 0

    Simple idea of the Kadane’s algorithm is to look for all positive contiguous segments of the array (max_ending_here or sum is used for this). 
    Keep track of maximum sum contiguous segment among all positive segments (max_so_far or gMax is used for this). 
    Each time we get a positive sum compare it with max_so_far and update max_so_far if it is greater than max_so_far.

    whenever we get max_ending_here or sum < 0  reset sum to 0 so that for next positive segment elements will be added to 0.

Loop for each element of the array
  (a) max_ending_here = max_ending_here + a[i]
  (b) if(max_so_far < max_ending_here)
            max_so_far = max_ending_here
  (c) if(max_ending_here < 0)
            max_ending_here = 0
return max_so_far

NOTE: this solution do not works for all Negative case.
*/
////////////////////////////////////////////////////////////////////////////////////////////////////////

int kadaneMax(int input[], int size)
{
    int sum = 0, gMax = 0;
    for (int i = 0; i < size; i++)
    {
        sum += input[i];
        if (gMax < sum)
            gMax = sum;
        if (sum < 0)
            sum = 0;
    }
    return gMax;
}
/* Solution 2 is more optimized version of Kadane's algorithm
in solution 2 we are setting global Max only when we encounter a negative value, 
in kadane's algo we are doing it for every number.
in solution 2 we are resetting sum to 0 only when we encounter a positive number after negatives, 
means for negative number we are not resetting it, in kadane's algo we are resetting it for all the numbers.
*/

int main()
{
    int input[] = {-3, -1, 7, 2, -2, 9, 4, -8, -4, 11, -20, -1, -1, 4};
    //int input[] = {-2147483647};
    int size = sizeof(input) / sizeof(int);

    //int max = findMaxSum(input, size);

    //int max = findMaxSumUpdated(input, size);

    int max = kadaneMax(input, size);

    cout << max << endl;
}