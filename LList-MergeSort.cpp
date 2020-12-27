/*////////////////////////////////// Q 138: Babbar450:  Linked List Merge Sort //////////////////////////////////
Given Pointer/Reference to the head of the linked list, the task is to Sort the given linked list using Merge Sort.
Note: If the length of linked list is odd, then the extra node should go in the first list while splitting.
Example 1:

Input:
N = 5
value[]  = {3,5,2,4,1}
Output: 1 2 3 4 5
Explanation: After sorting the given
linked list, the resultant matrix
will be 1->2->3->4->5.
//////////////////////////////////////////////////////////////////////////////////////////////////*/

#include <iostream>

using namespace std;

//////////////////////////// Solution ////////////////////////////
/*
MergeSort(headRef)
1) If the head is NULL or there is only one element in the Linked List 
    then return.
2) Else divide the linked list into two halves.  
      FrontBackSplit(head, &a, &b); // a and b are two halves 
3) Sort the two halves a and b.
      MergeSort(a);
      MergeSort(b);
4) Merge the sorted a and b (using SortedMerge() discussed here) 
   and update the head pointer using headRef.
     *headRef = SortedMerge(a, b);
*/

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

Node *merge(Node *first, Node *second)
{
    if (first != NULL && second != NULL && first != second)
    {
        Node *p1 = first;
        Node *p2 = second;
        Node *head = NULL;
        Node *p = NULL;

        if (p1->data <= p2->data)
        {
            p = p1;
            p1 = p1->next;
        }
        else
        {
            p = p2;
            p2 = p2->next;
        }
        head = p;

        while (p1 != NULL && p2 != NULL)
        {
            if (p1->data <= p2->data)
            {
                p->next = p1;
                p1 = p1->next;
            }
            else
            {
                p->next = p2;
                p2 = p2->next;
            }
            p = p->next;
        }
        while (p1 != NULL)
        {
            p->next = p1;
            p1 = p1->next;
            p = p->next;
        }
        while (p2 != NULL)
        {
            p->next = p2;
            p2 = p2->next;
            p = p->next;
        }

        p->next = NULL;
        return head;
    }
    return first;
}

Node *sortMerge(Node *first, int size1, Node *second, int size2)
{
    if (first != second && first != NULL && second != NULL)
    {
        int mid1 = (size1 + 1) / 2;
        int mid2 = (size2 + 1) / 2;
        Node *p1 = first;
        Node *p2 = second;
        for (int i = 1; i < mid1; i++)
        {
            p1 = p1->next;
        }
        Node *prev = p1;
        p1 = p1->next;
        prev->next = NULL;

        for (int i = 1; i < mid2; i++)
        {
            p2 = p2->next;
        }
        prev = p2;
        p2 = p2->next;
        prev->next = NULL;

        first = sortMerge(first, mid1, p1, size1 - mid1);
        second = sortMerge(second, mid2, p2, size2 - mid2);
        return merge(first, second);
    }
    return first;
}

Node *mergeSort(Node *start)
{
    Node *p = start;
    int size = 0;
    while (p != NULL)
    {
        size++;
        p = p->next;
    }
    int mid = (size + 1) / 2;

    p = start;
    for (int i = 1; i < mid; i++)
    {
        p = p->next;
    }
    Node *prev = p;
    p = p->next;
    prev->next = NULL;
    return sortMerge(start, mid, p, size - mid);
}
void printList(Node *node)
{
    while (node != NULL)
    {
        printf("%d ", node->data);
        node = node->next;
    }
    printf("\n");
}

void push(struct Node **head_ref, int new_data)
{
    Node *new_node = new Node(new_data);

    new_node->next = (*head_ref);
    (*head_ref) = new_node;
}

int main()
{
    long test;
    cin >> test;
    while (test--)
    {
        struct Node *a = NULL;
        long n, tmp;
        cin >> n;
        for (int i = 0; i < n; i++)
        {
            cin >> tmp;
            push(&a, tmp);
        }
        a = mergeSort(a);
        printList(a);
    }
    return 0;
}
