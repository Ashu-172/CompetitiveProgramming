/*///////////////////// Q 135: Babbar450: Add two numbers represented by linked lists ///////////////////
Given two numbers represented by two linked lists of size N and M. The task is to return a sum list. The sum list is a linked list representation of the addition of two input numbers.

Example 1:

Input:
N = 2
valueN[] = {4,5}
M = 3
valueM[] = {3,4,5}
Output: 3 9 0  
Explanation: For the given two linked
list (4 5) and (3 4 5), after adding
the two linked list resultant linked
list will be (3 9 0).
Example 2:

Input:
N = 2
valueN[] = {6,3}
M = 1
valueM[] = {7}
Output: 7 0
Explanation: For the given two linked
list (6 3) and (7), after adding the
two linked list resultant linked list
will be (7 0).
Your Task:
The task is to complete the function addTwoLists() which has node reference of both the linked lists and returns the head of the new list.        

Expected Time Complexity: O(N+M)
Expected Auxiliary Space: O(Max(N,M))

Constraints:
1 <= N, M <= 5000
///////////////////////////////////////////////////////////////////////////////////////////////////////*/
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

struct Node *buildList(int size)
{
    int val;
    cin >> val;

    Node *head = new Node(val);
    Node *tail = head;

    for (int i = 0; i < size - 1; i++)
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
    cout << endl;
}

struct Node *addTwoLists(struct Node *first, struct Node *second);

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, m;

        cin >> n;
        Node *first = buildList(n);

        cin >> m;
        Node *second = buildList(m);

        Node *res = addTwoLists(first, second);
        printList(res);
    }
    return 0;
}

struct Node *reverse(struct Node *start)
{
    if (start == NULL || start->next == NULL)
        return start;
    Node *prev = start, *p, *curr = start->next;
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
////////////////////////////////////// Solution 1 ///////////////////////////////////
/*
1. reverse both the input list.
2. iterate over both the lists in a loop to calculate sum, until any of them reached to end, 
    in sum also include carry. create a new node with value sum%10, and calculate carry as sum/10.
3.  link new node toprevious node.
4. in the end if carray is not 0 then create the last node with value as 1, and linkit in the end.
5. make last node to point to NULL.
5. return the reverse of the new list.

Time complexity = O(M) where M is the size of the bigger input list.
*/

struct Node *addTwoLists(struct Node *first, struct Node *second)
{
    Node *start = NULL, *p = NULL;
    int carry = 0, sum = 0;
    ;
    first = reverse(first);
    second = reverse(second);
    while (first != NULL && second != NULL)
    {
        sum = first->data + second->data + carry;
        carry = sum / 10;

        Node *temp = new Node(sum % 10);
        if (p == NULL)
        {
            p = temp;
            start = p;
        }
        else
        {
            p->next = temp;
            p = p->next;
        }
        first = first->next;
        second = second->next;
    }
    while (first != NULL)
    {
        sum = first->data + carry;
        carry = sum / 10;

        Node *temp = new Node(sum % 10);
        if (p == NULL)
        {
            p = temp;
            start = p;
        }
        else
        {
            p->next = temp;
            p = p->next;
        }
        first = first->next;
    }
    while (second != NULL)
    {
        sum = second->data + carry;
        carry = sum / 10;

        Node *temp = new Node(sum % 10);
        if (p == NULL)
        {
            p = temp;
            start = p;
        }
        else
        {
            p->next = temp;
            p = p->next;
        }
        second = second->next;
    }
    if (carry != 0)
    {
        Node *temp = new Node(carry);
        p->next = temp;
        p = p->next;
    }
    p->next = NULL;
    return reverse(start);
}