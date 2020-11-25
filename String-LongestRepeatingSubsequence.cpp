/*////////////////////// Q56 : Babbar450:  Longest Repeating Subsequence /////////////////////////////
Given a string str, find length of the longest repeating subseequence such that the two subsequence don’t have same string character at same position, i.e., any i’th character in the two subsequences shouldn’t have the same index in the original string.

Constraints:
1<= T <=100
1<= N <=1000

Example:

Input:
2
3
abc
5
axxxy

Output:
0
2
////////////////////////////////////////////////////////////////////////////////////////////////////*/
//////////////////// Solution /////////////////////////
/*
Approach for this problem is same as LCS (Longest Common Subsequence)
the only difference is, here we have single string instead of two strings.

we will consider same string as input1 and input2, and follow the same process.
one more thing we need to keep check is, index j should always be greater than i,
because here we are not having two different strings, we can not access same 
position while considering sequence,
for example in string abc, we can not put i and j both on 0 or 1 or 2.
if i is 0, j should be greater than 0 to form a subsequence.

string "abc" not forming a subsequence while string "aba" is forming a 
repeating subsequence "a" of length 1.
*/
#include <iostream>
#include <string>

using namespace std;

int longestSubsequence(string input)
{
    int size = input.size();
    int matrix[size + 1][size + 1];

    for (int i = 0; i <= size; i++)
        for (int j = 0; j <= size; j++)
        {
            if (i == 0 || j == 0)
                matrix[i][j] = 0;
            else
            { // i should always be less than j, in the string
                if (input[i - 1] == input[j - 1] && j > i)
                    matrix[i][j] = matrix[i - 1][j - 1] + 1;
                else
                    matrix[i][j] = max(matrix[i - 1][j], matrix[i][j - 1]);
            }
        }

    for (int i = 0; i < (size + 1); i++)
    {
        for (int j = 0; j < size + 1; j++)
            cout << matrix[i][j] << " ";
        cout << endl;
    }

    return matrix[size][size];
}

int main()
{
    string input = "axxxy";
    cout << longestSubsequence(input) << endl;
}