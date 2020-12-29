/*///////////////////// Q 145: Babbar450: Reverse a Doubly Linked List ///////////////////
Given a doubly linked list of n elements. The task is to reverse the doubly linked list.
Example 1:

Input:
LinkedList: 3 <--> 4 <--> 5
Output: 5 4 3
Example 2:

Input:
LinkedList: 75 <--> 122 <--> 59 <--> 196
Output: 196 59 122 75
Your Task:
Your task is to complete the given function reverseDLL(), which takes head reference as argument and should reverse the elements so that the tail becomes the new head and all pointers are correctly pointed. You need to return the new head of the reversed list. The printing and verification is done by the driver code.

Expected Time Complexity: O(n).
Expected Auxiliary Space: O(1).

Constraints:
1 <= number of nodes <= 103
0 <= value of nodes <= 103
////////////////////////////////////////////////////////////////////////////////////////*/
#include <iostream>

using namespace std;

struct Node
{
    int data;
    Node *next;
    Node *prev;
    Node(int x)
    {
        data = x;
        next = NULL;
        prev = NULL;
    }
};

Node *newNode(int data)
{
    Node *temp = new Node(data);

    return temp;
}

void displayList(Node *head)
{
    //Head to Tail
    while (head->next)
    {
        cout << head->data << " ";
        head = head->next;
    }
    cout << head->data;
}

int getLength(Node *head)
{
    Node *temp = head;

    int count = 0;
    while (temp->next != head)
    {
        count++;
        temp = temp->next;
    }
    return count + 1;
}

bool verify(Node *head)
{
    int fl = 0;
    int bl = 0;

    Node *temp = head;

    while (temp->next)
    {
        temp = temp->next;
        fl++;
    }

    while (temp->prev)
    {
        temp = temp->prev;
        bl++;
    }
    return fl == bl;
}

///////////////////////////////////////////// Solution 1 ///////////////////////////////////
Node *reverseDLL(Node *head)
{
    //Your code here
    Node *p = head, *temp = head;
    while (p != NULL)
    {
        temp = p->prev;
        p->prev = p->next;
        p->next = temp;
        p = p->prev;
    }
    if (temp != NULL)
        head = temp->prev;
    return head;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        Node *head = NULL, *tail = NULL;
        int x;
        cin >> x;
        head = newNode(x);
        tail = head;

        for (int i = 0; i < n - 1; i++)
        {
            cin >> x;
            Node *temp = newNode(x);
            tail->next = temp;
            temp->prev = tail;
            tail = temp;
        }
        head = reverseDLL(head);

        if (verify(head))
            displayList(head);
        else
            cout << "Your pointers are not correctly connected";

        cout << endl;
    }
    return 0;
}