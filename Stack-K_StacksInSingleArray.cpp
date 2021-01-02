/*/////////////////// Q 278: Babbar450: Implements K stacks in an Array //////////////////
Create a data structure kStacks that represents k stacks. Implementation of kStacks should use only one array, i.e., k stacks should use the same array for storing elements. Following functions must be supported by kStacks.

push(int x, int sn) –> pushes x to stack number ‘sn’ where sn is from 0 to k-1
pop(int sn) –> pops an element from stack number ‘sn’ where sn is from 0 to k-1
////////////////////////////////////////////////////////////////////////////////////////*/
#include <iostream>

using namespace std;

class KStack
{
    int *arr;
    int *next;
    int *top;
    int last = 0;
    int k;
    int size;

public:
    KStack(int totalSize, int totalStacks)
    {
        arr = new int[totalSize]();
        next = new int[totalSize];
        top = new int[totalStacks];
        size = totalSize;
        k = totalStacks;
        for (int i = 0; i < k; i++)
            top[i] = -1;
        for (int i = 0; i < size; i++)
            next[i] = i + 1;
    }

    void push(int num, int Sn)
    {
        if (last == size)
            __throw_overflow_error("Stack is Full..!");

        int i = last;
        arr[i] = num;
        last = next[i];
        next[i] = top[Sn];
        top[Sn] = i;
    }

    int pop(int Sn)
    {
        if (top[Sn] == -1)
            __throw_underflow_error("Stack is Empty..!");
        //capturing current top
        int i = top[Sn];
        //moving top to next
        top[Sn] = next[i];
        //linking free positions
        next[i] = last;
        last = i;
        return arr[i];
    }
};

int main()
{
    int k = 1, n = 10;
    KStack ks(n, k);
    // Let us put some items in stack number 2
    ks.push(15, 2);
    ks.push(45, 2);

    // Let us put some items in stack number 1
    ks.push(17, 1);
    ks.push(49, 1);
    ks.push(39, 1);

    // Let us put some items in stack number 0
    ks.push(11, 0);
    ks.push(9, 0);
    ks.push(7, 0);

    cout << "Popped element from stack 2 is " << ks.pop(2) << endl;
    cout << "Popped element from stack 1 is " << ks.pop(1) << endl;
    cout << "Popped element from stack 0 is " << ks.pop(0) << endl;
}