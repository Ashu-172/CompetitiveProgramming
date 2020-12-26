/*///////////////////// Q 134: Babbar450: Add “1” to a number represented as a Linked List ///////////////////
A number N is represented in Linked List such that each digit corresponds to a node in linked list. You need to add 1 to it.

Example 1:

Input:
LinkedList: 4->5->6
Output: 457 
Example 2:

Input:
LinkedList: 1->2->3
Output: 124 
Your Task:
Your task is to complete the function addOne() which takes the head of the linked list as the only argument and returns the head of the modified linked list. The driver code prints the number.
Note: The head represents the left-most digit of the number.

Expected Time Complexity: O(N).
Expected Auxiliary Space: O(1).

Constraints:
1 <= N <= 10^1000
////////////////////////////////////////////////////////////////////////////////////////////////////////////*/
#include <iostream>
using namespace std;

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

void printList(Node *node)
{
    while (node != NULL)
    {
        cout << node->data;
        node = node->next;
    }
    cout << "\n";
}

Node *addOne(Node *head);
Node *addOneRec(Node *head);
Node *addOneOptimized(Node *head);

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string s;
        cin >> s;

        Node *head = new Node(s[0] - '0');
        Node *tail = head;
        for (int i = 1; i < s.size(); i++)
        {
            tail->next = new Node(s[i] - '0');
            tail = tail->next;
        }

        head = addOneOptimized(head);
        printList(head);
    }
    return 0;
}
Node *reverse(Node *start)
{
    if (start == NULL)
        return start;
    Node *prev = start, *curr = start->next;
    Node *p = NULL;
    while (curr != NULL)
    {
        p = curr;
        curr = curr->next;
        p->next = prev;
        prev = p;
    }
    start->next = NULL;
    start = prev;
    return start;
}
//////////////////////////// Solution 1 (Reversing)/////////////////////////
/*
1. reverse the List
2. add 1 to the first node and forward carry to other nodes
3. reverse the list again.
4. while forwarding the carry, if it didn't became 0 till the end, create 
    a new node with value as 1 (carry) and put it at the start of the list.

Time complexity = O(n)
Space Complexity = O(1)
*/
Node *addOne(Node *start)
{
    start = reverse(start);
    Node *p = start;
    int carry = 1;
    while (p != NULL && carry != 0)
    {
        p->data = (p->data + 1) % 10;
        if (p->data != 0)
            carry = 0;
        p = p->next;
    }
    start = reverse(start);
    if (p == NULL && carry != 0)
    {
        Node *first = new Node(1);
        first->next = start;
        start = first;
    }
    return start;
}

////////////////////////////// Solution 2 (recursive) //////////////////////////////
/*
we can recursively add 1 to the last digit and move carry to previous number.
*/
int add(Node *p)
{
    // Base Condition
    if (p->next == NULL)
    {
        p->data = (p->data + 1) % 10;
        if (p->data == 0)
            return 1;
        else
            return 0;
    }
    //hypothesis
    int carry = add(p->next);
    // Induction
    if (carry > 0)
    {
        p->data = (p->data + carry) % 10;
        if (p->data == 0)
            return 1;
    }
    return 0;
}

Node *addOneRec(Node *start)
{
    int carry = add(start);
    if (carry > 0)
    {
        Node *first = new Node(1);
        first->next = start;
        start = first;
    }
    return start;
}

///////////////////////////////// Solution 3 ///////////////////////////////
/*
Find the last node in the linked list which is not equal to 9. Now there are three cases:

If there is no such node i.e. the value of every node is 9 then the new linked list will 
    contain all 0s and a single 1 inserted at the head of the linked list.
If the rightmost node which is not equal to 9 is the last node in the linked list then 
    add 1 to this node and return the head of the linked list.
If the node is other than the last node i.e. every node after it is equal to 9 then add
    1 to the current node and change all the nodes after it to 0.

Time Complexity  = O(n)
*/
Node *addOneOptimized(Node *start)
{
    Node *pos = NULL; // will point to last non-9 node
    Node *p = start;
    while (p != NULL)
    {
        if (p->data != 9)
            pos = p;
        p = p->next;
    }
    // if all node are 9
    Node *n;
    if (pos == NULL)
    {
        n = start;
        while (n != NULL)
        {
            n->data = 0;
            n = n->next;
        }
        Node *first = new Node(1);
        first->next = start;
        start = first;
    }
    else
    {
        pos->data += 1;
        pos = pos->next;
        while (pos != NULL)
        {
            pos->data = 0;
            pos = pos->next;
        }
    }
    return start;
}