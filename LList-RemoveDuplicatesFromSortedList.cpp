/*///////////////////// Q 131: Babbar450: Remove Duplicated From Sorted Linked List  ///////////////////
Given a singly linked list consisting of N nodes. The task is to remove duplicates 
(nodes with duplicate values) from the given list (if exists).
Note: Try not to use extra space. Expected time complexity is O(N). The nodes are arranged in a sorted way.
Example 1:

Input:
LinkedList: 2->2->4->5
Output: 2 4 5
Explanation: In the given linked list 
2 ->2 -> 4-> 5, only 2 occurs more 
than 1 time.
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
    //////////////// Solution 1   O(n) ///////////////////
    /*
    1. Iterate over the list with a loop till p->link 
        1.set prev to current node, and move current node one step forward.
        2. check data of prev and curr, if its same then move curr until 
            their values becomes different or we reach to the end.
            NOTE: since we are accessing data of prev and curr, we are checking 
            the condition p->link != NULL in outer loop, if we'll check p != null 
            in outerloop, inner loop condition will give segfault.
        3. if inner loop has ended because of End of List, we'll set prev->link to p->link 
            since p->link will be pointing to NULL (end).
        4. if inner loop has ended because of different values of prev and curr node's data
            we'll point prev->link to curr, since current has different value.
    */
    void removeDuplicates()
    {
        // your code goes here
        node *p = start;
        node *prev = NULL;
        node *temp = NULL;
        while (p->link != NULL)
        {
            prev = p;
            p = p->link;
            while (p->info == prev->info && p->link != NULL)
            {
                temp = p;
                p = p->link;
                free(temp);
            }
            if (prev->info == p->info)
            {
                prev->link = p->link;
            }
            else
                prev->link = p;
        }
    }
};
int main()
{
    LinkedList list;
    list.push(1);
    list.push(2);
    list.push(2);
    list.push(3);
    list.push(3);
    list.push(4);
    list.print();
    list.removeDuplicates();
    list.print();
}