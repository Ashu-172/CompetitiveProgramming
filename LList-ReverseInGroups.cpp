/*///////////////////// Q 127: Babbar450:Reverse a Linked List in group of Given Size ///////////////////
Given a linked list of size N. The task is to reverse every k nodes (where k is an input to the function) in the linked list.

Example 1:

Input:
LinkedList: 1->2->2->4->5->6->7->8
K = 4
Output: 4 2 2 1 8 7 6 5
Example 2:

Input:
LinkedList: 1->2->3->4->5
K = 3
Output: 3 2 1 5 4
Your Task:
The task is to complete the function reverse() which should reverse the linked list in group of size k and return the head of the modified linked list.

Expected Time Complexity : O(N)
Expected Auxilliary Space : O(1)
/////////////////////////////////////////////////////////////////////////////////////////*/
#include <bits/stdc++.h>
#include <stack>
using namespace std;

/* Link list node */
struct node *reverse(struct node *head, int k);

struct node
{
    int data;
    struct node *next;

    node(int x)
    {
        data = x;
        next = NULL;
    }
};

/////////////////////////// Solution 1 (Brute Force) /////////////////////////
/*
This approach is faster but complex to implement.
Time complexity : O(n)
Space Complexity : O(1)
*/
struct node *reverseBruteForce(struct node *start, int k)
{
    if (start == NULL || start->next == NULL)
        return start;
    struct node *curr = start, *p, *prev, *next, *temp = start, *first = start;
    bool isSet = false;
    while (curr != NULL)
    {
        p = curr;
        prev = curr;
        first = curr;
        curr = curr->next;

        for (int i = 0; i < k - 1 && curr != NULL; i++)
        {
            p = curr;
            curr = curr->next;
            p->next = prev;
            prev = p;
        }
        if (isSet != true)
        {
            start = prev;
            isSet = true;
        }
        else
        {
            temp->next = prev;
        }
        temp = first;
    }
    first->next = curr;
    return start;
}

////////////////////////////// Solution 2 (Recursion) //////////////////////////
struct node *reverseRec(struct node *start, int k)
{
    if (start == NULL || start->next == NULL)
        return start;

    struct node *prev = start, *p = start, *curr = start->next;
    for (int i = 0; i < k - 1 && curr != NULL; i++)
    {
        p = curr;
        curr = curr->next;
        p->next = prev;
        prev = p;
    }

    if (curr != NULL)
        start->next = reverseRec(curr, k);
    else
        start->next = NULL;

    return prev;
}

/////////////////////////////////// Solution 3 (stack) ///////////////////////////////
/*
Firstly, push the k elements of the linked list in the stack. Now pop elements one by 
one and keep track of the previously popped node. Point the next pointer of prev node 
to top element of stack. Repeat this process, until NULL is reached.
*/
struct node *reverseStk(struct node *start, int k)
{
    stack<struct node *> stk;
    struct node *curr = start, *prev = NULL;

    while (curr != NULL)
    {
        for (int i = 0; i < k && curr != NULL; i++)
        {
            stk.push(curr);
            curr = curr->next;
        }

        while (stk.size() > 0)
        {
            if (prev == NULL)
            {
                prev = stk.top();
                start = prev;
            }
            else
            {
                prev->next = stk.top();
                prev = prev->next;
            }
            stk.pop();
        }
    }
    prev->next = NULL;
    return start;
}

/* Function to print linked list */
void printList(struct node *node)
{
    while (node != NULL)
    {
        printf("%d ", node->data);
        node = node->next;
    }
    printf("\n");
}

/* Drier program to test above function*/
int main(void)
{
    int t;
    cin >> t;

    while (t--)
    {
        struct node *head = NULL;
        struct node *temp = NULL;
        int n;
        cin >> n;

        for (int i = 0; i < n; i++)
        {
            int value;
            cin >> value;
            if (i == 0)
            {
                head = new node(value);
                temp = head;
            }
            else
            {
                temp->next = new node(value);

                temp = temp->next;
            }
        }
        int k;
        cin >> k;
        head = reverse(head, k);
        printList(head);
    }
    return (0);
}

struct node *reverse(struct node *start, int k)
{
    //return reverseBruteForce(start, k);
    //return reverseRec(start, k);
    return reverseStk(start, k);
}
