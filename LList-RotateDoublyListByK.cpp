/*/////////////////// Q 149: Babbar450: Rotate DoublyLinked list by N nodes //////////////////
Given a doubly linked list, rotate the linked list counter-clockwise by N nodes. Here N is a 
given positive integer and is smaller than the count of nodes in linked list.

Examples:

Input : a  b  c  d  e   N = 2
Output : c  d  e  a  b 

Input : a  b  c  d  e  f  g  h   N = 4
Output : e  f  g  h  a  b  c  d 
////////////////////////////////////////////////////////////////////////////////////////////*/
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
///////////////////////////////////// Solution 1 /////////////////////////////
/*
1. make the list circular by connecting start and End.
2. move head by k steps and break the circular list.
3. head is pointing new starting node, so return Head.
////////////////
we can do it in a single loop by making another pointer and 
    using a counter, hen counter reaches to k, we'll store kth 
    node address in a pointer, and continue the loop till end.
now we'll connect the head and end node. and break the links 
    between k and k->prev nodes.
set head to kth node and return.
*/
Node *rotateList(Node *head, int k)
{
    /*// using double loops (not nested)
    // make the list circular
    Node *p = head;
    while (p->next != NULL)
        p = p->next;

    p->next = head;
    head->prev = p;

    // moving head by k positions and breaking the circle
    while (k--)
        head = head->next;

    head->prev->next = NULL;
    head->prev = NULL;
    return head;
    */
    Node *p = head;
    Node *q = NULL;
    int counter = 0;
    while (p->next != NULL)
    {
        p = p->next;
        counter++;
        if (counter == k)
            q = p;
    }
    p->next = head;
    head->prev = p;
    q->prev->next = NULL;
    p->prev = NULL;
    head = q;
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
        int k;
        cin >> k;
        head = rotateList(head, k);

        displayList(head);
    }
    return 0;
}