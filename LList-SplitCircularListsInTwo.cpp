/*///////////////////// Q 142: Babbar450: Split a Circular linked list into two halves ///////////////////
Given a Cirular Linked List of size N, split it into two halves circular lists. If there are odd number of nodes in the given circular linked list then out of the resulting two halved lists, first list should have one node more than the second list. The resultant lists should also be circular lists and not linear lists.
Example 1:

Input:
Circular LinkedList: 1->5->7
Output:
1 5
7
///////////////////////////////////////////////////////////////////////////////////////////////////////*/

#include <stdio.h>
#include <stdlib.h>

/* structure for a Node */
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

void splitList(struct Node *head, struct Node **head1_ref, struct Node **head2_ref);
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

        splitList(head, &head1, &head2);

        // printf("\nFirst Circular Linked List");
        printList(head1);

        // printf("\nSecond Circular Linked List");
        printList(head2);
    }
    return 0;
}

void splitList(Node *start, Node **head1_ref, Node **head2_ref)
{
    Node *slow = start, *fast = start->next, *prev = start, *start2;
    while (fast != start)
    {
        if (fast->next == start)
        {
            fast->next = slow->next;
            slow->next = start;
            *head1_ref = start;
            *head2_ref = fast->next;
            return;
        }
        slow = slow->next;
        prev = prev->next->next;
        fast = fast->next->next;
    }
    prev->next = slow->next;
    slow->next = start;
    *head1_ref = start;
    *head2_ref = prev->next;
}