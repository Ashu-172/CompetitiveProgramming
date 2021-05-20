/*//////////////////////////////// Q 329: Babbar450: Minimum Sum ////////////////////////////////////
Given an array Arr of size N such that each element is from the range 0 to 9. Find the minimum possible sum of two numbers formed using the elements of the array. All digits in the given array must be used to form the two numbers.


Example 1:

Input:
N = 6
Arr[] = {6, 8, 4, 5, 2, 3}
Output: 604
Explanation: The minimum sum is formed 
by numbers 358 and 246.

Example 2:

Input:
N = 5
Arr[] = {5, 3, 0, 7, 4}
Output: 82
Explanation: The minimum sum is 
formed by numbers 35 and 047.

Expected Time Complexity: O(N*logN)
Expected Auxiliary Space: O(1)


Constraints:
1 ≤ N ≤ 10^7
0 ≤ Arr[i] ≤ 9
///////////////////////////////////////////////////////////////////////////////////////////////////*/
#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;
////////////////////////////////////////////////////////// Solution 1 ///////////////////////////////////////
/*
For input {6, 8, 4, 5, 2, 3} if we want to form smallest two numbers, we have following points to consider
    1. length of both the numbers should have difference of maximum 1. For example if if we generate numbers of length 4 and 2, then the sum will surely be larger than the sum of numbers of 3 - 3 digits. 
    2. in the generated numbers MSB should be the smallest digit and LSB should be the largest digit.
Output: 604
Explanation: The minimum sum is formed by numbers 358 and 246.

To get the smallest number first we can use MinHeap. from the min heap we'll pop the smallest elements and use them to generate smallest possible numbers. since we need to generate two smallest numbers, we need to pop two smallest numbers from the heam and use them for generating two different numbers.

Time complexity for this solution is O(n log n) and space complexity is O(n).
*/

/*
The generated numbers are very large so we need to store them in strings since long int or long long int can not hold these numbers.
for Adding these numbers we need to process them digit by digit and store the sum in another string.
*/
string addLargeNumbers(string num1, string num2)
{
    int size1 = num1.size();
    int size2 = num2.size();
    int carry = 0;

    string result = "";
    int sum;

    int i = 1;
    for (i = 1; i <= size1 && i <= size2; i++)
    {
        sum = (num1[size1 - i] - '0') + (num2[size2 - i] - '0') + carry;
        result = to_string(sum % 10) + result;
        carry = sum / 10;
    }

    while (i <= size1) // when num1 still has digits to process
    {
        sum = (num1[size1 - i] - '0') + carry;
        result = to_string(sum % 10) + result;
        carry = sum / 10;
        i++;
    }

    while (i <= size2)
    {
        sum = (num2[size2 - i] - '0') + carry;
        result = to_string(sum % 10) + result;
        carry = sum / 10;
        i++;
    }

    if (carry != 0)
        result = to_string(carry) + result;

    // removing extra 0s
    for (int i = 0; i < result.size(); i++)
    {
        if (result[i] != '0')
            return result.substr(i);
    }
    return "0";
}

string minimumSumHeap(int arr[], int n)
{
    priority_queue<int, vector<int>, greater<int>> minHeap(arr, arr + n);

    string num1 = "", num2 = "";
    while (minHeap.size() > 0)
    {
        num1 += to_string(minHeap.top());
        minHeap.pop();

        if (minHeap.size() > 0)
        {
            num2 += to_string(minHeap.top());
            minHeap.pop();
        }
    }

    return addLargeNumbers(num1, num2);
}
////////////////////////////////////////////////////// Solution 2 ////////////////////////////////////////////////
/*
In the above solution we used minHeap for getting smallest numbers, instead we can also use sorting to get the smallest numbers.
time complexity for this solution is O(n log n) and the space complexity is O(1).
*/
string minimumSumSort(int arr[], int n)
{
    sort(arr, arr + n);
    string num1 = "", num2 = "";

    for (int i = 0; i < n; i++)
    {
        if (arr[i] != 0)
        {
            if (i % 2 == 0)
                num1 += to_string(arr[i]);
            else
                num2 += to_string(arr[i]);
        }
    }

    return addLargeNumbers(num1, num2);
}
int main()
{

    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    //cout << minimumSumHeap(arr, n) << endl;
    cout << minimumSumSort(arr, n) << endl;

    return 0;
}