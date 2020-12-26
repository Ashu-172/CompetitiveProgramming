/*///////////////////// Q 132: Babbar450: Remove Duplicated From Unsorted Linked List  ///////////////////
Given an unsorted linked list of N nodes. The task is to remove duplicate elements from this unsorted Linked List. When a value appears in multiple nodes, the node which appeared first should be kept, all others duplicates are to be removed.

Example 1:

Input:
N = 4
value[] = {5,2,2,4}
Output: 5 2 4
Explanation:Given linked list elements are
5->2->2->4, in which 2 is repeated only.
So, we will delete the extra repeated
elements 2 from the linked list and the
resultant linked list will contain 5->2->4
//////////////////////////////////////////////////////////////////////////////////////////////////////*/
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
    //////////////// Solution 1 ///////////////////
    /*
    We'll use HashTable to solve this problem.
    if list is empty we can directly return.
    1. First set prev to first node, and curr to second node or to Null if only 1 element is present. also put value of first node in the map.
    2. now start iterating over the list until current becomes Null (reached to End).

        1. check if current element is already present in the map, if it is then skip current number
        2. if current element is not present in the map, then:
            1) insert value in the map.
            2) set link of prev node to curr.
            3) move prev to curr.
    */
    void removeDuplicates()
    {
        unordered_map<int, int> map;
        if (start == NULL)
            return;
        node *curr = start->link;
        node *prev = start;
        map.insert(make_pair(start->info, 1));
        while (curr != NULL)
        {
            auto itr = map.find(curr->info);
            if (itr == map.end())
            {
                map.insert(make_pair(curr->info, 1));
                prev->link = curr;
                prev = curr;
            }
            curr = curr->link;
        }
        prev->link = curr;
    }

    ///////////////////////// Solution 2 /////////////////////
    /*
    we can remove duplicates by using double loops.
    we'll start iterating on the list from second position, and before that
    we'll de-Link first node from the list.
    while iterating we'll check each node in the first part of the list using
    inner loop.
    if the current element is not present in the first part then we'll link 
    last node of the first part of the list to current node and unlink current 
    node from the unchecked list.(second part of list)
    if current node is present in the first part of the list then we'll move 
    to the next node and repeat above steps.
    */
    void removeDuplicatesLinkBreak()
    {
        if (start == NULL)
            return;
        node *curr = start->link;
        node *prev = curr;
        node *p = start;
        p->link = NULL;

        while (curr != NULL)
        {
            p = start;
            while (p->link != NULL)
            {
                if (p->info == curr->info)
                    break;
                p = p->link;
            }
            if (p->link == NULL && p->info != curr->info)
            {
                p->link = curr;
                p = curr;
                curr = curr->link;
                p->link = NULL;
            }
            else
            {
                curr = curr->link;
            }
        }
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
    list.removeDuplicatesLinkBreak();
    list.print();
}