/*/////////////////// Q 150: Babbar450: Reverse a Doubly Linked list in group of Given Size //////////////////
Given a doubly linked list containing n nodes. The problem is to reverse every group of k nodes in the list.
////////////////////////////////////////////////////////////////////////////////////////////////////////////*/
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

Node *reverseInGroups(Node *head, int k)
{
    Node *p = head;
    Node *prev, *end, *start;

    while (p != NULL)
    {
        for (int i = 0; i < k && p != NULL; i++)
        {
            Node *temp = p->prev;
            p->prev = p->next;
            prev = p;
            p = p->next;
            prev->next = temp;
        }

        if (head->next == NULL) // first iteration  of while loop
        {
            end = head;
            head = prev;
            prev->prev = NULL;
        }
        else
        {
            end->next = prev;
            prev->prev = end;
            end = start;
        }
        start = p;
    }
    end->next = NULL;
    return head;
}

//////////////////////////////// Solution 2 /////////////////////////////
Node *revListInGroupOfGivenSize(Node *head, int k)
{
    Node *curr = head;
    Node *next = NULL;
    Node *prev = NULL;
    Node *start = head;
    int count = 0;

    while (curr != NULL && count < k)
    {
        Node *temp = curr->prev;
        curr->prev = curr->next;
        prev = curr;
        curr = curr->next;
        prev->next = temp;
        count++;
    }
    head = prev;
    // if next group exists then making the desired
    // adjustments in the link
    if (curr != NULL)
    {
        start->next = revListInGroupOfGivenSize(curr, k);
        start->next->prev = start;
    }
    else // base condition
    {
        start->next = NULL;
    }

    // pointer to the new head of the
    // reversed group
    return head;
}

// Function to print nodes in a
// given doubly linked list
void printList(Node *head)
{
    while (head != NULL)
    {
        cout << head->data << " ";
        head = head->next;
    }
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
        //head = reverseInGroups(head, k);
        head = revListInGroupOfGivenSize(head, k);

        displayList(head);
    }
    return 0;
}