/*/////////////////////////////////// Q 296: Babbar450: Queue using Stack //////////////////////////////
Implement a Queue using 2 stacks s1 and s2 .
A Query Q is of 2 Types
(i) 1 x (a query of this type means  pushing 'x' into the queue)
(ii) 2   (a query of this type means to pop element from queue and print the poped element)

Example 1:

Input:
5
1 2 1 3 2 1 4 2

Output: 
2 3

Explanation: 
In the first testcase
1 2 the queue will be {2}
1 3 the queue will be {2 3}
2   poped element will be 2 the queue 
    will be {3}
1 4 the queue will be {3 4}
2   poped element will be 3.
Example 2:

Input:
4
1 2 2 2 1 4

Output: 
2 -1

Explanation: 
In the second testcase 
1 2 the queue will be {2}
2   poped element will be 2 and 
    then the queue will be empty
2   the queue is empty and hence -1
1 4 the queue will be {4}.
Your Task:
You are required to complete the two methods push which take one argument an integer 'x' to be pushed into the queue and pop which returns a integer poped out from other queue(-1 if the queue is empty). The printing is done automatically by the driver code.

Expected Time Complexity : O(1) for push() and O(N) for pop() or O(N) for push() and O(1) for pop()  
Expected Auxilliary Space : O(1).

Constraints:
1 <= Q <= 100
1 <= x <= 100

Note:The Input/Ouput format and Example given are used for system's internal purpose, and should be used by a user for Expected Output only. As it is a function problem, hence a user should not read any input from stdin/console. The task is to complete the function specified, and not to write the full code.
///////////////////////////////////////////////////////////////////////////////////////////////////////*/
#include <iostream>
#include <stack>

using namespace std;

class StackQueue
{
private:
    stack<int> s1;
    stack<int> s2;

public:
    void push(int B);
    int pop();
};
int main()
{

    int T;
    cin >> T;
    while (T--)
    {
        StackQueue *sq = new StackQueue();
        int Q;
        cin >> Q;
        while (Q--)
        {
            int QueryType = 0;
            cin >> QueryType;
            if (QueryType == 1)
            {
                int a;
                cin >> a;
                sq->push(a);
            }
            else if (QueryType == 2)
            {
                cout << sq->pop() << " ";
            }
        }
        cout << endl;
    }
}

/*
pop: move all the elements from the stack 1 (which hold nely inserted elements) to stack 2.
     pop from stack 2.

push: if there is any element present in the staack 2 then push them to stack 1 and then push ne element to stack 1.
Time Complexity: 
        Push => O(n)
        Pop  => O(n)
*/

void StackQueue ::push(int x)
{
    while (s2.empty() != true)
    {
        s1.push(s2.top());
        s2.pop();
    }
    s1.push(x);
}

int StackQueue ::pop()
{
    int temp = -1;
    while (s1.empty() != true)
    {
        s2.push(s1.top());
        s1.pop();
    }
    if (s2.empty() != true)
    {
        temp = s2.top();
        s2.pop();
    }
    return temp;
}

/////////////////////////// Solution 2 (Optimized) ////////////////////////////
/*
in the above code, when we pop first element, we'll put all the inserted element to stack 2. nd when we insert we'll pop all the elements from stack 2 to stack 1.
but stack 2 already has elements in the order in which they should be popped from the queue. so we should not move the elements back to stack one from stack 2 before insertion, we can directly pop from stack to until it gets empty.

in this way for push operation we just have to push to the stack 1. this operation has complexity of O(1).
for pop operation we will move elements from stack1 to stack2 only when stack 2 is empty. so amortized time complexity for pop operation in O(1).
/////////////////////////////////////////////////////////////////////////////*/
void StackQueue ::push(int x)
{
    s1.push(x);
}

int StackQueue ::pop()
{
    int temp = -1;
    if (s2.empty()) // moving only if s2 is empty
        while (s1.empty() != true)
        {
            s2.push(s1.top());
            s1.pop();
        }

    if (s2.empty() != true)
    {
        temp = s2.top();
        s2.pop();
    }
    return temp;
}

//////////////////////////// Solution 3 (using Recursion) ///////////////////////
/*
we can do the pop operatoin using recursion. in this case we only need one stack.
*/
int StackQueue ::pop()
{
    int result;
    if (s1.empty())
        return -1;

    int temp = s1.top();
    s1.pop();
    if (s1.empty())
        result = temp;
    else
    {
        result = pop();
        s1.push(temp);
    }
    return result;
}