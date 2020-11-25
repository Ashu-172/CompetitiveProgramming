/*////////////////////// Q 55: Babbar450:  Longest Common Subsequences between two strings /////////////////////////////
Given two sequences, find the length of longest subsequence present in both of them. Both the strings are of uppercase.

Example 1:

Input:
A = 6, B = 6
str1 = ABCDGH
str2 = AEDFHR
Output: 3
Explanation: LCS for input Sequences
“ABCDGH” and “AEDFHR” is “ADH” of
length 3.
Example 1:

Input:
A = 3, B = 2
str1 = ABC
str2 = AC
Output: 2
Explanation: LCS of "ABC" and "AC" is
"AC" of length 2.

Expected Time Complexity : O(|str1|*|str2|)
Expected Auxiliary Space: O(|str1|*|str2|)

Constraints:
1<=size(str1),size(str2)<=100

Refer Tushar's video for understanding the approach
https://www.youtube.com/watch?v=NnD96abizww
////////////////////////////////////////////////////////////////////////////////*/
#include <iostream>
#include <string>

using namespace std;

void printCommonSubsequence(string input1, string input2)
{
    int size1 = input1.size();
    int size2 = input2.size();

    int matrix[size1 + 1][size2 + 1];
    string result = "";
    for (int i = 0; i <= size1; i++)
        for (int j = 0; j <= size2; j++)
        { //filling first row and column with 0
            if (i == 0 || j == 0)
            {
                matrix[i][j] = 0;
            }
            //when i!=0 and j!=0
            else
            { //first row and column in matrix is extra, so when we are checking ith and jth element,
                // we'll fill [i+1][j+1] element in matrix
                if (input1[i - 1] == input2[j - 1])
                    matrix[i][j] = matrix[i - 1][j - 1] + 1;
                else
                    matrix[i][j] = max(matrix[i - 1][j], matrix[i][j - 1]);
            }
        }

    //printing Longest Common Subsequence
    for (int i = size1, j = size2; i > 0 && j > 0;)
    {
        if (matrix[i][j] == matrix[i][j - 1])
            j--;
        else if (matrix[i][j] == matrix[i - 1][j])
            i--;
        else
        {
            // moving diagonally and adding result
            result = input1[i - 1] + result;
            i--;
            j--;
        }
    }
    cout << result << endl;
}

int findCommonSubsequence(string input1, string input2)
{
    int size1 = input1.size();
    int size2 = input2.size();

    int matrix[size1 + 1][size2 + 1];

    for (int i = 0; i <= size1; i++)
        for (int j = 0; j <= size2; j++)
        { //filling first row and column with 0
            if (i == 0 || j == 0)
            {
                matrix[i][j] = 0;
            }
            //when i!=0 and j!=0
            else
            { //first row and column in matrix is extra, so when we are checking ith and jth element,
                // we'll fill [i+1][j+1] element in matrix
                if (input1[i - 1] == input2[j - 1])
                    matrix[i][j] = matrix[i - 1][j - 1] + 1;
                else
                    matrix[i][j] = max(matrix[i - 1][j], matrix[i][j - 1]);
            }
        }
    //printing matrix
    // for (int i = 0; i <= size1; i++)
    // {
    //     for (int j = 0; j <= size2; j++)
    //         cout << matrix[i][j] << " ";
    //     cout << endl;
    // }
    return matrix[size1][size2];
}

int main()
{
    string input1 = "abcdaf";
    string input2 = "acbcf";

    cout << findCommonSubsequence(input1, input2) << endl;
    printCommonSubsequence(input1, input2);
}