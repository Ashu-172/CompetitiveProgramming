/*///////////////////// Q 217: Babbar450: Find Largest BST in a BTree ///////////////////////////////
Given a binary tree. Find the size of its largest subtree that is a Binary Search Tree.

Example 1:

Input:
        1
      /   \
     4     4
   /   \
  6     8
Output: 1
Explanation: There's no sub-tree with size
greater than 1 which forms a BST. All the
leaf Nodes are the BSTs with size equal
to 1.
Example 2:

Input: 6 6 3 N 2 9 3 N 8 8 2
            6
        /       \
       6         3
        \      /   \
         2    9     3
          \  /  \
          8 8    2 
Output: 2
Explanation: The following sub-tree is a
BST of size 2: 
       2
    /    \ 
   N      8
Your Task:
You don't need to read input or print anything. Your task is to complete the function largestBst() that takes the root node of the Binary Tree as its input and returns the size of the largest subtree which is also the BST. If the complete Binary Tree is a BST, return the size of the complete Binary Tree. 

Expected Time Complexity: O(N).
Expected Auxiliary Space: O(Height of the BST).

Constraints:
1 <= Number of nodes <= 100000
1 <= Data of a node <= 1000000
///////////////////////////////////////////////////////////////////////////////////////////////////*/
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

//////////////////////////////////////////// Solution ////////////////////////////////////////////////
bool isBST(Node *root, int &size, int &low, int &high)
{
    if (root->left == NULL && root->right == NULL)
    {
        low = root->data;
        high = root->data;
        size = 1;
        return true;
    }

    int lLow = 0, lHigh = 0, rLow = 0, rHigh = 0, lSize = 0, rSize = 0;
    bool lBST = true, rBST = true;
    if (root->left != NULL)
        lBST = isBST(root->left, lSize, lLow, lHigh);

    if (root->right != NULL)
        rBST = isBST(root->right, rSize, rLow, rHigh);

    if (lBST && rBST)
    {
        if (root->left == NULL)
        {
            if (root->data < rLow)
            {
                low = root->data;
                high = rHigh;
                size = rSize + 1;
                return true;
            }
        }
        else if (root->right == NULL)
        {
            if (root->data > lHigh)
            {
                low = lLow;
                high = root->data;
                size = lSize + 1;
                return true;
            }
        }
        else
        {
            if (root->data > lHigh && root->data < rLow)
            {
                low = lLow;
                high = rHigh;
                size = lSize + rSize + 1;
                return true;
            }
        }
    }
    size = max(lSize, rSize);
    low = 0;
    high = 0;
    return false;
}
int largestBst(Node *root)
{
    int size = 0, left = 0, right = 0;
    isBST(root, size, left, right);
    return size;
}

int main()
{
    Node *root = buildTree();
    cout << largestBst(root);

    return 0;
}