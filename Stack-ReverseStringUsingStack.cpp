/*/////////////////// Q 280: Babbar450: Implements K stacks in an Array //////////////////
You are given a string S, the task is to reverse the string using stack.

Example 1:

Input: S="GeeksforGeeks"
Output: skeeGrofskeeG
 
Your Task:
You don't need to read input or print anything. Your task is to complete the function reverse() which takes the string S as an input parameter and returns the reversed string.

Expected Time Complexity: O(N)
Expected Auxiliary Space: O(N)

Constraints:
1 ≤ length of the string ≤ 100
////////////////////////////////////////////////////////////////////////////////////////*/
#include <iostream>
#include <stack>
#include <cstring>

using namespace std;
char *reverse(char *str, int len);
int main()
{
    long long int t;
    cin >> t;
    while (t--)
    {
        char str[10000];
        cin >> str;
        long long int len = strlen(str);
        char *ch = reverse(str, len);
        cout << ch;
        cout << endl;
    }
    return 0;
}

// } Driver Code Ends

//return the address of the string
char *reverse(char *S, int len)
{
    stack<char> stk;
    for (int i = 0; i < len; i++)
    {
        stk.push(S[i]);
    }
    for (int i = 0; i < len; i++)
    {
        S[i] = stk.top();
        stk.pop();
    }
    return S;
}