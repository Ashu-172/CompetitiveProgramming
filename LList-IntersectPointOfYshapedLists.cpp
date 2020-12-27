/*///////////////////// Q 137: Babbar450: Intersection Point of two Linked Lists ///////////////////
Given two singly linked lists of size N and M, write a program to get the point where two linked lists intersect each other.
Example 1:

Input:
LinkList1 = 3->6->9->common
LinkList2 = 10->common
common = 15->30->NULL
Output: 15
Explanation:
Y ShapedLinked List
 

Your Task:
You don't need to read input or print anything. The task is to complete the function intersetPoint() which takes the pointer to the head of linklist1(head1) and linklist2(head2) as input parameters and returns data value of a node where two linked lists intersect. If linked list do not merge at any point, then it should return -1.
Challenge : Try to solve the problem without using any extra space.

Expected Time Complexity: O(N+M)
Expected Auxiliary Space: O(1)

Constraints:
1 <= N <= 100
1 <= value <= 1000
///////////////////////////////////////////////////////////////////////////////////////////////////*/
#include <iostream>
#include <unordered_map>

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

int intersectPointFloyed(struct Node *head1, struct Node *head2);
int intersectPointMarking(struct Node *head1, struct Node *head2);
int intersectPoint(struct Node *head1, struct Node *head2);

Node *inputList(int size)
{
    if (size == 0)
        return NULL;

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

/* Driver program to test above function*/
int main()
{
    int T, n1, n2, n3;

    cin >> T;
    while (T--)
    {
        cin >> n1 >> n2 >> n3;

        Node *head1 = inputList(n1);
        Node *head2 = inputList(n2);
        Node *common = inputList(n3);

        Node *temp = head1;
        while (temp != NULL && temp->next != NULL)
            temp = temp->next;
        if (temp != NULL)
            temp->next = common;

        temp = head2;
        while (temp != NULL && temp->next != NULL)
            temp = temp->next;
        if (temp != NULL)
            temp->next = common;

        cout << intersectPointFloyed(head1, head2) << endl;
        cout << intersectPointMarking(head1, head2) << endl;
        cout << intersectPoint(head1, head2) << endl;
    }
    return 0;
}
////////////////////////////////////// Solution 1 (Floyd's algo) ////////////////////////////////////
/*
1) we can traverse the first list, and when we reach to the last node we'll link it to the head of the 
    second list. we'll keep the pointer to the last node of first list for later use.
2) Now we can see both the lists as a single list having a loop, so now we can use floyd's Loop detection 
    algo to findout the intersection point in O(n) time.
3) after finding the intersection point, we'll again break the loop in order to keep the inputs as it was
    initially, for breaking the loop we'll use the pointer to the last node of the first list which we 
    kept safe in first step. we'll set it's next to NULL.
4) Now we can return intersecting node's data.

*/
int intersectPointFloyed(Node *head1, Node *head2)
{
    Node *p = head1;
    while (p->next != NULL)
        p = p->next;
    p->next = head2;

    // Floyed's Algo
    Node *slow = head1->next, *fast = head1->next->next;
    while (slow != fast)
    {
        if (fast == NULL || fast->next == NULL)
            return -1;
        slow = slow->next;
        fast = fast->next->next;
    }
    slow = head1;
    while (slow != fast)
    {
        slow = slow->next;
        fast = fast->next;
    }
    p->next = NULL;
    return slow->data;
}

//////////////////////////////// Solution 2 (Marking visited Node) ///////////////////////////////
/*
we can traverse first list and mark all the visited nodes by putting them into hash table.
then we'll traverse second list, and check each node in the hash table. if we found current 
node marked as visited, we know that this node is the starting point of the merged list.
we can return the node data, if we reach to the end without finding any already visited node 
then given two lists are not making Y shape structure.

*/
int intersectPointMarking(Node *head1, Node *head2)
{
    unordered_map<Node *, int> map;
    Node *p = head1;
    while (p != NULL)
    {
        map.insert(make_pair(p, 1));
        p = p->next;
    }
    p = head2;
    while (p != NULL)
    {
        if (map.find(p) != map.end())
            return p->data;
        p = p->next;
    }
    return -1;
}

///////////////////////////////// Solution 3 (x+y = y+x) /////////////////////////////////
/*
size of first and second list can be different but sum of their length will always be fixed.
if we start traversing both the lists using two different poiters, when we reach to the we 
redirect the pointer to other list's head. in this way after some moves, both pointers will 
start pointing same nodes.
when we encounter first node like this, we know that this node is the intersection point and
we can return this node.
if they reached to the end again without finding same nodes, then there is no intersection point
present.
1. whenever we'll see p1 == p2, it is the intersection point, return p1->data.
2. when p1 is not equal to p2 and both have next as NULL, it means lists are not intersecting, so we'll return -1.
3. if p1's next is null then move it to p2's head.
4. if p2's next is null then move it to p1's head.
*/
int intersectPoint(Node *head1, Node *head2)
{
    Node *p1 = head1, *p2 = head2;
    while (p1 != NULL && p2 != NULL)
    {
        if (p1 == p2)
            return p1->data;
        if (p1->next == NULL && p2->next == NULL)
        {
            return -1;
        }
        if (p1->next == NULL)
            p1 = head2;
        else
            p1 = p1->next;
        if (p2->next == NULL)
            p2 = head1;
        else
            p2 = p2->next;
    }
    return -1;
}

/////////////////////////////// Solution 4 (Using difference of node counts) ////////////////////////////
/*
Get count of the nodes in the first list, let count be c1.
Get count of the nodes in the second list, let count be c2.
Get the difference of counts d = abs(c1 – c2)
Now traverse the bigger list from the first node till d nodes so that from here onwards both the lists have equal no of nodes 
Then we can traverse both the lists in parallel till we come across a common node. (Note that getting a common node is done by comparing the address of the nodes)

This is not most optimised solution since here we first have to calculate the length of both the lists using two different loops.
*/