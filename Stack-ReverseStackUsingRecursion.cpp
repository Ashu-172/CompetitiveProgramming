/*//////////////////////////// Q 287: Babbar450: Reverse stack with recursion ///////////////////////////
Write a program to reverse a stack using recursion. You are not allowed to use loop constructs like while, for..etc, and you can only use the following ADT functions on Stack S: 
isEmpty(S) 
push(S) 
pop(S)
///////////////////////////////////////////////////////////////////////////////////////////////////////////*/
#include <iostream>
#include <stack>

using namespace std;

void insertAtBottom(stack<int> &stk, int num)
{
    if (stk.empty())
    {
        stk.push(num);
    }
    else
    {
        int temp = stk.top();
        stk.pop();
        insertAtBottom(stk, num);
        stk.push(temp);
    }
}

/*
1. pop the top element from the stack and store in temp.
2. reverse the remaining smaller stack.
3. put the temp at the bottom of the reversed stack.
*/
void reverseStack(stack<int> &stk)
{
    if (stk.empty())
        return;

    int temp = stk.top();
    stk.pop();
    reverseStack(stk);
    insertAtBottom(stk, temp);
}

int main()
{
    stack<int> stk;

    stk.push(2);
    stk.push(4);
    stk.push(6);
    stk.push(8);
    stk.push(10);

    reverseStack(stk);

    while (stk.empty() != true)
    {
        cout << stk.top() << " ";
        stk.pop();
    }
}
