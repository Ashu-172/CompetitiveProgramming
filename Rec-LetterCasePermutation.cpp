/*//////////////////// Recursion:Aditya Verma: Permute a string by changing case ////////////////////////
Given a string S, we can transform every letter individually to be lowercase or uppercase to create another string.

Return a list of all possible strings we could create. You can return the output in any order.

 

Example 1:

Input: S = "a1b2"
Output: ["a1b2","a1B2","A1b2","A1B2"]
Example 2:

Input: S = "3z4"
Output: ["3z4","3Z4"]
Example 3:

Input: S = "12345"
Output: ["12345"]
Example 4:

Input: S = "0"
Output: ["0"]

Constraints:

S will be a string with length between 1 and 12.
S will consist only of letters or digits.
///////////////////////////////////////////////////////////////////////////////////////////////////////*/
#include <iostream>
#include <string>
#include <vector>

using namespace std;

////////////////////////////////// Solution 1 (Recursion) /////////////////////////////
/*
1. there are two possibilities for a char in the string. Either it can be a alphabet or it can be a digit.
2. when we'll process input string char by char we'll have two choice for each alphabet char
    1. we can convert it to lower case and put in the output
    2. we can convert it to upper case and put in the output
3. For numeric char we'll have only one choice, we have to include it as it is in the output.
4. after taking decision for the first char of the input we'll remove it from the input string.
5. Base case is when input string becomes empty, we would have processed complete input string, 
    we can print the output now.
*/
void getLetterCasePermutation(string input, string output, vector<string> &result)
{
    if (input.length() == 0)
    {
        result.push_back(output);
        return;
    }

    // if 0th char is a letter
    if (isalpha(input[0]))
    {
        string op1 = output + (char)tolower(input[0]);
        string op2 = output + (char)toupper(input[0]);
        input.erase(input.begin() + 0);
        getLetterCasePermutation(input, op1, result);
        getLetterCasePermutation(input, op2, result);
    }
    else
    {
        output.push_back(input[0]);
        input.erase(input.begin() + 0);
        getLetterCasePermutation(input, output, result);
    }
}

int main()
{
    string input = "a1b23c";
    string output = "";

    vector<string> result;

    getLetterCasePermutation(input, output, result);
    for (string str : result)
    {
        cout << str << " ";
    }
}