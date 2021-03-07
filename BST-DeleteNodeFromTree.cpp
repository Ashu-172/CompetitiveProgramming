/*///////////////////// Q 198: Babbar450: Delete Node in a BST ///////////////////
Given a root node reference of a BST and a key, delete the node with the given key in the BST. Return the root node reference (possibly updated) of the BST.

Basically, the deletion can be divided into two stages:

Search for a node to remove.
If the node is found, delete the node.
Follow up: Can you solve it with time complexity O(height of tree)?

 

Example 1:


Input: root = [5,3,6,2,4,null,7], key = 3
Output: [5,4,6,2,null,null,7]
Explanation: Given key to delete is 3. So we find the node with value 3 and delete it.
One valid answer is [5,4,6,2,null,null,7], shown in the above BST.
Please notice that another valid answer is [5,2,6,null,4,null,7] and it's also accepted.

Example 2:

Input: root = [5,3,6,2,4,null,7], key = 0
Output: [5,3,6,2,4,null,7]
Explanation: The tree does not contain a node with value = 0.
Example 3:

Input: root = [], key = 0
Output: []
 

Constraints:

The number of nodes in the tree is in the range [0, 10^4].
-10^5 <= Node.val <= 10^5
Each node has a unique value.
root is a valid binary search tree.
-10^5 <= key <= 10^5
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
/////////////////////////////////////// Solution ///////////////////////////////////
/*
whenecer we delete a node from a bst, we need to move it's right sub tree to its place and we need to move it's left sub tree  to left to the left most node in the right sub tree (Read It Again) because that node will be the just bigger node of the left child.
To search for the key, we'll choose the branch in which key should be present based on the BST property. once we'll find the key following will be the possible cases:
1. if left and right nodes are not null then we need to find left most node in the right sub tree, then assign left sub tree to that node's left child, and return the right child node as the new root for that sub tree.
2. if left child is null and right child is not null than we'll directly return right child as new root for that sub tree.
3. if right child is null and left child is not null then we'll return left child as new root for that sub tree.
4. if both left and right childs are null, we'll return null because the deleted node is actually a leaf node.
*/
Node *findLeftMostNode(Node *root)
{
    if (root->left == NULL)
        return root;
    return findLeftMostNode(root->left);
}

Node *deleteNode(Node *root, int key)
{
    if (root == NULL)
        return root;

    if (root->data == key)
    {
        if (root->right != NULL && root->left != NULL)
        {
            Node *lMost = findLeftMostNode(root->right);
            lMost->left = root->left;
            return root->right;
        }
        else if (root->left == NULL && root->right != NULL)
            return root->right;
        else if (root->left != NULL && root->right == NULL)
            return root->left;
        else
            return NULL;
    }

    if (root->data > key)
        root->left = deleteNode(root->left, key);
    else
        root->right = deleteNode(root->right, key);

    return root;
}
int main()
{
    Node *root = buildTree();

    int key;
    cin >> key;
    root = deleteNode(root, key);
    inOrder(root);
    return 0;
}