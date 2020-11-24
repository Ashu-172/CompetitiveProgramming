/*////////////////////// Q 54: Babbar450:  Longest Palindrome Substing /////////////////////////////
Given a string S, find the longest palindromic substring in S. Substring of string S: S[ i . . . . j ] where 0 ≤ i ≤ j < len(S). Palindrome string: A string which reads the same backwards. More formally, S is palindrome if reverse(S) = S. Incase of conflict, return the substring which occurs first ( with the least starting index ).

NOTE: Required Time Complexity O(n2).

Input:
The first line of input consists number of the testcases. The following T lines consist of a string each.

Output:
In each separate line print the longest palindrome of the string given in the respective test case.

Constraints:
1 ≤ T ≤ 100
1 ≤ Str Length ≤ 104

Example:
Input:
1
aaaabbaa

Output:
aabbaa

Explanation:
Testcase 1: The longest palindrome string present in the given string is "aabbaa".
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////*/
#include <iostream>
#include <cstring>
#include <string>

using namespace std;

////////////////////////////// Solution 1 (Brute Force) ///////////////////////////////
/*
Step 1: Create a function isPalindrome(str, start, end), to check if 
        string has a palindrome from index = start to index = end.
Step 2: for every sub string start=0 to size-2 and end = size-1 call
        isPalindrome() function.
Step 3: if found a palindrome, store end-start+1 in MaxLen if greater
        than maxLen and also store pIndex = start.
Note:   Loop in step 2 should run only till end-start+1 >maxLen, 
        because palindrome smaller than maxLen are not of interest.
Step 4: Repeat step 2 and 3 for end = size-1 to 1

Time complexity is (n^3)
*/

bool isPalindrome(string input, int start, int end)
{
    int size = input.size();
    if (size == 0)
        return false;
    if (size == 1)
        return true;

    for (int i = start, j = end; i < j && start < end; i++, j--)
    {
        if (input[i] != input[j])
            return false;
    }
    return true;
}

void getLargestPalindrome(string input)
{
    int size = input.size();
    int maxLen = 0, pIndex = 0;

    if (size == 1)
    {
        cout << input << endl;
        return;
    }
    for (int i = 0; i < size - 1; i++)
        for (int j = size - 1; (j > 0) && (j - i + 1 > maxLen); j--)
        {
            if (isPalindrome(input, i, j))
            {
                if (j - i + 1 > maxLen)
                {
                    maxLen = j - i + 1;
                    pIndex = i;
                }
            }
        }
    if (maxLen == 1 || maxLen == 0)
    {
        cout << input[0] << endl;
        return;
    }

    for (int i = pIndex; i < pIndex + maxLen; i++)
        cout << input[i];
    cout << endl;
}

///////////////////////// Solution 2 (DP) ////////////////////////////
/*
To improve over the brute force solution, we first observe how we can avoid unnecessary re-computation while validating palindromes. Consider the case "ababa". If we already knew that "bab" is a palindrome, it is obvious that "ababa" must be a palindrome since the two left and right end letters are the same.
*/
string getLargestPalindromeDP(string input)
{
    int size = input.size();
    bool matrix[size][size];
    memset(matrix, false, sizeof(matrix));
    int maxLen = 1;
    int pStart = 0;
    //filling matrix for size 1 and size 2 palindromes
    for (int i = 0; i < size - 1; i++)
    {
        matrix[i][i] = true;
        if (matrix[i][i + 1] = (input[i] == input[i + 1]))
        {
            pStart = i;
            maxLen = 2;
        }
    }
    matrix[size - 1][size - 1] = 1;

    //checking palindromes for length>=3
    for (int k = 3; k <= size; k++)
    {
        for (int i = 0, j = k - 1; j < size; i++, j++)
        {
            if (matrix[i + 1][j - 1] && input[i] == input[j])
            {
                matrix[i][j] = true;
                if (k > maxLen)
                {
                    pStart = i;
                    maxLen = k;
                }
            }
        }
    }
    return input.substr(pStart, maxLen);
}

///////////////////////// Solution 3 (Expend Around Center) //////////////////////
/*
we could solve it in O(n^2) time using only constant space.

We observe that a palindrome mirrors around its center. Therefore, a palindrome can be expanded from its center, and there are only 2n - 1 such centers.

there are 2n - 1 but not n centers, The reason is the center of a palindrome can be in between two letters. Such palindromes have even number of letters (such as "abba") and its center is between the two 'b's.
*/
int expandPalindrome(string input, int left, int right)
{
    int size = input.size();
    /*
    Initializing length with 0 if left != right.
    Initializing with -1 when left == right, because in first
    iteration of loop input[i] == input[j], on adding 2 to length
    we'll get correct len of 1 (-1+2 = 1)
    */
    int len = left == right ? -1 : 0;
    for (int i = left, j = right; i >= 0 && j <= size - 1; i--, j++)
    {
        if (input[i] != input[j])
            break;
        len += 2;
    }
    return len;
}

string getLongestPalindrome(string input)
{
    int size = input.size();
    int len = 0, maxLen = 1, pStart = 0;
    if (size == 0)
        return "";

    for (int i = 0; i < size - 1; i++)
    {
        // to check odd sized palindrome, center is i
        int len1 = expandPalindrome(input, i, i);
        //check for even sized palindrome, center is between i, i+1
        int len2 = expandPalindrome(input, i, i + 1);

        len = max(len1, len2);
        if (len > maxLen)
        {
            maxLen = len;
            //calculating Start Index
            pStart = i - (len - 1) / 2;
        }
    }
    return input.substr(pStart, maxLen);
}

int main()
{
    string input = "aaaabbaaaaaabb";
    getLargestPalindrome(input);
    cout << getLargestPalindromeDP(input) << endl;
    cout << getLongestPalindrome(input) << endl;
}