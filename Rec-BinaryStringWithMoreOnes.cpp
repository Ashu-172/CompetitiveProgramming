/*/////////////////////// Recursion:Aditya Verma: n-Bit Binary String with more 1s than 0s /////////////////////
Given a positive integer N, the task is to find all the N bit binary numbers having more than or equal 1’s than 0’s for any prefix of the number.

Example 1:

Input:  N = 2
Output: 11 10
Explanation: 11 and 10 have more than 
or equal 1's than 0's
Example 2:

Input:  N = 3
Output: 111 110 101
Explanation: 111, 110 and 101 have more 
than or equal 1's than 0's
User Task:
Your task is to complete the function NBitBinary() which takes a single number as input and returns the list of strings in decreasing order. You need not take any input or print anything.

Expected Time Complexity: O(|2N|)
Expected Auxiliary Space: O(2N)

Constraints:
1 <= N <= 20
///////////////////////////////////////////////////////////////////////////////////////////////////*/
#include <iostream>
#include <string>
#include <vector>

using namespace std;

void GenerateBinaryStrings(int ones, int zeros, string output, int n, vector<string> &result)
{
    if (ones + zeros == n)
    {
        result.push_back(output);
        return;
    }

    // for 1 we always have a choice
    GenerateBinaryStrings(ones - 1, zeros, output + "1", n, result);

    // when zeros are more than ones, then only we'll have choice for zero
    if (zeros > ones)
    {
        GenerateBinaryStrings(ones, zeros - 1, output + "0", n, result);
    }
}

vector<string> getBinaryStrings(int n)
{
    int Ones = n;
    int Zeros = n;

    vector<string> result;
    string output = "";
    GenerateBinaryStrings(Ones, Zeros, output, n, result);
    return result;
}

int main()
{
    int n;
    cin >> n;

    vector<string> result;
    result = getBinaryStrings(n);
    for (string str : result)
        cout << str << " ";
}