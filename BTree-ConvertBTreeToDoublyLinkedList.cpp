/*///////////////////// Q 179: Babbar450: BTree To Doubly LinkedList ///////////////////
Given a Binary Tree (BT), convert it to a Doubly Linked List(DLL) In-Place. The left and 
right pointers in nodes are to be used as previous and next pointers respectively in 
converted DLL. The order of nodes in DLL must be same as Inorder of the given Binary Tree. 
The first node of Inorder traversal (leftmost node in BT) must be the head node of the DLL.

Example 1:

Input:
      1
    /  \
   3    2
Output:
3 1 2 
2 1 3 
Explanation: DLL would be 3<=>1<=>2

Example 2:

Input:
       10
      /   \
     20   30
   /   \
  40   60
Output:
40 20 60 10 30 
30 10 60 20 40
Explanation:  DLL would be 
40<=>20<=>60<=>10<=>30.
Your Task:
You don't have to take input. Complete the function bToDLL() that takes root node of the 
tree as a parameter and returns the head of DLL . The driver code prints the DLL both ways.

Expected Time Complexity: O(N).
Expected Auxiliary Space: O(H).
Note: H is the height of the tree and this space is used implicitly for recursion stack.

Constraints:
1 <= Number of nodes <= 105
1 <= Data of a node <= 105
///////////////////////////////////////////////////////////////////////////////////////*/
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Node
{
public:
    int data;
    Node *left = NULL, *right = NULL;
    Node(int data)
    {
        this->data = data;
    }
};

void inOrder(Node *node)
{
    if (node == NULL)
        return;

    inOrder(node->left);
    cout << node->data << " ";

    inOrder(node->right);
}

// Function to Build Tree
Node *buildTree()
{
    int size;
    cin >> size;
    string data;
    cin >> data;
    Node *root = new Node(stoi(data));
    size--;

    queue<Node *> q;
    q.push(root);

    while (size > 0)
    {
        Node *temp;
        if (q.empty() != true)
        {
            temp = q.front();
            q.pop();
        }
        else
        {
            break;
        }
        cin >> data;
        if (data != "N")
        {
            Node *node = new Node(stoi(data));
            temp->left = node;
            size--;
            q.push(node);
        }

        if (size > 0)
        {
            cin >> data;
            if (data != "N")
            {
                Node *node = new Node(stoi(data));
                temp->right = node;
                size--;
                q.push(node);
            }
        }
    }
    return root;
}
//////////////////////////////////////// Solution 1 ///////////////////////////////////
/*
1.  If left subtree exists, process the left subtree
    a. Recursively convert the left subtree to DLL by calling the function.
    b. Then find inorder predecessor of root in left subtree (inorder predecessor is rightmost node in left subtree).
    c. Make inorder predecessor as previous of root and root as next of inorder predecessor.

2.  If right subtree exists, process the right subtree (Below 3 steps are similar to left subtree).
    a. Recursively convert the right subtree to DLL by callingthe function.
    b. Then find inorder successor of root in right subtree (inorder successor is leftmost node in right subtree).
    c. Make inorder successor as next of root and root as previous of inorder successor.

3. Find the leftmost node and return it (the leftmost node is always head of converted DLL).
*/
Node *getRightMost(Node *root)
{
    if (root->right == NULL)
        return root;
    else
        return getRightMost(root->right);
}

Node *getLeftMost(Node *root)
{
    if (root->left == NULL)
        return root;
    else
        return getLeftMost(root->left);
}
void createLinks(Node *root)
{
    if (root->left == NULL && root->right == NULL)
        return;

    if (root->left != NULL)
    {
        createLinks(root->left);
        Node *rMost = getRightMost(root->left);
        rMost->right = root;
        root->left = rMost;
    }
    if (root->right != NULL)
    {
        createLinks(root->right);
        Node *lMost = getLeftMost(root->right);
        lMost->left = root;
        root->right = lMost;
    }
}

Node *bToDLL(Node *root)
{
    if (root == NULL)
        return root;

    createLinks(root);
    return getLeftMost(root);
}

////////////////////////////////////// Solution 2 ///////////////////////////////////
/*
We can solve this problem by doing inorder tracersal and keeping track of 
first and last node in each inorder traversal.

1. do level order traversal for left sub tree and get first and last nodes in that traversal.
    a.  point root->left to last node in this traversal and last node's right to root.
    b.  assign first node of this traversal to the first node of parent's traversal.

2. do level order traversal for right sub tree and get first and last nodes in that traversal.
    a.  point root->right to first node in this traversal and first node's left to root.
    b.  assign last node of this traversal to the last node of parent's traversal.

return first node of the first traversal, since it'll be the head of the Doubly Linked List.

Note:
if we want to make circular Doubly linked list, we can link first and last nodes in the end 
(in bToDLLInorder function) and return first node as head of the Circular Doubly Linked List.
*/
void inOrderTraversal(Node *root, Node *&first, Node *&last)
{
    if (root == NULL)
        return;

    Node *lFirst = NULL, *lLast = NULL, *rFirst = NULL, *rLast = NULL;

    if (root->left != NULL)
    {
        inOrderTraversal(root->left, lFirst, lLast);
        root->left = lLast;
        if (lLast != NULL)
            lLast->right = root;
        first = lFirst;
    }
    else
        first = root;

    if (root->right != NULL)
    {
        inOrderTraversal(root->right, rFirst, rLast);
        root->right = rFirst;
        if (rFirst != NULL)
            rFirst->left = root;
        last = rLast;
    }
    else
        last = root;
}
Node *bToDLLInorder(Node *root)
{
    if (root == NULL)
        return root;

    Node *first, *last;
    inOrderTraversal(root, first, last);
    return first;
}

int main()
{
    Node *root = buildTree();
    Node *head = bToDLLInorder(root);
    Node *p = head;
    while (p != NULL)
    {
        cout << p->data << " ";
        p = p->right;
    }
    return 0;
}