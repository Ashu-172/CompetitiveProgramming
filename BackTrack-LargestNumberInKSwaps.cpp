/*////////////////////////////////// Q 267: Babbar450: Find Largest Numbe in K Swaps ///////////////////////////////////
Given a number K and string str of digits denoting a positive integer, build the largest number possible by performing swap operations on the digits of str at most K times.

Example 1:

Input:
K = 4
str = "1234567"
Output:
7654321
Explanation:
Three swaps can make the
input 1234567 to 7654321, swapping 1
with 7, 2 with 6 and finally 3 with 5
Example 2:

Input:
K = 3
str = "3435335"
Output:
5543333
Explanation:
Three swaps can make the input 3435335 to 5543333, swapping 3 with 5, 4 with 5 and finally 3 with 4 

Expected Time Complexity: O(n!/(n-k)!) , where n = length of input string
Expected Auxiliary Space: O(n)


Constraints:
1 ≤ |str| ≤ 30
1 ≤ K ≤ 10
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////*/
#include <iostream>

using namespace std;
///////////////////////////////////////////////////// Solution /////////////////////////////////////////////
/*
To solve this problem we need to generate permutations using k swaps and we need to compare the string generated after every swap with the largest number string so far and save the maximum of them.

Algorithm:
1. if input string for current call is greater than the max so far, update the max.
2. iterate input from current index to end and do following.
    a. for i == index, directly call function without swapping and increment the index, it is needed because if we call function with incremented index only when we swap, then we can try out swapping only till index is less or equal to k.

    b. for i != index, check if ith char is greater than char at index, if it is then swap them and call the method recursively for incremented swap count and incremented index, to tryout swapping for next index. and after that we need to swap the values again in order to back track and repeat the same for next value of i.
    
3. The base condition is when swap count is equal to k or index is at the last char in string, then there is no more possible strings present for current call so we'll return.

Time complexity for this solution will be O(n^k) because there are n inerations in the loop and there will be k levels of recursion.
Space complexity will be O(n) storing result string.
*/
void findWithPermutations(string &input, int k, string &result, int swpCount, int index)
{
    if (result.compare(input) < 0)
        result = input;

    if (swpCount >= k || index == input.size() - 1)
        return;

    for (int i = index; i < input.size(); i++)
    {
        // skipping swap for current index, directly going for next index
        if (i == index)
        {
            findWithPermutations(input, k, result, swpCount, index + 1);
        }
        else if (input[index] < input[i]) // swapping only if ith char is greater
        {
            swap(input[index], input[i]);
            findWithPermutations(input, k, result, swpCount + 1, index + 1);
            swap(input[index], input[i]);
        }
    }
}

string findLargestNumber(string input, int k)
{
    string result = input;

    findWithPermutations(input, k, result, 0, 0);
    return result;
}

int main()
{
    string str;
    cin >> str;

    int k;
    cin >> k;
    cout << findLargestNumber(str, k);
}