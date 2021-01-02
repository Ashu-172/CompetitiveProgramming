/*/////////////////// Q 274: Babbar450: Implement Stack with Array from scratch //////////////////
Implement a Stack from scratch using Array and LinkedList.
////////////////////////////////////////////////////////////////////////////////////////////////*/

#include <iostream>
#include <array>
#include <iterator>

using namespace std;

template <typename T>
class stackArr
{
    T *array;
    int top = -1;
    int size = 1;

public:
    stackArr()
    {
        array = new T[1];
    }
    void push(T data)
    {
        if (top == size - 1)
        {
            T *temp = new T[2 * size];
            for (int i = 0; i <= top; i++)
                temp[i] = array[i];
            delete[] array;
            size = size * 2;
            array = temp;
        }
        array[top + 1] = data;
        top = top + 1;
    }

    void pop()
    {
        if (top < 0)
        {
            cout << "Empty Stack..!" << endl;
            return;
        }
        array[top];
        top--;
        if (top <= size / 4)
        {
            T *temp = new T[size / 2];
            for (int i = 0; i <= top; i++)
                temp[i] = array[i];
            delete[] array;
            size = size / 2;
            array = temp;
        }
    }

    void print()
    {
        for (int i = top; i >= 0; i--)
        {
            cout << array[i] << " ";
        }
        cout << endl;
    }

    T peek()
    {
        return array[top];
    }

    bool isEmpty()
    {
        return top < 0;
    }
};

int main()
{
    stackArr<int> stk;
    cout << (stk.isEmpty() ? "true" : "false");
    stk.print();
    stk.push(5);
    stk.push(10);
    stk.push(15);
    stk.push(20);
    stk.print();
    stk.pop();
    int num = stk.peek();
    cout << num << endl;
    stk.push(25);
    num = stk.peek();
    cout << num << endl;
    stk.print();
    cout << (stk.isEmpty() ? "true" : "false");
}