/*////////////////////// Q 294: Babbar450: Implement Stack and Queue using deque ///////////////////////
Implement Stck and Queue using Deque.
//////////////////////////////////////////////////////////////////////////////////////////////////////*/
#include <iostream>

using namespace std;

template <typename T>
class Deque
{
    int size = 0;
    class Node
    {
    public:
        T data;
        Node *prev;
        Node *next;
        Node(T data)
        {
            this->data = data;
            prev = NULL;
            next = NULL;
        }
    };

public:
    Node *front;
    Node *back;
    Deque()
    {
        front = NULL;
        back = NULL;
    }

    void insert_front(T data)
    {
        Node *temp = new Node(data);
        if (size == 0)
        {
            front = temp;
            back = temp;
            size++;
            return;
        }
        temp->next = front;
        front->prev = temp;
        front = temp;
        size++;
    }

    void insert_back(T data)
    {
        Node *temp = new Node(data);
        if (size == 0)
        {
            front = temp;
            back = temp;
            size++;
            return;
        }
        temp->prev = back;
        back->next = temp;
        back = temp;
        size++;
    }

    T delete_front()
    {
        if (front == NULL)
            __throw_runtime_error("Empty Queue..!");
        Node *temp = front;
        T data = temp->data;
        front = front->next;
        if (front != NULL)
            front->prev = NULL;
        free(temp);
        size--;
        return data;
    }

    T delete_back()
    {
        if (back == NULL)
            __throw_runtime_error("Empty Queue..!");
        Node *temp = back;
        T data = temp->data;
        back = back->prev;
        if (back != NULL)
            back->next = NULL;
        free(temp);
        size--;
        return data;
    }

    int getSize()
    {
        return size;
    }

    void print()
    {
        Node *p = front;
        while (p != NULL)
        {
            cout << p->data << " ";
            p = p->next;
        }
        cout << endl;
    }
};

template <typename T>
class DqStack
{
    Deque<T> dq;

public:
    void push(T data)
    {
        dq.insert_back(data);
    }

    T pop()
    {
        return dq.delete_back();
    }

    int size()
    {
        return dq.getSize();
    }
};

template <typename T>
class DqQueue
{
    Deque<T> dq;

public:
    void enque(T data)
    {
        dq.insert_back();
    }

    T dequeue()
    {
        return dq.delete_front();
    }

    int size()
    {
        return dq.getSize();
    }
};

int main()
{
    /*
    Deque<int> dq;
    dq.insert_front(5);
    dq.insert_front(6);
    dq.insert_back(4);
    dq.print();
    cout << dq.getSize() << endl;
    dq.delete_back();
    dq.print();
    dq.delete_front();
    dq.print();
    */

    DqStack<int> stk;
    stk.push(4);
    stk.push(5);
    stk.push(6);
    cout << stk.size() << endl;
    cout << stk.pop() << endl;
    cout << stk.pop() << endl;
    cout << stk.pop() << endl;
}