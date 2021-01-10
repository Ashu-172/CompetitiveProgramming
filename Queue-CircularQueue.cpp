/*/////////////////////////////// Q 298: Babbar450: Implement Circular Queue ////////////////////////
Implement a Circular Queue using array.
///////////////////////////////////////////////////////////////////////////////////////////////////*/
#include <iostream>

using namespace std;

class circularQueue
{
    int *arr;
    int size = 0;
    int front = -1;
    int rear = -1;

public:
    circularQueue(int n)
    {
        size = n;
        arr = new int[size];
    }

    void push(int num)
    {
        int index = (rear + 1) % size;
        if (front == index)
            __throw_overflow_error("Queue is Full..");

        arr[index] = num;
        rear = index;
        if (front == -1)
            front = rear;
    }

    int pop()
    {
        if (front == -1)
            __throw_underflow_error("Empty Queue..!");
        int num = arr[front];
        if (front == rear)
            front = rear = -1;
        else
            front = (front + 1) % size;

        return num;
    }

    int getFront()
    {
        if (front == -1)
            __throw_underflow_error("Empty Queue..!");
        return arr[front];
    }
    int getRear()
    {
        if (rear == -1)
            __throw_underflow_error("Empty Queue..!");
        return arr[rear];
    }

    void display()
    {
        if (front == -1)
            return;

        int i = front;
        if (front <= rear)
        {
            while (i <= rear)
                cout << arr[i++] << " ";
        }
        else
        {
            while (i < size)
                cout << arr[i++] << " ";
            i = 0;
            while (i <= rear)
                cout << arr[i++] << " ";
        }
        cout << endl;
    }
};

int main()
{
    circularQueue que(5);
    que.push(14);
    que.push(22);
    que.push(13);
    que.push(-6);

    que.display();

    cout << que.pop() << endl;
    cout << que.pop() << endl;
    que.display();
    cout << que.pop() << endl;
    que.push(4);
    que.push(8);
    que.push(12);
    que.display();
}