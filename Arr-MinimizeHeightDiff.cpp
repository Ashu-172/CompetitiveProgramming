/*////////////////////// Q 9: Babbar450 : Minimise the Maximum Difference Between Heights /////////////////////////////
Given an array arr[] denoting heights of N towers and a positive integer K, modify the heights of each tower either by increasing or decreasing them by K only once. Find out the minimum difference of the heights of shortest and longest modified towers.
Given an array arr of N integers. Find the contiguous sub-array with maximum sum.
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////*/

#include <iostream>

using namespace std;

/*
first we need to get the minimum number and maximum number and to get 
the minimum difference add k to minimum and subtract k from maximum.

now there are other numbers who can change the minimum difference after 
adding or subtracting k.

if we see a number for which num-k is less than min and num + k ia greater than max
then since we have to either add or subtract k from each num, this num will give 
new min or max.
                (num-k < min && num+k >max)

numbers who don't follow above condition can not change max and min heights hence
can not change minimum difference.

from the above condition we can say that numbers present within range
min+k to max-k are the only candidates to be checked 

to choose whether we should add or subtract k from such a number we can check
which operation is giving minimum difference of heights.

add = num+k
sub = num -k

since add is larger than max, if we choose add (means increasing by k), it will
be the new max hence minimum differece will be given by (add-min)

similarly sub is lesser than min, if we choose sub (means decressing by k), it
will be the new min hence minimum difference  of heights will be given by (max-sub).

to choose the correct operation ( adding k or subtracting k to num) we need to 
check which one of the above two values gives minimum difference.

        if( (max-sub) <= (add-min) ) 
            min = sub; // maximum will remain same
        else
            max = add; // minimum will remain same


here in above condition if max-sub is equal to add-min then it means num + k and num -k
has same effect on minimum difference hence we can either choose to increase num by k (by
doing max = add) or we can choose to decrese num by k (by doing min = sub).

to solve this we can sort the array and calculate min and max. And then 
we can iterate from min+k to max-k range and after calculating add and sub 
we can check above conditions and get final min and max values.
this solution will give us O(n logn) complexity because of sorting.

better approach is to iterate over the array to get initial min and max values.
and then again iterate over the array and check above condition for all the 
elements since we don't have sorted array we can not iterate with range.
*/

int getMinDiff(int input[], int size, int k)
{
    int min = input[0], max = input[0];
    int add = 0, sub = 0;

    //if size is 1 then minimum diff will be 0
    if (size == 1)
        return 0;

    // finding max and min
    for (int i = 1; i < size; i++)
    {
        if (input[i] > max)
            max = input[i];
        else if (input[i] < min)
            min = input[i];
    }
    // calcuating new min and max
    if ((max - min) >= k)
    {
        max -= k;
        min += k;
    }
    else
    {
        max += k;
        min += k;
    }

    // swapping for the case when max-k < min + k
    //eg max = 100 min 10 and k=70
    if (min > max)
        swap(min, max);

    for (int i = 0; i < size; i++)
    {
        add = input[i] + k;
        sub = input[i] - k;

        if (sub < min && add > max)
            if ((max - sub) <= (add - min))
                min = sub;
            else if ((max - sub) > (add - min))
                max = add;

        if (min > max)
            swap(min, max);
    }

    return max - min;
}

int main()
{
    int input[] = {1, 2, 3};
    int size = sizeof(input) / sizeof(int);
    int k = 1;
    int min = 5, max = 2;

    int minDiff = getMinDiff(input, size, k);
    cout << minDiff << endl;
}