/*///////////////////// Q 126: Babbar450: Reverse the Singly LinkedList ///////////////////
Given pointer to the head node of a linked list, the task is to reverse the linked list. 
We need to reverse the list by changing the links between nodes.

Examples: 

Input: Head of following linked list 
1->2->3->4->NULL 
Output: Linked list should be changed to, 
4->3->2->1->NULL
/////////////////////////////////////////////////////////////////////////////////////////*/
#include <iostream>

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

    void reverse()
    {
        // Empty List
        if (start == NULL)
            return;

#if 0 // not a betterApproach
        node *p, *end;
        // Single node is always reverse of itself
        if(start->link == NULL)
            return;

        // Reversing last node link.
        p = start;
        while (p->link->link != NULL)
        {
            p = p->link;
        }
        end = p->link;
        p->link->link = p;

        // Reversing remaining nodex
        while (start->link->link != start)
        {
            p = start;
            while (p->link->link->link != p->link)
            {
                p = p->link;
            }
            p->link->link = p;
        }
        start->link = NULL;
        start = end;
#endif

        // single traversa approach
        node *prev = start; // will track pervious node
        node *p = start->link;
        node *curr = p; // will track current node

        prev->link = NULL; // first node will point to NULL in reverse order

        while (p->link != NULL)
        {
            p = p->link;
            curr->link = prev; // reversing the link
            prev = curr;       //moving curr and prev to next position
            curr = p;
        }
        curr->link = prev;
        start = p; // in the end set start to last node
    }

    void reverseRec(node *&p)
    {
        // Base Condition
        if (p->link == NULL)
        {
            start = p;
            return;
        }

        reverseRec(p->link);
        p->link->link = p;
    }
    void reverseV2()
    {
        node *p = start;

        //if empty
        if (start == NULL)
            return;

        reverseRec(p);
        p->link = NULL;
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
    list.print();
    list.reverseV2();
    list.print();
    list.push(11);
    list.push(12);
    list.print();
}