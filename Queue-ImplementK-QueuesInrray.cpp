/*/////////////////////////////// Q 297: Babbar450: Implement K Queues In Array ////////////////////////
Create a data structure kQueues that represents k queues. Implementation of kQueues should use only one array, i.e., k queues should use the same array for storing elements. Following functions must be supported by kQueues.

enqueue(int x, int qn) –> adds x to queue number ‘qn’ where qn is from 0 to k-1
dequeue(int qn) –> deletes an element from queue number ‘qn’ where qn is from 0 to k-1
/////////////////////////////////////////////////////////////////////////////////////////////////////*/
#include <iostream>

using namespace std;

class kQueue
{
    int *arr;
    int *front;
    int *rear;
    int *next;
    int curr;
    int k;
    int size;

public:
    kQueue(int arrSize, int queueCount)
    {
        arr = new int[arrSize]();
        front = new int[queueCount];
        rear = new int[queueCount];
        next = new int[arrSize];

        for (int i = 0; i < queueCount; i++)
        {
            front[i] = -1;
            rear[i] = -1;
        }
        for (int i = 0; i < arrSize; i++)
            next[i] = i + 1;

        k = queueCount;
        size = arrSize;
        curr = 0;
    }

    bool isEmpty(int qId)
    {
        if (front[qId] == -1)
            return true;
        return false;
    }

    void push(int num, int qId)
    {
        arr[curr] = num;
        int temp = next[curr]; // next val of curr
        if (rear[qId] != -1)
            next[rear[qId]] = curr;
        rear[qId] = curr;
        if (front[qId] == -1)
            front[qId] = curr;
        next[curr] = -1; // pointing nothing
        curr = temp;
    }

    int pop(int qId)
    {
        if (isEmpty(qId))
            return -1;
        int res = arr[front[qId]];
        int oldCurr = curr;
        curr = front[qId];
        front[qId] = next[front[qId]];
        next[curr] = oldCurr;
        if (front[qId] == -1)
            rear[qId] = -1;
        return res;
    }

    void printQueues()
    {
        for (int i = 0; i < size; i++)
            cout << arr[i] << " ";
    }

    void printNext()
    {
        for (int i = 0; i < size; i++)
            cout << next[i] << " ";
    }
};

int main()
{
    int k = 3, n = 10;
    kQueue ks(n, k);

    // Let us put some items in queue number 2
    ks.push(15, 2);
    ks.push(45, 2);

    // Let us put some items in queue number 1
    ks.push(17, 1);
    ks.push(49, 1);
    ks.push(39, 1); //--

    // Let us put some items in queue number 0
    ks.push(11, 0);
    ks.push(9, 0);
    ks.push(7, 0);

    cout << "Dequeued element from queue 2 is " << ks.pop(2) << endl;
    cout << "Dequeued element from queue 1 is " << ks.pop(1) << endl;
    cout << "Dequeued element from queue 0 is " << ks.pop(0) << endl;
    cout << "Dequeued element from queue 2 is " << ks.pop(2) << endl;
    cout << "Dequeued element from queue 1 is " << ks.pop(1) << endl;
    cout << "Dequeued element from queue 0 is " << ks.pop(0) << endl;
    cout << "Dequeued element from queue 1 is " << ks.pop(1) << endl;
    cout << "Dequeued element from queue 0 is " << ks.pop(0) << endl;
    cout << "Dequeued element from queue 2 is " << ks.pop(2) << endl;
    cout << "Dequeued element from queue 1 is " << ks.pop(1) << endl;
    cout << "Dequeued element from queue 0 is " << ks.pop(0) << endl;

    return 0;
}