/*//////////////////////////// Q 286: Babbar450: Insert at the Bottom of the stack ///////////////////////////
Insert a given element at the bottom of the stack
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

int main()
{
    stack<int> stk;

    stk.push(2);
    stk.push(4);
    stk.push(6);
    stk.push(8);
    stk.push(10);

    insertAtBottom(stk, 12);

    while (stk.empty() != true)
    {
        cout << stk.top() << " ";
        stk.pop();
    }
}
