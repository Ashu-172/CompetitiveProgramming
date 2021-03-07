/*///////////////////// Q 202: Babbar450: Populate Inorder successor of all nodes ///////////////////
Given a Binary Tree, write a function to populate next pointer for all nodes. The next pointer for every node should be set to point to inorder successor.

Input:
The first line of input contains an integer T denoting the number of test cases. Then T test cases follow. Each test case contains an integer n denoting the number of edges respectively. The last line contains the edges of the tree.

Output:
Print the data for both nodes separated by "->" ( without quotes). -1 is printed if there is no successor for the node.

Constraints:
1<=T<=10^5
1<=n<=10^5
1<=data of the node<=10^5

Example:
Input:
1
3
10 8 L 8 3 L 10 12 R

Output:
3->8 8->10 10->12 12->-1
////////////////////////////////////////////////////////////////////////////////////////*/
#include <iostream>
#include <queue>

using namespace std;

class Node
{
public:
    int data;
    Node *left = NULL, *right = NULL, *next = NULL;
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
void printInorderSuccessor(Node *root, Node *&prev)
{
    if (root == NULL)
        return;

    printInorderSuccessor(root->left, prev);
    if (prev != NULL)
    {
        prev->next = root;
    }
    prev = root;
    printInorderSuccessor(root->right, prev);
}
Node *leftMost(Node *root)
{
    if (root == NULL)
        return NULL;

    if (root->left == NULL)
        return root;
    return leftMost(root->left);
}
int main()
{
    Node *root = buildTree();
    Node *prev = NULL;
    printInorderSuccessor(root, prev);
    if (root != NULL)
    {
        Node *p = leftMost(root);
        while (p != NULL && p->next != NULL)
        {
            cout << p->data << "->" << p->next->data << " ";
            p = p->next;
        }
        cout << p->data << "->" << -1 << endl;
    }
    return 0;
}