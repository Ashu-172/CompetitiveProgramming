/*/////////////////// Q 146: Babbar450: Find pairs with given sum in doubly linked list //////////////////
Given a sorted doubly linked list of positive distinct elements, the task is to find pairs in doubly linked list whose sum is equal to given value x, without using any extra space ? 

Example:  

Input : head : 1 <-> 2 <-> 4 <-> 5 <-> 6 <-> 8 <-> 9
        x = 7
Output: (6, 1), (5,2)
Expected time complexity is O(n) and auxiliary space is O(1).
////////////////////////////////////////////////////////////////////////////////////////////////////////*/
#include <iostream>

using namespace std;

struct node
{
    int data;
    node *prev;
    node *next;
    node(int num)
    {
        data = num;
        prev = NULL;
        next = NULL;
    }
};

///////////////////////////////////// solution 1 ////////////////////////////////
/*
we'll use double pointer approach
Initialize two pointer variables to find the candidate elements in the sorted doubly linked list.Initialize first with start of 
    doubly linked list i.e; first=head and initialize second with last node of doubly linked list i.e; second=last_node.
We initialize first and second pointers as first and last nodes. Here we don’t have random access, so to find second pointer, 
    we traverse the list to initialize second.
If current sum of first and second is less than x, then we move first in forward direction. If current sum of first and second 
    element is greater than x, then we move second in backward direction.
Loop termination conditions are also different from arrays. The loop terminates when pointers cross each other (second == first) and (second->next == first).
*/

void findPairs(node *start, int num)
{
    node *p = start;
    node *q = start;

    while (q->next != NULL)
    {
        q = q->next;
    }

    while (p != q && q->next != p)
    {
        if (p->data + q->data == num)
        {
            cout << "( " << p->data << ", " << q->data << " ) ";
            p = p->next;
            q = q->prev;
        }
        else if (p->data + q->data > num)
            q = q->prev;
        else
            p = p->next;
    }
}

int main()
{
    int size;
    cin >> size;

    node *head, *tail;
    int num;
    cin >> num;
    head = new node(num);
    tail = head;
    for (int i = 1; i < size; i++)
    {
        cin >> num;
        node *temp = new node(num);
        temp->prev = tail;
        tail->next = temp;
        tail = tail->next;
    }

    cin >> num;
    findPairs(head, num);
}