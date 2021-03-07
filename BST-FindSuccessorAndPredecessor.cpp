/*///////////////////// Q 200: Babbar450: Find Successor and PreDecessor of a Key in BST ///////////////////
There is BST given with root node with key part as integer only. You need to find the inorder successor and predecessor of a given key. In case, if the either of predecessor or successor is not found print -1.

Input:
The first line of input contains an integer T denoting the number of test cases. Then T test cases follow. Each test case contains n denoting the number of edges of the BST. The next line contains the edges of the BST. The last line contains the key.

Output:
Print the predecessor followed by successor for the given key. If the predecessor or successor is not found print -1.

Constraints:
1<=T<=100
1<=n<=100
1<=data of node<=100
1<=key<=100

Example:
Input:
2
6
50 30 L 30 20 L 30 40 R 50 70 R 70 60 L 70 80 R
65
6
50 30 L 30 20 L 30 40 R 50 70 R 70 60 L 70 80 R
100

Output:
60 70
80 -1
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
//////////////////////////////// Solution //////////////////////////
/*
1. If root is NULL
      then return
2. if key is found then
    a. If its left subtree is not null
        Then predecessor will be the right most 
        child of left subtree or left child itself.
    b. If its right subtree is not null
        The successor will be the left most child 
        of right subtree or right child itself.
    return
3. If key is smaller then root node
        set the successor as root
        search recursively into left subtree
    else
        set the predecessor as root
        search recursively into right subtree
*/
Node *leftMost(Node *root)
{
    if (root == NULL)
        return NULL;
    if (root->left == NULL)
    {
        return root;
    }
    return leftMost(root->left);
}
Node *rightMost(Node *root)
{
    if (root == NULL)
        return NULL;
    if (root->right == NULL)
        return root;
    return rightMost(root->right);
}
void findPreSuc(Node *root, Node *&pre, Node *&suc, int key)
{
    if (root == NULL)
        return;

    if (root->data == key)
    {
        if (root->right != NULL)
            suc = leftMost(root->right);
        if (root->left != NULL)
            pre = rightMost(root->left);
        return;
    }
    else if (root->data < key)
    {
        pre = root;
        findPreSuc(root->right, pre, suc, key);
    }
    else // if(root->data >key)
    {
        suc = root;
        findPreSuc(root->left, pre, suc, key);
    }
}

int main()
{
    Node *root = buildTree();
    Node *pre, *suc;
    int key;
    cin >> key;
    findPreSuc(root, pre, suc, key);
    cout << ((pre != NULL) ? pre->data : -1) << endl;
    cout << ((suc != NULL) ? suc->data : -1) << endl;
    return 0;
}