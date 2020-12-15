/*///////////////// Q 96: Babbar450: Find Missing and Repeating Number from Unsorted array //////////////////
Given an unsorted array Arr of size N of positive integers. One number 'A' from set {1, 2, …N} is missing and one number 'B' occurs twice in array. Find these two numbers.

Example 1:

Input:
N = 2
Arr[] = {2, 2}
Output: 2 1
Explanation: Repeating number is 2 and 
smallest positive missing number is 1.
Example 2:

Input:
N = 3
Arr[] = {1, 3, 3}
Output: 3 2
Explanation: Repeating number is 3 and 
smallest positive missing number is 2.
Your Task:
You don't need to read input or print anything. Your task is to complete the function findTwoElement() which takes the array of integers arr and n as parameters and returns an array of integers of size 2 denoting the answer ( The first index contains B and second index contains A.)

Expected Time Complexity: O(N)
Expected Auxiliary Space: O(1)

Constraints:
1 ≤ N ≤ 105
1 ≤ Arr[i] ≤ N
///////////////////////////////////////////////////////////////////////////////////////////////////////////*/
#include <iostream>

using namespace std;

////////////////////////////////////// Solution 1 (Using two equations)/////////////////////////////////
/*
first calculate sum and square sum for n
sum = n * (n + 1) /2
squareSum = n * (n + 1) * (2n +1) /6;

these values are the sum and SquareSum when there is no repeating and missing elements.

now we'll iterate over the over the arra and calculate sum and square sum for the given array
lSum+= input[i]
lSquareSum += input[i] * input[i]


now if we calculate the difference of sum and lSum it will be the difference between the missing
number and repeated number
Example: [2, 1, 5, 4, 6, 6]  N = 6
sum = 6*7 /2 = 21
lSum = 24

sumDiff = 24-21 = 3 (difference between 6 and 3)
If this difference is positive then we can conclude that missinng number is smaller than repeated number.

Now if we calculate the difference between squareSum and lSquareSum, then it will be the difference 
between squares of missing number and repeating numbers.

squareSum = 6 * 7 * 13 /6 = 91
lSquareSum = 4 + 1 + 25 + 16 + 36 + 36 = 118

squareDiff = 118 - 91 = 27 (which is diff between 3*3 and 6*6)

lets say missing num is x and repeated num is y then we have folloing equations
        y - x     = sumDiff
        y^2 - x^2 = squareDiff

    =>  y + x = squaareDiff / sumDiff
        y + x = 27/3 = 9

now we have y+x and y-x both, we can find x and y
        y + x = 9
        y - x = 3

    => 2y = (9 + 3) = 12
    =>  y = 12/2 = 6            => y = (squareDiff / sumDiff + sumDiff) / 2

        x = y - 3 = 6 -3        => x = y - sumDiff
    =>  x = 3

so the repeating number is 6 and missing number is 3.

Time Complexity = O(n) 
Space Complexity = O(1)

NOTE: For Large input it is failing because of arithmatic overflow, solved in Gfg Solution: https://practice.geeksforgeeks.org/viewSol.php?subId=29ed90d1422ed293ed472cad5138c26f&pid=702678&user=ashutosh_17
*/

int *findMissingRepeating(int n, int *input)
{
    int gSum = n * (n + 1) / 2;
    int gSquareSum = n * (n + 1) * (2 * n + 1) / 6;
    int lSum = 0;
    int lSquareSum = 0;

    int sumDiff, squareDiff;
    int x, y;

    for (int i = 0; i < n; i++)
    {
        lSum += input[i];
        lSquareSum += input[i] * input[i];
    }

    sumDiff = lSum - gSum;
    squareDiff = lSquareSum - gSquareSum;

    y = ((squareDiff / sumDiff) + sumDiff) / 2;
    x = y - sumDiff;
    cout << x << " " << y << endl;
    static int result[2];
    result[0] = x;
    result[1] = y;
    return result;
}

int main()
{
    int n;
    cin >> n;
    int input[n];
    for (int i = 0; i < n; i++)
    {
        cin >> input[i];
    }
    findMissingRepeating(n, input);
}
