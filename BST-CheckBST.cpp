/*///////////////////// Q 201: Babbar450: Check whether Given Binary tree is a BST or Not ///////////////////
Given a binary tree. Check whether it is a BST or not.
Note: We are considering that BSTs can not contain duplicate Nodes.

Example 1:

Input:
    2
 /    \
1      3
Output: 1 
Explanation: 
The left subtree of root node contains node 
with key lesser than the root node’s key and 
the right subtree of root node contains node 
with key greater than the root node’s key.
Hence, the tree is a BST.
Example 2:

Input:
  2
   \
    7
     \
      6
       \
        5
         \
          9
           \
            2
             \
              6
Output: 0 
Explanation: 
Since the node with value 7 has right subtree 
nodes with keys less than 7, this is not a BST.
Your Task:
You don't need to read input or print anything. Your task is to complete the function isBST() which takes the root of the tree as a parameter and returns true if the given binary tree is BST, else returns false. 

Expected Time Complexity: O(N).
Expected Auxiliary Space: O(Height of the BST).

Constraints:
0 <= Number of edges <= 100000
////////////////////////////////////////////////////////////////////////////////////////*/
#include <iostream>
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
//////////////////////////////// Solution 1//////////////////////////
/*
We can use inorder traversal to check the Given tree. Inorder traversal of a BST always gives nodes in sorted order. so in inorder traversal we can keep track of previously visited node and compare the current node with that. if value of current node is lesser than or equal to the previous node we can say that the Tree is not a BST. if value of the current node is greated than the previously visited node's value, we'll update the previous with current node and recursively repeat the process.
*/
bool checkBST(Node *root, int &prev)
{
    if (root == NULL)
        return true;

    if (!checkBST(root->left, prev))
        return false;

    if (prev >= root->data)
        return false;
    else
        prev = root->data;

    if (!checkBST(root->right, prev))
        return false;

    return true;
}
bool isBST(Node *root)
{
    int prev = INT_MIN;
    return checkBST(root, prev);
}

int main()
{
    Node *root = buildTree();
    cout << isBST(root);
    return 0;
}