/*//////////////////////////// Q 284: Babbar450: Infix To Postfix ///////////////////////////
///////////////////// Q 285: Babbar450: Evaluation Of Postfix Expression ////////////////////
Given an infix expression in the form of string str. Convert this infix expression to postfix expression.

Infix expression: The expression of the form a op b. When an operator is in-between every pair of operands.
Postfix expression: The expression of the form a b op. When an operator is followed for every pair of operands.
â€‹Note: The order of precedence is: ^ greater than * equals to / greater than + equals to -. 
Example 1:

Input: str = "a+b*(c^d-e)^(f+g*h)-i"
Output: abcd^e-fgh*+^*+i-
Explanation:
After converting the infix expression 
into postfix expression, the resultant 
expression will be abcd^e-fgh*+^*+i-
Example 2:

Input: str = "A*(B+C)/D"
Output: ABC+*D/
Explanation:
After converting the infix expression 
into postfix expression, the resultant 
expression will be ABC+*D/
 
Your Task:
This is a function problem. You only need to complete the function infixToPostfix() that takes a string(Infix Expression) as a parameter and returns a string(postfix expression). The printing is done automatically by the driver code.

Expected Time Complexity: O(|str|).
Expected Auxiliary Space: O(|str|).

Constraints:
1 ≤ |str| ≤ 105

/////////////////////////////////////////////////////////////////////////////////////////////////*/

#include <iostream>
#include <stack>
#include <cmath>

using namespace std;

/* ///////////////// for converting from infix to postfix ///////////////////
1. if char is an operand, print it.
2. if stck is empty, push the operator.
3. if operand is '(' or ')' 
    a) if it is '(' push on the stack
    b) if it is ')' then pop till stack top is '('  and print them excluding '('.
4. if precedence of opernd is greated than stk.top() precedence  or stack top is '(' push operand on the stack
5. if precedence is less than stack top then pop and print from the stack untill stk top precedence become lesser than  operand or top become ')'.
6. in the end pop and print from the stack until it became empty.
*/

int precedence(char c)
{
    if (c == '^')
        return 3;
    else if (c == '*' || c == '/')
        return 2;
    else if (c == '+' || c == '-')
        return 1;
    else
        return -1;
}

string infixToPostfix(string s)
{
    stack<char> stk;
    string result = "";
    for (char c : s)
    {
        if (c == '(' || c == ')')
        {
            if (c == '(')
                stk.push(c);
            else
            {
                while (!stk.empty())
                {
                    if (stk.top() != '(')
                    {
                        cout << stk.top();
                        result.push_back(stk.top());
                        stk.pop();
                    }
                    else
                    {
                        stk.pop();
                        break;
                    }
                }
            }
        }
        else
        {
            int prec = precedence(c);
            if (prec == -1)
            {
                cout << c;
                result.push_back(c);
            }
            else if (stk.empty())
                stk.push(c);
            else
            {
                int sPrec = precedence(stk.top());
                if (prec > sPrec || stk.top() == '(')
                    stk.push(c);
                else
                {
                    while (!stk.empty())
                    {
                        if (prec <= precedence(stk.top()) && stk.top() != '(')
                        {
                            cout << stk.top();
                            result.push_back(stk.top());
                            stk.pop();
                        }
                        else
                            break;
                    }
                    stk.push(c);
                }
            }
        }
    }
    while (!stk.empty())
    {
        cout << stk.top();
        result.push_back(stk.top());
        stk.pop();
    }
    cout << endl;
    return result;
}
///////////////////////// Evaluating Postfix Expression ///////////////////////////////
/*
Given string exp representing a postfix expression, the task is to evaluate the expression and find the final value. Operators will only include the basic arithmetic operators like *, /, + and -.

Example 1:

Input: str = "231*+9-"
Output: -4
Explanation:
After solving the given expression, 
we have -4 as result.
*/
int evaluatePostfix(string input)
{
    stack<int> stk; // stack should be of int type not of char typr because
                    //then only large result of expression can be stored in it.
    for (char c : input)
    {
        if (c == '+' || c == '-' || c == '*' || c == '/' || c == '^')
        {
            int op2 = stk.top();
            stk.pop();
            int op1 = stk.top();
            stk.pop();
            int result;
            if (c == '+')
                result = op1 + op2;
            else if (c == '-')
                result = op1 - op2;
            else if (c == '*')
                result = op1 * op2;
            else if (c == '/')
                result = op1 / op2;
            else
                result = pow(op1, op2);
            stk.push(result);
        }
        else
            stk.push(c - '0');
    }
    return stk.top();
}
int main()
{

    string exp;
    cin >> exp;
    cout << evaluatePostfix(infixToPostfix(exp)) << endl;
    return 0;
}