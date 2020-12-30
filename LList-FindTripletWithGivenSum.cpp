/*/////////////////// Q 147: Babbar450: Find triplets with given sum in doubly linked list //////////////////
Given a sorted doubly linked list of distinct nodes(no two nodes have the same data) and a value x. Count triplets in the list that sum up to a given value x.
////////////////////////////////////////////////////////////////////////////////////////////////////////*/
#include <iostream>
#include <unordered_map>

using namespace std;

struct node
{
    int data;
    node *prev;
    node *next;
    node(int num)
    {
        data = num;
        prev = NULL;
        next = NULL;
    }
};

///////////////////////////////////////// Solution 1 (Hashing) ////////////////////////////////////
/*
Create a hash table with (key, value) tuples represented as (node data, node pointer) tuples. Traverse
     the doubly linked list and store each node’s data and its pointer pair(tuple) in the hash table. 
Now, generate each possible pair of nodes. For each pair of nodes, calculate the p_sum(sum of data in 
    the two nodes) and check whether (x-p_sum) exists in the hash table or not. 
If it exists, then also verify that the two nodes in the pair are not same to the node associated with
    (x-p_sum) in the hash table and finally increment count. 
Return (count / 3) as each triplet is counted 3 times in the above process.
*/
int findTripletsHashing(node *head, int num)
{
    unordered_map<int, node *> map;
    node *p = head;
    int count = 0;
    while (p != NULL)
    {
        map.insert(make_pair(p->data, p));
        p = p->next;
    }

    for (p = head; p->next != NULL; p = p->next)
        for (node *q = p->next; q != NULL; q = q->next)
        {
            int sum = p->data + q->data;
            auto itr = map.find(num - sum);
            if (itr != map.end())
            {
                if (itr->second != p && itr->second != q)
                {
                    cout << "( " << p->data << ", " << q->data << ", " << itr->first << ") ";
                    count++;
                }
            }
        }
    cout << endl;
    return count / 3;
}

//////////////////////////////////////// Solution 2 (Double Pointer) ////////////////////////////////////
/*
1) we'll fix one pointer p to head and use double pointer approach for remaining nodes to find pairs for (num - p->data ).
this we'll repeat for n-2 nodes by moving p by one node. for this we'll use a loop and time complexity for this loop will be O(n).
2) inside the loop we are using double pointer approach to find pair, which also has O(n) time complexity.

so final time complexity will be O(n^2)
*/
void findTriplets(node *head, int num)
{
    node *p = head;
    node *end = head;
    node *q, *r;

    while (end->next != NULL)
    {
        end = end->next;
    }
    for (p = head; p->next->next != NULL;)
    {
        q = p->next;
        r = end;
        while (q != r && r->next != q)
        {
            if (p->data + q->data + r->data == num)
            {
                cout << "( " << p->data << ", " << q->data << ", " << r->data << ") ";
                q = q->next;
                r = r->prev;
            }
            else if (p->data + q->data + r->data < num)
                q = q->next;
            else
                r = r->prev;
        }
        p = p->next;
    }
}

int main()
{
    int size;
    cin >> size;

    node *head, *tail;
    int num;
    cin >> num;
    head = new node(num);
    tail = head;
    for (int i = 1; i < size; i++)
    {
        cin >> num;
        node *temp = new node(num);
        temp->prev = tail;
        tail->next = temp;
        tail = tail->next;
    }

    cin >> num;
    //cout << findTripletsHashing(head, num);
    findTriplets(head, num);
}