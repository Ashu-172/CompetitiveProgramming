/*//////////////////////////// Q 293: Babbar450: Implement Stack Using Queue ///////////////////////////
Implement a Stack using two queues q1 and q2.

Example 1:

Input:
push(2)
push(3)
pop()
push(4)
pop()
Output: 3 4
Explanation:
push(2) the stack will be {2}
push(3) the stack will be {2 3}
pop()   poped element will be 3 the 
        stack will be {2}
push(4) the stack will be {2 4}
pop()   poped element will be 4  
Example 2:

Input:
push(2)
pop()
pop()
push(3)
Output: 2 -1
Your Task:

Since this is a function problem, you don't need to take inputs. You are required to complete the two methods push() which takes an integer 'x' as input denoting the element to be pushed into the stack and pop() which returns the integer poped out from the stack(-1 if the stack is empty).

Expected Time Complexity: O(1) for push() and O(N) for pop() (or vice-versa).
Expected Auxiliary Space: O(1) for both push() and pop().

Constraints:
1 <= Number of queries <= 100
1 <= values of the stack <= 100
//////////////////////////////////////////////////////////////////////////////////////////////////////*/
#include <iostream>
#include <queue>

using namespace std;

class QueueStack
{
private:
    queue<int> q1;
    queue<int> q2;

public:
    void push(int);
    int pop();
};

int main()
{
    int T;
    cin >> T;
    while (T--)
    {
        QueueStack *qs = new QueueStack();

        int Q;
        cin >> Q;
        while (Q--)
        {
            int QueryType = 0;
            cin >> QueryType;
            if (QueryType == 1)
            {
                int a;
                cin >> a;
                qs->push(a);
            }
            else if (QueryType == 2)
            {
                cout << qs->pop() << " ";
            }
        }
        cout << endl;
    }
}
////////////////////////////////// Solution 1 push => O(n) pop => O(1) ///////////////////////////////////////
/*
Push:
1. before pushing any element to queue 1, put all the elements from queue1 to queue2.
2. push the new element in the queue 1, so that it'll be placed at the front of the queue1.
3. now push all the elements from queue 2 to queue 1.
Pop:
1. pop from queue 1, it'll always have elements in reverse order. (like stack)
*/
#if 1
void QueueStack ::push(int x)
{
    while (q1.empty() != true)
    {
        q2.push(q1.front());
        q1.pop();
    }
    q1.push(x);
    while (q2.empty() != true)
    {
        q1.push(q2.front());
        q2.pop();
    }
}
int QueueStack ::pop()
{
    int num = -1;
    if (q1.empty() != true)
    {
        num = q1.front();
        q1.pop();
    }
    return num;
}
////////////////////////////////// Solution 2 (Push => O(1), pop => O(n)) //////////////////////////////
/*
Push:
1. push elements to queue 1, as they come.
pop:
1. put all the elements from queue 1 to queue 2 till only last element left in the queue 1.
1. capture the back or front (only one element is there) of queue 1.
3. pop the remaining element from the queue 1 to remove.
4. put all the elements from queue 2 to queue 1 back in same order.
5. return the captured element.
*/
void QueueStack ::push(int x)
{
    q1.push(x);
}

int QueueStack ::pop()
{
    while (q1.size() != 1)
    {
        q2.push(q1.front());
        q1.pop();
    }
    int num = q1.front();
    q1.pop();
    while (q2.empty() != true)
    {
        q1.push(q2.front());
        q2.pop();
    }
    return num;
}

/////////////////////////////// Solution 3 (Using Single Queue) Push => o(n) pop O(1) //////////////////////
/*  push => O(n) 
1. push the element in the queue.
2. remove all the elements except the inserted element and puch them back to the queue (Rotation)
pop => O(1)
1. pop the element from the queue.
*/
void QueueStack ::push(int x)
{
    q1.push(x);
    while (q1.front() != x)
    {
        q1.push(q1.front());
        q1.pop();
    }
}

int QueueStack ::pop()
{
    int x = q1.front();
    q1.pop();
    return x;
}
#endif

/////////////////////////////// Solution 4 (Using Single Queue) Push => O(1) pop O(n) //////////////////////
/*  push => O(1) 
1. push the element in the queue.
Pop => O(n)
1. capture the back of the queue.
2. remove all the elements from the queue and put them back till front become equal to the captured element.
3. pop the front element from the queue and return.
*/
void QueueStack ::push(int x)
{
    q1.push(x);
}

int QueueStack ::pop()
{
    int x = q1.back();
    while (q1.front() != x)
    {
        q1.push(q1.front());
        q1.pop();
    }
    q1.pop();
    return x;
}