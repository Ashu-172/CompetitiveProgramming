/*///////////////////// Concept: Implement a Max Heap ///////////////////////////////
Implement a Max Heap with Following Functions:
    1. InsertKey
    2. DeleteKey
    3. getMax
    4. extractMax
    5. replaceKey

Reference: https://www.geeksforgeeks.org/binary-heap/
///////////////////////////////////////////////////////////////////////////////////*/
#include <iostream>
#include <algorithm>

using namespace std;

class max_heap
{
    int size = 0;
    int capacity = 0;
    int *data;

public:
    max_heap(int capacity)
    {
        this->capacity = capacity;
        this->size = 0;
        this->data = new int[capacity];
    }

    int getMax()
    {
        return data[0];
    }

    int extractMax();

    bool replaceKey(int index, int data);

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

    void maxHeapify(int index)
    {
        int l = left(index);
        int r = right(index);
        int largest = index;

        if (l < size && data[l] > data[largest])
            largest = l;

        if (r < size && data[r] > data[largest])
            largest = r;

        if (largest != index)
        {
            swap(data[index], data[largest]);
            maxHeapify(largest);
        }
    }
};

int max_heap ::extractMax()
{
    if (size == 0)
        return INT_MAX;

    if (size == 1)
    {
        size--;
        return data[0];
    }

    int max = data[0];
    data[0] = data[size - 1];
    size--;
    maxHeapify(0);
    return max;
}

bool max_heap ::replaceKey(int index, int value)
{
    if (index >= size)
        return false;
    data[index] = value;
    maxHeapify(0);
    return true;
}

bool max_heap ::deleteKey(int index)
{
    if (index >= size)
        return false;

    if (replaceKey(index, INT_MIN))
    {
        size--;
        //minHeapify(0); // not needed, already done in  decreaseKey
        return true;
    }
    ///////////// Another way /////////////
    /*
    if(decreaseKey(index, INT_MAX))
    {
        size--;
        extractMax();
        return true;
    } 
    */
    return false;
}

bool max_heap ::insertKey(int value)
{
    if (size == capacity)
        return false;

    size++;
    int index = size - 1;
    data[index] = value;
    while (index != 0 && data[parent(index)] < data[index])
    {
        swap(data[index], data[parent(index)]);
        index = parent(index);
    }
    return true;
}

void max_heap ::printHeap()
{
    for (int i = 0; i < size; i++)
    {
        cout << data[i] << " ";
    }
    cout << endl;
}

int main()
{
    max_heap mHeap(11);
    mHeap.insertKey(6);
    mHeap.insertKey(3);
    mHeap.insertKey(1);
    mHeap.insertKey(15);
    mHeap.insertKey(4);
    mHeap.insertKey(45);

    mHeap.printHeap();
    cout << mHeap.extractMax() << endl;
    mHeap.printHeap();
    cout << mHeap.getMax() << endl;
    mHeap.printHeap();
    cout << mHeap.replaceKey(0, 2) << endl;
    mHeap.printHeap();
    cout << mHeap.getMax() << endl;
    mHeap.deleteKey(4);
    mHeap.printHeap();
}