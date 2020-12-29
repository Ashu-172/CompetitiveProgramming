/*///////////////////// Q 141: Babbar450: Check If Given List is Circular ///////////////////
Given a singly linked list, find if the linked list is circular or not. A linked list is called circular if it not NULL terminated and all nodes are connected in the form of a cycle. An empty linked list is considered as circular.

Example 1:

Input:
LinkedList: 1->2->3->4->5
(the first and last node is connected,
i.e. 5 --> 1)
Output: 1
///////////////////////////////////////////////////////////////////////////////////////////*/

#include <iostream>
using namespace std;

/* Link list Node */
struct Node
{
    int data;
    struct Node *next;

    Node(int x)
    {
        data = x;
        next = NULL;
    }
};

/* Function to get the middle of the linked list*/
bool isCircular(struct Node *head);

/* Driver program to test above function*/
int main()
{
    int T, i, n, l, k;

    cin >> T;

    while (T--)
    {

        cin >> n >> k;
        Node *head = NULL, *tail = NULL;
        int x;
        cin >> x;
        head = new Node(x);
        tail = head;
        for (int i = 0; i < n - 1; i++)
        {
            cin >> x;
            tail->next = new Node(x);
            tail = tail->next;
        }
        if (k == 1 && n >= 1)
            tail->next = head;

        printf("%d\n", isCircular(head));
    }
    return 0;
}

bool isCircular(Node *head)
{
    // Your code here
    Node *p = head->next;
    while (p != NULL)
    {
        if (p == head)
            return true;
        p = p->next;
    }
    return false;
}