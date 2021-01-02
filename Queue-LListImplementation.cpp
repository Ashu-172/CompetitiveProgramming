/*/////////////////// Q 275: Babbar450: Implement Queue using Linked List from Scratch //////////////////
Implement  Queue using Linked List.
//////////////////////////////////////////////////////////////////////////////////////////////////////*/
#include <iostream>

using namespace std;

template <typename T>
class Queue
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
    Node *front;
    Node *back;
    int size;

public:
    Queue()
    {
        size = 0;
        front = NULL;
        back = NULL;
    }

    void enque(T data)
    {
        Node *temp = new Node(data);
        if (front == NULL)
        {
            back = temp;
            front = back;
        }
        else
        {
            back->next = temp;
            back = temp;
        }
        size++;
    }

    void deque()
    {
        if (front == NULL)
        {
            cout << "Empty Queue..!" << endl;
            return;
        }
        Node *temp = front;
        front = front->next;
        free(temp);
        size--;
    }

    T peek()
    {
        if (front == NULL)
            __throw_length_error("Empty Queue..!");
        return front->data;
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

    int getSize()
    {
        return size;
    }
};

int main()
{
    Queue<int> que;
    que.enque(5);
    que.enque(10);
    que.enque(15);
    que.enque(20);
    que.print();
    cout << que.peek() << endl;
    que.deque();
    cout << que.peek() << endl;
    que.enque(25);
    cout << que.peek() << endl;
    que.print();
    cout << que.getSize() << endl;
}