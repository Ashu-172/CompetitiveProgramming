/*///////////////////// Q 203: Babbar450: Find LCA  of 2 nodes in a BST ///////////////////
Given a Binary Search Tree (with all values unique) and two node values. Find the Lowest Common Ancestors of the two nodes in the BST.

Example 1:

Input:
              5
           /    \
         4       6
        /         \
       3           7
                    \
                     8
n1 = 7, n2 = 8
Output: 7
Example 2:

Input:
     2
   /   \
  1     3
n1 = 1, n2 = 3
Output: 2
Your Task:
You don't need to read input or print anything. Your task is to complete the function LCA() which takes the root Node of the BST and two integer values n1 and n2 as inputs and returns the Lowest Common Ancestor of the Nodes with values n1 and n2 in the given BST. 

Expected Time Complexity: O(Height of the BST).
Expected Auxiliary Space: O(Height of the BST).

Constraints:
1 <= N <= 10^4
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
//////////////////////////////// Solution 1 //////////////////////////
/*
there are four possibilities for the values n1 and n2 to be found in the BST.
1. both the nodes can be present in left sub tree, in this case call function recursively for left subtree.
2. both the nodes can be present in right sub tree, in this case call function recursively for right subtree.
3. when one node present in left sub tree and one is present in right sub tree, in this case lowest Commeon Ancestor will be the current node because after that both the nodes are present in different subtrees. (return root)
4. when root is equal to either of the node, this case will arise only if case 3 is not there. only in case of 1 and 2 this case will occur. in this case we'll return the current node because this node will be the ancestor of itself and other node will also come in its subtree. (return root)

*/
Node *LCA(Node *root, int n1, int n2)
{
    if (root == NULL)
        return NULL;

    if (root->data > n1 && root->data > n2)
        return LCA(root->left, n1, n2);
    else if (root->data < n1 && root->data < n2)
        return LCA(root->right, n1, n2);
    else if ((root->data < n1 && root->data > n2) ||
             (root->data > n1 && root->data < n2))
        return root;
    else
        return root;
}
/*
here in the solution in case 3 and 4, we'll return the root, so we can merge these two cases as following:

Node *LCA(Node *root, int n1, int n2)
{
    if (root == NULL)
        return NULL;

    if (root->data > n1 && root->data > n2)
        return LCA(root->left, n1, n2);
    else if (root->data < n1 && root->data < n2)
        return LCA(root->right, n1, n2);
    else
        return root;
}
*/
int main()
{
    Node *root = buildTree();
    int n1, n2;
    cin >> n1 >> n2;
    cout << LCA(root, n1, n2)->data;
    return 0;
}