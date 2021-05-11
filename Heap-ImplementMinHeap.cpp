/*///////////////////// Concept: Implement a Min Heap ///////////////////////////////
Implement a Min Heap with Following Functions:
    1. InsertKey
    2. DeleteKey
    3. getMin
    4. extractMin
    5. decreaseKey

Reference: https://www.geeksforgeeks.org/binary-heap/
///////////////////////////////////////////////////////////////////////////////////*/
#include <iostream>
#include <algorithm>

using namespace std;

class min_heap
{
    int size = 0;
    int capacity = 0;
    int *data;

public:
    min_heap(int capacity)
    {
        this->capacity = capacity;
        this->size = 0;
        this->data = new int[capacity];
    }

    int getMin()
    {
        return data[0];
    }

    int extractMin();

    bool decreaseKey(int index, int data);

    bool deleteKey(int index);

    bool insertKey(int data);

    void printHeap();

private:
    int parent(int index)
    {
        return (index - 1) / 2;
    }

    int left(int index)
    {
        return (index * 2) + 1;
    }

    int right(int index)
    {
        return (index * 2) + 2;
    }

    void minHeapify(int index)
    {
        int l = left(index);
        int r = right(index);
        int smallest = index;

        if (l < size && data[l] < data[smallest])
            smallest = l;

        if (r < size && data[r] < data[smallest])
            smallest = r;

        if (smallest != index)
        {
            swap(data[index], data[smallest]);
            minHeapify(smallest);
        }
    }
};

int min_heap ::extractMin()
{
    if (size == 0)
        return INT_MIN;

    if (size == 1)
    {
        size--;
        return data[0];
    }

    int min = data[0];
    data[0] = data[size - 1];
    size--;
    minHeapify(0);
    return min;
}

bool min_heap ::decreaseKey(int index, int value)
{
    if (index >= size)
        return false;
    data[index] = value;
    minHeapify(0);
    return true;
}

bool min_heap ::deleteKey(int index)
{
    if (index >= size)
        return false;

    if (decreaseKey(index, INT_MAX))
    {
        size--;
        //minHeapify(0); // not needed, already done in  decreaseKey
        return true;
    }
    ///////////// Another way /////////////
    /*
    if(decreaseKey(index, INT_MIN))
    {
        size--;
        extractMin();
        return true;
    } 
    */
    return false;
}

bool min_heap ::insertKey(int value)
{
    if (size == capacity)
        return false;

    size++;
    int index = size - 1;
    data[index] = value;
    while (index != 0 && data[parent(index)] > data[index])
    {
        swap(data[index], data[parent(index)]);
        index = parent(index);
    }
    return true;
}

void min_heap ::printHeap()
{
    for (int i = 0; i < size; i++)
    {
        cout << data[i] << " ";
    }
    cout << endl;
}

int main()
{
    min_heap mHeap(11);
    mHeap.insertKey(6);
    mHeap.insertKey(3);
    mHeap.insertKey(1);
    mHeap.insertKey(15);
    mHeap.insertKey(4);
    mHeap.insertKey(45);

    mHeap.printHeap();
    cout << mHeap.extractMin() << endl;
    mHeap.printHeap();
    cout << mHeap.getMin() << endl;
    mHeap.printHeap();
    cout << mHeap.decreaseKey(0, 2) << endl;
    mHeap.printHeap();
    cout << mHeap.getMin() << endl;
    mHeap.deleteKey(4);
    mHeap.printHeap();
}