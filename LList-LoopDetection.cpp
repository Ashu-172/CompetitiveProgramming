/*///////////////////// Q 128: Babbar450: Detect Loop In a Linked List  ///////////////////
Given a linked list of N nodes. The task is to check if the the linked list has a loop. 
Linked list can contain self loop.

///////////// Q 129: Babbar450: Write a program to Delete loop in a linked list ///////////
You are given a linked list of N nodes. Remove the loop from the linked list, if present. 
Note: X is the position of the node to which the last node is connected to. If it is 0, then there is no loop.

///////////// Q 130: Babbar450: Find first node of loop in a linked list ///////////


Example 1:

Input:
N = 3
value[] = {1,3,4}
X = 2
Output: 1
Explanation: The link list looks like
1 -> 3 -> 4
     ^    |
     |____|    
A loop is present. If you remove it 
successfully, the answer will be 1. 
/////////////////////////////////////////////////////////////////////////////////////////*/
#include <iostream>
#include <unordered_map>

using namespace std;
class LinkedList
{
    class node
    {
    public:
        int info;
        node *link;
    };

    node *start;

public:
    LinkedList()
    {
        start = NULL;
    }
    void push(int num)
    {
        node *temp = new node();
        temp->info = num;
        if (start == NULL)
        {
            temp->link = start;
            start = temp;
        }
        else
        {
            node *p = start;
            while (p->link != NULL)
                p = p->link;

            temp->link = p->link;
            p->link = temp;
        }
    }

    void print()
    {
        node *p = start;
        while (p != NULL)
        {
            cout << p->info << " ";
            p = p->link;
        }
        cout << endl;
    }

    void createLoop(int k)
    {
        node *p = start;
        node *temp;
        int count = 1;
        while (p->link != NULL)
        {
            if (count == k)
                temp = p;
            p = p->link;
            count++;
        }
        p->link = temp;
    }
    /////////////////////////////// Finding hte loop //////////////////////
    int detectLoop()
    {
        node *fast = start;
        node *slow = start;
        while (fast != NULL && fast->link != NULL)
        {
            slow = slow->link;
            fast = fast->link->link;
            if (slow == fast)
                break;
        }
        // when no loop is present;
        if (fast == NULL || fast->link == NULL)
            return -1;

        //resetting slow poiter to start and moving by 1 step
        slow = start;
        int index = 1;
        while (slow != fast)
        {
            slow = slow->link;
            fast = fast->link;
            index++;
        }
        return index;
    }
    ///////////////////////// Remove Solution 1 (floyd's algo) //////////////////
    void removeLoop()
    {
        node *slow = start;
        node *fast = start;
        node *prev = NULL;
        while (fast != NULL && fast->link != NULL)
        {
            slow = slow->link;
            prev = fast->link;
            fast = fast->link->link;
            if (slow == fast)
                break;
        }
        // if No Loop present
        if (fast == NULL || fast->link == NULL)
            return;

        slow = start;
        while (slow != fast)
        {
            slow = slow->link;
            prev = fast;
            fast = fast->link;
        }
        prev->link = NULL;
    }

    ///////////////////// remove Solution 2 (hash map)
    void hashAndRemove()
    {
        // hash map to hash addresses of the linked list nodes
        unordered_map<node *, int> node_map;
        node *head = start;
        // pointer to last node
        node *last = NULL;
        while (head != NULL)
        {
            // if node not present in the map, insert it in the map
            if (node_map.find(head) == node_map.end())
            {
                node_map[head]++;
                last = head;
                head = head->link;
            }
            // if present, it is a cycle, make the last node's next pointer NULL
            else
            {
                last->link = NULL;
                break;
            }
        }
    }
};

int main()
{
    LinkedList list;
    list.push(4);
    list.push(8);
    list.push(12);
    list.push(16);
    list.push(20);
    list.push(11);
    list.push(12);
    list.print();

    int k = 3;
    list.createLoop(3);
    cout << list.detectLoop() << endl;
    //list.removeLoop();
    list.hashAndRemove();
    cout << list.detectLoop() << endl;
}
