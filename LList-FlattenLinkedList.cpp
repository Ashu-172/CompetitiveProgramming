/*/////////////////// Q 153: Babbar450: Flattening a Linked List //////////////////
Given a Linked List of size N, where every node represents a sub-linked-list and contains two pointers:
(i) a next pointer to the next node,
(ii) a bottom pointer to a linked list where this node is head.
Each of the sub-linked-list is in sorted order.
Flatten the Link List such that all the nodes appear in a single level while maintaining the sorted order. 
Note: The flattened list will be printed using the bottom pointer instead of next pointer.
Example 1:

Input:
5 -> 10 -> 19 -> 28
|     |     |     | 
7     20    22   35
|           |     | 
8          50    40
|                 | 
30               45
Output:  5-> 7-> 8- > 10 -> 19-> 20->
22-> 28-> 30-> 35-> 40-> 45-> 50.

Note: | represents the bottom pointer.

Your Task:
You do not need to read input or print anything. Complete the function flatten() that takes the head of the linked list as input parameter and returns the head of flattened link list.

Expected Time Complexity: O(N*M)
Expected Auxiliary Space: O(1)

Constraints:
0 <= N <= 50
1 <= Mi <= 20
1 <= Element of linked list <= 103
/////////////////////////////////////////////////////////////////////////////////*/
#include <iostream>

struct Node
{
    int data;
    struct Node *next;
    struct Node *bottom;

    Node(int x)
    {
        data = x;
        next = NULL;
        bottom = NULL;
    }
};

using namespace std;

void printList(Node *Node)
{
    while (Node != NULL)
    {
        printf("%d ", Node->data);
        Node = Node->bottom;
    }
}

Node *flatten(Node *root);

int main(void)
{

    int t;
    cin >> t;
    while (t--)
    {
        int n, m, flag = 1, flag1 = 1;
        struct Node *temp = NULL;
        struct Node *head = NULL;
        struct Node *pre = NULL;
        struct Node *tempB = NULL;
        struct Node *preB = NULL;
        cin >> n;
        int work[n];
        for (int i = 0; i < n; i++)
            cin >> work[i];
        for (int i = 0; i < n; i++)
        {
            m = work[i];
            --m;
            int data;
            scanf("%d", &data);
            temp = new Node(data);
            temp->next = NULL;
            temp->bottom = NULL;

            if (flag)
            {
                head = temp;
                pre = temp;
                flag = 0;
                flag1 = 1;
            }
            else
            {
                pre->next = temp;
                pre = temp;
                flag1 = 1;
            }
            for (int j = 0; j < m; j++)
            {

                int temp_data;
                scanf("%d", &temp_data);
                tempB = new Node(temp_data);

                if (flag1)
                {
                    temp->bottom = tempB;
                    preB = tempB;
                    flag1 = 0;
                }
                else
                {
                    preB->bottom = tempB;
                    preB = tempB;
                }
            }
        }
        Node *fun = head;
        Node *fun2 = head;

        Node *root = flatten(head);
        printList(root);
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends

/*  Function which returns the  root of 
    the flattened linked list. */

Node *merge(Node *first, Node *second)
{
    if (first == NULL)
        return second;
    if (second == NULL)
        return first;

    Node *head, *tail;
    if (first->data <= second->data)
    {
        head = first;
        tail = first;
        first = first->bottom;
    }
    else
    {
        head = second;
        tail = second;
        second = second->bottom;
    }

    while (first != NULL && second != NULL)
    {
        if (first->data <= second->data)
        {
            tail->bottom = first;
            first = first->bottom;
        }
        else
        {
            tail->bottom = second;
            second = second->bottom;
        }
        tail = tail->bottom;
    }
    if (first != NULL)
        tail->bottom = first;

    if (second != NULL)
        tail->bottom = second;

    return head;
}

Node *flatten(Node *root)
{
    if (root != NULL)
        root = merge(root, flatten(root->next));
    return root;
}