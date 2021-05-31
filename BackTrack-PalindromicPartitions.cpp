/*////////////////////////////////// Q 261: Babbar450: Print All Palindromic Partitions ///////////////////////////////////
Given a string, find all possible palindromic partitions of given string.

Example:
Input: NITIN
Output: N I T I N
        N ITI N
        NITIN

Input: geeks
output: g e e k s
        g ee k s
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////*/
#include <iostream>
#include <string>
#include <vector>

using namespace std;

/*
the idea here is to take all possible substrings from starting character and add it into the prefix separated with space if it is palindromic and now repeat same process with the remaining parts of the string. if the substring is not palindromic then it can not lead to a palindromic partition so return back from there.
example: input = "iti"
                                prefix suffix
                                   ""    iti
                               /         |          \
                            i  ti       it  i     iti   ""
                             / \              
                          t i   ti  ""
                            |
                           i ""  

Here in first level we have three possible substrings starting with first character "i" which are i, it, iti. here "i" is palindromic so first we'll repeat the function for the remaining part of the string which is "ti". 
    here at second level again we have two possible substrings of "ti" which are "t" and "ti". here again "t" is palindromic so we'll repeat the function call for remaining part of string which is "i".
        at level 3 for string "i" there is only one possible substring which is "i" itself. again we'll call the function for remaining part which is empty string "" so we'll put prefix in result and return back from there (backtrack) to level 2.
    now on level two we have one more string which is "ti" here ti is not a palindrom so it can not give a palindromic partition. we'll back track from here to the previous level.
in level 1 the next substring is "it", it is not a palindrom, so we'll not call function for this and return from here to level 0 and go for the last possible substring present which is "iti". it is a palindromic string so we'll call function for the remain part of the string which is "".
since the suffix is empty "" we'll put the prefix in the result.

in this way we'll have following two solution
    i t i
    iti

Algorithm:
1. loop for generating all possible substrings from start, and do following for each
    a. check if the substring is a palindrome or not, if not then skip this and check for the next one
    b. if it is a palindromic substring then append this substring in the prifix with a space, and call the function for the remaining part of the string.

Base condition is when the suffix part becomes empty, meaning all the charactrs are processed and present in the prefix part. here put the prefix in result vector and return.

at level 1 there will be n substrings, at level two for each of them there can be n-1 substrings maximum and so on. so the time complexity is O(!n) the actual time complexity will be very less than this.
*/

bool isPalindrome(string input)
{
    for (int i = 0, j = input.size() - 1; i < j; i++, j--)
    {
        if (input[i] != input[j])
            return false;
    }
    return true;
}

void createPartitions(string prefix, string suffix, vector<string> &result)
{
    if (suffix == "")
    {
        result.push_back(prefix);
        return;
    }

    for (int i = 1; i <= suffix.size(); i++)
    {
        string str = suffix.substr(0, i);
        if (isPalindrome(str) == true)
        {
            createPartitions(prefix + " " + str, suffix.substr(i), result);
        }
    }
}

vector<string> findPalindromicPartitions(string input)
{
    string prefix = "";
    vector<string> result;
    createPartitions(prefix, input, result);
    return result;
}
int main()
{
    string s;
    cin >> s;
    vector<string> result = findPalindromicPartitions(s);
    for (string s : result)
    {
        cout << s << endl;
    }
}