/*///////////////////// Q 218: Babbar450: Flatten The BST ///////////////////////////////
Given a binary search tree, the task is to flatten it to a sorted list.
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

////////////////////////////// Solution (inorder) //////////////////////////////////////
void inorder(Node *root, vector<int> &result)
{
    if (root == NULL)
        return;

    inorder(root->left, result);
    result.push_back(root->data);
    inorder(root->right, result);
}

int main()
{
    Node *root = buildTree();
    vector<int> result;
    inorder(root, result);
    for (int num : result)
        cout << num << " ";
    cout << endl;

    return 0;
}