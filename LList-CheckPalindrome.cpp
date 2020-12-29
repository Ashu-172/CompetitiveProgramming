/*///////////////////////////// Q 143: Babbar450: Check If List is a Palindrome //////////////////////////
Given a singly linked list of size N of integers. The task is to check if the given linked list is palindrome or not.

Example 1:

Input:
N = 3
value[] = {1,2,1}
Output: 1
Explanation: The given linked list is
1 2 1 , which is a palindrome and
Hence, the output is 1.
Example 2:

Input:
N = 4
value[] = {1,2,3,4}
Output: 0
Explanation: The given linked list
is 1 2 3 4 , which is not a palindrome
and Hence, the output is 0.

Expected Time Complexity: O(N)
Expected Auxialliary Space Usage: O(1)  (ie, you should not use the recursive stack space as well)

Constraints:
1 <= N <= 105
////////////////////////////////////////////////////////////////////////////////////////////////////////*/
#include <iostream>
#include <stack>

using namespace std;

struct Node
{
    int data;
    Node *next = NULL;
    Node(int n)
    {
        data = n;
        next = NULL;
    }
};

Node *reverse(Node *start)
{
    if (start == NULL || start->next == NULL)
        return start;
    Node *prev = start;
    Node *p = start;
    Node *next = start->next;
    while (next != NULL)
    {
        p = next;
        next = next->next;
        p->next = prev;
        prev = p;
    }
    start->next = NULL;
    return prev;
}

///////////////////////////////////////// Solution 1 (Reversing) ///////////////////////////////////
/*
1. we can search for middle node of the list and then reverse the listfrom next node to end.
2. Now we can use to pointers to match the nodes. first pointer will start from first node and second pointe will start from next to middle node.
3. we can compare till second pointer reaches to last node.
4. if any data didn't match thenwwe'll return false. 
5. if all data matched then its a palindrome and e'll reverse the second half of the list again to change the list into its original version andthen we'll return true.

Time complexity for this approach is O(n).
*/
bool isPalindrome(Node *start)
{
    Node *slow = start;
    Node *fast = start->next;
    while (fast != NULL)
    {
        if (fast->next == NULL)
        {
            break;
        }
        slow = slow->next;
        fast = fast->next->next;
    }
    slow->next = reverse(slow->next);

    Node *p = start;
    Node *q = slow->next;
    while (q != NULL)
    {
        if (p->data != q->data)
        {
            return false;
        }
        p = p->next;
        q = q->next;
    }
    slow->next = reverse(slow->next);
    return true;
}

/////////////////////////////////// Solution 2 (using stack) //////////////////////////////////
/*
we can put first half of the list into the stack, and then we can start comparing remaining half of hte nodes with top of the stack and keep on popping the top element.
if node is not matching the top we can return false.
*/
bool isPalindromeStack(Node *start)
{
    Node *slow = start;
    Node *fast = start->next;
    stack<int> stk;
    while (fast != NULL)
    {
        stk.push(slow->data);
        if (fast->next == NULL)
        {
            break;
        }
        slow = slow->next;
        fast = fast->next->next;
    }
    slow = slow->next;
    while (slow != NULL)
    {
        if (slow->data != stk.top())
            return false;
        stk.pop();
        slow = slow->next;
    }
    return true;
}

int main()
{
    int size, first, n;
    cin >> size;
    Node *start = NULL, *end = NULL;
    cin >> first;
    start = new Node(first);
    end = start;
    for (int i = 1; i < size; i++)
    {
        cin >> n;
        end->next = new Node(n);
        end = end->next;
    }
    //cout << isPalindrome(start);
    cout << isPalindromeStack(start);
}