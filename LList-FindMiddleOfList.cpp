/*///////////////////// Q 140: Babbar450: Find the middle Element of a linked list ///////////////////
Given a non-empty, singly linked list with head node head, return a middle node of linked list.
If there are two middle nodes, return the second middle node.

///////////////////////////////////////////////////////////////////////////////////////////////////*/
#include <iostream>

using namespace std;

struct Node
{
    int data;
    Node *next;
    Node(int val)
    {
        data = val;
        next = NULL;
    }
};

Node *inputList(int size)
{
    Node *head, *tail;
    int val;

    cin >> val;
    head = tail = new Node(val);

    while (--size)
    {
        cin >> val;
        tail->next = new Node(val);
        tail = tail->next;
    }

    return head;
}

void printList(Node *n)
{
    while (n)
    {
        cout << n->data << " ";
        n = n->next;
    }
}

Node *findMiddle(Node *start)
{
    Node *mid = start, *end = start->next;
    while (end != NULL)
    {
        if (end->next == NULL)
            return mid->next;
        mid = mid->next;
        end = end->next->next;
    }
    return mid;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        Node *head = inputList(n);
        Node *result = findMiddle(head);
        cout << result->data << endl;
    }
    return 0;
}
