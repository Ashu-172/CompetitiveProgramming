/*/////////////////////////////////// Q 295: Babbar450: Stack Permutations //////////////////////////////
A stack permutation is a permutation of objects in the given input queue which is done by transferring elements from input queue to the output queue with the help of a stack and the built-in push and pop functions.

The well defined rules are:

Only dequeue from the input queue.
Use inbuilt push, pop functions in the single stack.
Stack and input queue must be empty at the end.
Only enqueue to the output queue.
There are a huge number of permutations possible using a stack for a single input queue.
Given two arrays, both of unique elements. One represents the input queue and the other represents the output queue. Our task is to check if the given output is possible through stack permutation.

Examples:

Input : First array: 1, 2, 3  
        Second array: 2, 1, 3
Output : Yes
/////////////////////////////////////////////////////////////////////////////////////////////////////*/

#include <iostream>
#include <queue>
#include <stack>

using namespace std;
//////////////////////////////////////// Solution //////////////////////////////////////////
/*
1. check if the front of the input queue and output queue is same or not, if it is matched then pop the element from both the queues and put it back in the output queue at the end.
2. if front of the queues not matched then check the top of the stack if it is same as front of the output queue or not (if stack is not empty).
3. if matched then pop the element from the stack and output queue and push it back to the output queue.
4. if not matched then put the element in the stack.
repeat above steps until q1 becomes empty.
5. in the end if input queue and stack became empty then we can say output queue is a satck permutation of input queue since we are removing elements from input queue and stack only when that element is matched with output queue.
    if there is any element left in the input queue or stack then otput queue is not a stack permutation of input.
*/
string checkPermutation(queue<int> q1, queue<int> q2)
{
    stack<int> stk;
    while (q1.empty() != true)
    {
        if (q1.front() != q2.front())
        {
            if (stk.empty() != true)
            {
                if (stk.top() != q2.front())
                {
                    stk.push(q1.front());
                    q1.pop();
                }
                else
                {
                    stk.pop();
                    q2.push(q2.front());
                    q2.pop();
                }
            }
            else
            {
                stk.push(q1.front());
                q1.pop();
            }
        }
        else
        {
            q1.pop();
            q2.push(q2.front());
            q2.pop();
        }
    }
    if (q1.empty() && stk.empty())
        return "yes";
    else
        return "No";
}

int main()
{
    queue<int> q1;
    queue<int> q2;
    stack<int> stk;

    q1.push(1);
    q1.push(2);
    q1.push(3);

    q2.push(1);
    q2.push(2);
    q2.push(3);

    cout << checkPermutation(q1, q2) << endl;
}