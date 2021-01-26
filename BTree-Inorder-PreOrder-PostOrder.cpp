/*///////////////////// Q 167,168,169: Babbar450: PreOrder-PostOrder-InOrder of Binary Tree ///////////////////
Find inorder, preorder and postorder traversal of tree.
/////////////////////////////////////////////////////////////////////////////////////////////////////*/
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
///////////////////// Recursive Approach //////////////////////
void inOrder(Node *node)
{
    if (node == NULL)
        return;

    inOrder(node->left);
    cout << node->data << " ";
    inOrder(node->right);
}

void preOrder(Node *node)
{
    if (node == NULL)
        return;

    cout << node->data << " ";
    preOrder(node->left);
    preOrder(node->right);
}

void postOrder(Node *node)
{
    if (node == NULL)
        return;

    postOrder(node->left);
    postOrder(node->right);
    cout << node->data << " ";
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

int main()
{
    Node *root = buildTree();
    inOrder(root);
    cout << endl;
    preOrder(root);
    cout << endl;
    postOrder(root);
    cout << endl;
    return 0;
}