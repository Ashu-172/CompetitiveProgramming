/*////////////////////// Q 47: Babbar450 : Check Palindrome String /////////////////////////////
Given a string S, check if it is palindrome or not.

Example 1:

Input: S = "abba"
Output: 1
Explanation: S is a palindrome
///////////////////////////////////////////////////////////////////////////////////////*/

#include <iostream>
#include <string>

using namespace std;
////////////////////////////////// Double Pointer approach ///////////////////////////////
int checkPalindrome(string input)
{
    int size = input.length();
    int i = 0;
    while (i < size / 2)
    {
        if (input[i] != input[size - i - 1])
            return 0;
        i++;
    }
    return 1;
}

int main()
{
    string input = "a";
    cout << checkPalindrome(input);
}