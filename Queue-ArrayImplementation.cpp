/*/////////////////// Q 275: Babbar450: Implement Queue using Array from Scratch //////////////////
Implement  Queue using Array.
/////////////////////////////////////////////////////////////////////////////////////////////////*/
#include <iostream>

using namespace std;

template <typename T>
class Queue
{
    int front;
    int back;
    int size;
    int capacity;
    T *array;

public:
    Queue()
    {
        front = -1;
        back = -1;
        size = 0;
        capacity = 1;
        array = new T[1];
    }

    void enque(T data)
    {
        if (size == capacity)
        {
            T *temp = new T[2 * capacity];
            capacity = capacity * 2;
            for (int i = 0; i < size; i++)
                temp[i] = array[i];
            delete[] array;
            array = temp;
        }
        array[++back] = data;
        size++;
        if (size == 1)
            front = back;
    }

    void deque()
    {
        if (size == 0)
        {
            cout << "Empty Queue..!" << endl;
            return;
        }
        front++;
        size--;
        if (size <= capacity / 4)
        {
            T *temp = new T[capacity / 2];
            for (int i = 0; i < size; i++)
            {
                temp[i] = array[i];
            }
            delete[] array;
            array = temp;
            capacity = capacity / 2;
        }
    }

    int peek()
    {
        return array[front];
    }

    void print()
    {
        for (int i = front; i <= back; i++)
            cout << array[i] << " ";
        cout << endl;
    }
};

int main()
{
    Queue<int> que;
    que.peek();
    que.enque(4);
    que.enque(8);
    que.enque(12);
    que.enque(16);
    cout << que.peek() << endl;
    que.print();
    que.deque();
    cout << que.peek() << endl;
    que.deque();
    que.print();
}