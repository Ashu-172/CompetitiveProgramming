/*/////////////////// Q 281: Babbar450: Design a stack that supports getMin() in O(1) //////////////////
Question: Design a Data Structure SpecialStack that supports all the stack operations like push(), pop(), isEmpty(), isFull() and an additional operation getMin() which should return minimum element from the SpecialStack. All these operations of SpecialStack must be O(1). To implement SpecialStack, you should only use standard Stack data structure and no other data structure like arrays, list, .. etc. 
Example: 

Consider the following SpecialStack
16  --> TOP
15
29
19
18

When getMin() is called it should 
return 15, which is the minimum 
element in the current stack. 

If we do pop two times on stack, 
the stack becomes
29  --> TOP
19
18

When getMin() is called, it should 
return 18 which is the minimum in 
the current stack.
////////////////////////////////////////////////////////////////////////////////////////*/
#include <iostream>
#include <stack>

using namespace std;
/////////////////// Solution 1 (Using extra stack for Minimum values) //////////////////
class SpecialStack
{
    stack<int> sStack;
    int size;
    stack<int> min;

public:
    SpecialStack(int n)
    {
        size = n;
    }

    void push(int num)
    {
        sStack.push(num);
        if (min.size() == 0)
            min.push(num);
        else
        {
            if (num < min.top())
                min.push(num);
        }
    }

    int pop()
    {
        int num = sStack.top();
        sStack.pop();
        if (num == min.top())
            min.pop();
        return num;
    }

    bool isFull()
    {
        return sStack.size() == size;
    }

    bool isEmpty()
    {
        return sStack.size() == 0;
    }

    int getMin()
    {
        return min.top();
    }
};
///////////////////////////////////// Solution 2 O(1) space ///////////////////////////////////
/*
How does this approach work?
When element to be inserted is less than minEle, we insert “2x – minEle”. The important thing to note is, 2x – minEle will always be less than x (proved below), i.e., new minEle and while popping out this element we will see that something unusual has happened as the popped element is less than the minEle. So we will be updating minEle.

How 2*x - minEle is less than x in push()? 
x < minEle which means x - minEle < 0

// Adding x on both sides
x - minEle + x < 0 + x 

2*x - minEle < x 

We can conclude 2*x - minEle < new minEle 
-----------------------------------------------------------------------------------------------------------------
While popping out, if we find the element(y) less than the current minEle, we find the new minEle = 2*minEle – y.

How previous minimum element, prevMinEle is, 2*minEle - y
in pop() is y the popped element?

 // We pushed y as 2x - prevMinEle. Here 
 // prevMinEle is minEle before y was inserted
 y = 2*x - prevMinEle  

 // Value of minEle was made equal to x
 minEle = x .
    
 prevminEle = 2 * x - y 
            = 2 * minEle - y

Example:
    lets say stack has one element which is 2, so this will be the min also.
    1. now we are pushing 1 to the stack, but 1 is lessthan current min so we'll do following calculation
        y   = 2 * x -min
            = 2 * 1 -2
            = 0
        And min = x = 1

        Now we'll push y to the stack and new min is 1. (in this case top will be smaller than the in)

    2. now if we want to pop  from the stack, we'll check if the top element is smaller than min, that 
        means the element which will be popped is the min in this case.
        so result will be 1.
        we also need to update the min to prev min value, which we'll calculate with the top of the stack
            prevMin = 2*min - y 
                    = 2*1 - 0         here 0 is top of the stack and 1 is current min
                    = 2.
            
*/
class SpecialStack2
{
    stack<int> stk;
    int size;
    int min;

public:
    SpecialStack2(int n)
    {
        size = n;
    }

    void push(int x)
    {
        if (stk.size() == 0)
        {
            stk.push(x);
            min = x;
            return;
        }

        if (x < min)
        {
            stk.push(2 * x - min);
            min = x;
        }
        else
            stk.push(x);
    }

    int pop()
    {
        int y = stk.top();
        stk.pop();
        if (y < min)
        {
            int x = min;
            min = 2 * x - y;
            return x;
        }
        return y;
    }

    bool isFull()
    {
        return stk.size() == size;
    }

    bool isEmpty()
    {
        return stk.size() == 0;
    }

    int getMin()
    {
        return min;
    }
};

int main()
{
    int n;
    cin >> n;
    SpecialStack2 stk(n);
    stk.push(18);
    stk.push(19);
    stk.push(29);
    stk.push(15);
    stk.push(16);
    cout << stk.getMin() << endl;
    cout << stk.pop() << endl;
    cout << stk.pop() << endl;
    cout << stk.getMin() << endl;
}