/*/////////////////// Q 276: Babbar450: Implement Two Stacks In an Array //////////////////
Your task is to implement  2 stacks in one array efficiently.
Example 1:

Input:
push1(2)
push1(3)
push2(4)
pop1()
pop2()
pop2()

Output:
3 4 -1

Explanation:
push1(2) the stack1 will be {2}
push1(3) the stack1 will be {2,3}
push2(4) the stack2 will be {4}
pop1()   the poped element will be 3 
from stack1 and stack1 will be {2}
pop2()   the poped element will be 4 
from stack2 and now stack2 is empty
pop2()   the stack2 is now empty hence -1 .
 
Your Task:
You don't need to read input or print anything. You are required to complete the 4 methods push1, push2 which takes one argument an integer 'x' to be pushed into stack one and two and pop1, pop2 which returns the integer poped out from stack one and two. If no integer is present in the array return -1.

Expected Time Complexity: O(1) for all the four methods.
Expected Auxiliary Space: O(1) for all the four methods.

Constraints:
1 <= Number of queries <= 100
1 <= value in the stack <= 100
The sum of elements in both the stacks < size of the given array
/////////////////////////////////////////////////////////////////////////////////////////*/
#include <iostream>

using namespace std;

class twoStacks
{
    int *arr;
    int size;
    int top1, top2;

public:
    twoStacks(int n = 100)
    {
        size = n;
        arr = new int[n];
        top1 = -1;
        top2 = size;
    }

    void push1(int x);
    void push2(int x);
    int pop1();
    int pop2();
};

int main()
{

    int T;
    cin >> T;
    while (T--)
    {
        twoStacks *sq = new twoStacks();

        int Q;
        cin >> Q;
        while (Q--)
        {
            int stack_no;
            cin >> stack_no;
            int QueryType = 0;
            cin >> QueryType;

            if (QueryType == 1)
            {
                int a;
                cin >> a;
                if (stack_no == 1)
                    sq->push1(a);
                else if (stack_no == 2)
                    sq->push2(a);
            }
            else if (QueryType == 2)
            {
                if (stack_no == 1)
                    cout << sq->pop1() << " ";
                else if (stack_no == 2)
                    cout << sq->pop2() << " ";
            }
        }
        cout << endl;
    }
}

void twoStacks ::push1(int x)
{
    if (top1 == -1)
        top1 = (size / 2) - 1;
    else
        top1--;
    arr[top1] = x;
}

/* The method push to push element into the stack 2*/
void twoStacks ::push2(int x)
{
    if (top2 == size)
        top2 = size / 2;
    else
        top2++;
    arr[top2] = x;
}

int twoStacks ::pop1()
{
    if (top1 == -1)
        return -1;
    if (top1 == (size / 2) - 1)
    {
        top1 = -1;
        return arr[(size / 2) - 1];
    }
    return arr[top1++];
}

int twoStacks ::pop2()
{
    if (top2 == size)
        return -1;
    if (top2 == size / 2)
    {
        top2 = size;
        return arr[size / 2];
    }
    return arr[top2--];
}