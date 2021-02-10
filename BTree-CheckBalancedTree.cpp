/*///////////////////// Q 175: Babbar450: Check Balanced Tree ///////////////////
Given a binary tree, find if it is height balanced or not. 
A tree is height balanced if difference between heights of left and right subtrees is not more than one for all nodes of tree. 

A height balanced tree
        1
     /     \
   10      39
  /
5

An unbalanced tree
        1
     /    
   10   
  /
5

Example 1:

Input:
      1
    /
   2
    \
     3 
Output: 0
Explanation: The max difference in height
of left subtree and right subtree is 2,
which is greater than 1. Hence unbalanced
Example 2:

Input:
       10
     /   \
    20   30 
  /   \
 40   60
Output: 1
Explanation: The max difference in height
of left subtree and right subtree is 1.
Hence balanced. 
Your Task:
You don't need to take input. Just complete the function isBalanced() that takes root node as parameter and returns true, if the tree is balanced else returns false.

Constraints:
1 <= Number of nodes <= 105
0 <= Data of a node <= 106

Expected time complexity: O(N)
Expected auxiliary space: O(h) , where h = height of tree
/////////////////////////////////////////////////////////////////////////////////*/
#include <iostream>
#include <vector>
#include <deque>
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

///////////////////////////////////////// Solution ////////////////////////////////////
/*
1. calculate the height of left and right sub tree and also check they are balanced
2. if any of the them is unbalanced return false
3. if both are balanced  then calculate difference of left and right sub trees, if it
    is greater than 1 then return false.
4. calculate height for current sub tree as  max(leftHeight, rightHeight) + 1
5. return with Height and true(since Tree is balanced if reached till this step).
*/

bool isBalancedHeight(Node *root, int &height)
{
    if (root == NULL)
        return true;

    int lHeight = 0, rHeight = 0;

    if (isBalancedHeight(root->left, lHeight) != true)
        return false;

    if (isBalancedHeight(root->right, rHeight) != true)
        return false;

    if (lHeight - rHeight > 1 || rHeight - lHeight > 1)
        return false;

    height = max(lHeight, rHeight) + 1;
    return true;
}
bool isBalanced(Node *root)
{
    int height = 0;
    return isBalancedHeight(root, height);
}
int main()
{
    Node *root = buildTree();
    cout << isBalanced(root) << endl;
    return 0;
}
