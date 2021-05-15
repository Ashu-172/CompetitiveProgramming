/*//////////////////////////////// Q 321: Babbar450: Merge K Sorted Linked Lists ////////////////////////////////
Given K sorted linked lists of different sizes. The task is to merge them in such a way that after merging they will be a single sorted linked list.

Example 1:

Input:
K = 4
value = {{1,2,3},{4 5},{5 6},{7,8}}
Output: 1 2 3 4 5 5 6 7 8
Explanation:
The test case has 4 sorted linked 
list of size 3, 2, 2, 2
1st    list     1 -> 2-> 3
2nd   list      4->5
3rd    list      5->6
4th    list      7->8
The merged list will be
1->2->3->4->5->5->6->7->8.

Expected Time Complexity: O(nk Logk)
Expected Auxiliary Space: O(k)
Note: n is the maximum size of all the k link list

Constraints
1 <= K <= 10^3
///////////////////////////////////////////////////////////////////////////////////////////////////////////////*/

#include <iostream>
#include <queue>

using namespace std;

struct Node
{
    int data;
    Node *next;

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
        printf("%d ", node->data);
        node = node->next;
    }
    cout << endl;
}

struct compare
{
    bool operator()(Node *left, Node *right)
    {
        return left->data > right->data;
    }
};

class Solution
{
public:
    ///////////////////////////////////////// Solution 1 (Using Heap) //////////////////////////////////
    /*
    we can put all the members in a min Heap and then one by one we can pop the top element and recreate the links between the nodes.
    Time complexity  = O(inserting elements in the heap) + O(popping elements from the heap)
                    = O(n log n) + O(n log n)
                    = O(n log n)
                    where n is total number of elements
    */
    Node *mergeKListsWithHeap(Node *arr[], int k)
    {
        priority_queue<Node *, vector<Node *>, compare> maxHeap;
        for (int i = 0; i < k; i++)
        {
            Node *start = arr[i];
            while (start != NULL)
            {
                maxHeap.push(start);
                start = start->next;
            }
        }
        Node *head = maxHeap.top();
        Node *temp = head;
        maxHeap.pop();
        while (maxHeap.size() != 0)
        {
            temp->next = maxHeap.top();
            maxHeap.pop();
            temp = temp->next;
        }
        temp->next = NULL;
        return head;
    }

    //////////////////////////////////////// Solution 2 (using merge method) ///////////////////////////////
    /*
    we can store head of the first linkedlist in a variable and we can iterate over the array and keep on merge the lists in the result list of the merge. for this we need to modify the standard merge function of the merge sort for using pointers instead of counters.

    Time complexity  = O(total number of lists ) * time complexity of merge
                    = O(k * timecomplexity of merge)
                    
    */
    Node *merge(Node *listAhead, Node *listBhead)
    {
        Node *p1 = listAhead;
        Node *p2 = listBhead;
        Node *head = NULL;

        if (p1->data < p2->data)
        {
            head = p1;
            p1 = p1->next;
        }
        else
        {
            head = p2;
            p2 = p2->next;
        }

        Node *temp = head;
        while (p1 != NULL && p2 != NULL)
        {
            if (p1->data < p2->data)
            {
                temp->next = p1;
                p1 = p1->next;
            }
            else
            {
                temp->next = p2;
                p2 = p2->next;
            }
            temp = temp->next;
        }

        while (p1 != NULL)
        {
            temp->next = p1;
            p1 = p1->next;
            temp = temp->next;
        }

        while (p2 != NULL)
        {
            temp->next = p2;
            p2 = p2->next;
            temp = temp->next;
        }
        temp->next = NULL;
        return head;
    }

    Node *mergeKLists(Node *arr[], int k)
    {
        Node *head = arr[0];
        for (int i = 1; i < k; i++)
        {
            Node *temp = arr[i];
            head = merge(head, temp);
        }
        return head;
    }
};

int main()
{
    int N;
    cin >> N;
    struct Node *arr[N];
    for (int j = 0; j < N; j++)
    {
        int n;
        cin >> n;

        int x;
        cin >> x;
        arr[j] = new Node(x);
        Node *curr = arr[j];
        n--;

        for (int i = 0; i < n; i++)
        {
            cin >> x;
            Node *temp = new Node(x);
            curr->next = temp;
            curr = temp;
        }
    }
    Solution obj;
    //Node *res = obj.mergeKListsWithHeap(arr, N);
    Node *res = obj.mergeKLists(arr, N);
    printList(res);

    return 0;
}