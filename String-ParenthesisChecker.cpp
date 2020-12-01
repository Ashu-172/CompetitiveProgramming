/*////////////////////// Q 62: Babbar450:  Parenthesis Checker /////////////////////////////
Given an expression string x. Examine whether the pairs and the orders of “{“,”}”,”(“,”)”,”[“,”]” are correct in exp.
For example, the function should return 'true' for exp = “[()]{}{[()()]()}” and 'false' for exp = “[(])”.

Example 1:

Input:
{([])}

Output: 
true

Explanation: 
{ ( [ ] ) }. Same colored brackets can form 
balaced pairs, with 0 number of 
unbalanced bracket.
Example 2:

Input: 
()

Output: 
true

Explanation: 
(). Same bracket can form balanced pairs, 
and here only 1 type of bracket is 
present and in balanced way.
Example 3:

Input: 
([]

Output: 
false

Explanation: 
([]. Here square bracket is balanced but 
the small bracket is not balanced and 
Hence , the output will be unbalanced.
Your Task:
This is a function problem. You only need to complete the function ispar() that takes a string as a parameter and returns a boolean value true if brackets are balanced else returns false. The printing is done automatically by the driver code.

Expected Time Complexity: O(|x|)
Expected Auixilliary Space: O(|x|)

Constraints:
1 ≤ |x| ≤ 105

Note: The drive code prints "balanced" if function return true, otherwise it prints "not balanced".
//////////////////////////////////////////////////////////////////////////////////*/

#include <iostream>
#include <string>
#include <stack>

using namespace std;

////////////////////// Solution 1 ///////////////////////
/*
for each type of parenthesis we can check if that is balanced.
NOTE: This solution don't work for inputs like [(]).
for that we need to use stack.
*/
bool checkPar(string input, char start, char end)
{
    int size = input.size();
    int sum = 0;
    for (int i = 0; i < size; i++)
    {
        if (input[i] == start)
            sum++;
        else if (input[i] == end)
            sum--;

        if (sum < 0)
            return false;
    }
    if (sum != 0)
        return false;
    return true;
}

bool isBalanced(string input)
{
    if (checkPar(input, '[', ']'))
        if (checkPar(input, '{', '}'))
            return checkPar(input, '(', ')');

    return false;
}

//////////////////////// Solution 2 (using stack) ///////////////////
/*
1. whenever we encounter (, {, [ we will push it on stack.
2. when current char is ) or } or ], we'll check top of the stack
    if paired paranthesis is present on top of the stack, we'll pop
    the paired char from top of the stack.
3. if top is not paired then we'll return false.
    eg if top is (, and current char is ) we'll pop (.
        if top is [ and current char is ) we'll return false because [) is not paired.

Note: if stack is empty we'll directly return false if c is ), }, ]. on empty stack top() gives segFault. 
*/
bool isPar(string input)
{
    stack<char> stk;
    for (char c : input)
    {
        if (c == '[' || c == '{' || c == '(')
            stk.push(c);
        else
        { // when stack is empty, ),},] are not allowed.
            if (stk.empty())
                return false;

            // stk.top() on empty stack cause Seg Fault, empty stack has to be checked first
            if (c == ')' && stk.top() == '(')
                stk.pop();
            else if (c == '}' && stk.top() == '{')
                stk.pop();
            else if (c == ']' && stk.top() == '[')
                stk.pop();
            else
                return false;
        }
    }
    if (stk.empty())
        return true;
    else
        return false;
}

int main()
{
    string input = "{([)]}";
    cout << isBalanced(input) << endl;
    cout << isPar(input) << endl;
}