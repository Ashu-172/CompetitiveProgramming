/*/////////////////////////////// Q 299: Babbar450: Implement LRU Cache /////////////////////////////
The task is to design and implement methods of an LRU cache. The class has two methods get() and set() which are defined as follows.
get(x)   : Returns the value of the key x if the key exists in the cache otherwise returns -1.
set(x,y) : inserts the value if the key x is not already present. If the cache reaches its capacity it should invalidate the least recently used item before inserting the new item.
In the constructor of the class the size of the cache should be intitialized.

Example 1:

Input:
N = 2
Q = 2
Queries = SET 1 2 GET 1
Output: 2
Explanation: Cache Size = 2
SET 1 2 GET 1
SET 1 2 : 1 -> 2
GET 1 : Print the value corresponding
to Key 1, ie 2.
Example 2:

Input:
N = 2
Q = 7
Queries = SET 1 2 SET 2 3 SET 1 5
SET 4 5 SET 6 7 GET 4 GET 1
Output: 5 -1
Explanation: Cache Size = 2
SET 1 2 SET 2 3 SET 1 5 SET 4 5
SET 6 7 GET 4 GET 1
SET 1 2 : 1 -> 2
SET 2 3 : 1 -> 2, 2 -> 3 (the most
recently used one is kept at the
rightmost position) 
SET 1 5 : 2 -> 3, 1 -> 5
SET 4 5 : 1 -> 5, 4 -> 5 (Cache size
is 2, hence we delete the least
recently used key-value pair)
SET 6 7 : 4 -> 5, 6 -> 7 
GET 4 : Prints 5
GET 1 : No key-value pair having
key = 1. Hence prints -1.
Your Task:
You only need to complete the provided functions get() and set(). 

Expected Time Complexity: O(1) for both get() and set().
Expected Auxiliary Space: O(1) for both get() and set(). (though, you may use extra space for cache storage and implementation purposes).

Constraints:
1 <= N <= 1000
1 <= Q <= 100000
1 <= x, y <= 1000
///////////////////////////////////////////////////////////////////////////////////////////////////*/
//////////////// Solution 1 (Array Based Solution - using circular caache) [O(n) , O(n)]/////////////
#include <iostream>

using namespace std;

class Data
{
public:
    int key, value, age;
    Data()
    {
        key = -1;
        value = -1;
        age = -1;
    }
};

class LRUCache
{
private:
    Data *arr;
    int front, back, age, size;

    int search(int key)
    {
        int index = front;
        if (front > back)
        {
            while (index < size)
            {
                if (arr[index].key == key)
                    return index;
                index++;
            }
            index = 0;
        }
        while (index <= back)
        {
            if (arr[index].key == key)
                return index;
            index++;
        }
        return -1;
    }

public:
    // constructor for cache
    LRUCache(int cap)
    {
        arr = new Data[cap];
        front = -1;
        back = -1;
        size = cap;
        age = 0;
    }

    // this function should return value corresponding to key
    int get(int key)
    {
        int index = search(key);
        if (index == -1) // cache miss
            return -1;
        else
        { // inserting new element in cache
            Data temp = arr[index];
            if (index <= back)
            {
                while (index < back)
                {
                    arr[index] = arr[index + 1];
                    index++;
                }
            }
            else if (index == front)
            {
                front = (front + 1) % size;
                back = (back + 1) % size;
                index = back;
            }
            else
            {
                while (index < size)
                {
                    arr[index] = arr[(index + 1) % size];
                    index++;
                }
                index = 0;
                while (index < back)
                {
                    arr[index] = arr[index + 1];
                    index++;
                }
            }

            arr[index] = temp;
            arr[index].age = age;
            age++;
        }
        return arr[index].value;
    }

    // storing key, value pair
    void set(int key, int value)
    {
        int index = search(key);
        if (index == -1) // Not found
        {
            if ((back + 1) % size == front) // cache full
            {
                front = (front + 1) % size;
                back = (back + 1) % size;
                index = back;
            }
            else
            {
                back = (back + 1) % size;
                index = back;
                if (front == -1)
                    front = back;
            }
        }
        else // found : updating age
        {
            if (index <= back)
            {
                while (index < back)
                {
                    arr[index] = arr[index + 1];
                    index++;
                }
            }
            else if (index == front)
            {
                front = (front + 1) % size;
                back = (back + 1) % size;
                index = back;
            }
            else
            {
                while (index < size)
                {
                    arr[index] = arr[(index + 1) % size];
                    index++;
                }
                index = 0;
                while (index < back)
                {
                    arr[index] = arr[index + 1];
                    index++;
                }
            }
        }

        arr[index].key = key;
        arr[index].value = value;
        arr[index].age = age;
        age++;
    }
};

int main()
{
    int capacity;
    cin >> capacity;
    LRUCache *cache = new LRUCache(capacity);

    int queries;
    cin >> queries;
    while (queries--)
    {
        string q;
        cin >> q;
        if (q == "SET")
        {
            int key;
            cin >> key;
            int value;
            cin >> value;
            cache->set(key, value);
        }
        else
        {
            int key;
            cin >> key;
            cout << cache->get(key) << " ";
        }
    }
    return 0;
}