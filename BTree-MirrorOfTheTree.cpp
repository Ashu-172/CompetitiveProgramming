/*///////////////////// Q 166: Babbar450: Mirror of Binary Tree ///////////////////
Given a binary tree, the task is to create a new binary tree which is a mirror image of the given binary tree.

Examples:

Input:
        5
       / \
      3   6
     / \
    2   4
Output:
Inorder of original tree: 2 3 4 5 6 
Inorder of mirror tree: 6 5 4 3 2
Mirror tree will be:
  5
 / \
6   3
   / \
  4   2

Input:
        2
       / \
      1   8
     /     \
    12      9
Output:
Inorder of original tree: 12 1 2 8 9 
Inorder of mirror tree: 9 8 2 1 12 
/////////////////////////////////////////////////////////////////////////////////*/
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
/*///////////////////////// Solution ///////////////////////
-> if root is null, then in mirror also root will be null.
-> if not null then create a node with same data.
-> create mirror of left sub tree and assign it to right pointer of mirror node.
-> create mirror of right sub tree and assign it to left pointer of mirror node.
-> return mirror node.
*/
Node *createMirror(Node *root)
{
    if (root == NULL)
    {
        return NULL;
    }

    Node *mirror = new Node(root->data);
    mirror->right = createMirror(root->left);
    mirror->left = createMirror(root->right);
    return mirror;
}

int main()
{
    Node *root = buildTree();
    Node *mirror = createMirror(root);
    inOrder(root);
    cout << endl;
    inOrder(mirror);
    return 0;
}
