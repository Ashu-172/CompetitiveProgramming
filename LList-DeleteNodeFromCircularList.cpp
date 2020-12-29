/*///////////////////// Q 144: Babbar450: Delete Node From a Circular List ///////////////////
From a given circular Linked List, delete a Node
Input : 2->5->7->8->10->(head node)
        data = 5
Output : 2->7->8->10->(head node)

Input : 2->5->7->8->10->(head node)
         7
Output : 2->5->8->10->2(head node)
////////////////////////////////////////////////////////////////////////////////////////////*/
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

Node *deleteNode(Node *start, int num);
struct Node *newNode(int key)
{
    struct Node *temp = new Node(key);

    return temp;
}
/* Function to split a list (starting with head) into two lists.
   head1_ref and head2_ref are references to head Nodes of 
    the two resultant linked lists */

void printList(struct Node *head)
{
    struct Node *temp = head;
    if (head != NULL)
    {
        do
        {
            printf("%d ", temp->data);
            temp = temp->next;
        } while (temp != head);
        printf("\n");
    }
}

/* Driver program to test above functions */
int main()
{

    int t, n, i, x;
    scanf("%d", &t);
    while (t--)
    {
        struct Node *temp, *head = NULL;
        struct Node *head1 = NULL;
        struct Node *head2 = NULL;
        scanf("%d", &n);
        scanf("%d", &x);
        head = new Node(x);
        temp = head;
        for (i = 0; i < n - 1; i++)
        {
            scanf("%d", &x);

            temp->next = new Node(x);

            temp = temp->next;
        }

        temp->next = head;
        int num;
        cin >> num;

        printList(head);

        head = deleteNode(head, num);

        printList(head);
    }
    return 0;
}

/////////////////////////////////////// Solution 1 /////////////////////////////////////
Node *deleteNode(Node *start, int num)
{
    Node *p = start;
    Node *q = start->next;

    while (q->data != num && q != start)
    {
        p = q;
        q = q->next;
    }
    if (q->data == num)
    {
        p->next = q->next;
        q->next = NULL;
        free(q);
    }
    return start;
}
