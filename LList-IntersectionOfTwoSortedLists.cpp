/*///////////////////// Q 136: Babbar450: Intersection of two sorted Linked Lists ///////////////////
Given two lists sorted in increasing order, create a new list representing the intersection of the 
two lists. The new list should be made with its own memory — the original lists should not be changed.

Example 1:

Input:
L1 = 1->2->3->4->6
L2 = 2->4->6->8
Output: 2 4 6
Explanation: For the given first two
linked list, 2, 4 and 6 are the elements
in the intersection.
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

Node *findIntersection(Node *head1, Node *head2);

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, m;
        cin >> n >> m;

        Node *head1 = inputList(n);
        Node *head2 = inputList(m);

        Node *result = findIntersection(head1, head2);

        printList(result);
        cout << endl;
    }
    return 0;
}

//////////////////////////////////// Solution 1 //////////////////////////////////////
/*
1. traverse over the lists until any one of them reached to the end, and do following
    a) if pointers of both the lists has same data then put it in a new Node, and 
        if the start is null then make start point to new node else make prev node to
        point to the new node and move prev to point to the new node.
    b) if both the pointers has different data then move the pointer forward which 
        has smaller value.
2. when any of the loop reached to the end there is no possibility to have anymore 
    common data in the lists, so now we'll set prev->link to NULL and return start 
    of the new list.

Time Complexity = O(m+n)
*/
Node *findIntersection(Node *head1, Node *head2)
{
    Node *start = NULL;
    Node *p = NULL;
    while (head1 != NULL && head2 != NULL)
    {
        if (head1->data == head2->data)
        {
            Node *temp = new Node(head1->data);
            if (start == NULL)
            {
                start = temp;
                p = start;
            }
            else
            {
                p->next = temp;
                p = p->next;
            }
            head1 = head1->next;
            head2 = head2->next;
        }
        else
        {
            if (head1->data < head2->data)
                head1 = head1->next;
            else
                head2 = head2->next;
        }
    }
    p->next = NULL;
    return start;
}