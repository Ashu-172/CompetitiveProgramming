/*/////////////////// Q 277: Babbar450: Implement Stack with Middle ELement //////////////////
Design a stack with operations on middle element

implement a stack which will support following operations in O(1) time complexity?
1) push() which adds an element to the top of stack.
2) pop() which removes an element from top of stack.
3) findMiddle() which will return middle element of the stack.
4) deleteMiddle() which will delete the middle element.
/////////////////////////////////////////////////////////////////////////////////////////*/
#include <iostream>

using namespace std;

/*
 we need to find and delete middle element. Deleting an element from middle is not O(1) for array. Also, we may need to move the middle pointer up when we push an element and move down when we pop(). In singly linked list, moving middle pointer in both directions is not possible.

The idea is to use Doubly Linked List (DLL). We can delete middle element in O(1) time by maintaining mid pointer. We can move mid pointer in both directions using previous and next pointers.
*/

class Stack
{
    class Node
    {
    public:
        int data;
        Node *prev;
        Node *next;

        Node(int data)
        {
            this->data = data;
            this->prev = NULL;
            this->next = NULL;
        }
    };

    Node *top;
    Node *middle;
    int size;

public:
    Stack()
    {
        top = NULL;
        middle = NULL;
        size = 0;
    }

    void push(int num)
    {
        Node *temp = new Node(num);
        if (top == NULL)
        {
            top = temp;
            middle = temp;
            size++;
            return;
        }
        top->prev = temp;
        temp->next = top;
        top = temp;
        size++;
        if (size % 2)
            middle = middle->prev;
    }

    int pop()
    {
        if (size == 0)
            return -1;
        Node *temp = top;
        top = top->next;
        int num = temp->data;
        free(temp);
        size--;
        if (size % 2 == 0)
            middle = middle->next;
        return num;
    }

    int findMiddle()
    {
        return (middle == NULL ? -1 : middle->data);
    }

    void delMiddle()
    {
        if (size == 0)
            return;

        Node *temp = middle;
        if (size != 1)
        {
            middle->prev->next = middle->next;
            if (middle->next != NULL)
                middle->next->prev = middle->prev;
        }
        if (size % 2)
            middle = middle->next;
        else
            middle = middle->prev;
        free(temp);
        size--;
    }
};

int main()
{
    Stack stk;
    cout << stk.findMiddle() << endl;
    stk.push(2);
    stk.push(4);
    stk.push(6);
    stk.push(8);
    cout << stk.findMiddle() << endl;
    stk.delMiddle();
    cout << stk.findMiddle() << endl;
    cout << stk.pop() << endl;
    cout << stk.findMiddle() << endl;
    stk.delMiddle();
    cout << stk.findMiddle() << endl;
    stk.push(10);
    cout << stk.findMiddle() << endl;
    stk.push(12);
    cout << stk.findMiddle() << endl;
}