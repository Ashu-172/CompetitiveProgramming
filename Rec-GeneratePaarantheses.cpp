/*///////////////////////////Recursion:Aditya Verma: Generatae Balanced Parantheses /////////////////////////
Given n pairs of parentheses, write a function to generate all combinations of well-formed parentheses.
Example 1:

Input: n = 3
Output: ["((()))","(()())","(())()","()(())","()()()"]

xample 2:

Input: n = 1
Output: ["()"]
 
Constraints:
1 <= n <= 8
//////////////////////////////////////////////////////////////////////////////////////////////////*/
#include <iostream>
#include <string>
#include <vector>

using namespace std;

// baased on Observation 1
void GenerateParentheses1(int open, int close, string output, vector<string> &result)
{
    if (open == 0 && close == 0)
    {
        result.push_back(output);
        return;
    }

    if (open == close)
    {
        GenerateParentheses1(open - 1, close, output + "(", result);
    }
    else
    {
        if (open == 0)
            GenerateParentheses1(open, close - 1, output + ")", result);
        else
        {
            GenerateParentheses1(open - 1, close, output + "(", result);
            GenerateParentheses1(open, close - 1, output + ")", result);
        }
    }
}

// Based on Observation 2 (Notes)
void GenerateParentheses2(int open, int close, string output, vector<string> &result)
{
    if (open == 0 && close == 0)
    {
        result.push_back(output);
        return;
    }

    if (open != 0)
        GenerateParentheses2(open - 1, close, output + "(", result);

    if (close > open)
        GenerateParentheses2(open, close - 1, output + ")", result);
}

int main()
{
    int n;
    cin >> n;
    int open = n;
    int close = n;

    string output = "";
    vector<string> result1;
    vector<string> result2;

    GenerateParentheses1(open, close, output, result1);
    GenerateParentheses2(open, close, output, result2);
    for (string out : result1)
        cout << out << " ";
    cout << endl;
    for (string out : result2)
        cout << out << " ";
}