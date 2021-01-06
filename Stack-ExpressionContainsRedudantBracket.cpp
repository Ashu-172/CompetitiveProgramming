/*///////////////////////// Q 292: Babbar450: Expression contains redundant bracket or not /////////////////////
Given a string of balanced expression, find if it contains a redundant parenthesis or not. A set of parenthesis are redundant if same sub-expression is surrounded by unnecessary or multiple brackets. Print ‘Yes’ if redundant else ‘No’.

Note: Expression may contain ‘+‘, ‘*‘, ‘–‘ and ‘/‘ operators. Given expression is valid and there are no white spaces present.

Example:

Input: 
((a+b))
(a+(b)/c)
(a+b*(c-d))
Output: 
Yes
Yes
No

Explanation:
1. ((a+b)) can reduced to (a+b), this Redundant
2. (a+(b)/c) can reduced to (a+b/c) because b is
surrounded by () which is redundant.
3. (a+b*(c-d)) doesn't have any redundant or multiple
brackets.
///////////////////////////////////////////////////////////////////////////////////////////////*/
#include <iostream>
#include <string>
#include <stack>

using namespace std;

////////////////////////////////////////////////// Solution ////////////////////////////////////
/*
We iterate through the given expression and for each character in the expression, if the character is a open parenthesis ‘(‘ or any of the operators or operands, we push it to the stack. If the character is close parenthesis ‘)’, then pop characters from the stack till matching open parenthesis ‘(‘ is found.
Now for redundancy two condition will arise while popping-
1. case: ((a+b))
    in this case we'll push characters till b, when we reaach to first ) we'll pop till (, now for next char which is ')', we'll find '(' on top of the stack so it is a redundant bracket, return true or "yes".
2. case (a)
    in this case we'll push characters till a, and wwhen we'll reach to ')', we'll see there is no operand in the ctack till last '(', so we can conclude that  this is a bracket around a operand which is considered redundant, so we can return true of "yes".
*/
string findRedundant(string input)
{
    stack<char> stk;
    for (char c : input)
    {
        if (c == ')')
        {
            char top = stk.top();
            bool flag = true;
            while (top != '(')
            {
                if (top == '+' || top == '-' || top == '*' || top == '/')
                    flag = false;
                top = stk.top();
                stk.pop();
            }

            if (flag == true)
                return "yes";
        }
        else
        {
            stk.push(c);
        }
    }
}

int main()
{
    string S;
    cin >> S;

    cout << findRedundant(S) << endl;

    return 0;
}