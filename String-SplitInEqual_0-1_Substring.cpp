/*///////// Q 59: Babbar450: Split the Binary string into two substring with equal 0’s and 1’s //////////
Given a binary string str of length N, the task is to find the maximum count of substrings str can be 
divided into such that all the substrings are balanced i.e. they have equal number of 0s and 1s. If 
it is not possible to split str satisfying the conditions then print -1.

Example:

Input: str = “0100110101”
Output: 4
The required substrings are “01”, “0011”, “01” and “01”.

Input: str = “0111100010”
Output: 3
The required substrings are "01" "111000" " 10"
///////////////////////////////////////////////////////////////////////////////////////////////////////*/
#include <iostream>
#include <string>

using namespace std;

///////////////////// Solution 1 (counting 0s and 1s) ////////////////
/*
to solve this problem we can count number of 0s and 1s and whenever number 
of 0s and 1s are equal we found one substring with equal 0s and 1s, hence 
we can increase the count.
Time complexity O(1)  which is equal to BCR for this problem.
*/

int countSubstrings(string input)
{
    int size = input.size();
    if (size == 0)
        return -1;
    int count = 0;
    int One = 0, Zero = 0;
    for (int i = 0; i < size; i++)
    {
        if (input[i] == '0')
            Zero++;
        else
            One++;

        if (Zero == One)
            count++;
    }
    // if zeros and Ones are not equal in the end return -1
    if (Zero != One)
        return -1;

    return count;
}

/////////////////////// Solution 2 ////////////////////////
/*
we can consider each 0 as -1 and 1 remains 1, now we can get 
    sum by adding -1 for 0 and 1 for 1.
in this way whenever we encounter sum == 0, we increase the 
    count by 1. 
in the end if sum is not equal to 0, it indicates that string
    is not satisfying given condition (0s are not equal to 1s)
    in this case we'll return -1
*/

int countSubstringsII(string input)
{
    int size = input.size();
    if (size == 0)
        return -1;
    int sum = 0;
    int count = 0;
    for (int i = 0; i < size; i++)
    {
        if (input[i] == '0')
            sum--;
        else
            sum++;

        if (sum == 0)
            count++;
    }
    if (sum != 0)
        return -1;

    return count;
}

int main()
{
    string input = "011110001";
    cout << countSubstrings(input) << endl;
    cout << countSubstringsII(input) << endl;
}