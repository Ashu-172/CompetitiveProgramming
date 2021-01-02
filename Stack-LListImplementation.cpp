/*/////////////////// Q 274: Babbar450: Implement Stack with LinkedList from scratch //////////////////
Implement a Stack from scratch using Array and LinkedList.
////////////////////////////////////////////////////////////////////////////////////////////////*/
#include <iostream>

using namespace std;

template <typename T>
class Stack
{
    class Node
    {
    public:
        T data;
        Node *next;

        Node(T data)
        {
            this->data = data;
            this->next = NULL;
        }
    };

    Node *top;
    int length;

public:
    Stack()
    {
        length = 0;
        top = NULL;
    }

    bool isEmpty()
    {
        return top == NULL;
    }

    T peek()
    {
        if (top == NULL)
            __throw_length_error("Empty Stack..!");

        return top->data;
    }

    void push(T data)
    {
        Node *temp = new Node(data);
        temp->next = top;
        top = temp;
        length++;
    }

    void pop()
    {
        Node *temp = top;
        top = top->next;
        free(temp);
        length--;
    }

    int size()
    {
        return length;
    }

    void print()
    {
        Node *p = top;
        while (p != NULL)
        {
            cout << p->data << " ";
            p = p->next;
        }
        cout << endl;
    }
};

int main()
{
    Stack<int> stk;
    //stk.peek();
    stk.push(5);
    stk.peek();
    stk.push(10);
    stk.push(15);
    stk.push(20);
    stk.print();
    cout << stk.peek() << endl;
    stk.pop();
    stk.push(25);
    cout << stk.peek() << endl;
    stk.print();
    stk.pop();
    stk.pop();
    stk.print();
}