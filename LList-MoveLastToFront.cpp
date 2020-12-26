/*///////////////////// Q 133: Babbar450: Move last element to front of a given Linked List  ///////////////////
Write a function that moves the last element to the front in a given Singly Linked List. For example, if the 
given Linked List is 1->2->3->4->5, then the function should change the list to 5->1->2->3->4.
//////////////////////////////////////////////////////////////////////////////////////////////////////////////*/
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
    LinkedList(int n)
    {
        node *temp = new node();
        temp->info = n;
        temp->link = NULL;
        start = temp;
    }
    void push(int num)
    {
        node *temp = new node();
        temp->info = num;
        temp->link = NULL;
        if (start == NULL)
            start = temp;
        else
        {
            node *p = start;
            while (p->link != NULL)
                p = p->link;
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

    void moveLastToFront()
    {
        if (start == NULL || start->link == NULL)
            return;
        node *prev = start;
#if 0 // using double pointers
        node *last = start->link;
        while (last->link != NULL)
        {
            prev = last;
            last = last->link;
        }
        prev->link = last->link;
        last->link = start;
        start = last;
#endif
        // using single Node
        while (prev->link->link != NULL)
        {
            prev = prev->link;
        }
        prev->link->link = start;
        start = prev->link;
        prev->link = NULL;
    }
};
int main()
{
    LinkedList list;
    list.push(1);
    list.push(2);
    list.push(3);
    list.push(3);
    list.push(2);
    list.push(4);
    list.print();
    list.moveLastToFront();
    list.print();
}