/*///////////////////////// Q 291: Babbar450: Length Of the Longest Valid SubString /////////////////////
Given a string S consisting only of opening and closing parenthesis 'ie '('  and ')', find out the length of the longest valid(well-formed) parentheses substring.
NOTE: Length of smallest the valid substring ( ) is 2.

Example 1:

Input: S = "(()("
Output: 2
Explanation: The longest valid 
substring is "()". Length = 2.
Example 2:

Input: S = "()(())("
Output: 6
Explanation: The longest valid 
substring is "()(())". Length = 6.

Your Task:  
You dont need to read input or print anything. Complete the function findMaxLen() which takes S as input parameter and returns the maxlength.

Expected Time Complexity:O(n)
Expected Auxiliary Space: O(1)   

Constraints:
1 <= |S| <= 105
//////////////////////////////////////////////////////////////////////////////////////////////////////*/
#include <iostream>
#include <stack>

using namespace std;

////////////////////////////////////// Solution 1 (Brute Force) /////////////////////////////////////////
/*
A Simple Approach is to find all the substrings of given string. For every string, check if it is a valid string or not. If valid and length is more than maximum length so far, then update maximum length. We can check whether a substring is valid or not in linear time using a stack (See this for details). Time complexity of this solution is O(n^2).
Total subsequences = n(n+1)/2
Time complexity = O(n^2).
*/
class Solution
{
public:
    int validate(string input)
    {
        int len = 0;
        stack<int> stk;
        for (char c : input)
        {
            if (c == '(')
                stk.push(c);
            else if (c == ')' && stk.empty() == false)
            {
                stk.pop();
                len += 2;
            }
            else
                return 0;
        }
        return stk.empty() ? len : 0;
    }

    int findForAll(string prefix, string str)
    {
        if (str.size() == 0)
            return 0;

        prefix.push_back(str[0]);
        int max1 = validate(prefix);
        str.erase(0, 1);
        int max2 = findForAll("", str);
        int max3 = findForAll(prefix, str);
        return max(max1, max(max2, max3));
    }

    ///////////////////////////// Solution 2 O(n) //////////////////////////////
    /*
   The idea is to store indexes of previous starting brackets in a stack. The first element of the stack is a special element that provides index before the beginning of valid substring (base for next valid string). 

1) Create an empty stack and push -1 to it. 
   The first element of the stack is used 
   to provide a base for the next valid string. 

2) Initialize result as 0.

3) If the character is '(' i.e. str[i] == '('), 
   push index'i' to the stack. 
   
4) Else (if the character is ')')
   a) Pop an item from the stack (Most of the 
      time an opening bracket)
   b) If the stack is not empty, then find the
      length of current valid substring by taking 
      the difference between the current index and
      top of the stack. If current length is more 
      than the result, then update the result.
   c) If the stack is empty, push the current index
      as a base for the next valid substring.

5) Return result.
   */
    int findMaxLen(string s)
    {
        stack<int> stk;
        stk.push(-1);
        int maxLen = 0;

        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] == '(')
                stk.push(i);
            else
            {
                stk.pop();
                if (!stk.empty())
                {
                    int diff = i - stk.top();
                    maxLen = max(maxLen, diff);
                }
                else
                    stk.push(i);
            }
        }
        return maxLen;
    }
};
int main()
{
    string S;
    cin >> S;
    Solution ob;
    cout << ob.findMaxLen(S) << endl;
    cout << ob.findForAll("", S) << endl;

    return 0;
}
